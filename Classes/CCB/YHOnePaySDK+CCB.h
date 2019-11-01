//
//  YHOnePaySDK+CCB.h
//  YHOnePaySDK
//
//  Created by Jagtu on 2019/3/14.
//

#import "YHOnePaySDK.h"

NS_ASSUME_NONNULL_BEGIN

@interface YHOnePaySDK (CCB)

//集成建行手机银行APP支付及内嵌H5网页支付方法（首选）
- (void)ccbpayOrder:(NSString *)orderStr;

//指定跳转建行手机银行APP支付方法
- (void)ccbpayAppOrder:(NSString *)orderStr;

//指定弹出内嵌H5支付方法
- (void)ccbpayUrlOrder:(NSString *)orderStr;

//微信支付方法
- (void)ccbpayWechatOrder:(NSString *)orderStr;

//支付宝支付方法
- (void)ccbpayAliOrder:(NSString *)orderStr;

//银联支付方法
- (void)ccbpayUnionOrder:(NSString *)orderStr;

//综合选择支付，弹出界面供商户选择已开通支付方式。
- (void)payViewOrder:(NSString *)orderStr;

//获取建行手机银行APP支付完成后返回信息（需在AppDelegate.m的 openURL代理方法中实现，下面详细描述）
- (void)ccbProcessWithResult:(NSURL *)resultUrl;

@end

NS_ASSUME_NONNULL_END
