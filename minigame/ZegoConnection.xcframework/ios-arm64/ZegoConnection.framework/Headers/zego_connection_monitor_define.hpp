#ifndef zego_connection_monitor_define_hpp
#define zego_connection_monitor_define_hpp

#include "zego_connection_define.hpp"

namespace ZEGO
{

namespace CONNECTION
{
    /**
    网络状态变化响应
    
    @param result 网络状态变化信息
    @return  
    @note
    */
	using OnNetStateChangedDelegate = std::function<void(ZegoConnectionNetType nt)>;

    /**
     获取当前网络类型
     
     @param net_type 网络类型
     @return
     @note 
     */
    using OnGetCurrentNetTypeDelegate = std::function<void(ZegoConnectionNetType net_type)>;

}// CONNECTION
}// ZEGO


#endif /* zego_connection_monitor_define_hpp */
