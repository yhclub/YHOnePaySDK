//
//  YHWebView.h
//  YHOnePaySDK
//
//  Created by zxl on 2017/8/22.
//  Copyright © 2017年 YLZYH. All rights reserved.
//

#import <UIKit/UIKit.h>

@class WKWebView;

typedef void(^YHWebviewLoadingProgress)(double progress);

typedef void(^YHWebviewSetTitle)(NSString *title);

typedef void(^YHWebviewCanGoBackWithTag)(BOOL cangoback,NSInteger tag);

typedef void(^YHWebviewCanGoBack)(BOOL cangoback);

typedef void(^YHWebviewDidFinishNavigation)(void);

typedef void(^YHWebviewLoadingAnimation)(BOOL isLoading);

typedef void(^YHWebviewNetError)(NSError * error);

typedef BOOL(^YHWebviewStartLoad)(NSURLRequest * request);


/**
 * YHWebView
 */

@interface YHOnePayWebView : UIView

@property (nonatomic, strong)WKWebView *webView;

@property (nonatomic, strong)UIProgressView *progressView;

@property (nonatomic, copy)NSString *url;

@property (nonatomic, copy)NSString *htmlStr;//html字符串

@property (nonatomic, assign)BOOL firstLoad;//第1次加载

@property (nonatomic, assign)NSInteger *count;//当前加载层数

@property(nonatomic,copy)YHWebviewNetError failwithError;

@property(nonatomic,copy)YHWebviewLoadingAnimation loadingAnimationBlock;

@property(nonatomic,copy)YHWebviewLoadingProgress startProgressBlock;

@property(nonatomic,copy)YHWebviewLoadingProgress progressBlock;

@property(nonatomic,copy)YHWebviewLoadingProgress endProgressBlock;

@property(nonatomic,copy)YHWebviewStartLoad willStartLoadBlock;

@property(nonatomic,copy)YHWebviewDidFinishNavigation didFinishNavigationBlock;

@property(nonatomic,copy)YHWebviewSetTitle setTitleBlock;

@property(nonatomic,copy)YHWebviewCanGoBack canGoBackBlock;


-(id)initWithFrame:(CGRect)frame withUrl:(NSString *)url;

-(id)initWithFrame:(CGRect)frame withHtml:(NSString *)html;

-(void)webviewReloadData;

-(void)goBack;
-(void)goForword;

-(BOOL)canGoback;
-(BOOL)canGoForword;

-(void)refresh;


@end
