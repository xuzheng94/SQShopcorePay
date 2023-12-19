//
//  SQShopApi.h
//  shopcore
//
//  Created by Sunny on .
//

#import <UIKit/UIKit.h>
#import <shopcore/shopcore.h>

NS_ASSUME_NONNULL_BEGIN

@interface SQShopApi : NSObject

/**
 @brief 注册
 @param config 店铺配置
 */
+ (void)registerShopConfig:(SQShopConfig *)config;

/**
 @brief 处理外部链接回跳，微信支付等
 @param url 外部链接
 */
+ (BOOL)handleOpenURL:(NSURL *)url;

+ (BOOL)continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler;

/**
 @brief 创建一个收银台页面
 @param outerMainOrderNo 主单号
 @param outerUserId 用户id
 @return 收银台
 */
+ (SPViewController *)createPagePayOrderWithOuterMainOrderNo:(NSString *)outerMainOrderNo
                                                 outerUserId:(NSString *)outerUserId;

/**
 @brief 用当前导航push一个收银台页面
 @param outerMainOrderNo 主单号
 @param outerUserId 用户id
 */
+ (void)pushPayOrderWithViewController:(UIViewController *)viewController
                      outerMainOrderNo:(NSString *)outerMainOrderNo
                           outerUserId:(NSString *)outerUserId;

/**
 @brief present方式展示一个收银台页面
 @param outerMainOrderNo 主单号
 @param outerUserId 用户id
 */
+ (void)presentPayOrderWithViewController:(UIViewController *)viewController
                         outerMainOrderNo:(NSString *)outerMainOrderNo
                              outerUserId:(NSString *)outerUserId;

@end

NS_ASSUME_NONNULL_END
