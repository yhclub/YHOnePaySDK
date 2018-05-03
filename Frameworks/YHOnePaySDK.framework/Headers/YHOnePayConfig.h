//
//  YHOnePayConfig.h
//  YHPaySDK
//  配置
//  Created by 42318168@qq.com on 2018/01/31.
//  Copyright © 2018年 易惠科技. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface YHOnePayConfig : NSObject

@property(nonatomic,strong)NSString * onePayUrl;//统一支付服务端地址
@property(nonatomic,strong)NSString * appScheme;

@property(nonatomic,assign)BOOL isEvaluateTrust;//是否调用SecTrustEvaluate来验证SSL证书
@property(nonatomic,assign)BOOL showLog;

@property(nonatomic,assign)BOOL useMyResult;//YES则在支付成功有弹框提醒，NO则没有，默认YES
@property(nonatomic,assign)BOOL ensureCorrectSuccess;//YES则确保如果返回支付成功可信(即SDK将再次向服务端确认支付结果)【前提是调起统一收银台页面】 默认值为YES
@property(nonatomic,assign)NSTimeInterval netWorkRequestTimeoutInterval;//网络超时时间设置，默认20秒

//内容底色
@property(nonatomic,strong)UIColor * viewBgColor;
@property(nonatomic,strong)UIColor * contentBgColor;

@property(nonatomic,strong)UIColor  * navigationBarTitleColor;
@property(nonatomic,strong)UIColor  * navigationBarBgColor;
@property(nonatomic,strong)UIImage  * navigationBackBarImage;

@property(nonatomic,strong)UIColor * buttonTitleColor;
@property(nonatomic,strong)UIColor * buttonBgColor;
@property(nonatomic,strong)UIColor * buttonLightTitleColor;
@property(nonatomic,strong)UIColor * buttonLightBgColor;

//标题1 颜色
@property(nonatomic,strong)UIColor * blackTextColor;
//标题2 颜色
@property(nonatomic,strong)UIColor * darkGreyTextColor;
//标题 颜色
@property(nonatomic,strong)UIColor * greyTitleColor;
//正文 颜色
@property(nonatomic,strong)UIColor * greyTextColor;
//提示 颜色
@property(nonatomic,strong)UIColor * lightGreyTextColor;

//突出标题颜色，用户重要级文字信息
@property(nonatomic,strong)UIColor * stressTextColor;
@property(nonatomic,strong)UIColor * blueTextColor;

//突出颜色，用于特别需要强调和突出的文字
@property(nonatomic,strong)UIColor * stressColor;

@property(nonatomic,strong)UIColor * lineColor;//线条灰色
@property(nonatomic,strong)UIColor * borderColor;//各种边框正常颜色

@property(nonatomic,strong)UIColor * loadTextColor;//加载框文字颜色
@property(nonatomic,strong)UIColor * loadBgColor;//加载框背景色
@property(nonatomic,strong)UIColor * loadCoverBgColor;//加载框遮挡背景色


/**
 *  创建单例
 *
 *  @return 返回单例对象
 */
+ (instancetype)shareInstance;

@end
