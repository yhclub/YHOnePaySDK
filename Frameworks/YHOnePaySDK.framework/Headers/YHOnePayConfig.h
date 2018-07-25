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
@property(nonatomic,strong)NSString * appScheme;//设置回调URL Schemes 默认值为[[NSBundle mainBundle] bundleIdentifier]。需要在商户APP设置有相应的URL Schemes 否则支付宝支付完成无法回调回APP

@property(nonatomic,assign)BOOL isEvaluateTrust;//是否调用SecTrustEvaluate来验证SSL证书
@property(nonatomic,assign)BOOL showLog;        //默认YES
@property(nonatomic,assign)BOOL useCustomResult;//YES则直接回调，由商户自行处理支付结果，NO则SDK将弹窗提示，默认NO

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
