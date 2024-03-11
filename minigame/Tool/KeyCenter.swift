//
//  KeyCenter.swift
//  minigame
//
//  Created by zego on 2024/3/4.
//

import Foundation

struct KeyCenter {
    private var _token = ""
    
    let appID = 1339309869
    let appSign = "cf9736bb967728eb1a1c4fe72a26b5b9ea18903f3684a95d8dad2094076bd71c"
    
    
    public mutating func getRTCToken()->String {
        return _token
    }
    public mutating func setRTCToken(token: String) {
        _token = token
    }
}

struct RandomUserInfo {
    public func getRandomName() -> String {
        let names: [String] = ["张三", "李四", "王五", "武则天", "秦始皇", "刘邦", "项羽", "女娲","王昭君", "西施","貂蝉", "杨玉环", "赵飞燕", "上官婉儿", "孙悟空", "唐僧", "猪八戒", "牛魔王", "盘古", "太上老君","周瑜", "吴刚"]
        let randomIndex = Int.random(in: 1...100) % names.count
        return names[randomIndex]
    }
    
    public func getRandomAvatar() -> String {
        let avatars: [String] = [
            "https://docservice-storage-alpha.zego.im/00c483552faefc8df47184643f9defee%2Fb7d2b72179deb6f134ca3006709e865c%2F16%2Fb7d2b72179deb6f134ca3006709e865c%2Fthumbnails%2F1.png?8m79mtgw0h2rqqhx",
            "https://docservice-storage-alpha.zego.im/00c483552faefc8df47184643f9defee%2Fb7d2b72179deb6f134ca3006709e865c%2F16%2Fb7d2b72179deb6f134ca3006709e865c%2Fthumbnails%2F1.png?8m79mtgw0h2rqqhx",
            "https://docservice-storage-alpha.zego.im/00c483552faefc8df47184643f9defee%2F61795d64787b32be071a61815cf305f0%2F16%2F61795d64787b32be071a61815cf305f0%2Fthumbnails%2F1.png?x71e2k5hkdjy6d9d",
            "https://docservice-storage-alpha.zego.im/00c483552faefc8df47184643f9defee%2Fc123c70be5a933d24119ab9a7023d941%2F16%2Fc123c70be5a933d24119ab9a7023d941%2Fthumbnails%2F1.png?fnvzwzqdfa5umu0q",
            "https://docservice-storage-alpha.zego.im/00c483552faefc8df47184643f9defee%2Fbdf1f499db619c8d007993f2f80b3a08%2F16%2Fbdf1f499db619c8d007993f2f80b3a08%2Fthumbnails%2F1.png?ugdhfdidkepug1uw",
            "https://docservice-storage-alpha.zego.im/00c483552faefc8df47184643f9defee%2F99fe2e224d26ad4f747f3f8c973b8a37%2F16%2F99fe2e224d26ad4f747f3f8c973b8a37%2Fthumbnails%2F1.png?6tub8wo058btyxlt",
            "https://docservice-storage-alpha.zego.im/00c483552faefc8df47184643f9defee%2F4ed11a20532ba7b2115e9288ed72b5a5%2F16%2F4ed11a20532ba7b2115e9288ed72b5a5%2Fthumbnails%2F1.png?zfbbm6uny2w7mezf",
            "https://docservice-storage-alpha.zego.im/00c483552faefc8df47184643f9defee%2F8d6abe9c6f744bfe26e12f459e4d454a%2F16%2F8d6abe9c6f744bfe26e12f459e4d454a%2Fthumbnails%2F1.png?55krvuez9ogs5lgf",
            "https://docservice-storage-alpha.zego.im/00c483552faefc8df47184643f9defee%2F299f3c1b5d502e3fc1acb70222385c9b%2F16%2F299f3c1b5d502e3fc1acb70222385c9b%2Fthumbnails%2F1.png?opvop22azg75d6e6",
            "https://docservice-storage-alpha.zego.im/00c483552faefc8df47184643f9defee%2F29ff384c19afd85418a665ad30ed599f%2F16%2F29ff384c19afd85418a665ad30ed599f%2Fthumbnails%2F1.png?g8gny92brmg421h4",
            "https://docservice-storage-alpha.zego.im/00c483552faefc8df47184643f9defee%2F0fefb0b0dddbaf5b0d8801e17bd27085%2F16%2F0fefb0b0dddbaf5b0d8801e17bd27085%2Fthumbnails%2F1.png?n0uj3to4diztaz2c",
            "https://docservice-storage-alpha.zego.im/00c483552faefc8df47184643f9defee%2F45ed2bf73239d6bc9e90bfc27d3d059e%2F16%2F45ed2bf73239d6bc9e90bfc27d3d059e%2Fthumbnails%2F1.png?ybqr3lrmuw45c7v7",
            "https://docservice-storage-alpha.zego.im/00c483552faefc8df47184643f9defee%2F732f10bfe988cca9c32779b2d6cd50ec%2F16%2F732f10bfe988cca9c32779b2d6cd50ec%2Fthumbnails%2F1.png?wbyfrzrsuxjnjdpp",
            "https://docservice-storage-alpha.zego.im/00c483552faefc8df47184643f9defee%2Ffbb3fd12a3c8e5d03b6608c231c6899e%2F16%2Ffbb3fd12a3c8e5d03b6608c231c6899e%2Fthumbnails%2F1.png?eu7bqwr8lsydfk1v",
            "https://docservice-storage-alpha.zego.im/00c483552faefc8df47184643f9defee%2F7c59ce2bc7fe93083a1d68a34ff37c22%2F16%2F7c59ce2bc7fe93083a1d68a34ff37c22%2Fthumbnails%2F1.png?i72ntxnqcd7npmem",
            "https://docservice-storage-alpha.zego.im/00c483552faefc8df47184643f9defee%2Fb63236dcfca4ea5efeb48fbaf2769147%2F16%2Fb63236dcfca4ea5efeb48fbaf2769147%2Fthumbnails%2F1.png?u980x6c9mhcj87gj"
        ]
        
        let randomIndex = Int.random(in: 1...1000) % avatars.count
        return avatars[randomIndex]
    }
}


