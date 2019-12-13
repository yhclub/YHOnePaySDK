//
//  YHOnePayHelper.h
//  YHOnePaySDK
//
//  Created by Jagtu on 2018/7/31.
//  Copyright © 2018年 yh. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YHOnePayHelper : NSObject


+(BOOL)isNilOrEmpty:(id)obj;

/**
 更新IP地址等信息
 */
+(void)requestIpInfoCompletionBlock:(void(^)(NSString *ipAddress))completionBlock;

/**
 获取Referer信息
 */
+(NSString *)getWxH5PayReferer;

//获取UUID（UUID+keyChain）
+(NSString *)getUUID;


+(NSString *)getAppUserAgent;


@end
