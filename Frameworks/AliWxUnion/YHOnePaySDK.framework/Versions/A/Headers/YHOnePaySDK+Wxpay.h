//
//  YHOnePaySDK+Wxpay.h
//  YHOnePaySDK
//
//  Created by Jagtu on 2019/3/14.
//

#import "YHOnePaySDK.h"
#import "WXApi.h"

NS_ASSUME_NONNULL_BEGIN

@interface YHOnePaySDK (Wxpay) <WXApiDelegate>

- (void)wxpayWithParam:(NSDictionary *)param;

- (void)wxpayWithUrl:(NSString *)directUrl;

- (void)wxpayProcessWithResult:(NSURL *)resultUrl;

- (BOOL)wxpayProcessWithUniversalLink:(NSUserActivity *)userActivity;

@end

NS_ASSUME_NONNULL_END
