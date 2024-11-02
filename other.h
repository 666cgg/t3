#ifndef OTHER_H
#define OTHER_H
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <iostream>
#include <filesystem>
#include <httplib.h>
#include <json.hpp>
#include <codecvt>
#include <string>
#include <cstdio>
#define CPPHTTPLIB_OPENSSL_SUPPORT
namespace fs = std::filesystem;
using json = nlohmann::json;

#ifdef BUILDING_MY_DLL
#define MY_DLL_API __declspec(dllexport)
#else
#define MY_DLL_API __declspec(dllimport)
#endif

class MY_DLL_API other {
public:

    static std::string exec(const char* cmd);
    static std::string load_file_json_configuration(const std::string& filename, const std::string& name, const std::string& name1);
    static std::string load_json_configuration(const std::string &json_str, const std::string &name, const std::string &name1);
    static int check_file(const std::string& path);
    static void download_file(const std::string& url, const std::string& path);
    static std::string readFirstLine(const std::string& response);
    static bool isLoginSuccessful(const std::string& firstLine);
    static std::string removeTrailingNewline(std::string str);
    static std::string trim(const std::string& str);
    static void setColor(int colorCode);
};

#endif // OTHER_H