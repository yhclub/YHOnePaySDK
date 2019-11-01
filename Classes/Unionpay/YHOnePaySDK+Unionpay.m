//
//  YHOnePaySDK+Unionpay.m
//  YHOnePaySDK
//
//  Created by Jagtu on 2019/3/14.
//

#import "YHOnePaySDK+Unionpay.h"
#import "YHOnePayWebVC.h"

@implementation YHOnePaySDK (Unionpay)

- (BOOL)unionpayWithTn:(NSString *)tn
{
    BOOL isPay = NO;
    if (![YHOnePayHelper isNilOrEmpty:tn]) {
        //调用云闪付
        isPay = [[UPPaymentControl defaultControl] startPay:tn
                                                 fromScheme:[YHOnePayConfig shareInstance].appScheme
                                                       mode:[YHOnePayConfig shareInstance].isDebug?@"01":@"00"
                                             viewController:[YHOnePayVCHelper getCurrentVc]];
    }
    return isPay;
}

- (void)unionpayWithForm:(NSString *)payForm directURL:(NSString *)directUrl
{
    if (![YHOnePayHelper isNilOrEmpty:payForm]) {
        
        // 提交表单 data.result.html
        NSString * payOrderForm = [NSString stringWithFormat:@"<script type='text/javascript'>function autoSubmit(){document.getElementById('channel_form').submit();}</script><body onload='autoSubmit();'><form action='%@%@'  id='channel_form' name='channel_form' method='post' target='_self'><input type='hidden' id='form' name='form' value='%@' /></form></body>",[YHOnePayConfig shareInstance].onePayUrl,kPayIframeConfirm,payForm];
        YHOnePayWebVC * web = [[YHOnePayWebVC alloc] initWithHtml:payOrderForm withTitle:@"前往支付.."];
        [YHOnePayVCHelper gotoNextVC:web];
        
    }else if (![YHOnePayHelper isNilOrEmpty:directUrl]){
        /** Web方式：支付链接 **/
        YHOnePayWebVC * web = [[YHOnePayWebVC alloc] initWithUrl:directUrl withTitle:@"前往支付.."];
        [YHOnePayVCHelper gotoNextVC:web];
        
    }else{
        
        [self completionWithCode:YLZErrCodeParamExpection message:@"交易异常，请重新发起" result:@{@"err":@"支付表单或跳转链接丢失"}];
        
    }
}


- (void)unionpayProcessWithResult:(NSURL *)resultUrl
{
    [[UPPaymentControl defaultControl] handlePaymentResult:resultUrl completeBlock:^(NSString *code, NSDictionary *data) {
        
        if ([@"cancel" isEqualToString:code]){
            
            [self completionWithCode:YLZErrCodeUserCancel message:@"交易已取消" result:data];
            
        }else {
            
            if ([YHOnePayConfig shareInstance].useCustomQueryPayResult) {
                
                NSString * message = @"交易结果未知";
                YLZErrCode errCode = YLZErrCodeUnKnown;
                if ([@"fail" isEqualToString:code]){
                    errCode = YLZErrCodePayFail;
                    message = @"交易失败";
                }else if ([@"suceess" isEqualToString:code]) {
                    errCode = YLZErrCodeSuccess;
                    message = @"交易成功";
                }
                
                [self completionWithCode:errCode message:message result:nil];
            }else{
                
                [self refreshPayResult];
            }
        }
    }];
}

@end
