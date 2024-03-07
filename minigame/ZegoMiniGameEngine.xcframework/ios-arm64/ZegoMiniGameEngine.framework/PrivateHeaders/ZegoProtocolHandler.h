//
//  ZegoProtocolHandler.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2022/12/19.
//

#import <Foundation/Foundation.h>
#import "ZegoGameDefines.h"
#import "ZegoStartGameConfig.h"
#import "ZegoServerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZegoProtocolHandler : NSObject

+ (ZegoProtocolHandler *)sharedEngine;

+ (void)login:(NSString *)userName
   userAvatar:(NSString *)userAvatar
       result:(IZegoCommonCallBack)result;

+ (void)getGameListWithPageIndex:(int)pageIndex
                        pageSize:(int)pageSize
                 gameOrientation:(ZegoGameOrientation)gameOrientation
                        gameMode:(ZegoGameMode)gameMode
                          result:(IZegoCommonCallBack)result;

+ (void)getGameInfoWithGameID:(NSString *)gameID
                       result:(IZegoCommonCallBack)result;

+ (void)createGameRoomWithGameID:(NSString *)gameID
                          roomID:(NSString *)roomID
                    maxPlayerNum:(int)maxPlayerNum
                        gameCoin:(long)gameCoin
                         taxType:(int)taxType
                         taxRate:(int)taxRate
                          result:(IZegoCommonCallBack)result;

+ (void)closeGameRoomWithGameID:(NSString *)gameID
                         roomID:(NSString *)roomID
                         result:(IZegoCommonCallBack)result;

+ (void)sendHeartbeatWithGameID:(NSString *)gameID
                         roomID:(NSString *)roomID;

+ (void)startGameWithGameID:(NSString *)gameID
                         roomID:(NSString *)roomID
                    gameConfig:(ZegoStartGameConfig *)gameConfig
               userSeatInfoList:(NSArray *)userSeatInfoList
              robotSeatInfoList:(NSArray *)robotSeatInfoList
                         result:(IZegoCommonCallBack)result;

+ (void)startCloudGame:(NSString *)gameID
                roomID:(NSString *)roomID
          appParameter:(NSString *)appParameter
             cloudType:(int)cloudType
         cloudResquestParam:(NSDictionary *)cloudResquestParam
                result:(IZegoCommonCallBack)result;

+ (void)stopCloudGame:(NSString *)gameID
               roomID:(NSString *)roomID
               result:(IZegoCommonCallBack)result;

+ (void)startPublishCloudGame:(NSString *)gameID
                       roomID:(NSString *)roomID
                     streamID:(NSString *)streamID
                    wlRequest:(WLStartPublishRequestData *_Nullable)wlRequest
                       result:(IZegoCommonCallBack)result;

+ (void)stopPublishCloudGame:(NSString *)gameID
                       roomID:(NSString *)roomID
                     streamID:(NSString *)streamID
                       result:(IZegoCommonCallBack)result;

+ (void)controlCloudGame:(NSString *)gameID
                  roomID:(NSString *)roomID
                 optType:(NSString *)optType
                optValue:(NSString *)optValue
                  result:(IZegoCommonCallBack)result;
@end

NS_ASSUME_NONNULL_END
