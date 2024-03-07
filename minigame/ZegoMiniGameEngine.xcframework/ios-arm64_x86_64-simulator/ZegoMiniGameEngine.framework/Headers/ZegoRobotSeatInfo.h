//
//  ZegoRobotSeatInfo.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2023/5/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZegoRobotSeatInfo : NSObject

/// The name of the bot.
@property (nonatomic, copy) NSString *robotName;

/// The serial number of the seat indicates the position of the seat.
@property (nonatomic, assign) int seatIndex;

/// The URL of the robot's avatar, and the transmission protocol must be HTTPS.
@property (nonatomic, copy) NSString *robotAvatar;

/// The AI difficulty of the bot, on a scale of 0 - 5.
@property (nonatomic, assign) int robotLevel;

/// The gold coin value on the robot.
@property (nonatomic, assign) long robotBalance;

- (instancetype)initWithRobotName:(NSString *)robotName
                        seatIndex:(int)seatIndex
                      robotAvatar:(NSString *)robotAvatar
                       robotLevel:(int)robotLevel
                     robotBalance:(long)robotBalance;

@end

NS_ASSUME_NONNULL_END
