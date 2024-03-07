//
//  ZegoGameInfoDetail.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2023/1/10.
//

#import <Foundation/Foundation.h>
#import "ZegoGameInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZegoGameInfoDetail : ZegoGameInfo

/// The maximum number of players the game can support, can have multiple values.
@property (nonatomic, strong) NSArray *playerNum;

/// The minimum amount of game gold coins that need to be brought into the normal game of the game.
@property (nonatomic, strong) NSArray *coin;

/// Optional scene (temporarily unused)
@property (nonatomic, strong) NSArray *sceneMode;

/// The screen orientation supported by the game, 1 is portrait, 2 is landscape.
@property (nonatomic, assign) int gameOrientation;

/// The width of game design.
@property (nonatomic, assign) int designWidth;

/// The height of game design.
@property (nonatomic, assign) int designHeight;

/// The minimum height value required by the game container.
@property (nonatomic, assign) int safeHeight;

/// The minimum multiple of coins bet. The minimum amount of coins required to participate in the game is equal to minCoinMultiples multiplied by the game's coin bet amount.
@property (nonatomic, assign) int minCoinMultiples;

/// Cloud rendering parameters: Cloud service provider type, 1: Tencent Cloud, 2: Alibaba Cloud, 3: Huawei Cloud.
@property (nonatomic, assign) int cloudType;

/// Cloud rendering parameters: fps
@property (nonatomic, assign) int fps;

/// Cloud rendering parameters: Minimum bitrate [1, 15] (unit: Mbps)
@property (nonatomic, assign) int minBitrate;

/// Cloud rendering parameters: Maximum bitrate [1, 15] (unit: Mbps)
@property (nonatomic, assign) int maxBitrate;
@end

NS_ASSUME_NONNULL_END
