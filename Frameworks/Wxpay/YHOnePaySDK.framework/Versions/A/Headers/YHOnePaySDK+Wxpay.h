//
//  YHOnePaySDK+Wxpay.h
//  YHOnePaySDK
//
//  Created by Jagtu on 2019/3/14.
//


#import <YHOnePaySDK/YHOnePaySDK.h>
#import "WXApi.h"

NS_ASSUME_NONNULL_BEGIN

@interface YHOnePaySDK (Wxpay) <WXApiDelegate>

- (void)wxpayWithParam:(NSDictionary *)param;

/** 【微信小程序】
 * @param param 包含appid、miniuser、minipath
 */
- (void)wxMinipayWithParam:(NSDictionary *)param;

/**
 * 【微信小程序-全民付全民移动支付】
 */
- (void)wxMinipayWithUpParam:(NSDictionary *)param;

- (void)wxpayWithUrl:(NSString *)directUrl;

- (BOOL)wxpayProcessWithResult:(NSURL *)resultUrl;

- (BOOL)wxpayProcessWithUniversalLink:(NSUserActivity *)userActivity;

@end

NS_ASSUME_NONNULL_END
