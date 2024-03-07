//
//  ZegoShowType.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2023/1/31.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(int, ZegoGameOrientation) {
    // 横竖屏，查询游戏列表时传ZegoShowOrientationBoth则返回所有支持横屏和竖屏的游戏
    ZegoShowOrientationBoth = 0,
    // 支持竖屏的游戏
    ZegoShowOrientationPortrait = 1,
    // 支持横屏的游戏
    ZegoShowOrientationLandscape = 2
};
