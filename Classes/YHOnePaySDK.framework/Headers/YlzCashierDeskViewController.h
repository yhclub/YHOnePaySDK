//
//  YlzCashierDeskDelegate
//  YlzPaymentSDK
//  支付收银台界面
//  Created by jagtu@sina.com on 16/8/23.
//  Copyright © 2016年 ylzinfo. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <YHBaseSDK/YHBaseSDK.h>

#import "YHOnePayRouter.h"

/**
 * 显示收银台
 * 支持 push与present两种方式推出
 * [navigationController pushViewController:instance animated:animated];
 * [controller presentViewController:instance animated:animated completion:nil];
 */


@interface YlzCashierDeskViewController : YHBaseVC


/**
 *  初始化支付收银台界面
 *  @param chargeNo       订单单号
 */
-(instancetype)initWithChargeNo:(NSString *)_chargeNo;

-(void)resfreshViewWithCode:(YLZErrCode)errorCode message:(NSString *)message result:(NSDictionary *)resultDic;

@end
