//
//  ZegoGameMode.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2023/1/31.
//
#import <Foundation/Foundation.h>

typedef NS_ENUM(int, ZegoGameMode) {
    /// the host's game with play mode.
    ZegoGameModeHostsGame = 1,
    /// show mode games.
    ZegoGameModeShowGame = 2,
    /// Games that return to pure play mode.
    ZegoGameModeMallGame = 3,
    /// Cloud Game
    ZegoGameModeCloudGame = 4,
    /// Matchmaking in the game (individual seated placeholder mode)"
    ZegoGameModeMatchInGame = 5,
};
