//
//  YHOnePaySDK+Extend.h
//  YHOnePaySDK
//
//  Created by Jagtu on 2020/10/26.
//

#import <YHOnePaySDK/YHOnePaySDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface YHOnePaySDK (Extend)

/**
 *  山西人社厅-农行支付
 *  @param traderInfo {"proId":"产品编号","userInput":{"input1":"证件号码","input2":"姓名"}}
 *  @parm appId: 如果为空，则调用默认参数
 *  @parm miniUser: 如果为空，则调用默认参数
 *  @param completionBlock 支付结果回调Block，获得支付结果。
 */
- (void)sxrst_ABCPayOrder:(NSDictionary *)traderInfo callback:(YHOPayCompletionBlock _Nullable)completionBlock;


///  打开农行app
/// @param infoDic 字典内包含3个字段：code、name、idNo、可不传后面2个字段：input3,input4;
+(void)openBankAbcWithTradInfo:(NSDictionary *)infoDic;

@end

NS_ASSUME_NONNULL_END
