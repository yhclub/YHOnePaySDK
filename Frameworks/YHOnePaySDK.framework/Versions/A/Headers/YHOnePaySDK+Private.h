//
//  PayApi.h
//  YHOnePaySDK
//
//  Created by dev on 16/8/23.
//  Copyright © 2016年 jagtu. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface YHOnePaySDK(Private)

//回调(内部使用)
-(void)completionWithCode:(YLZErrCode)errorCode message:(NSString *)message result:(NSDictionary *)resultDic;

@end
