//
//  YHOnePayHelper.h
//  YHOnePaySDK
//
//  Created by Jagtu on 2018/7/31.
//  Copyright © 2018年 yh. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YHOnePayHelper : NSObject


+(BOOL)isNilOrEmpty:(id)obj;

//获取UUID（UUID+keyChain）
+(NSString *)getUUID;


+(NSString *)getAppUserAgent;


/**
 获取Referer信息
 */
+(NSString *)getWxH5PayReferer;

/**
 * 打开外部链接
 */
+(void)openURL:(NSURL *)url completionHandler:(void (^ __nullable)(BOOL success))completion;


/**
 更新IP地址等信息
 */
+(void)requestIpInfoCompletionBlock:(void(^)(NSString *ipAddress))completionBlock;

@end

NS_ASSUME_NONNULL_END
