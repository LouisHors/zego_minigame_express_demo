//
//  ViewController.swift
//  minigame
//
//  Created by zego on 2024/1/4.
//

import UIKit
import ZegoExpressEngine

class HomeViewController: UIViewController {
    @IBOutlet weak var gameList: UITableView!
    
    let gameNameList: [String] = ["打扑克", "打飞机", "打咩"]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        gameList.dataSource = self
        gameList.delegate = self
        createZego()
        loginRoom()
    }
    
    func requestGameList() {
        
    }
    
    func createZego() {
        ZegoRTCManager.shared.initRTC()
    }
    
    func loginRoom() {
        ZegoRTCManager.shared.loginRoom(roomID: "aaa", userID: "bbb") { errorCode in
            
        }
    }
    
    func onSelectGame(index: Int) {
        // 点击了具体的游戏,跳转到具体的游戏页
        switch index {
        case 0, 1:
            // 都跳转到同一个页面,只是加载不同的游戏
            
            return
        default:
            let alertVC = UIAlertController(title: "提示", message: "游戏还在开发中,敬请期待", preferredStyle: .alert)
            let confirmAction = UIAlertAction(title: "确定", style: .destructive)
            alertVC.addAction(confirmAction)
            present(alertVC, animated: true)
            return
        }
    }
    
}

extension HomeViewController: UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return gameNameList.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = UITableViewCell(style: .default, reuseIdentifier: "HorsMiniGameTest")
        cell.textLabel?.text = gameNameList[indexPath.row]
        return cell
    }
}

extension HomeViewController: UITableViewDelegate {
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        onSelectGame(index: indexPath.row)
    }
}
