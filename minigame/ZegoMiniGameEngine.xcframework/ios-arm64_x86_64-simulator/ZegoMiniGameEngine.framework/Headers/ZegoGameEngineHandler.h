//
//  IZegoGameEngineHandler.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2023/1/6.
//

#import <Foundation/Foundation.h>
#import "ZegoGameRobotConfig.h"
#import "ZegoGameActionCallback.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZegoGameState) {
    ZegoGameIdle,       // The game is not started, idle state.
    ZegoGamePreparing,  // Game preparation
    ZegoGamePlaying,    // Game in progress.
    ZegoGameStopping,   // Game paused.
    ZegoGameOver,       // game over.
};

typedef NS_ENUM(NSInteger, ZegoGameLoadState) {
    ZegoGameLoading, // After downloading game resources, start loading the game.
    ZegoGameLoaded,  // When the game is loaded and user interaction can begin.
};

typedef NS_ENUM(NSInteger, ZegoGamePlayerState) {
    ZegoGamePlayerStartPlay, // Players start participating in the game.
    ZegoGamePlayerStopPlay   // The player stops participating in the game.
};


@protocol ZegoGameEngineHandler <NSObject>

@optional

/// 30 seconds notification before the token is about to expire.
///
/// Available since: 1.0.0 and above.
/// Description: When receiving this callback, the developer should call the [updateToken] function to update the Token in time.
/// When to call /Trigger: When there are only 30 seconds left for the authentication token, the SDK will call back this function to notify the developer to update the authentication token.
/// Caution: None.
- (void)onTokenWillExpire;

/// Notifies of updates to the game's loading state.
///
/// Available since: 1.0.0 and above.
/// Description: After the game is loaded, the game's loading state changes are returned through this interface.
/// When to call /Trigger: After calling the [loadGame] interface to load the game, it will be notified when the loading status of the game changes.
/// Caution: None.
///
/// @param gameLoadState game loading status
- (void)onGameLoadStateUpdate:(ZegoGameLoadState)gameLoadState;

/// Game state change notification interface.
///
/// Available since: 1.0.0 and above.
/// Description:After the game is loaded, the state changes of the game are returned through this interface.
/// When to call /Trigger: After calling the [loadGame] interface to load the game, it will be notified when the state of the game changes.
/// Caution: None.
///
/// @deprecated It will be deprecated in version 1.4.0 and above. Please use the [onGameStateUpdate:reasonCode:] function instead.

/// @param gameState The state enumeration of the game.
- (void)onGameStateUpdate:(ZegoGameState)gameState DEPRECATED_ATTRIBUTE;

/// Game state change notification interface.
///
/// Available since: 1.3.0 and above.
/// Description:After the game is loaded, the state changes of the game are returned through this interface.
/// When to call /Trigger: After calling the [loadGame] interface to load the game, it will be notified when the state of the game changes.
/// Caution: None.
///
/// @param gameState The state enumeration of the game.
/// @param reasonCode Reason for game state change.
///                                       - 0: Normal process
///                                       - 1: Players are missing
///                                       - 2: Insufficient chips
///                                       - 3: Match timeout
///                                       - 9999: Unknown exception
- (void)onGameStateUpdate:(ZegoGameState)gameState reasonCode:(int)reasonCode;

/// Current player status notifications
///
/// Available since: 1.0.0 and above.
/// Description: Current player status notifications (in-game/not-in-game)
/// When to call /Trigger: After calling loadGame, the player starts the game, or stops the game
/// Caution: None.
///
/// @param playerState The state of the player.
- (void)onPlayerStateUpdate:(ZegoGamePlayerState)playerState;

/// Unload game notification
///
/// Available since: 1.0.0 and above.
/// Description: Notification when game unloading is complete.
/// When to call /Trigger: When the game room is closed or [unloadGame] is called to unload the game, this callback will be notified when the game unloading is complete.
/// Caution: None.
///
/// @param gameID The game ID.
- (void)onUnloaded:(NSString *)gameID;

/// Notification of recharge required
///
/// Available since: 1.0.0 and above.
/// Description: Inform the player to recharge the game gold coins.
/// When to call /Trigger: After calling [loadGame] to load, during the game, if the current game gold coins are not enough to continue the game, it will be notified.
/// Caution: None.
///
/// @param gameID The game ID.
- (void)onChargeRequire:(NSString *)gameID;

/// Notification interface for custom playing of game sounds.
///
/// Available since: 1.0.0 and above.
/// Description: The name of the notification sound, whether to play it, url, whether to play it in a loop, and the volume.
/// When to call /Trigger: After calling [loadGame] to load the game and specify the game sound as custom playback, it will be called back whenever there is a game sound that needs to be played/stopped.
/// Caution: None.
///
/// @param name The name of the game sound, which can be used as an ID to uniquely identify the game sound.
/// @param isPlay  true to play, false to stop playback.
/// @param url The url of the game audio file.
/// @param isLoop true for loop playback, false for single playback.
/// @param volume Playback volume, range is [0, 100].
- (void)onGameSoundPlay:(NSString *)name isPlay:(BOOL)isPlay url:(NSString *)url isLoop:(BOOL)isLoop volume:(int)volume;

/// Customize the notification interface for the volume change of the playback sound.
///
/// Available since: 1.0.0 and above.
/// Description: Notifies a volume change of a custom playback sound.
/// When to call /Trigger: After calling [loadGame] to load the game and specify the game sound as custom playback, it will be called back whenever the volume of the game sound needs to be modified.
/// Caution: None.
///
/// @param name The name of the game sound, which can be used as an ID to uniquely identify the game sound.
/// @param volume  The volume of the music, the range is [0, 100].
- (void)onGameSoundVolumeChange:(NSString *)name volume:(int)volume;

/// Notification interface when an error occurs in the game.
///
/// Available since: 1.0.0 and above.
/// Description: Notify in-game error messages.
/// When to call /Trigger: In the game, when the game goes wrong. modified.
/// Caution: None.
///
/// @param errorCode Game error codes, for specific error codes, refer to the error code document (https://doc-zh.zego.im/article/17799).
/// @param errorMessage  Game error message.
- (void)onGameError:(int)errorCode errorMessage:(NSString *)errorMessage;

/// In-game View or button click event notification interface.
///
/// Available since: 1.0.0 and above.
/// Description: Notify the click event of View or button in the game.
/// When to call /Trigger: In the game, fired when the user clicks some View or button in the game.
/// Caution: None.
///
/// @param actionID ID of the View or Button:
///                                 - 1000: Ready (ready button)
///                                 - 1001: CancelReady (Cancel Ready button)
///                                 - 1002: Join (join button)
///                                 - 1003: Start (start button)
///                                 - 1004: Stop (stop button)
///                                 - 1005: End (end button)
///                                 - 1006: SettleClose (the settlement interface close button)
///                                 - 1007: SettleAgain (Settle Again button on the settlement interface)
///                                 - 1008: Recharge (recharge reminder button)
///                                 - 1009: BlankArea (the game field randomly matches the half-screen mode blank area)
///                                 - 2000: AvatarClicked (click player avatar)
///                                 - 8008: Share (share button)
/// @param data  The data attached to View or button click can be in various formats. This needs to be defined by the game, and it is generally empty.
- (void)onActionEventUpdate:(int)actionID data:(NSString *)data;

/// The notification interface of the settlement result of each game.
///
/// Available since: 1.0.0 and above.
/// Description: Notify the settlement result of each game.
/// When to call /Trigger: After participating in the game, when each round of the game ends, you will not receive a notification if you do not participate in the game.
/// Caution: None.
///
/// @param result Data in Json format, including winning and losing results, etc.
- (void)onGameResult:(NSString *)result;

/// The interface for requesting the robot configuration, which needs to return the robot configuration.
///
/// Available since: 1.0.0 and above.
/// Description: When the gameConfig parameter in the [loadGame] method sets useRobot to true, the user can customize the robot configuration through [onRobotConfigRequire]
/// When to call /Trigger: loadGame.
/// Caution: None.
///
/// @param gameID Game ID.
- (ZegoGameRobotConfig *)onRobotConfigRequire:(NSString *)gameID;

/// Notify the application layer to modify the microphone state of the RTC.
///
/// Available since: 1.0.0 and above.
/// Description: Notify the application layer to modify the microphone status of the RTC (voice games will use it, such as: who is undercover)
/// When to call /Trigger: User microphone state change
/// Caution: None.
///
/// @param isMute isMute // "1" - off "0" - on.
- (void)onMicStateChange:(BOOL)isMute;

/// Notify the application layer to modify the speaker status of the RTC.
///
/// Available since: 1.0.0 and above.
/// Description: Notify the application layer to modify the speaker status of the RTC (used in voice games, such as: who is undercover).
/// When to call /Trigger: others user speaker state change
/// Caution: None.
///
/// @param isMute isMute // "1" - off "0" - on.
- (void)onSpeakerStateChange:(NSArray<NSString *> *)userIDList isMute:(BOOL)isMute;

/// User intercepts game request.
///
/// Available since: 1.4.0 and above.
/// Description: If the customer has interception requirements, execute callback.onSuccess() to allow user operations, and callback.onFail(error) to intercept, so that the operation in the game will not execute the request.
/// When to call /Trigger: User operates game UI events, such as taking a seat, etc.
/// Caution: None.
///
/// @param actionID  1001:join seat,
///                 1002:Get out of your seat,
///                 1003:Add seats randomly.
///                 etc.
/// @param data action data
/// @param callBack  callback.onSuccess() Yes, user operations are allowed，callback.onFail(error) User operation is not allowed .
///
- (void)onGameActionRequest:(int)actionID data:(NSString *)data callBack:(ZegoGameActionCallback *)callBack;

@end

NS_ASSUME_NONNULL_END
