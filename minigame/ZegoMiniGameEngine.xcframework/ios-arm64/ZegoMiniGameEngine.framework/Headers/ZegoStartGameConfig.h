//
//  ZegoStartGameConfig.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2023/6/2.
//

#import <Foundation/Foundation.h>
#import "ZegoGameTaxType.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZegoStartGameConfig : NSObject

/// The taxation type of the game, the default is ZegoGameTaxTypeForWinner. optional.
@property (nonatomic, assign) ZegoGameTaxType taxType;

/// The tax rate of this game, the range is [0, 10000), corresponding to the value of taxRate, which is 0 by default. optional.
@property (nonatomic, assign) int taxRate;

/// The minimum number of gold coins required to play the game, the default is 0. required.
@property (nonatomic, assign) long minGameCoin;

/// After calling [startGame], the game server waits for the player to be in position (in seconds). If the player is not fully in position after this time, an error will be reported. The default is 60. required.
@property (nonatomic, assign) int timeOut;

/// Map of custom parameters for game configuration. Use this Map to pass some custom parameters of the game. For more information, please contact ZEGO technical support. optional.
@property (nonatomic, strong) NSDictionary<NSString *, id> *customConfig;

- (instancetype)initWithTaxType:(ZegoGameTaxType)taxType
                        taxRate:(int)taxRate
                    minGameCoin:(long)minGameCoin
                        timeOut:(int)timeOut
                   customConfig:(NSDictionary<NSString *, id> *)customConfig;
@end

NS_ASSUME_NONNULL_END
