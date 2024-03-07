//
//  ZegoGameDefines.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2022/12/6.
//

#import <Foundation/Foundation.h>
#import "ZegoGameInfo.h"
#import "ZegoGameInfoDetail.h"

#define ZEGO_MINI_GAME_ENGINE_VERSION @"1.4.1.42"

typedef void (^IZegoCommonCallBack)(int errorCode, _Nullable id object);
typedef void (^ZegoJsBridgeCallBack)(_Nullable id result);
typedef void (^ZegoJsBridgeFinishCallBack)(NSString *_Nullable command, _Nullable id result);
typedef void (^IZegoGameListCallBack)(NSInteger errorCode, NSArray<ZegoGameInfo *> * _Nullable gameList);
typedef void (^IZegoGameInfoDetailCallBack)(NSInteger errorCode, ZegoGameInfoDetail * _Nullable gameInfo);
typedef void (^IZegoLoadGameCallBack)(NSInteger errorCode);
typedef void (^IZegoStartGameCallBack)(NSInteger errorCode);
typedef void (^IZegoActionReqFailCallBack)(NSInteger errorCode);
typedef void (^IZegoActionReqSuccessCallBack)(void);
