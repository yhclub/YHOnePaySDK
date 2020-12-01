//
//  YHOnePaySDK+Alipay.h
//  YHOnePaySDK
//
//  Created by Jagtu on 2019/3/14.
//


#import <YHOnePaySDK/YHOnePaySDK.h>
#import <AlipaySDK/AlipaySDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface YHOnePaySDK (Alipay)

- (void)alipayOrder:(NSString *)orderStr;

- (void)alipayWithUrl:(NSString *)directUrl;

/**
 * 【支付宝小程序】
 * @param param 包含miniuser、minipath、query、appScheme
 */
- (void)aliMinipayWithParam:(NSDictionary *)param;

/**
 * 【支付宝小程序-全民付全民移动支付】
 */
- (void)aliMinipayWithUpParam:(NSDictionary *)param;

- (BOOL)alipayProcessWithResult:(NSURL *)resultUrl;

- (BOOL)alipayInterceptorWithUrl:(NSString *)directUrl;

@end

NS_ASSUME_NONNULL_END
