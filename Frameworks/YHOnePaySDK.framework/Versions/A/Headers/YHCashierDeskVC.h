//
//  YlzCashierDeskDelegate
//  YHOnePaySDK
//  支付收银台界面
//  Created by jagtu@sina.com on 16/8/23.
//  Copyright © 2016年 ylzinfo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YHOnePayDelegate.h"

/**
 * 显示收银台
 * 支持 push与present两种方式推出
 * [navigationController pushViewController:instance animated:animated];
 * [controller presentViewController:instance animated:animated completion:nil];
 */


@interface YHCashierDeskVC : YHBaseVC <YHOnePayDelegate>

@property(nonatomic,strong)NSString *chargeNo;

/**
 * 回调Block
 */
@property(nonatomic,copy,nullable)YHOPayCompletionBlock completionBlock;

-(instancetype)initWithChargeNo:(NSString *)chargeNo completionBlock:(YHOPayCompletionBlock)completionBlock;


@end
