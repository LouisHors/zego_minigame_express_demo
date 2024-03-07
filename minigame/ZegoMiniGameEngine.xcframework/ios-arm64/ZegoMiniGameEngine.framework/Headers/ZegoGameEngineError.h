//
//  ZegoGameEngineError.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2023/2/10.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(int, ZegoGameEngineError) {
    /// success.
    ZegoMiniGameEngineSuccess = 0,
    /// Network Error.
    ZegoGameEngineErrorNetwork = 7000001,
    /// Invalid user information.
    ZegoGameEngineErrorInvalidUserInfo = 7000002,
    /// Invalid parameter.
    ZegoGameEngineErrorInvalidParams = 7000003,
    /// Invalid token or expired.
    ZegoGameEngineErrorInvalidToken = 7000004,
    /// Invalid room id.
    ZegoGameEngineErrorInvalidRoomID = 7000005,
    /// Invalid game id.
    ZegoGameEngineErrorInvalidGameID = 7000006,
    /// timeout error.
    ZegoGameEngineErrorTimeOut = 7000007,
    /// already initialized.
    ZegoGameEngineErrorAlreadyInit = 7000008,
    /// Uninitialized.
    ZegoGameEngineErrorNotInit = 7000009,
    /// Game container not set.
    ZegoGameEngineErrorNotSetGameContainer = 7000010,
    /// Game info is empty.
    ZegoGameEngineErrorGameInfoIsNull = 7000011,
    /// Game is not running.
    ZegoGameEngineErrorGameIsNotRunning = 7000012,
    /// The current game does not support loading in this mode.
    ZegoGameEngineErrorGameNotSupportThisMode = 7000013,
    // does not support the region to run
    ZegoGameEngineErrorRegionLimit = 7000014,
    // This game has already been loaded.
    ZegoGameEngineErrorGameAlreadyLoaded = 7000015,
};
