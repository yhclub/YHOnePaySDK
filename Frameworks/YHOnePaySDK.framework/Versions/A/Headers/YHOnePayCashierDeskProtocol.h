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
 *  请在viewWillAppear:中调用此方法，可通过[YHOnePaySDK defaultService].waitingCallBack判断是否需要请求
 *  @return 返回是否已处理。NO则将自动发起请求查询结果
 */
-(BOOL)refreshPayResultWhenViewWillAppear;

/**
 *  初始化统一支付订单单号
 *  @param chargeNo 订单单号
 */
-(void)setChargeNo:(NSString *)chargeNo;


@end
