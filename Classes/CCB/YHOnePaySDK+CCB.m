//
//  YHOnePaySDK+CCB.m
//  YHOnePaySDK
//
//  Created by Jagtu on 2019/3/14.
//

#import "YHOnePaySDK+CCB.h"
#import "YHOnePayWebVC.h"
#import "CCBNetPaySDK.h"
#import "WXApi.h"

@implementation YHOnePaySDK (CCB)

//集成建行手机银行APP支付及内嵌H5网页支付方法（首选）
- (void)ccbpayOrder:(NSString *)orderStr
{
    if ([YHOnePayHelper isNilOrEmpty:orderStr]) {
        [self completionWithCode:YLZErrCodeParamExpection message:@"支付凭证为空" result:nil];
        return;
    }

    YHWeakifySelf;
    [[CCBNetPay defaultService] payOrder:orderStr callback:^(NSDictionary *dic) {
        YHStrongifySelf;
        [self callback:dic];
    }];
}

//指定跳转建行手机银行APP支付方法
- (void)ccbpayAppOrder:(NSString *)orderStr
{
    if ([YHOnePayHelper isNilOrEmpty:orderStr]) {
        [self completionWithCode:YLZErrCodeParamExpection message:@"支付凭证为空" result:nil];
        return;
    }
    
    NSString * appScheme = [YHOnePayConfig shareInstance].appScheme;
    if (!appScheme.length) {
        appScheme = [[NSBundle mainBundle] bundleIdentifier];
    }
    
    YHWeakifySelf;
    [[CCBNetPay defaultService] payAppOrder:orderStr callback:^(NSDictionary *dic) {
        YHStrongifySelf;
        [self callback:dic];
    }];
}

//指定弹出内嵌H5支付方法
- (void)ccbpayUrlOrder:(NSString *)orderStr
{
    if ([YHOnePayHelper isNilOrEmpty:orderStr]) {
        [self completionWithCode:YLZErrCodeParamExpection message:@"支付凭证为空" result:nil];
        return;
    }
    
    NSString * appScheme = [YHOnePayConfig shareInstance].appScheme;
    if (!appScheme.length) {
        appScheme = [[NSBundle mainBundle] bundleIdentifier];
    }
    
    YHWeakifySelf;
    [[CCBNetPay defaultService] payUrlOrder:orderStr callback:^(NSDictionary *dic) {
        YHStrongifySelf;
        [self callback:dic];
    }];
}

//微信支付方法
- (void)ccbpayWechatOrder:(NSString *)orderStr
{
    if ([YHOnePayHelper isNilOrEmpty:orderStr]) {
        [self completionWithCode:YLZErrCodeParamExpection message:@"支付凭证为空" result:nil];
        return;
    }
    [[CCBNetPay defaultService] registerWechatPayApp:[YHOnePayConfig shareInstance].appScheme];
    YHWeakifySelf;
    [[CCBNetPay defaultService] payWechatOrder:orderStr callback:^(NSDictionary *dic) {
        YHStrongifySelf;
        [self callback:dic];
    }];
}

//支付宝支付方法
- (void)ccbpayAliOrder:(NSString *)orderStr
{
    if ([YHOnePayHelper isNilOrEmpty:orderStr]) {
        [self completionWithCode:YLZErrCodeParamExpection message:@"支付凭证为空" result:nil];
        return;
    }
    
    NSString * appScheme = [YHOnePayConfig shareInstance].appScheme;
    if (!appScheme.length) {
        appScheme = [[NSBundle mainBundle] bundleIdentifier];
    }
    
    YHWeakifySelf;
    [[CCBNetPay defaultService] payAliOrder:orderStr callback:^(NSDictionary *dic) {
        YHStrongifySelf;
        [self callback:dic];
    }];
}

//银联支付方法
- (void)ccbpayUnionOrder:(NSString *)orderStr
{
    if ([YHOnePayHelper isNilOrEmpty:orderStr]) {
        [self completionWithCode:YLZErrCodeParamExpection message:@"支付凭证为空" result:nil];
        return;
    }
    
    YHWeakifySelf;
    [[CCBNetPay defaultService] payUnionOrder:orderStr callback:^(NSDictionary *dic) {
        YHStrongifySelf;
        [self callback:dic];
    }];
}

//综合选择支付，弹出界面供商户选择已开通支付方式。
- (void)payViewOrder:(NSString *)orderStr
{
    if ([YHOnePayHelper isNilOrEmpty:orderStr]) {
        [self completionWithCode:YLZErrCodeParamExpection message:@"支付凭证为空" result:nil];
        return;
    }
    YHWeakifySelf;
    [[CCBNetPay defaultService] payViewOrder:orderStr callback:^(NSDictionary *dic) {
        YHStrongifySelf;
        [self callback:dic];
    }];
}

//获取建行手机银行APP支付完成后返回信息（需在AppDelegate.m的 openURL代理方法中实现，下面详细描述）
- (void)ccbProcessWithResult:(NSURL *)resultUrl
{
    if ([resultUrl.host isEqualToString:@"safepay"]
        || [resultUrl.host isEqualToString:@"platformapi"])//支付宝钱包快登授权返回authCode
    {
        //如果极简开发包不可用，会跳转支付宝钱包进行支付，需要将支付宝钱包的支付结果回传给开发包
        YHWeakifySelf;
        [[CCBNetPay defaultService] processOrderWithPaymentResult:resultUrl standbyCallback:^(NSDictionary *resultDic) {
            //注意：如果原有回调block有效，这边将不会执行
            LOG(@"result = %@",resultDic);
            YHStrongifySelf;
            [self callback:resultDic];
        }];
        [WXApi handleOpenURL:resultUrl delegate:[CCBNetPay defaultService]];
    }
}

-(void)callback:(NSDictionary *)resultDic
{
    LOG(@"reslut = %@",resultDic);
    /**
    1.    code = -1。H5支付（龙支付H5、银联支付） 取消支付。
    2.    epayStatus = ”” 为手机银行APP支付取消
    3.    epayStatus = Y 为手机银行APP支付成功，未开商户通知
    4.    有返回。以字段SUCCESS为“Y”支付成功，“N”支付失败，ERRORMSG字段为错误信息。
    5.    nil。手机银行无返回信息 订单状态请商户以异步服务器通知为准。
     */
    NSString *epayStatus = [resultDic objectForKey:@"epayStatus"];
    NSInteger code = [resultDic objectForKey:@"code"]?[[resultDic objectForKey:@"code"] integerValue]:0;
    NSString *SUCCESS = [resultDic objectForKey:@"SUCCESS"]?:@"";
    NSString *ERRCODE = [resultDic objectForKey:@"ERRCODE"]?:@"";
    NSString * message = [resultDic objectForKey:@"ERRORMSG"]?:@"";
    
    YLZErrCode errCode = YLZErrCodeCommon;
    if (code == -1 || [@"" isEqualToString:epayStatus]) {//用户中途取消
        errCode = YLZErrCodeUserCancel;
        message = @"交易已取消";
    }else if ([@"Y" isEqualToString:epayStatus] || [@"true" isEqualToString:epayStatus]) {//手机银行APP支付成功
        errCode = YLZErrCodeSuccess;
        message = @"交易成功";
    }else if ([@"Y" isEqualToString:SUCCESS] || [@"true" isEqualToString:SUCCESS]) {//支付成功
        if ([YHOnePayHelper isNilOrEmpty:ERRCODE]) {
            errCode = YLZErrCodeSuccess;
            message = @"交易成功";
        }else{
            
            if ([@"000000" isEqualToString:ERRCODE]) {
                errCode = YLZErrCodeSuccess;
                message = @"交易成功";
            }else{
                errCode = YLZErrCodePayFail;
                message = [resultDic objectForKey:@"ERRMSG"]?:@"交易失败";
            }
        }
    }else if ([@"N" isEqualToString:SUCCESS]) {//支付失败
        errCode = YLZErrCodePayFail;
        message = [resultDic objectForKey:@"ERRORMSG"]?:@"交易失败";
        
    }else{
        //正在处理中，支付结果未知（有可能已经支付成功），订单状态请商户以异步服务器通知为准。
        errCode = YLZErrCodeInProcess;
        message = @"交易结果未知（有可能已经支付成功）";
    }
    [self completionWithCode:errCode message:message result:resultDic];
}

@end
