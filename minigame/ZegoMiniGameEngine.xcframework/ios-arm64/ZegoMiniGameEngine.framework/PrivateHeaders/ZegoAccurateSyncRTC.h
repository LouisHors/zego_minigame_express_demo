//
//  ZegoAccurateSyncRTC.h
//  ZegoAccurateSync
//
//  Created by liquan on .
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZegoAccurateSyncLogLevel) {
    ZegoAccurateSyncLogLevelGrievous = 0,
    ZegoAccurateSyncLogLevelError = 1,
    ZegoAccurateSyncLogLevelWarning = 2,
    ZegoAccurateSyncLogLevelGeneric = 3,
    ZegoAccurateSyncLogLevelDebug = 4,
};

typedef NS_ENUM(NSUInteger, ZegoAccurateSyncLogModule) {
    ZegoAccurateSyncLogModuleManager = 0,
    ZegoAccurateSyncLogModuleView = 1,
    ZegoAccurateSyncLogModuleData = 2,
};

typedef void(^zegoRTCHttpBlock)(int seq, int errorCode,NSString *message,NSString *response);

@protocol ZegoAccurateSyncRTCDelegate <NSObject>

- (void)roomState:(int)roomState errorCode:(int)errorCode roomID:(NSString *)roomID;

@end

@interface ZegoAccurateSyncRTC : NSObject

+ (instancetype)sharedInstance;

//统一接入相关
- (void)setDelegate:(id<ZegoAccurateSyncRTCDelegate>)delegate;

- (void)httpRequestMethod:(int)requestMethod url:(NSString *)url api:(NSString *)api agentService:(NSString *)agentService requestData:(NSString *)requestData requestHeader:(NSString *)requestHeader completionBlock:(zegoRTCHttpBlock)completionBlock;

//日志相关
+ (void)initCustomLogger:(NSString *)headInfo;

+ (void)logWithLevel:(ZegoAccurateSyncLogLevel)level logModule:(ZegoAccurateSyncLogModule)module functionName:(NSString *)functionName tag:(nullable id)tag info:(nullable id)info;


@end

NS_ASSUME_NONNULL_END
