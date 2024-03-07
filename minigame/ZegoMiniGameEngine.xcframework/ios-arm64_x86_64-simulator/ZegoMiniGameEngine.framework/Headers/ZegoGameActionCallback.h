//
//  ZegoGameActionCallback.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2024/1/22.
//

#import <Foundation/Foundation.h>
#import "ZegoGameDefines.h"

@interface ZegoGameActionCallback : NSObject

@property (nonatomic, copy) IZegoActionReqFailCallBack onFail;
@property (nonatomic, copy) IZegoActionReqSuccessCallBack onSuccess;

@end

