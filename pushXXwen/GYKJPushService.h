//
//  GYKJPushService.h
//  GYKJDemo
//
//  Created by chenxuefang on 2019/8/20.
//  Copyright © 2019 chenxuefang. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger,EncryptionType) {
    EncryptionTypeNone = 0,
    EncryptionTypeDo,
};

@interface GYKJPushService : NSObject

@property (nonatomic,strong) NSString *hostStr;
@property (nonatomic,strong) NSString *deviceTokenStr;
@property (nonatomic,strong) NSString *requestMethod;
@property (nonatomic,assign) EncryptionType type;

+ (instancetype)defaultPushService;

//授权和注册
- (BOOL)PushApplication:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

//向服务器发送DeviceToken
- (void)sendDeviceTokenToService:(NSString *)urlStr;

//注册成功得到deviceToken
- (void)PushApplication:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
//注册失败报错
- (void)PushApplication:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

//这个是为了在HomeScreen点击App图标进程序
- (void)BecomeActive:(UIApplication *)application;

//这是处理发送过来的推送
- (void)PushApplication:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo;
- (void)PushApplication:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:( void (^ _Nullable)(UIBackgroundFetchResult))completionHandler;

@end

NS_ASSUME_NONNULL_END
