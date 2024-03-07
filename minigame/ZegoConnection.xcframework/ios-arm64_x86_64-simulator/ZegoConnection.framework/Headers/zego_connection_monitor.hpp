//
//  网络状态监控接口
//
//  zego_connection_monitor.h
//  
//
//  Created by arvin on 2019/07/18.
//

#ifndef zego_connection_monitor_hpp
#define zego_connection_monitor_hpp

#include <memory>
#include <vector>
#include "zego_connection_monitor_define.hpp"

namespace ZEGO
{

namespace CONNECTION
{     
	class NetMonitorImpl;

    class ZEGOCONNECTION_API ZegoConnectionMonitor
    {
    public:
        static std::shared_ptr<ZegoConnectionMonitor> GetInstance();
        virtual ~ZegoConnectionMonitor();
        
    private:
		ZegoConnectionMonitor();
        
    public:        
        /**
         注册网络变化监听
         
         @param delegate 状态变化回调
         @note 注意 delegate 的回调不一定在 Register 的线程
         @return 注册的序列号
         */
        ZCSeq RegisterMonitorDelegate(const OnNetStateChangedDelegate& delegate);
        
        /**
         取消监听网络状态变化
         
         @param seq 注册的序列号
         */
        void UnRegisterMonitorDelegate(ZCSeq seq);
        
        /**
         获取当前网络类型
         
         @note 在初始化阶段，在 iOS 平台下，返回值有可能不精确，当网络是移动网络类型时，需要异步才能获取到具体的类型，此时会返回 ZegoConnectionNetType::ZEGO_NT_UNKNOWN 类型。如果需要准确的类型，请调用 [GetCurrentNetType(const OnGetCurrentNetTypeDelegate&)] 方法
         @return 返回当前网络类型
         */
        ZegoConnectionNetType GetCurrentNetType();

        /**
         获取当前网络类型
         
         @note 注意 delegate 的回调不一定在调用的线程
         */
        void GetCurrentNetType(const OnGetCurrentNetTypeDelegate& delegate);

        /**
         获取上一次的网络类型
         
         @return 返回上一次的网络类型
         */
        ZegoConnectionNetType GetLastNetType();

        /**
         手动检查网络类型是否变化
         
         */
        void CheckCurrentNetType();

	private:
		std::shared_ptr<NetMonitorImpl> impl_;
    };
    
}// CONNECTION
}// ZEGO


#endif /* zego_connection_monitor_hpp */
