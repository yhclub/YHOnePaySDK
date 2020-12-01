//
//  YHOnePayGlobalConfig.h
//  YHRongYiTong
//
//  Created by jagtu on 2018/01/13.
//  Copyright © 2017年 YH. All rights reserved.
//

#ifndef YHOnePayConfig_h
#define YHOnePayConfig_h

#define kGetCashierInfo @"/cashier/info"
#define kPayConfirm @"/cashier/payConfirm"
#define kQueryOrderResult @"/cashier/query"
#define kPayIframeConfirm @"/cashier/payiframe"

#define kUP_WAP_BACK_URL @"/frontCall"

#define kChannelHcPay @"JKT_APP"
#define kChannelAliPay @"ALI_APP"
#define kChannelAliWapPay @"ALI_WAP" //打开 data.result.directUrl
#define kChannelAliMiniPay @"ALI_MIN"
#define kChannelWxPay @"WX_APP"
#define kChannelWxWapPay @"WX_WAP" //打开 data.result.directUrl
#define kChannelWxMiniPay @"WX_MIN"
#define kChannelUpWapPay @"UP_WAP" // 提交表单 data.result.html
#define kChannelUpAppPay @"UP_APP" //
#define kChannelUpWxMinPay @"UP_WX_MIN"
#define kChannelUpAliMinPay @"UP_ALI_MIN"
#define kChannelCCBApp @"CCB_APP" //
#define kChannelICBCWallet @"ICBC_WALLET" //工行钱包
#define kChannelICBCApp @"ICBC_APP" //


#define kDefaultChannelType @"app"

#define kChannelTypeWap @"wap"

#define kWeChatPayUniversalLinkPrefix @"https://www.ylzpay.com/"

//0 成功 1正在 2 失败
#define KChargeStatInit @"1"
#define KChargeStatSuccess @"0"
#define KChargeStatFail @"2"

#define RGBA(R/*红*/, G/*绿*/, B/*蓝*/, A/*透明*/) \
[UIColor colorWithRed:R/255.f green:G/255.f blue:B/255.f alpha:A]


#endif /* YHOnePayConfig_h */
