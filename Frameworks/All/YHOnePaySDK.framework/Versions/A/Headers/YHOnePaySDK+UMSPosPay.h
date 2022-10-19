//
//  YHOnePaySDK+UMSPosPay.h
//  YHOnePaySDK
//
//  Created by Jagtu on 2019/3/14.
//

#import <YHOnePaySDK/YHOnePaySDK.h>
#import <YHUPPayPluginSDK/UPAPayPlugin.h>
#import <YHUPPayPluginSDK/UPPaymentControl.h>

NS_ASSUME_NONNULL_BEGIN

@interface YHOnePaySDK (UMSPosPay)

/**
 支付宝支付
 @param payData 订单信息:appPayRequest对应的json字符串
 */
- (void)UMSPosPayWithAliPayData:(NSDictionary *)payData;

/**
 支付宝小程序支付
 @param payData 订单信息:appPayRequest对应的json字符串
 */
- (void)UMSPosPayWithAliMinPayData:(NSDictionary *)payData;

/**
 微信支付
 @param payData 订单信息:appPayRequest对应的json字符串
 */
- (void)UMSPosPayWithWxPayData:(NSDictionary *)payData;

/**
 云闪付支付
 @param payData 订单信息:appPayRequest对应的json字符串
 */
- (void)UMSPosPayWithCloudPayData:(NSDictionary *)payData;

/**
 支付回调处理

 @param url App处理的openUrl
 */
- (BOOL)UMSPosPayProcessWithResult:(NSURL *)url;

/*! @brief 处理微信通过Universal Link启动App时传递的数据
*
* 需要在 application:continueUserActivity:restorationHandler:中调用。
* @param userActivity 微信启动第三方应用时系统API传递过来的userActivity
* @return 成功返回YES，失败返回NO。
 */
- (BOOL)UMSPosPayProcessWithUniversalLink:(NSUserActivity *)userActivity;

@end

NS_ASSUME_NONNULL_END
