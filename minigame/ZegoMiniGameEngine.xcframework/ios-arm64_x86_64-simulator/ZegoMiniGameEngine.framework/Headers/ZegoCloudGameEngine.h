//
//  ZegoCloudGameEngine.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2023/9/8.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ZegoCloudGameEngineHandler.h"
#import "ZegoGameEngineError.h"
#import "ZegoGameDefines.h"
#import "ZegoStreamProfile.h"

@interface ZegoCloudGameEngine : NSObject

+ (ZegoCloudGameEngine *_Nonnull)sharedEngine;

/// Set the parent container of the cloud game view
///
/// Available since: 1.3.0 and above.
/// Description: Set the parent container of the cloud game view to host the cloud game view.
/// When to call: After calling the [ZegoMiniGameEngine init] method in ZegoMiniGameEngine, before calling [ZegoCloudGameEngine startCloudGame] in ZegoCloudGameEngine.
/// Caution: If no parent container is set, an error will be reported when calling [startCloudGame], error code 7000010.
///
/// @param gameContainer  A container for hosting cloud-games
- (void)setCloudGameContainer:(UIView *_Nonnull)gameContainer;


/// Set the cloud game's event callback
///
/// Available since: 1.3.0 and above.
/// Description: Set the cloud game's event callback.
/// When to call: After calling the [ZegoMiniGameEngine init] method, before calling the [ZegoCloudGameEngine startCloudGame] method.
/// Caution: None
///
/// @param handler Event notification callback. [nil] means not receiving any callback notifications.
- (void)setCloudGameEngineHandler:(nullable id<ZegoCloudGameEngineHandler>)handler;

/// Start cloud gaming
///
/// Available since: 1.3.0 and above.
/// Description: Start cloud gaming.
/// When to call: After calling the [ZegoMiniGameEngine init] method
/// Caution: None
///
/// @param gameID Cloud gaming ID.
/// @param roomID Cloud gaming room ID.
/// @param gameConfig Cloud gaming config.
///         Command line startup, add three parameters: token, width, height, and auto, representing the game activation code, width, height, and automatic login respectively.
///         Note: If there is width and height, the resolution customization will be disabled, and width must appear in pairs with height. Auto can only be effective if the token exists.
///         "token=101312 width=607 height=1000 auto=1" is the running parameter.
///         Each field must have a space between them.
/// @param callBack Method execution result callback.
- (void)startCloudGame:(NSString *_Nonnull)gameID
                roomID:(NSString *_Nonnull)roomID
            gameConfig:(NSDictionary <NSString *, id> *_Nullable)gameConfig
              callBack:(IZegoCommonCallBack _Nullable )callBack;

/// Stop cloud gaming
///
/// Available since: 1.3.0 and above.
/// Description: Stop cloud gaming.
/// When to call: After calling the [ZegoCloudGameEngine startCloudGame] method
/// Caution: None
///
/// @param gameID Cloud gaming ID.
/// @param roomID Cloud gaming room ID.
/// @param callBack Method execution result callback.
- (void)stopCloudGame:(NSString *_Nonnull)gameID
               roomID:(NSString *_Nonnull)roomID
             callBack:(IZegoCommonCallBack _Nullable )callBack;

/// Cloud gaming starts streaming.
///
/// Available since: 1.3.0 and above.
/// Description: The cloud gaming anchor starts streaming on the broadcaster side, and the audience receives room stream update notifications by listening to Zego RTC. If the update type is ZegoUpdateTypeAdd, they will start pulling the live stream.
/// When to call: After calling the [ZegoCloudGameEngine startCloudGame] method
/// Caution: None
///
/// @param gameID Cloud gaming ID.
/// @param roomID Cloud gaming room ID.
/// @param streamID Stream ID, a string of up to 256 characters.
///   Caution:
///   Only support numbers, English characters and '-', '_'.
/// @param callBack Method execution result callback.
- (void)startPublishCloudGameStream:(NSString *_Nonnull)gameID
                             roomID:(NSString *_Nonnull)roomID
                           streamID:(NSString *_Nonnull)streamID
                           callBack:(IZegoCommonCallBack _Nullable)callBack;

/// Cloud gaming stop streaming.
///
/// Available since: 1.3.0 and above.
/// Description: Cloud game streamers stop streaming, while the audience stops pulling the stream by listening to the room stream update notification of Zego RTC, and if the update type is ZegoUpdateTypeDelete, the stream pulling will be stopped.
/// When to call: After calling the [ZegoCloudGameEngine startPublishCloudGameStream] method
/// Caution: None
///
/// @param gameID Cloud gaming ID.
/// @param roomID Cloud gaming room ID.
/// @param streamID Stream ID, a string of up to 256 characters.
///   Caution:
///   Only support numbers, English characters and '-', '_'.
/// @param callBack Method execution result callback.
- (void)stopPublishCloudGameStream:(NSString *_Nonnull)gameID
                            roomID:(NSString *_Nonnull)roomID
                          streamID:(NSString *_Nonnull)streamID
                          callBack:(IZegoCommonCallBack _Nullable)callBack;

/// Set bitstream parameters.
///
/// Available since: 1.3.0 and above.
/// Description: Setting the bit rate parameters. This interface is used to set the recommended bit rate parameters, which may be adjusted by the cloud based on the dynamics of the game.
/// When to call: After calling the [ZegoCloudGameEngine startPublishCloudGameStream] method
/// Caution: None
///
/// @param streamProfile streamProfile.
- (int)setStreamProfile:(ZegoStreamProfile *_Nonnull)streamProfile;

/// Adjusting the volume of cloud gaming.
///
/// Available since: 1.3.0 and above.
/// Description: Adjusting the volume of cloud gaming.
/// When to call: After calling the [ZegoCloudGameEngine startCloudGame] method
/// Caution: None
///
/// @param volume The volume is greater than or equal to 0 and less than or equal to 100.
- (int)setPlayVolume:(int)volume;

/// Get the current volume of cloud gaming.
///
/// Available since: 1.3.0 and above.
/// Description: Get the current volume of cloud gaming.
/// When to call: After calling the [ZegoCloudGameEngine startCloudGame] method
/// Caution: None
///
/// @param callBack  Method execution result callback.
- (void)getPlayVolume:(IZegoCommonCallBack _Nullable)callBack;

/// Send keyboard events.
///
/// Available since: 1.3.0 and above.
/// Description: Send keyboard events, the value of key is the corresponding keyboard code.
/// When to call: After calling the [ZegoCloudGameEngine startCloudGame] method
/// Caution: None
///
/// @param key keyboard code.You can refer to:https://www.toptal.com/developers/keycode
- (void)sendKeyboardEvent:(int)key;

/// Control cloud gaming.
///
/// Available since: 1.3.0 and above.
/// Description: Controlling cloud games includes functions such as switching camera views, moving the camera, rotating the camera, UI events, automatic unit deployment, game modes, etc.
/// When to call: After calling the [ZegoCloudGameEngine startCloudGame] method
/// Caution: None
///
/// @param gameID Cloud gaming ID.
/// @param roomID Cloud gaming room ID.
/// @param opType Control type.
/// @param opValue Control value.
/// @param callBack Method execution result callback.
- (void)controlCloudGame:(NSString *_Nonnull)gameID
                  roomID:(NSString *_Nonnull)roomID
                  opType:(NSString *_Nonnull)opType
                 opValue:(NSString *_Nullable)opValue
                callBack:(IZegoCommonCallBack _Nullable)callBack;

/// Destroy instance objects.
///
/// Available since: 1.3.0 and above.
/// Description:When you don't want to reuse the instance object and need to create a new one, you need to call this method.
/// When to call: After calling the [ZegoCloudGameEngine stopCloudGame] method
/// Caution: Not recommended to call, the revised instance is a singleton.
///
+ (void)destroyInstance;

@end
