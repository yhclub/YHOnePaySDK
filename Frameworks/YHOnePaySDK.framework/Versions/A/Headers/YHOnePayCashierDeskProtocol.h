//
//  YHOnePayCashierDeskProtocol.h
//  YHOnePaySDK
//
//  Created by Jagtu on 2018/9/14.
//

#import <Foundation/Foundation.h>
#import <YHOnePaySDK/YHOnePayConfig.h>

@protocol YHOnePayCashierDeskProtocol <NSObject>

/**
 * 处理支付结果
 * @return 返回是否已处理。YES则不在执行YHOnePaySDK的回调
 */
-(BOOL)processPaymentResult:(YLZErrCode)errorCode message:(NSString *)message result:(NSDictionary *)resultDic;

@optional

/**
 *  刷新支付结果（当收银台重新显示时）
 *  当应用从后台进入活跃状态时，会调用此方法。
 *  请在你的收银台页面viewWillAppear:中异步调用此方法(延迟0.5秒调用)
 */
-(void)refreshPayResultWhenViewWillAppear;

/**
 *  初始化统一支付订单单号
 *  @param chargeNo 订单单号
 */
-(void)setChargeNo:(NSString *)chargeNo;


@end
