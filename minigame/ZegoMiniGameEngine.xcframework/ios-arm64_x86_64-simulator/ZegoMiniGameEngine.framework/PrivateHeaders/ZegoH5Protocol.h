//
//  ZegoH5Protocol.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2022/12/28.
//

#import <Foundation/Foundation.h>
#import "ZegoGameRobotConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZegoH5Protocol : NSObject

@end

@interface H5RequestBase : NSObject
@property (nonatomic, copy) NSString *seq;
@property (nonatomic, copy) NSString *command;
@end

@interface InitData : NSObject

@property (nonatomic, copy) NSString *version;
@end


@interface PlayerPlayingData : NSObject

@property (nonatomic, copy) NSString *userID;
@property (nonatomic, assign) BOOL isPlaying;
@end


@interface PlayerEndData : NSObject

@property (nonatomic, copy) NSString *userID;
@end

@interface PlayerEventData : NSObject

@property (nonatomic, copy) NSString *userID;
@property (nonatomic, assign) int teamID;
@property (nonatomic, assign) BOOL isIn;
@property (nonatomic, assign) int reason;
@property (nonatomic, copy) NSString *kickUserID;

@end

@interface PlayerReadyEvent : NSObject

@property (nonatomic, copy) NSString *userID;
@property (nonatomic, assign) BOOL isReady;
@end

@interface VideoStyle : NSObject

@property (nonatomic, assign) int type;
@end

@interface GameInstruction : NSObject

@property (nonatomic, assign) BOOL isHtml;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *content;
@end

@interface ZegoH5Response : NSObject

@property (nonatomic, copy) NSString *seq;
@property (nonatomic, assign) int code;
@property (nonatomic, strong) NSDictionary *data;

- (instancetype)initH5Response:(NSString *)seq code:(int)code data:(NSDictionary *)data;
- (NSString *)toString;
@end
 
@interface LeaveGameData : NSObject

@property (nonatomic, copy) NSString *gameID;
@end

@interface LeaveGame : H5RequestBase

@property (nonatomic, strong) LeaveGameData *data;

- (void)setLeaveGame:(NSString *)gameID;
- (NSString *)toString;
@end

 
@interface GameUserStatus : NSObject

@property (nonatomic, copy) NSString *userID;
@property (nonatomic, assign) BOOL status;
@end

@interface GameRecharge : NSObject

@property (nonatomic, copy) NSString *userID;
@end

@interface SoundPlayData : NSObject

@property (nonatomic, assign) BOOL isPlay;
@property (nonatomic, assign) int playType; // 0:一次性播放、1:循环播放
@property (nonatomic, assign) int volume;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *url;
@end

@interface SoundVolumeChangeData : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) int volume;
@property (nonatomic, copy) NSString *url;
@end

@interface GameStatusData : NSObject

@property (nonatomic, assign) int status;
@property (nonatomic, assign) int reasonCode;

@end

@interface GameButtonEvent : NSObject

@property (nonatomic, assign) int buttonID;
@property (nonatomic, copy) NSString *data;
@end

@interface GameLanguage : NSObject

@property (nonatomic, copy) NSString *language;
@end

@interface UpdateCodeData : NSObject

@property (nonatomic, copy) NSString *code;
@end

@interface UpdateCode : H5RequestBase

@property (nonatomic, strong) UpdateCodeData *data;

- (void)updateCode:(NSString *)code;
- (NSString *)toString;
@end

@interface RefreshSpinData : NSObject

@property (nonatomic, copy) NSString *gameID;
@end

@interface RefreshSpin : H5RequestBase

@property (nonatomic, strong) RefreshSpinData *data;

- (void)refreshSpin:(NSString *)gameID;
- (NSString *)toString;
@end

@interface RefreshMicAndSpeakerStateData : NSObject

@end

@interface RefreshMicAndSpeakerState : H5RequestBase

@property (nonatomic, strong) RefreshMicAndSpeakerStateData *data;

- (void)refreshMicAndSpeakerStateData;

- (NSString *)toString;
@end

@interface GetGameSettingData : NSObject

@end

@interface GetGameSetting : H5RequestBase

@property (nonatomic, strong) GetGameSettingData *data;

- (void)getGameSetting;
- (NSString *)toString;
@end

@interface GameSwitchData : NSObject

@property (nonatomic, copy) NSString *settingType;
@property (nonatomic, copy) NSString *settingValue;
@end

@interface SetGameSetting : H5RequestBase

@property (nonatomic, strong) GameSwitchData *data;

- (void)setGameSetting:(NSString *)settingType settingValue:(NSString *)settingValue;
- (NSString *)toString;
@end

@interface GetGameComponentData : NSObject

@end

@interface GetGameComponent : H5RequestBase

@property (nonatomic, strong) GetGameComponentData *data;

- (void)getGetGameComponent;
- (NSString *)toString;
@end


@interface SetGameComponentData : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) BOOL isShow;
@end

@interface SetGameComponent : H5RequestBase

@property (nonatomic, strong) SetGameComponentData *data;

- (void)setGameComponent:(NSString *)name isShow:(BOOL)isShow;
- (NSString *)toString;
@end

@interface GetGameFunctionListData : NSObject

@end

@interface GetGameFunctionList : H5RequestBase

@property (nonatomic, strong) GetGameFunctionListData *data;

- (void)getGameFunctionList;
- (NSString *)toString;
@end

@interface RunCustomFunctionData : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSArray *params;
@end

@interface RunCustomFunction : H5RequestBase

@property (nonatomic, strong) RunCustomFunctionData *data;

- (void)runCustomFunction:(NSString *)name;
- (NSString *)toString;
@end

@interface RobotConfigData : NSObject

@property (nonatomic, assign) int robotLevel;

@property (nonatomic, copy) NSString *robotNick;

@property (nonatomic, copy) NSString *robotAvatar;

@property (nonatomic, assign) int useRobotAfterTime;

@property (nonatomic, assign) int minRobotCoins;

@property (nonatomic, assign) int maxRobotCoins;

- (instancetype)initWithConfig:(ZegoGameRobotConfig *)config;

- (NSDictionary *)configToDict;

@end

@interface ActionRequest : NSObject

@property (nonatomic, assign) int actionID;
@property (nonatomic, copy) NSString *data;

@end

@interface ActionResponse : NSObject

@property (nonatomic, assign) int responseCode;

- (instancetype)initWithResCode:(int)responseCode;

- (NSDictionary *)configToDict;
@end


@interface RtcMicStateEvent : NSObject

@property (nonatomic, assign) BOOL isMute;

@end

@interface RtcSpeakerStateEvent : NSObject

@property (nonatomic, assign) BOOL isMute;

@property (nonatomic, copy) NSArray <NSString *>* userIDList;

@end
  
@interface H5ErrorData : NSObject

@property (nonatomic, assign) int errorCode;
@property (nonatomic, copy) NSString *message;
@end

@interface InitCloudGameData : NSObject

@property (nonatomic, assign) long appid;

@property (nonatomic, assign) int cloudType;

@end

@interface InitCloudGame : H5RequestBase

@property (nonatomic, strong) InitCloudGameData *data;

- (void)setInit:(long)appID cloudType:(int)cloudType;

- (NSString *)toString;

@end


@interface StartCloudGameData : NSObject

@property (nonatomic, copy) NSString *serverSession;
@property (nonatomic, copy) NSString *sdkMsg;

@end

@interface StartCloudGame : H5RequestBase

@property (nonatomic, strong) StartCloudGameData *data;

- (void)setServerSession:(NSString *)serverSession sdkMsg:(NSString *)sdkMsg;

- (NSString *)toString;

@end


@interface UninitCloudGameData : NSObject

@end

@interface UninitCloudGame : H5RequestBase

@property (nonatomic, strong) UninitCloudGameData *data;

- (void)setUninit;

- (NSString *)toString;

@end


@interface CloudGameSetStreamProfileData : NSObject

@property (nonatomic, assign) int fps;
@property (nonatomic, assign) int max_bitrate;
@property (nonatomic, assign) int min_bitrate;

@end

@interface CloudGameSetStreamProfile : H5RequestBase

@property (nonatomic, strong) CloudGameSetStreamProfileData *data;

- (void)setStreamProfile:(int)fps maxBitrate:(int)maxBitrate minBitrate:(int)minBitrate;

- (NSString *)toString;

@end


@interface CloudGameSetVideoVolumeData : NSObject

@property (nonatomic, assign) double value;

@end

@interface CloudGameSetVideoVolume : H5RequestBase

@property (nonatomic, strong) CloudGameSetVideoVolumeData *data;

- (void)setVideoVolume:(double)volume;

- (NSString *)toString;

@end


@interface CloudGameGetVideoData : NSObject


@end

@interface CloudGameGetVideoVolume : H5RequestBase

@property (nonatomic, strong) CloudGameGetVideoData *data;

- (NSString *)toString;

@end

@interface CloudGameSetDisplayMarginData : NSObject

@property (nonatomic, assign) float marginLeft;

@property (nonatomic, assign) float marginTop;

@property (nonatomic, assign) float marginRight;

@property (nonatomic, assign) float marginBottom;

@end

@interface CloudGameSetDisplayMargin : H5RequestBase

@property (nonatomic, strong) CloudGameSetDisplayMarginData *data;

- (void)setLeft:(float)left top:(float)top right:(float)right bottom:(float)bottom;

- (NSString *)toString;

@end

@interface CloudGameSendKeyboardData : NSObject

@property (nonatomic, assign) int key;

@end

@interface CloudGameSendKeyboardEvent : H5RequestBase

@property (nonatomic, strong) CloudGameSendKeyboardData *data;

- (void)setKeyboard:(int)key;

- (NSString *)toString;

@end

NS_ASSUME_NONNULL_END
 




