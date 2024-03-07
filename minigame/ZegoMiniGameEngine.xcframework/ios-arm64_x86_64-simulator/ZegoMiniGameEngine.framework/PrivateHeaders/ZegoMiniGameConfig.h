//
//  ZegoMiniGameConfig.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2023/1/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface ZegoMiniGameConfig : NSObject

+ (instancetype)sharedInstance;

/// ID of the game room
@property (nonatomic, copy) NSString *roomID;
/// game ID
@property (nonatomic, copy) NSString *gameID;
/// The code for the user to log in to the background needs to be passed to the game.
@property (nonatomic, copy) NSString *userCode;
@property (nonatomic, assign) ZegoGameMode gameMode;
@property (nonatomic, assign) ZegoGameOrientation gameOrientation;
@property (nonatomic, assign) int webViewWidth;
@property (nonatomic, assign) int webViewHeight;
@property (nonatomic, assign) BOOL isSoundPlayedByNative;

@property (nonatomic, strong) NSDictionary <NSString *, id> *gameConfig;
@end

NS_ASSUME_NONNULL_END
