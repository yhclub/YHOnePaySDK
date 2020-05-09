//
//  YHOnePayTheme.h
//  Pods-YHOnePaySDK_Example
//
//  Created by Jagtu on 2018/8/13.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <YHBaseSDK/YHNavView.h>

@interface YHOnePayTheme : NSObject

//主色、主灰色
@property(nonatomic,copy)UIColor *th_colorMain;
@property(nonatomic,copy)UIColor *th_colorMainGray;

//辅色
@property(nonatomic,copy)UIColor *th_colorSecondary1;
@property(nonatomic,copy)UIColor *th_colorSecondary2;
@property(nonatomic,copy)UIColor *th_colorSecondary3;

//辅灰色
@property(nonatomic,copy)UIColor *th_colorSecondaryGray1;
@property(nonatomic,copy)UIColor *th_colorSecondaryGray2;
@property(nonatomic,copy)UIColor *th_colorSecondaryGray3;

//灰色
@property(nonatomic,copy)UIColor *th_colorBlack;
@property(nonatomic,copy)UIColor *th_colorDarkGray;
@property(nonatomic,copy)UIColor *th_colorGray;
@property(nonatomic,copy)UIColor *th_colorLightGray;
@property(nonatomic,copy)UIColor *th_colorWhiteGray;
@property(nonatomic,copy)UIColor *th_colorWhite;

//文字灰色
@property(nonatomic,copy)UIColor *th_colorTextBlack;
@property(nonatomic,copy)UIColor *th_colorTextDarkGray;
@property(nonatomic,copy)UIColor *th_colorTextGray;
@property(nonatomic,copy)UIColor *th_colorTextLightGray;
@property(nonatomic,copy)UIColor *th_colorTextWhite;   //配对colorMain底色

//背景色
@property(nonatomic,copy)UIColor *th_colorBg;    //#f5f5f5
@property(nonatomic,copy)UIColor *th_colorBgWhite;//#ffffff


/**
 nav样式
 */
@property(nonatomic,assign)YHNavStyle th_navStyle;


/**
 *  创建单例
 *
 *  @return 返回单例对象
 */
+ (instancetype)shareConfig;


@end
