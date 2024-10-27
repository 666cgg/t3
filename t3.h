#ifndef T3_H
#define T3_H

#ifdef BUILDING_MY_DLL
#define MY_DLL_API __declspec(dllexport)
#else
#define MY_DLL_API __declspec(dllimport)
#endif

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>
#include <json.hpp>
#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;
using json = nlohmann::json;

class MY_DLL_API t3 {
public:
    static std::string body_return_t3;

    // 下载文件
    static bool downloadFile(const std::string& url, const std::string& path, const std::string& outputFile);

    // 自动登录
    static int Automatic_login(const std::string& url, const std::string& path, const std::string& t, const std::string& s, const std::string& filename);

    // 代码登录
    static int code_login(const std::string& url, const std::string& path, const std::string& appkey, const std::string& kami, const std::string& imei, const std::string& t, const std::string& s);

    // 解绑代码
    static std::string unbinding_code(const std::string& url, const std::string& path, const std::string& appkey, const std::string& kami, const std::string& imei, const std::string& t, const std::string& s);
    static std::string unbinding_code(const std::string& url, const std::string& path, const std::string& appkey, const std::string& user, const std::string& pass, const std::string& imei, const std::string& t, const std::string& s);

    // 验证
    static std::string verify(const std::string& url, const std::string& path, const std::string& t, const std::string& s);

    // 新版本检查
    static std::string new_version(const std::string& url, const std::string& path, const std::string& t, const std::string& s);
    static std::string new_version(const std::string& url, const std::string& path, const std::string& version, const std::string& t, const std::string& s);

    // 版本确定
    static std::string determine_version(const std::string& url, const std::string& path, const std::string& version, const std::string& t, const std::string& s);

    // 用户注册
    static std::string user_registration(const std::string& url, const std::string& path, const std::string& user, const std::string& pass, const std::string& email, const std::string& t, const std::string& s);

    // 用户登录
    static int user_login(const std::string& url, const std::string& path, const std::string& user, const std::string& pass, const std::string& imei, const std::string& t, const std::string& s);

    // 用户充值
    static std::string user_recharges(const std::string& url, const std::string& path, const std::string& user, const std::string& card, const std::string& t, const std::string& s);

    // 文档云存储
    static std::string documents_cloud(const std::string& url, const std::string& path, const std::string& token, const std::string& t, const std::string& s);

    // 签名比较
    static int signature_comparison(const std::string& url, const std::string& path, const std::string& autograph, const std::string& t, const std::string& s);

    // 用户密码更改
    static std::string user_pass(const std::string& url, const std::string& path, const std::string& user, const std::string& oldpass, const std::string& newpass, const std::string& t, const std::string& s);

    // KAMI 状态查询
    static std::string kami_state(const std::string& url, const std::string& path, const std::string& kami, const std::string& t, const std::string& s);

    // 读取 JSON 文件
    static nlohmann::json read_json_file(const std::string& filename);

    // 心跳验证
    static std::string heart_verify(const std::string& url, const std::string& path, const std::string& user, const std::string& pass, const std::string& statecode, const std::string& t, const std::string& s);
};

#endif // T3_H