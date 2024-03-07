//
//  ZegoGameManager.swift
//  minigame
//
//  Created by 刘豪 on 2024/3/7.
//

import UIKit
import Alamofire
import ZegoMiniGameEngine


class ZegoGameManager: NSObject {
    let game_host = "http://192.168.30.211:3020"
    
    static let shared = ZegoGameManager()
    
    public func queryGameCoinWith(userID: String, appID: String, gameID: String, completion: (_ errorCode: Int, _ coin: Int)->Void) {
        
    }
    
    public func exchangeCoinWith(userID: String, appID: String, gameID: String, gameCoins: Int, completion: (_ errooCode: Int, _ coins: Int)->Void) {
        
    }
    
    public func getGameTokenWithUserID(userID: String, appID: String, completion: (_ errorCode:Int, _ token: String)->Void) {
        
    }
    
    public func describeUserCurrency(userID: String, gameID: String, completion: (_ errorCode: Int, _ token: String)->Void) {
        
    }
    
    public func getGameLauchCode(userID: String, appID: String, gameID: String, roomID: String, avatar: String, sex: Int, completion: (_ errorCode: Int, _ gameLaunchCode: String)->Void) {
        
    }
    
    public func postToURL(url: String, isJson: Bool, param: Dictionary<String, Any>, completion: (_ errorCode: Int, _ result: Result<Any, Error>)->Void) {
        
        
    }
    
    func getCurrentTimeStamp()->String {
        let date = Date(timeIntervalSinceNow: 0)
        let interval = date.timeIntervalSince1970 * 1000
        let stampString = "\(interval)"
        return stampString
    }
    
}
