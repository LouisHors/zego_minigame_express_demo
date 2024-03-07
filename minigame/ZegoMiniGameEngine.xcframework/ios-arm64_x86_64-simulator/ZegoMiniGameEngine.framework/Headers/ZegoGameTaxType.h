//
//  ZegoGameTaxType.h
//  ZegoMiniGameEngine
//
//  Created by zego on 2023/3/21.
//

#ifndef ZegoGameTaxType_h
#define ZegoGameTaxType_h

typedef NS_ENUM(NSInteger, ZegoGameTaxType) {
    /// Taxes are levied on all wagered game coins.
    ZegoGameTaxTypeBetCoin = 1,
    /// Only the winner is taxed.
    ZegoGameTaxTypeForWinner
};


#endif /* ZegoGameTaxType_h */
