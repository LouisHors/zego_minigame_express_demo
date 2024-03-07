//
//  ZegoStreamProfile.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2023/9/20.
//

#import <Foundation/Foundation.h>

@interface ZegoStreamProfile : NSObject

/// Frame rate, range [10,60].
@property (nonatomic, assign) int fps;

/// Minimum bitrate, ranging from 1 to 15 Mbps.
@property (nonatomic, assign) int minBitrate;

/// Maximum bitrate, range [1,15], unit: Mbps.
@property (nonatomic, assign) int maxBitrate;

- (instancetype)initWithFps:(int)fps minBitrate:(int)minBitrate maxBitrate:(int)maxBitrate;
@end
