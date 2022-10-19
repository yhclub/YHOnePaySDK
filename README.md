* IOS接入说明
背景：微信支付1.8.6版本之后，微信支付成功之后采用iOS的通用链接(Universal Links) 的方式回调商户APP，这就要求商户APP支持通用链接(Universal Links)
	[Universal Links](https://developer.apple.com/library/archive/documentation/General/Conceptual/AppSearch/UniversalLinks.html "Universal Links")是iOS9推出的一项功能，使你的应用可以通过传统的HTTPS链接来启动APP(如果iOS设备上已经安装了你的app，不管在微信里还是在哪里)， 或者打开网页(iOS设备上没有安装你的app)。

## 快速升级

``
pod 'YHOnePaySDK', '~> 1.5.18'
``
#### 子库说明
YHOnePaySDK包含如下子库，其中默认库AliWx
* Alipay:【Alipay】支持支付宝支付
* Wxpay:【Wxpay】支持微信支付
* AliWx:【Wxpay、Alipay】支持微信、支付宝
* AliWxUnion：【Wxpay、Alipay、Unionpay】支持微信、支付宝、银联
* AliWxUMS：【Wxpay、Alipay、UMSPosPay】支持微信、支付宝、云闪付
* All:【Wxpay,Alipay,UMSPosPay,Unionpay】支持微信、支付宝、银联、云闪付

*版本记录：* 

| 版本号  | 状态 | 更新内容 |
| ------- | ----- | ------------ |
| 1.5.18  | release | 1. 更新支付宝网页支付、微信网页支付、支付宝二维码支付ALI_QR；2. 更改获取IP地址接口；3. 更改最低支持系统iOS9.0；4. 新增支付方式UMSPosPay，包括【微信小程序-全民付移动支付】kChannelUpWxMinPay、【支付宝银联小程序支付】kChannelUpAliMinPay；5. 去掉依赖GTMBase64；6. 支持【微信小程序支付  |
| 1.5.10  | test | 完善微信小程序支付  |
| 1.5.9  | release | 支持微信小程序（银商渠道）支付  |
| 1.5.8  | release | 支持支付宝小程序（银商渠道）支付<br>完善H5支付回调  |
| 1.5.6  | release | 去掉UIWebView  |
| 1.5.5  | release | 更新第三方依赖，支付宝、微信使用官方最新版本<br>修复bug[微信支付调起SDK失败]  |
| 1.5.4  | release | 添加支付宝、微信的单独子库  |
| 1.5.3  | release | 新增子库，AliWxUnion 、AliWx(只包括微信支付宝渠道)  |
| 1.1.0  | release | 重构代码  |
| 1.0.3 | release | baseSDK等不指定版本 |
| 1.0.1 | release | 修改[YHOnePayConfig shareInstance]，增加useCustomResult;//YES则直接回调，由商户自行处理支付结果，NO则SDK将弹窗提示，默认NO |
| 1.0.1 | release | 支持修改导航栏背景颜色与标题颜色、返回按钮图片； |
| 1.0.0 | release | 初始版本，支持微信APP支付、支付宝APP支付 |


#### 直接导入方式：
无

### 修改1：添加 Universal Links

![Turn On Capabilities ](https://showdoc.ylzpay.com/server/../Public/Uploads/2019-10-31/5dba9376351ad.webp "Turn On Capabilities ")

您可能会收到Select a Development Team to Use for Provisioning的提示。选择您所在的Apple开发人员团队，然后按Choose继续。
or Xcode版本11，如下图
![Xcode版本11，如图](https://showdoc.ylzpay.com/server/../Public/Uploads/2019-10-31/5dba948b0cfaf.jpg "Xcode版本11，如图")

接下来，按+并添加以下域：applinks:www.ylzpay.com

请务必添加applinks前缀。您现在应该看到以下内容：

![](https://showdoc.ylzpay.com/server/../Public/Uploads/2019-10-31/5dba94e83b928.png)


### 修改2: 设置 App Transport Security(ATS)

由于需要启动第三方客户端，SDK在构件内调用了 canOpen方法，请在plist文件中，将要使用的URL Schemes列为白名单。
（银联云闪付白名单： uppaysdk、uppaywallet、uppayx1、 uppayx2、uppayx3 ）
（建行支付白名单：mbspay、secretfree ）
（微信支付白名单：weixin、wechat、<font color='red'>weixinULAPI</font>）
（支付宝支付白名单：alipay、<font color='red'>alipays</font>）
（工行支付白名单：com.icbc.iphoneclient、com.icbc.iphoneEChannel、com.icbc.iphone.emall、cn.com.icbc.eMallMobileClient）


### 修改3：Universal Links回调处理

- 在 AppDelegate.m文件中，增加引用代码：
```objective-c
#import <YHOnePaySDK/YHOnePaySDK.h>
```
- 在@implementation AppDelegate中添加如下方法：

```objective-c
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
	[[YHOnePaySDK defaultService] processOrderWithPaymentResult:url standbyCallback:^(YLZErrCode errorCode, NSString *message, NSDictionary *resultDic) {
			LOG(@"errorCode = %ld",(long)errorCode);
			LOG(@"message = %@",message);
			LOG(@"result = %@",resultDic);
		}];
    
}
```

```objective-c
- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url
{
	[[YHOnePaySDK defaultService] processOrderWithPaymentResult:url standbyCallback:^(YLZErrCode errorCode, NSString *message, NSDictionary *resultDic) {
			LOG(@"errorCode = %ld",(long)errorCode);
			LOG(@"message = %@",message);
			LOG(@"result = %@",resultDic);
		}];
    
}
```

```objective-c
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options
{
	[[YHOnePaySDK defaultService] processOrderWithPaymentResult:url standbyCallback:^(YLZErrCode errorCode, NSString *message, NSDictionary *resultDic) {
			LOG(@"errorCode = %ld",(long)errorCode);
			LOG(@"message = %@",message);
			LOG(@"result = %@",resultDic);
		}];
    
}
```

```
-(BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler
{
	//ios 9.0以后
    return [[YHOnePaySDK defaultService] processOrderWithUserActivity:userActivity standbyCallback:^(YLZErrCode errorCode, NSString *message, NSDictionary *resultDic) {
        NSLog(@"errorCode = %ld",(long)errorCode);
        NSLog(@"message = %@",message);
        NSLog(@"result = %@",resultDic);
        
    }];
}

```
