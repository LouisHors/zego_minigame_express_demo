//
//  ZegoCloudGameEngineHandler.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2023/9/19.
//

#import <Foundation/Foundation.h>

@protocol ZegoCloudGameEngineHandler <NSObject>

@optional

/// Cloud Game error
///
/// Available since: 1.3.0 and above.
/// Description: Callback method for SDK connection failure.
/// When to call /Trigger: SDK connection failed.
/// Caution: None.
- (void)onCloudGameError:(int)errorCode message:(NSString *)message;

/// Cloud Game first frame
///
/// Available since: 1.3.0 and above.
/// Description: Cloud rendering first frame callback.
/// When to call /Trigger: The first frame of the cloud rendering appeared.
/// Caution: None.
- (void)onCloudGameFirstFrame;

@end
