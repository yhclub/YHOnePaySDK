//
//  UIImage+YHOnePay.h
//  YHOnePayistrationSDK
//
//  Created by zxl on 2018/4/9.
//  Copyright © 2018年 YH. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (YHOnePay)


FOUNDATION_EXPORT NSString * const YHOnePayBundle;

/**
 获取bundle image

 @param imageName name
 @return image
 */
+(UIImage *)onepay_imageWithName:(NSString *)imageName;


/**
  获取bundle image name

 @param imageName name
 @return str
 */
+(NSString *)onepay_getImageName:(NSString *)imageName;

@end
