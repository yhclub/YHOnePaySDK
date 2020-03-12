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

- (void)alipayProcessWithResult:(NSURL *)resultUrl;

- (BOOL)alipayInterceptorWithUrl:(NSString *)directUrl;

@end

NS_ASSUME_NONNULL_END
