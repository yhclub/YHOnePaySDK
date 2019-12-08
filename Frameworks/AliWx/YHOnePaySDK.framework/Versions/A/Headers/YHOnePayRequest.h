//
//  YHOnePayRequest.h
//  WYGJ
//
//  Created by Jagtu on 17-11-22.
//  Copyright (c) 2017年 YH. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^YHOnePayRequestCallBackBlock)(NSDictionary * resultDic);
typedef void(^YHOnePayRequestNoNetWorkBlock)(NSError * error);

@interface YHOnePayRequest : NSObject<NSURLConnectionDataDelegate>

@property(nonatomic,strong)           NSMutableURLRequest * urlRequest;
@property(nonatomic,strong)           NSMutableData       * resultData;
@property(nonatomic,copy)           YHOnePayRequestCallBackBlock finishCallbackBlock;// 执行完成后回调的block
@property(nonatomic,copy)           YHOnePayRequestCallBackBlock finishErrorBlock;//请求失败后回调的block
@property(nonatomic,copy)           YHOnePayRequestNoNetWorkBlock noNetworkBlock;//当请求无网络时回调的block


+(YHOnePayRequest *)requestWithURL:(NSURL *)url
               params:(NSData *)data
           withMethod:(NSString *)method
  finishCallbackBlock:(YHOnePayRequestCallBackBlock)finish
        failNoNetwork:(YHOnePayRequestNoNetWorkBlock)noNetwork;   //所传参数为字典请求成功与失败以及无网络时

- (void)cancel;

@end
