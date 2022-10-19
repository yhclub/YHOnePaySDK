## YHOnePaySDK
### 统一支付
##### 子库
* Alipay:【Alipay】
* Wxpay:【Wxpay】
* AliWx:【Wxpay、AliWx】
* AliWxUnion：【Wxpay、AliWx、Unionpay】
* AliWxUMS：【Wxpay、AliWx、UMSPosPay】
* All:【Wxpay,Alipay,UMSPosPay,Unionpay】


版本记录
### SDK1.5.18
1. 更新支付宝网页支付、微信网页支付、支付宝二维码支付ALI_QR
2. 更改获取IP地址接口
3. 更改最低支持系统iOS9.0
4. 新增支付方式UMSPosPay，包括【微信小程序-全民付移动支付】kChannelUpWxMinPay、【支付宝银联小程序支付】kChannelUpAliMinPay
5. 去掉依赖GTMBase64
6. 支持【微信小程序支付】
- *7. 引入加解密【YHEnDecriptionSDK/EncryptAES】（已还原）
- *8. 支持工行e支付【ICBCPay】、建行龙支付【CCB】
- *9. 新增CCBGovPay(sxrsj)


### SDK1.5.10
1. 完善微信小程序（银商渠道）、支付宝小程序（银商渠道）

### SDK1.5.9
1. 支持微信小程序（银商渠道）支付


### SDK1.5.8
1. 支持支付宝小程序（银商渠道）支付
2. 完善H5支付回调

### SDK1.5.6
1. 去掉UIWebView

### SDK1.1.0
1. 重构代码

### SDK1.0.3（弃用）
1. baseSDK等不指定版本

### SDK1.0.1
1. 修改[YHOnePayConfig shareInstance]，增加useCustomResult;//YES则直接回调，由商户自行处理支付结果，NO则SDK将弹窗提示，默认NO

### SDK1.0.1
1. 修复无法返回bug；
2. 修复支付完成崩溃bug；
3. 可修改导航栏背景颜色与标题颜色、返回按钮图片。
