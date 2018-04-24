//
//  PayApi.h
//  YlzPaymentSDK
//
//  Created by dev on 16/8/23.
//  Copyright © 2016年 jagtu. All rights reserved.
//

#import <Foundation/Foundation.h>

/*! @brief 错误码
 *
 */
typedef NS_ENUM(NSInteger,YLZErrCode) {
    YLZErrCodeSuccess           = 0,    /**< 成功    订单支付成功*/
    YLZErrCodeCommon     = -1,   /**< 普通错误类型    其它支付错误*/
    YLZErrCodeUserCancel = -2,   /**< 用户点击取消并返回    用户中途取消*/
    YLZErrCodeSentFail   = -3,   /**< 发送失败    网络连接出错*/
    YLZErrCodeAuthDeny   = -4,   /**< 授权失败    */
    YLZErrCodeUnsupport  = -5,   /**< 不支持    */
    YLZErrCodeParamExpection     = -6,   /**< 参数异常错误    */
    YLZErrCodeInProcess     = -7,   /**< 正在处理中，支付结果未知（有可能已经支付成功），请查询商户订单列表中订单的支付状态    */
    YLZErrCodePayFail   = -8,   /**< 订单支付失败    */
    YLZErrCodeRepeat   = -9,   /**< 重复请求    */
    YLZErrCodeUnKnown   = -10,   /**< 支付结果未知（有可能已经支付成功），请查询商户订单列表中订单的支付状态    */
    YLZErrCodeExpection   = -11,/**< 代码异常，响应数据异常等   */
    YLZErrCodeWebCallReturnUrl   = -12,/** web 回调支付结果页面returnUrl   */
};

/**
 *  @param errorCode 错误码
 *  @param message   提示信息
 *  @param resultDic 其他返回结果
 */
typedef void(^PayCompletionBlock)(YLZErrCode errorCode,NSString * message,NSDictionary * resultDic);




@class YlzCashierDeskViewController;

@interface YHOnePayRouter : NSObject
@property(nonatomic,copy)PayCompletionBlock completionBlock;//回调Block

/**
 *  创建统一支付单例服务
 *
 *  @return 返回单例对象
 */
+ (YHOnePayRouter *)defaultService;

/**
 *  统一支付，将调起SDK内置收银台页面，让用户选择支付渠道
 *
 *  @param chargeNo        订单号（【统一支付服务端】返回的订单号chargeNo）
 *  @param completionBlock 支付结果回调Block，获得支付结果。
 *                         支付成功后，用户服务器也会收到易联众服务器发送的异步通知。 最终支付成功请根据服务端异步通知为准。(特别是微信支付，这里返回成功不代表支付成功，需服务端再次查询确定)
 
 */
-(void)paymentWithChargeNo:(NSString *)chargeNo callback:(PayCompletionBlock)completionBlock;

/**
 *  统一支付
 *
 *  @param orderParam      订单信息（【统一支付服务端】返回的订单信息）
 *  @param completionBlock 支付结果回调Block，获得支付结果。
 *                         支付成功后，用户服务器也会收到易联众服务器发送的异步通知。 最终支付成功请根据服务端异步通知为准。(特别是微信支付，这里返回成功不代表支付成功，需服务端再次查询确定)
 
 */
- (void)paymentWithParam:(id)orderParam callback:(PayCompletionBlock)completionBlock;



/**
 *  查询订单支付信息(获取发起第三方支付的入参信息)
 *
 *  @param chargeNo        订单号（【统一支付服务端】返回的订单号chargeNo）
 *  @param channelId       渠道编码（【统一支付服务端】返回的channelId）
 *  @param completionBlock 查询结果回调Block
 */
-(void)queryPayInfo:(NSString *)chargeNo channelId:(NSString *)channelId callback:(PayCompletionBlock)completionBlock;

/**
 *  查询订单详情
 *
 *  @param chargeNo       订单号
 *  @param completionBlock 回调Block
 */
- (void)queryOrderInfo:(NSString *)chargeNo callback:(PayCompletionBlock)completionBlock;


/**
 *  查询支付结果接口
 *
 *  @param chargeNo       订单号
 *  @param completionBlock 支付结果回调Block
 
 */
- (void)queryPayResult:(NSString *)chargeNo callback:(PayCompletionBlock)completionBlock;


/**
 *  处理第三方app支付完成后跳回商户app携带的支付结果Url
 *
 *  @param resultUrl        支付结果url
 *  @param completionBlock  支付结果回调Block
 *  【由于在跳转第三方支付的过程中，商户app在后台很可能被系统kill了，所以之前调起支付接口设置的callback就会失效，请商户对standbyCallback返回的回调结果进行处理,就是在这个方法里面处理跟callback一样的逻辑】
 *  注：如果商户app并未被系统kill掉，且之前调起支付接口时设置的callback有效，则不会调用completionBlock
 */
- (void)processOrderWithPaymentResult:(NSURL *)resultUrl standbyCallback:(PayCompletionBlock)completionBlock;




//回调(内部使用)
-(void)completionWithCode:(YLZErrCode)errorCode message:(NSString *)message result:(NSDictionary *)resultDic;

@end
