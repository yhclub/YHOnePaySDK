//
//  YHOnePaySDK+Unionpay.h
//  YHOnePaySDK
//
//  Created by Jagtu on 2019/3/14.
//

#import <YHOnePaySDK/YHOnePaySDK.h>
#import <YHUPPayPluginSDK/UPAPayPlugin.h>
#import <YHUPPayPluginSDK/UPPaymentControl.h>

NS_ASSUME_NONNULL_BEGIN

@interface YHOnePaySDK (Unionpay)

- (BOOL)unionpayWithTn:(NSString *)tn;

- (void)unionpayWithForm:(NSString *)payForm directURL:(NSString *)directUrl;

- (void)unionpayProcessWithResult:(NSURL *)resultUrl;

@end

NS_ASSUME_NONNULL_END
