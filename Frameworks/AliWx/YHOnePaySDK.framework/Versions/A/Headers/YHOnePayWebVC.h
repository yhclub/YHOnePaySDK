//
//  YHOnePayWebVC.h
//  YHOnePaySDK
//
//  Created by YLZ-MAC on 15/1/21.
//  Copyright (c) 2015年 YLZ-MAC. All rights reserved.
//

#import <UIKit/UIKit.h>

@class YHOnePayWebView;

@interface YHOnePayWebVC : YHBaseVC<UIWebViewDelegate>

@property (nonatomic, strong)YHOnePayWebView *webView;

-(id)initWithUrl:(NSString *)url withTitle:(NSString *)title;

-(id)initWithHtml:(NSString *)html withTitle:(NSString *)title;

@end



