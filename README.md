# SQShopcorePay
sdk收银台
[TOC]
### 1. SDK集成
环境要求
iOS11.0以上(iOS10.0功能无法使用)
arm64 & x86_64（模拟器）
1. 通过 CocoaPods 集成：在工程的 Podfile 里面添加以下代码
`pod 'ShopcorePay', '~>1.0.0'`

_注意:pod install如果失败，请先执行 pod search Shopcore,如显示的 Shopcore 版本不是最新的，则执行 pod repo update 操作更新本地 repo 的内容_

2. 手动集成：将 SDK 文件中包含的 Shopcore.framework,Cordova.framework 两个包添加到你所建的工程中  
**Embed 选择 Embed & Sign**

### 2. 注册应用
导入头文件 
`#import <shopcore/shopcore.h>`

注册你的应用:
```
SQShopConfig *shopConfig = [[SQShopConfig alloc] init];
shopConfig.mchID = @"XXXXXXX";
shopConfig.urlScheme = @"xxxxxx";
shopConfig.wxAppId = @"wxAPPIDXXXXXX"; // 选填
shopConfig.universalLink = @"https://www.xxxxxx.com/"; // 选填
[SQShopApi registerShopConfig:shopConfig];
```

处理支付app的回调:
// APPDelegate中：
```
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsey,id> *)options {
     [SQShopApi handleOpenURL:url];
}
```
### 3. 开始支付，sdk提供三个函数方便接入，可根据业务场景接入
1. 收银台页面

```
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
```
2. 监听支付成功/失败通知

`[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onPay:) name:@"__SHOP2CN_SDK_EVT_PAY_RES__" object:nil];`
