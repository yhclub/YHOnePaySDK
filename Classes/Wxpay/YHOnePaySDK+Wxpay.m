//
//  YHOnePaySDK+Wxpay.m
//  YHOnePaySDK
//
//  Created by Jagtu on 2019/3/14.
//

#import "YHOnePaySDK+Wxpay.h"

@implementation YHOnePaySDK (Wxpay)

- (void)wxpayWithParam:(NSDictionary *)wx_app_pay
{
    /* 示例
     @"wx_app_pay": @{
        @"appid":@"wxb27e6fb0d7a2f90f",
        @"nonceStr":@"1100566457",
        @"package":@"Sign=WXPay",
        @"partnerid":@"1344597901",
        @"prepayid":@"wx20160819110056ab67e3d52c0328335808",
        @"sign":@"770B0AE944F9C47328BDEF39C3E6FC38",
        @"timeStamp":@"1471575657396"
     }
     */
    if ([YHOnePayHelper isNilOrEmpty:wx_app_pay]) {
        [self completionWithCode:YLZErrCodeParamExpection message:@"微信交易凭证为空" result:nil];
        return;
    }
    
    NSString * appid = [wx_app_pay objectForKey:@"appid"];
    //注册APPID
    BOOL isRegister = NO;
    if (appid && [appid isKindOfClass:[NSString class]]) {
        NSString *universalLink = [NSString stringWithFormat:@"%@/%@/",kWeChatPayUniversalLinkPrefix,appid];
        isRegister = [WXApi registerApp:appid universalLink:universalLink];
    }
    if (!isRegister) {
        [self completionWithCode:YLZErrCodeParamExpection message:@"向微信客户端注册APPID失败" result:nil];
        return;
    }else{

    }
    //调起支付
    PayReq *request = [[PayReq alloc] init];
    request.partnerId = [wx_app_pay objectForKey:@"partnerid"];
    request.prepayId= [wx_app_pay objectForKey:@"prepayid"];
    request.package = [wx_app_pay objectForKey:@"package"];
    request.nonceStr= [wx_app_pay objectForKey:@"nonceStr"]?[wx_app_pay objectForKey:@"nonceStr"]:[wx_app_pay objectForKey:@"noncestr"];
    request.timeStamp= [([wx_app_pay objectForKey:@"timeStamp"]?[wx_app_pay objectForKey:@"timeStamp"]:[wx_app_pay objectForKey:@"timestamp"]) intValue];
    request.sign= [wx_app_pay objectForKey:@"sign"];
    
    YHWeakifySelf;
    [WXApi sendReq:request completion:^(BOOL success) {
        YHStrongifySelf;
        if (!success) {
            [self completionWithCode:YLZErrCodeParamExpection message:@"打开微信支付失败" result:nil];
        }
    }];
}

- (void)wxpayWithUrl:(NSString *)directUrl
{
    if([YHOnePayHelper isNilOrEmpty:directUrl]){
        [self completionWithCode:YLZErrCodeParamExpection message:@"订单请求丢失" result:nil];
        return;
    }
    //由于这里是APP调起支付，不是网页H5发起支付，所以这里directUrl值不需要再拼接上redirect_url参数
    YHOnePayWebVC * web = [[YHOnePayWebVC alloc] initWithUrl:directUrl withTitle:@"正在拉起微信支付.."];
    [YHOnePayVCHelper gotoNextVC:web];
}

- (void)wxpayProcessWithResult:(NSURL *)resultUrl
{
    if ([[resultUrl absoluteString] hasPrefix:@"wx"]){
        
        [WXApi handleOpenURL:resultUrl delegate:self];
        
    }else if ([[resultUrl absoluteString] hasPrefix:[YHOnePayHelper getWxH5PayReferer]]){
        
        //微信h5回调
        
        if ([YHOnePayConfig shareInstance].useCustomQueryPayResult) {
            
            [self completionWithCode:YLZErrCodeInProcess message:@"交易结果未知" result:nil];
        }else{
            [self refreshPayResult];
        }
    }
}

- (BOOL)wxpayProcessWithUniversalLink:(NSUserActivity *)userActivity
{
    return  [WXApi handleOpenUniversalLink:userActivity delegate:self];
}


#pragma mark - WXApiDelegate
- (void)onResp:(BaseResp *)resp {
    if ([resp isKindOfClass:[PayResp class]]) {
        //服务器端查询支付通知或查询API返回的结果再提示成功
        
        PayResp*response=(PayResp*)resp;
        
        NSString * message = @"交易结果未知";
        YLZErrCode errCode = YLZErrCodeUnKnown;
        if (response.errCode == WXSuccess) {
            errCode = YLZErrCodeSuccess;
            message = @"交易成功";
        }else if (response.errCode == WXErrCodeCommon) {
            errCode = YLZErrCodeCommon;
            message = @"交易错误";
        }else if (response.errCode == WXErrCodeAuthDeny) {
            errCode = YLZErrCodeAuthDeny;
            message = @"微信授权失败，交易已取消";
        }else if (response.errCode == WXErrCodeUnsupport) {
            errCode = YLZErrCodeUnsupport;
            message = @"微信不支持，交易已取消";
        }else if (response.errCode == WXErrCodeUserCancel) {
            errCode = YLZErrCodeUserCancel;
            message = @"交易已取消";
        }else if (response.errCode == WXErrCodeSentFail) {
            errCode = YLZErrCodeSentFail;
            message = @"网络异常，交易错误";
        }
        
        if (errCode == YLZErrCodeUnKnown) {
            
            if ([YHOnePayConfig shareInstance].useCustomQueryPayResult) {
                [self completionWithCode:YLZErrCodeInProcess message:message result:nil];
            }else{
                [self refreshPayResult];
            }
        }else{
            
            [self completionWithCode:errCode message:message result:nil];
        }
    }
}


@end
