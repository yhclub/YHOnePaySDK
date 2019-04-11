//
//  YHOnePayConfig.h
//  YHPaySDK
//  配置
//  Created by 42318168@qq.com on 2018/01/31.
//  Copyright © 2018年 易惠科技. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for YHOnePaySDK.
FOUNDATION_EXPORT double YHOnePaySDKVersionNumber;

//! Project version string for YHOnePaySDK.
FOUNDATION_EXPORT const unsigned char YHOnePaySDKVersionString[];

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
};

/**
 *  @param errorCode 错误码
 *  @param message   提示信息
 *  @param resultDic 其他返回结果
 */
typedef void(^YHOPayCompletionBlock)(YLZErrCode errorCode,NSString * message,NSDictionary * resultDic);



@interface YHOnePayConfig : NSObject

/**
 *  创建单例
 *
 *  @return 返回单例对象
 */
+ (instancetype)shareInstance;

/**
 * 统一支付服务端地址，请务必设置
 */
@property(nonatomic,copy)NSString * onePayUrl;

/** APP支付回调URL Schemes，请务必设置
 *  默认值为[[NSBundle mainBundle] bundleIdentifier]
 *  注：微信支付是将其分配给商户对应appId作为回调URL Schemes，商户APP也应该添加
 *  注：推荐使用微信支付appId作为URL Schemes，特别是使用建行龙支付渠道只能设置为微信支付的appId
 */
@property(nonatomic,copy)NSString * appScheme;

/** --- 其他(可选配置) --- **/
//微信支付渠道的类型 app 或者 wap
@property(nonatomic,copy)NSString * wxChannelType;

//是否调用SecTrustEvaluate来验证SSL证书
@property(nonatomic,assign)BOOL isEvaluateTrust;

//默认NO,设置是否为测试模式
@property(nonatomic,assign)BOOL isDebug;

//YES则直接回调，由商户自行处理支付结果，NO则SDK将弹窗提示，默认NO
@property(nonatomic,assign)BOOL useCustomResult;

//支付结果未知时，请求服务端确认支付结果，默认为NO，YES则由商户自行请求服务端查询支付结果
@property(nonatomic,assign)BOOL useCustomQueryPayResult;

//网络超时时间设置，默认20秒
@property(nonatomic,assign)NSTimeInterval netWorkRequestTimeoutInterval;

@property(nonatomic,copy)NSString * ipAddress;

@end
