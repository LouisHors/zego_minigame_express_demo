//
//  ZegoGameInfo.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2022/12/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZegoGameInfo : NSObject
/// The ID of the game.
@property (nonatomic, copy) NSString *gameID;

/// The name of the game.
@property (nonatomic, copy) NSString *gameName;

/// Introduction to the game.
@property (nonatomic, copy) NSString *gameDesc;

/// The game's icon url.
@property (nonatomic, copy) NSString *thumbnail;

/// List of game modes supported by this game. 1: ZegoGameModeHostsGame, 2: ZegoGameModeShowGame, 3: ZegoGameModeMallGame.
@property (nonatomic, strong) NSArray *gameMode;

- (NSString *)toString;
@end

NS_ASSUME_NONNULL_END
