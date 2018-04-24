//
//  YHOnePayTool.h
//  YHOnePaySDK
//
//  Created by Jagtu on 2018/4/10.
//  Copyright © 2018年 yh. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface YHOnePayTool : NSObject

/**
 由于bundle无法自动识别@2x,@3x图片,我们根据系统scale进行判断
 @param imageName imgName
 @return imageName
 */
+(UIImage *)getBundleImageNamePath:(NSString *)imageName;

+(UINavigationController *)getCurrentNav;
+(UIViewController *)getCurrentVc;

+(void)gotoNextVC:(UIViewController *)vc;

/**
 ** lineView:       需要绘制成虚线的view
 ** startPoint:     虚线开始位置
 ** endPoint:    虚线结束位置
 ** lineColor:      虚线的颜色
 **/
+ (void)drawDashLine:(UIView *)lineView startPoint:(CGPoint)sP endPoint:(CGPoint)eP lineColor:(UIColor *)lineColor;


@end
