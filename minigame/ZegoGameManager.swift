//
//  ZegoGameManager.swift
//  minigame
//
//  Created by 刘豪 on 2024/3/7.
//

import UIKit
import Alamofire
import ZegoMiniGameEngine

struct DescribeGameLaunchCodeData: Codable {
    var gameLaunchCode: String?
}

protocol ServerResponse {
    var code: Int { get set }
    var message: String { get set }
    var requestID: String { get set }
}

struct ChargeModel {
}

struct QueryGameSpinRequest {
    var appId: Int = 0
    var userID: String = ""
    var gameID: String = ""
    
    public func queryGameSpinsRequest(userID: String, appID: Int, gameID: String) {
        
    }
    
//    public func toRequestDic()->[String: Any] {
//        
//    }
}

struct QueryGameCoinData: Codable {
    var gameCoin: Int = 0
}

struct ExchangeGameSpinRequest {
    var outOderID: String?
    var appID: Int = 0
    var userID: String = ""
    var gameID: String = ""
    var gameSpin: Int = 0
    
    public func exchageGameSpinRequest(outOderID: String, userID: String, appID: Int, gameID: String, gameSpins: Int) {
        
    }
    
//    public func toRequestDic()->[String: Any] {
//        
//    }
}

struct ExchangeGameCoinData: Codable {
    var gameCoin: Int = 0
    var outOrderID: String?
    var orderID: String?
}

struct ExchangeGameResponse: ServerResponse {
    var code: Int
    
    var message: String
    
    var requestID: String
}


class ZegoGameManager: NSObject, ZegoGameEngineHandler {
    let game_host = "http://192.168.30.211:3020"
    let encoder = URLEncodedFormParameterEncoder(encoder: URLEncodedFormEncoder(alphabetizeKeyValuePairs: false))
    
    
    
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
    
    public func postToURL(url: String, isJson: Bool, param: [String: Any], completion: @escaping (_ errorCode: Int, _ result: Data?)->Void) {
        
        AF.request(url, parameters: param).validate().response { response in
            let decoder = JSONDecoder()
            switch response.result {
            case .success(_):
                let data = response.data
                completion(1, data)
            case .failure(_):
                completion(0, nil)
            }
        }
    }
    
    func getCurrentTimeStamp()->String {
        let date = Date(timeIntervalSinceNow: 0)
        let interval = date.timeIntervalSince1970 * 1000
        let stampString = "\(interval)"
        return stampString
    }
    
    override init() {
        super.init()
        initZegoGame()
    }
    
    func initZegoGame() {
        let userInfo: ZegoGameUserInfo = ZegoGameUserInfo()
        userInfo.userID = RandomUserInfo().getRandomName()
        userInfo.userName = RandomUserInfo().getRandomName()
        userInfo.avatar = RandomUserInfo().getRandomAvatar()
        ZegoMiniGameEngine.shared().`init`(KeyCenter().appID, token: KeyCenter().appSign, userInfo: userInfo) { error, obj in
            if error != 0 {
                print("ZegoMiniGameEngine init failed, pay attention")
            }else {
                // init success
            }
        }
        
        ZegoMiniGameEngine.shared().setGameEngineHandler(self)
    }
    
    public func getGameList(callback: @escaping (_ errorCode: Int)->Void) {
        ZegoMiniGameEngine.shared().getAllGameList { errorCode, gameList in
            callback(errorCode)
            if errorCode != 0 {
                print("zego mini game engine get game list failed, pay attention")
            }else {
                print(gameList ?? [])
            }
        }
    }
    
    public func loadGame(gameID: String, mode: ZegoGameMode, gameConfig: [String: String], callback: @escaping (_ errorCode: Int)->Void) {
        ZegoMiniGameEngine.shared().loadGame(gameID, gameMode: mode, gameConfig: gameConfig) { error in
            callback(error)
            if error == 0 {
                // 加载成功, 跳转,回调到上层实现
            }else {
                // 加载失败
                print("mini game: load game failed, errorCode: \(error)")
            }
        }
    }
    
    public func setGameView(view: UIView) {
        ZegoMiniGameEngine.shared().setGameContainer(view)
    }
    
    public func startGame(gameID: String, gamePlayerCount: Int, enableRobot: Bool, taxRate: Int, callback: @escaping (_ errorCode: Int)->Void) {
        var robotsInfo: [ZegoRobotSeatInfo] = []
        var playerInfo: [ZegoUserSeatInfo] = []
        if enableRobot {
            var i = 0
            while i < gamePlayerCount-1 {
                let robot = ZegoRobotSeatInfo(robotName: RandomUserInfo().getRandomName(), seatIndex: Int32(i+1), robotAvatar: RandomUserInfo().getRandomAvatar(), robotLevel: 0, robotBalance: 1000)
                robotsInfo.append(robot)
                i+=1
            }
        }else {
            let userInfo = ZegoUserSeatInfo(userID: RandomUserInfo().getRandomName(), seatIndex: 0)
            playerInfo.append(userInfo)
        }
        
        var config = ZegoStartGameConfig()
        config.taxRate = 0
        config.taxType = .forWinner
        config.minGameCoin = 0
        config.timeOut = 60
        
        ZegoMiniGameEngine.shared().startGame(config, userSeatInfoList: playerInfo, robotSeatInfoList: robotsInfo) { error in
            callback(error)
        }
    }
    
    public func unloadGame(forceQuit: Bool) {
        ZegoMiniGameEngine.shared().unloadGame(forceQuit)
    }
    
    
// MARK: -minigame handler
    func onTokenWillExpire() {
        print("token will expire soon")
    }
    
    func onGameResult(_ result: String) {
        print("mini game: on game result: \(result)")
    }
    
    func onGameLoadStateUpdate(_ gameLoadState: ZegoGameLoadState) {
        print("mini game: on game load state udpate: \(gameLoadState)")
    }
    
    func onGameStateUpdate(_ gameState: ZegoGameState, reasonCode: Int32) {
        print("mini game: on game state udpate: \(gameState), reason: \(reasonCode)")
    }
    
    func onUnloaded(_ gameID: String) {
        print("mini game: on unload game: \(gameID)")
    }
    
    func onGameError(_ errorCode: Int32, errorMessage: String) {
        print("mini game: on game error: \(errorCode), message: \(errorMessage)")
    }
    
    func onActionEventUpdate(_ actionID: Int32, data: String) {
        print("mini game: on action event update: \(actionID), content: \(data)")
    }
    
    
}
