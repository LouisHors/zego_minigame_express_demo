//
//  ZegoUserSeatInfo.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2023/5/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZegoUserSeatInfo : NSObject

/// userID
@property (nonatomic, copy) NSString *userID;

/// User seat number
@property (nonatomic, assign) int seatIndex;

- (instancetype)initWithUserID:(NSString *)userID seatIndex:(int)seatIndex;
@end

NS_ASSUME_NONNULL_END
