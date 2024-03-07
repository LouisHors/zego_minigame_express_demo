//
//  基础接口
//
//  zego_connection_base.h
//
//
//  Created by arvin on 2019/07/18.
//

#ifndef zego_connection_base_hpp
#define zego_connection_base_hpp

#include "zlogger/zlogger-all.h"
#include "zego_connection_define.hpp"
#include <memory>

namespace ZEGO
{
namespace CONNECTION
{
    bool IsCurlNetworkError(uint32 curlError);

    bool IsCurlSSLError(uint32 curlError);

    std::string GetCurlErrorInfo(uint32 curlError);

    uint32 GetMaxCurlError();

    uint32 GetNetAgentVersion();

    std::string GetVersion();

#if defined(ANDROID) || defined(_OS_OHOS_)
    bool InitPlatform(void* jvm, void* ctx, void* loader);
#endif // defined(ANDROID) || defined(_OS_OHOS_)

    void SetExternalLogger(std::shared_ptr<zlogger::ILogger> logger);

    //内部调用
    bool IsQuicDisable0RttError(ZCError error);
    bool IsQuicDisableVerifyCertError(ZCError error);

    void SetBaseGlobalProxyInfo(Socks5ProxyConfigList& config);

    void GetAvailableProxyInfo(std::string& proxyIP, int& proxyPort);

}// CONNECTION
}// ZEGO


#endif /* zego_connection_base_hpp */
