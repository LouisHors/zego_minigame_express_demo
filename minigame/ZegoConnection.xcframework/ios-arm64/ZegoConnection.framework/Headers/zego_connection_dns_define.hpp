//
//  zego_connection_dns_define.h
//  ZegoConnection
//
//  Created by Strong on 2019/10/10.
//

#ifndef zego_connection_dns_define_hpp
#define zego_connection_dns_define_hpp

#include <string>
#include <vector>
#include "zego_connection_define.hpp"

namespace ZEGO
{

namespace CONNECTION
{
    enum class NameServerSource
    {
        HardCodeIP,
        LocalDNSResolve,
        ServerRespond
    };
    
    enum class NameServerProtocol
    {
        TCP = 0,
        UDP = 1,
    };
    
    struct NameServerAddress
    {
        IP2Type ip;
        uint32 port;
    };
    
    struct NameServerAddressInfo
    {
        NameServerProtocol protocol;
        NameServerAddress address;
    };
    
    enum class DNSStrategy
    {
        LocalDNS_First,
        ZegoNS_First
    };
    
    enum  DNSSource
    {
        LocalDNS = 1,
        ZegoNS = 1 << 1,
    };
    
    enum class DNSUpdateType
    {
        //连接超时
        Unreach = 1,
        //证书验证失败
        Untrust = 2,
        //信令请求成功
        Reached = 3
    };

    enum class DNSCategory
    {
        Available,
        Reached,
        UnReached,
        UnTrust,
    };
    
    struct DNSIP
    {
        std::string replaceDomain;
        int souce = 0;
        IP2Type ip;
        uint32 port = 0;
        DNSCategory category;
    };
    
    struct DNSEventData
    {
        uint32 error      = 0;
        uint64 startTime  = 0;  
        uint64 finishTime = 0;
        bool   isMemoryCache = false;  //是否是内存中读取的数据，一般只有非内存读取的数据，进行实际的域名解析外部才需要上报
    };

    //dns event data 用来收集当前dns 请求的过程数据
    struct LocalDNSEventData : DNSEventData
    {

    };

    struct ZegoNSRequestServiceInfoEvent
    {
        std::string ip;  // zegons 请求ip
        uint32      port;
        std::string protocol;    // zegons 使用的协议
    };

    struct ZegoNSEventData : DNSEventData
    {
        std::vector<ZegoNSRequestServiceInfoEvent> requestInfo;
    };

    //DNS 解析数据
    struct DNSData
    {
        std::string domain;
        std::string backupIp = ""; //备用IP
        std::string backupDomain = "";
        
        std::vector<DNSIP> ipList; //结果 [已连接成功ip, 可用ip, 不可用ip]

        bool detectSuccess = false;

        uint64 startTime     = 0;
        uint64 finishTime    = 0;

        //dns 解析过程中信息数据，一般用于数据上报
        std::shared_ptr<LocalDNSEventData> localEvent = nullptr;
        std::shared_ptr<ZegoNSEventData>   zegoNSEvent = nullptr;
    };
    
    // localDNS collect data
    struct LocalDNSResolveEvent
    {
        uint64 startTime = 0;
        uint64 finishTime = 0;

        std::string domain = "";
        std::vector<std::string> ipList;

    };
    
    // init by ZegoNS
    struct ZegoNSRequestDataCollect
    {
        uint64 startTime = 0;
        uint64 finishTime = 0;
        
        uint32 error = 0;
        std::string errorMessage;
        std::string protocol;
        std::string serverIp;
        uint32 serverPort = 0;
        std::string requestID;
        std::string domain;
        std::vector<std::string> ipList;
    };

    struct ZegoNSRequestEvent
    {
        uint64 startTime = 0;
        uint64 finishTime = 0;

        std::vector<ZegoNSRequestDataCollect> reqList;
    };

    struct ZegoNSResolveEvent
    {
        uint64 start_time = 0;
        uint64 finish_time = 0;
        std::string domain;
        std::vector<std::string> ip_list;
        std::vector<ZegoNSRequestServiceInfoEvent> request_info;
    };
    
	struct ZegoNSConfigEvent
	{
		uint32 uCode = 0;
		std::string detectUrl;
	};

    struct ZegoNSNtpEvent
    {
        uint32 uCode = 0;
        std::vector<std::string> ntpAddrs;
    };

    struct ZegoNetAgentAddressInfoEvent
    {
        uint32 uCode = 0;
        std::string zegonsIp;
        int port = 0;

        std::string zegons_return_server_sni_host;
        ZegoNetAgentAddressInfo addressInfo;
    };

    using OnZegoNSAddressUpdateDelegate = std::function<void(const ZegoAppInfo& appInfo, const DNSStrategy strategy, const std::vector<NameServerAddressInfo>& addresses)>;
    
    using OnZegoNSServerTimeUpdateDelegate = std::function<void(uint64 serverTime)>;

    // Local DNS report
    using OnLocalDNSResolveEventDelegate = std::function<void(const std::shared_ptr<LocalDNSResolveEvent>& event)>;

    using OnLocalDNSAsyncResolveResultDelegate = std::function<void(const std::shared_ptr<DNSData>& data)>;

    // Zego NS report
    using OnZegoNSResolveEventDelegate = std::function<void(const std::shared_ptr<ZegoNSResolveEvent>& data)>;

	using OnZegoNSGetDectecConfigDelegate = std::function<void(const std::shared_ptr<ZegoNSConfigEvent>& data)>;

    using OnZegoNSGetNtpServerDelegate = std::function<void(const std::shared_ptr<ZegoNSNtpEvent>& data)>;

    using OnZegoNSGetNetAgentAddressInfoDelegate = std::function<void(const std::shared_ptr<ZegoNetAgentAddressInfoEvent>& data)>;

    using OnZegoNSGetRootCertDelegate = std::function<void(uint32 error, bool is_quic_ecc, uint32 cert_version, const std::string& cert_data)>;
}
}


#endif /* zego_connection_dns_define_hpp */
