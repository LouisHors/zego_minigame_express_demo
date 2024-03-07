#pragma once

#include "zsetting_fwd.h"

namespace zego
{
namespace zegosetting
{
    class ISetting
    {
      public:
        static ISetting_ptr create();
        virtual ~ISetting() = default;

        // 初始化接口
        virtual int32_t init(const init_options_t& options)   = 0;
        virtual void    uninit()                              = 0;
        virtual void    stop_polling()                        = 0;
        virtual void    start_polling()                       = 0;
        virtual void    set_token(const std::string& token)   = 0;
        virtual void    set_userid(const std::string& userid) = 0;
        

        // 环境变量接口 (如果同一个key设置了多次，后向前覆盖)
        virtual void set_request_kv(const std::string& key, int32_t value)            = 0;
        virtual void set_request_kv(const std::string& key, uint32_t value)           = 0;
        virtual void set_request_kv(const std::string& key, const std::string& value) = 0;
        virtual void set_request_kv(const std::string& key, float value)              = 0;

        // 以上四个接口 内部转为string存储(后台协议统一使用string类型请求)
        virtual std::map<std::string, std::string> get_request_kv() = 0;

        virtual std::map<std::string, std::string> local_cache()        = 0;
        virtual std::map<std::string, std::string> local_versions()     = 0;
        virtual std::map<std::string, uint32_t> local_number_versions() = 0;

        virtual void fetch_bypass(const std::vector<std::string>& cloud_filenames, fetch_callback_t fetch_callback, bool need_polling) = 0;

      public:
        // test interface
        virtual void test_set_client_ip(const std::string& ip) = 0;
        virtual void test_set_http_url(const std::string& url) = 0;
    };

    struct init_options_t {
        // 基本配置
        uint32_t    appid;       // appid
        std::string appsign;     // appsign
        std::string product;     // 产品名称
        std::string deviceid;    // 设备ID
        std::string cache_path;  // 缓存路径

        polling_notify_t  polling_notify{nullptr};   // 轮询回调

        // 是否使用云控测试环境 (客户的mode为test时 云控也使用test 与柔性配置的两个环境配置对齐)
        bool use_test_env = false;
        // 测试用参数
        bool internal_agent_overseas      = false;  // 是否海外模式（影响统一接入的保底IP）
        bool internal_agent_use_alpha_env = false;  // 是否使用统一接入的alpha环境 仅云控SDK与后台新版本联调时使用
    };

    struct fetch_result_t {
        struct item_t {
            int64_t     code           = 0;
            std::string message        = "";
            std::string cloud_filename = "";
            std::string json           = "";
            std::string versions       = "";
            uint32_t    g_versions     = 0;
            std::string hash_data_hex_string;
        };
        int64_t                             code    = 0;
        std::string                         message = "";
        std::vector<fetch_result_t::item_t> items{};

        std::shared_ptr<struct ::ZEGO::CONNECTION::HttpContext> detail{nullptr};  // 数据上报使用
        std::string url;
    };

}  // namespace zegosetting
}  // namespace zego

// 1. 存储
//      按product、appid、文件分开存储   cache_path/product/appid/dyamic/file_hash - v
//                                     cache_path/product/appid/static/file_hash - v
// 2. 缓存
//      1. 内部维护一个 file_list 每次轮询会拉取所有的file , 与对应的缓存对比，若有差异，通过polling_notify_t回调给上层
//      2. 内部的file_list会维护 "上次拉取成功时间"，用户主动拉取时，若间隔时间小于 polling_freq 则时间返回缓存
//      3. 需要后台支持：每次轮询事件，会拉取所有文件，此时希望后台能够支持批量拉取，否则10个文件要轮询50分钟，无法接受
