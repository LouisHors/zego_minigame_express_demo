//
//  ZegoRTCManager.swift
//  minigame
//
//  Created by zego on 2024/3/4.
//

import Foundation
import ZegoExpressEngine

struct StreamInfo {
    var isHost: Bool = false
    var userID: String = ""
    var userName: String = ""
    var streamID: String = ""
}

struct RTCUser {
    var userID: String = ""
    var userName: String = ""
    var type: Int = 0
}

class ZegoRTCManager: NSObject {
    var expressEngine: ZegoExpressEngine?
    
    var isInit: Bool = false
    var isInRoom: Bool = false
    var memberCount: Int = 0
    
    var currentUserName: String = ""
    var currentUserID: String = ""
    var currentRoomID: String = ""
    var publishStreamID: String = ""
    
    var streamInfoList: [StreamInfo] = []
    var streamExtraInfoList: [ZegoRoomExtraInfo] = [];
    var rtcUserList: [ZegoUser] = []
    
    static let shared = ZegoRTCManager()
    
    private override init() {
        super.init()
    }
    
    public func initRTC() {
        if isInit {
            return
        }
        
        let profile = ZegoEngineProfile()
        profile.appID = UInt32(KeyCenter().appID)
        profile.appSign = KeyCenter().appSign
        profile.scenario = .broadcast
        expressEngine = ZegoExpressEngine.createEngine(with: profile, eventHandler: ZegoRTCManager.shared)
        isInit = true
    }
    
    public func destroyRTC(callback: @escaping ZegoDestroyCompletionCallback) {
        expressEngine = nil
        ZegoExpressEngine.destroy(callback)
        streamInfoList .removeAll()
        isInit = false
    }
    
    public func loginRoom(roomID: String, userID: String, callback: @escaping (_ errorCode: Int32)->Void) {
        if !isInit {
            return
        }
        currentRoomID = roomID
        currentUserID = userID
        currentUserName = userID
        var config = ZegoRoomConfig()
        config.isUserStatusNotify = true
        expressEngine?.loginRoom(roomID, user: ZegoUser(userID: userID), config: config, callback: { [unowned self] errorCode, extendedData in
            callback(errorCode)
            isInRoom = errorCode == 0
        })
    }
    
    public func leaveRoom() {
        if isInRoom {
            streamExtraInfoList.removeAll()
            streamInfoList.removeAll()
        }
        ZegoExpressEngine.shared().logoutRoom()
        isInRoom = false
        rtcUserList.removeAll()
    }
    
    public func startLive(isHost: Bool) {
        var publishStreamID = currentRoomID + "_" + currentUserID + "_"
        if isHost {
            publishStreamID = publishStreamID + "_host"
        }
        ZegoExpressEngine.shared().startPublishingStream(publishStreamID)
    }
    
    public func stopLive() {
        ZegoExpressEngine.shared().stopPublishingStream()
    }
}

extension ZegoRTCManager: ZegoEventHandler {
    func onRoomStateChanged(_ reason: ZegoRoomStateChangedReason, errorCode: Int32, extendedData: [AnyHashable : Any], roomID: String) {
        print("ZEGO__自己在本房间内的连接状态--\(errorCode)----\(extendedData)----\(reason)")
        
        if reason == .kickOut || reason == .loginFailed {
            leaveRoom()
        }
    }
    
    func onRoomStreamUpdate(_ updateType: ZegoUpdateType, streamList: [ZegoStream], extendedData: [AnyHashable : Any]?, roomID: String) {
        print("ZEGO__房间内其他用户推流/停止推流时--\(updateType)----\(streamList)----\(String(describing: extendedData))---\(roomID)")
        if updateType == .add {

        }
        
        if updateType == .add {
            streamList.forEach({print("ZEGO__加入的用户id:\($0.user.userID)----\($0.streamID)----\(roomID)")})
        } else if updateType == .delete {
            streamList.forEach({print("ZEGO__退出的用户id:\($0.user.userID)----\($0.streamID)----\(roomID)")})
        }
    }
    
    func onPublisherStateUpdate(_ state: ZegoPublisherState, errorCode: Int32, extendedData: [AnyHashable : Any]?, streamID: String) {
        if errorCode != 0 {
            //推流临时中断
            if errorCode == 1003020 {
                
            }
            print("ZEGO__推流状态出错 errorCode: \(errorCode)")
        } else {
            switch state {
            case .noPublish:
                print("ZEGO__没有推流")
            case .publishRequesting:
                print("ZEGO__正在请求推流")
            case .publishing:
                print("ZEGO__正在推流")
            default:
                return
                
            }
        }
    }
}
