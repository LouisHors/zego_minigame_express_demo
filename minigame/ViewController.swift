//
//  ViewController.swift
//  minigame
//
//  Created by zego on 2024/1/4.
//
import SwiftUI

struct ContentView: View {
    var headers = ["棋牌类", "射击类", "其他"]
    let items: [String] = ["掼蛋", "射击大师", "敬请期待..."]
    @State private var singleSelection: UUID?
    
    var body: some View {
        NavigationView {
            List(selection: $singleSelection) {
                ForEach (headers, id: \.self) {header in
                    Section(header: Text(header)) {
                        Button {
                            onSelectGame(idx: headers.firstIndex(of: header) ?? 0)
                        } label: {
                            Text(items[headers.firstIndex(of: header) ?? 0])
                                .labelStyle(.titleOnly)
                                .foregroundColor(.black)
                        }
                    }
                }
            }
            .navigationBarTitle("Game List")
        }
    }
    
    func onSelectGame(idx: Int) {
        // 跳转
        if idx == 2 {
            // alert
            
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}

