//
//  YHOnePaySDK+Alipay.m
//  YHOnePaySDK
//
//  Created by Jagtu on 2019/3/14.
//

#import "YHOnePaySDK+Alipay.h"


@implementation YHOnePaySDK (Alipay)

- (void)alipayOrder:(NSString *)orderStr
{
    if ([YHOnePayHelper isNilOrEmpty:orderStr]) {
        [self completionWithCode:YLZErrCodeParamExpection message:@"支付凭证为空" result:nil];
        return;
    }
    
    NSString * appScheme = [YHOnePayConfig shareInstance].appScheme;
    if (!appScheme.length) {
        appScheme = [[NSBundle mainBundle] bundleIdentifier];
    }
    // NOTE: 调用支付宝支付
    YHWeakifySelf;
    [[AlipaySDK defaultService] payOrder:orderStr fromScheme:appScheme callback:^(NSDictionary *resultDic) {
        YHStrongifySelf;
        [self callback:resultDic];
    }];
}

- (void)alipayWithUrl:(NSString *)directUrl
{
    if([YHOnePayHelper isNilOrEmpty:directUrl]){
        [self completionWithCode:YLZErrCodeParamExpection message:@"订单请求丢失" result:nil];
        return;
    }
    
    NSString * appScheme = [YHOnePayConfig shareInstance].appScheme;
    if (!appScheme.length) {
        appScheme = [[NSBundle mainBundle] bundleIdentifier];
    }
    
    YHWeakifySelf;
    // 此处调用支付宝SDK提供的支付接口进行支付
    BOOL isIntercepted = [[AlipaySDK defaultService] payInterceptorWithUrl:directUrl fromScheme:appScheme callback:^(NSDictionary *resultDic) {
        YHStrongifySelf;
        [self callback:resultDic];
    }];
    if (! isIntercepted) {
        //调用WebView打开
        YHOnePayWebVC * web = [[YHOnePayWebVC alloc] initWithUrl:directUrl withTitle:@"正在拉起支付宝支付.."];
        [YHOnePayVCHelper gotoNextVC:web];
    }
}

- (BOOL)alipayInterceptorWithUrl:(NSString *)directUrl
{
    if([YHOnePayHelper isNilOrEmpty:directUrl]){
        [self completionWithCode:YLZErrCodeParamExpection message:@"订单请求丢失" result:nil];
        return NO;
    }
    
    NSString * appScheme = [YHOnePayConfig shareInstance].appScheme;
    if (!appScheme.length) {
        appScheme = [[NSBundle mainBundle] bundleIdentifier];
    }
    
    YHWeakifySelf;
    // 此处调用支付宝SDK提供的支付接口进行支付
    BOOL isIntercepted = [[AlipaySDK defaultService] payInterceptorWithUrl:directUrl fromScheme:appScheme callback:^(NSDictionary *resultDic) {
        YHStrongifySelf;
        [self callback:resultDic];
    }];
    
    return isIntercepted;
}


- (void)alipayProcessWithResult:(NSURL *)resultUrl
{
    if ([resultUrl.host isEqualToString:@"safepay"]
        || [resultUrl.host isEqualToString:@"platformapi"])//支付宝钱包快登授权返回authCode
    {
        //如果极简开发包不可用，会跳转支付宝钱包进行支付，需要将支付宝钱包的支付结果回传给开发包
        YHWeakifySelf;
        [[AlipaySDK defaultService] processOrderWithPaymentResult:resultUrl standbyCallback:^(NSDictionary *resultDic) {
            //注意：如果原有回调block有效，这边将不会执行
            LOG(@"result = %@",resultDic);
            YHStrongifySelf;
            [self callback:resultDic];
        }];
    }
}


-(void)callback:(NSDictionary *)resultDic
{
    LOG(@"reslut = %@",resultDic);
    NSString * resultStatus = [resultDic objectForKey:@"resultCode"]?:[resultDic objectForKey:@"resultStatus"];
    NSString * message = @"";
    YLZErrCode errCode = YLZErrCodeCommon;
    if ([@"9000" isEqualToString:resultStatus]) {//订单支付成功
        errCode = YLZErrCodeSuccess;
        message = @"交易成功";
    }else if ([@"8000" isEqualToString:resultStatus]) {//正在处理中，支付结果未知（有可能已经支付成功），请查询商户订单列表中订单的支付状态
        errCode = YLZErrCodeInProcess;
        message = @"交易处理中";
    }else if ([@"4000" isEqualToString:resultStatus]) {//订单支付失败
        errCode = YLZErrCodePayFail;
        message = @"交易失败，请重新操作";
    }else if ([@"5000" isEqualToString:resultStatus]) {//重复请求
        errCode = YLZErrCodeRepeat;
        message = @"订单重复交易";
    }else if ([@"6001" isEqualToString:resultStatus]) {//用户中途取消
        errCode = YLZErrCodeUserCancel;
        message = @"交易已取消";
    }else if ([@"6002" isEqualToString:resultStatus]) {//网络连接出错
        errCode = YLZErrCodeSentFail;
        message = @"交易失败，网络连接出错";
    }else if ([@"6004" isEqualToString:resultStatus]) {//支付结果未知（有可能已经支付成功），请查询商户订单列表中订单的支付状态
        errCode = YLZErrCodeUnKnown;
        message = @"交易结果未知（有可能已经支付成功）";
    }
    if ([[resultDic objectForKey:@"memo"] length]) {
        message = [NSString stringWithFormat:@"%@",[resultDic objectForKey:@"memo"]];
    }else if ([resultDic objectForKey:@"result"]) {
        NSDictionary *result = [NSDictionary dictionaryWithJsonString:[resultDic objectForKey:@"result"]];
        if ([result objectForKey:@"alipay_trade_app_pay_response"]) {
            NSDictionary *atapResponse = [result objectForKey:@"alipay_trade_app_pay_response"];
            message = [atapResponse objectForKey:@"sub_msg"]?[atapResponse objectForKey:@"sub_msg"]:([atapResponse objectForKey:@"msg"]?[atapResponse objectForKey:@"msg"]:message);
        }
    }
    
    if (errCode == YLZErrCodeSuccess) {
        //第一步： 提取response字段值
        //                NSDictionary * result = [resultDic objectForKey:@"result"];
        //                NSDictionary * alipay_trade_wap_pay_response = [result objectForKey:@"alipay_trade_wap_pay_response"];//签名原始字符串
        //                NSString * sign_type = [result objectForKey:@"sign_type"];//签名类型（RSA目前代表1024位签名）
        //                NSString * sign = [result objectForKey:@"sign"];//签名
        //第二步：验证签名是否合法
        
        //签名验证通过后，必须严格按照如下的描述校验通知参数的合法性
        
        //1、商户需要验证该通知数据中的out_trade_no是否为商户系统中创建的订单号；
        //2、判断total_amount是否确实为该订单的实际金额（即商户订单创建时的金额）；
        //3、校验通知中的seller_id（或者seller_email) 是否为out_trade_no这笔单据对应的操作方（有的时候，一个商户可能有多个seller_id/seller_email）；
        //4、验证app_id是否为该商户本身。
        //上述1、2、3、4有任何一个验证不通过，则表明同步校验结果是无效的，只有全部验证通过后，才可以认定买家付款成功
        
    }
    
    [self completionWithCode:errCode message:message result:resultDic];
}

@end
