//
//  YHOnePayDelegate.h
//  YHOnePaySDK
//
//  Created by Jagtu on 2019/3/9.
//

#import <Foundation/Foundation.h>
#import <YHOnePaySDK/YHOnePayConfig.h>

@protocol YHOnePayDelegate <NSObject>

/**
 * 支付结果回调，请处理
 */
-(void)processPaymentResult:(YLZErrCode)errorCode message:(NSString *)message result:(NSDictionary *)resultDic;

@optional

/**
 *  刷新支付结果，并自行调用处理结果
 *  当应用从后台进入活跃状态时（当用户支付完成重新回到APP），会调用此方法。
 *  备注：
 *      如未使用定制接口查询支付结果，可直接调用统一支付平台接口查询：
 *          [[YHOnePaySDK defaultService] refreshPayResult]
 *      您可在收银台界面即将展示时(viewWillAppear:)延迟1秒调用此方法以便获取最新支付结果
 */
-(void)refreshPayResult;

/**
 *  初始化统一支付订单单号
 *  @param chargeNo 订单单号
 */
-(void)setChargeNo:(NSString *)chargeNo;


@end
