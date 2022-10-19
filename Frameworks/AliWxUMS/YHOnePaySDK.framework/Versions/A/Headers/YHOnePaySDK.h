//
//  YHOnePaySDK.h
//  YHOnePaySDK
//
//  V1.0.0    Update  2018/4/27.
//  V2.0.8    Update  2018/8/12
//  V2.1.9    Update  2018/9/5
//  V1.2.3.1  Update  2018/11/12
//  V1.2.9.3  Update  2018/11/20
//  V1.5.9    Update  2020/9/27
//  V1.5.10   Update  2020/12/4
//  V1.5.10   Update  2020/12/4
//
//  Copyright © 2018年～2021年 yh. All rights reserved.
//
// In this header, you should import all the public headers of your framework using statements like
// #import <YHOnePaySDK/YHOnePaySDK.h>


#import <UIKit/UIKit.h>

//依赖组件
#import <YHBaseSDK/YHBaseSDK.h>
#import <YHCategorySDK/YHCategorySDK.h>
#import <YHUtiliitiesSDK/YHUtiliitiesSDK.h>
#import <YHAlertSDK/YHAlertSDK.h>

//config
#import <YHOnePaySDK/YHOnePayConfig.h>
#import <YHOnePaySDK/YHOnePayTheme.h>
#import <YHOnePaySDK/YHOnePayDelegate.h>
#import <YHOnePaySDK/YHOnePayGlobalConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface YHOnePaySDK : NSObject

/**
 * 代理回调
 */
@property(nonatomic,weak,nullable) id<YHOnePayDelegate> delegate;

/**
 * 统一支付订单号
 */
@property(nonatomic,strong,nullable)NSString *chargeNo;

/**
 * 统一支付结果回调Block
 */
@property(nonatomic,copy,nullable)YHOPayCompletionBlock completionBlock;

/**
 * 支付等待，YES为支付中，需要去查询支付结果；
 */
@property(nonatomic,assign)BOOL waitingCallBack;


/**
 *  创建统一支付单例服务
 *
 *  @return 返回单例对象
 */
+ (YHOnePaySDK *)defaultService;

/**
 *  统一支付，将调起SDK内置收银台页面，让用户选择支付渠道
 *
 *  @param chargeNo        订单号（【统一支付服务端】返回的订单号chargeNo）
 *  @param completionBlock 支付结果回调Block，获得支付结果。
 *                         支付成功后，用户服务器也会收到易联众服务器发送的异步通知。 最终支付成功请根据服务端异步通知为准。(特别是微信支付，这里返回成功不代表支付成功，需服务端再次查询确定)
 
 */
-(void)paymentWithChargeNo:(NSString *)chargeNo
                  callback:(YHOPayCompletionBlock _Nullable)completionBlock;

/**
 *  统一支付
 *
 *  @param orderParam      订单信息（【统一支付服务端】返回的订单信息）
 *  @param completionBlock 支付结果回调Block，获得支付结果。
 *                         支付成功后，用户服务器也会收到易联众服务器发送的异步通知。 最终支付成功请根据服务端异步通知为准。(特别是微信支付，这里返回成功不代表支付成功，需服务端再次查询确定)
 
 */
- (void)paymentWithParam:(id)orderParam
                callback:(YHOPayCompletionBlock)completionBlock;

- (void)paymentWithParam:(id)orderParam
                delegate:(id<YHOnePayDelegate>)delegate;


/**
 *  查询订单支付信息(获取发起第三方支付的入参信息)
 *
 *  @param chargeNo        订单号（【统一支付服务端】返回的订单号chargeNo）
 *  @param channelId       渠道编码（【统一支付服务端】返回的channelId）
 *  @param completionBlock 查询结果回调Block
 */
-(void)queryPayInfo:(NSString *)chargeNo
          channelId:(NSString *)channelId
           callback:(YHOPayCompletionBlock _Nullable)completionBlock;

/**
 *  查询订单详情
 *
 *  @param chargeNo       订单号
 *  @param completionBlock 回调Block
 */
- (void)queryOrderInfo:(NSString *)chargeNo
              callback:(YHOPayCompletionBlock _Nullable)completionBlock;


/**
 *  查询支付结果接口
 *
 *  @param chargeNo       订单号
 *  @param completionBlock 支付结果回调Block
 
 */
- (void)queryPayResult:(NSString *)chargeNo
              callback:(YHOPayCompletionBlock _Nullable)completionBlock;


/**
 *  处理第三方app支付完成后跳回商户app携带的支付结果Url
 *
 *  @param resultUrl        支付结果url
 *  @param completionBlock  支付结果回调Block
 *  【由于在跳转第三方支付的过程中，商户app在后台很可能被系统kill了，所以之前调起支付接口设置的callback就会失效，请商户对standbyCallback返回的回调结果进行处理,就是在这个方法里面处理跟callback一样的逻辑】
 *  注：如果商户app并未被系统kill掉，且之前调起支付接口时设置的callback有效，则不会调用completionBlock
 */
- (void)processOrderWithPaymentResult:(NSURL *)resultUrl
                      standbyCallback:(YHOPayCompletionBlock _Nullable)completionBlock;


- (BOOL)processOrderWithUserActivity:(NSUserActivity *)userActivity
                     standbyCallback:(YHOPayCompletionBlock _Nullable)completionBlock;


/**
 * 刷新支付结果
 */
-(void)refreshPayResult;


/**
 * 设置支付结果(请勿随意调用)
 */
-(void)completionWithCode:(YLZErrCode)errorCode message:(NSString *)message result:(NSDictionary * _Nullable)resultDic;

#ifdef DEBUG

-(void)testAction;

#endif

@end

NS_ASSUME_NONNULL_END
