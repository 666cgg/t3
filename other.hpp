#pragma once
#include"include/nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <cstdarg>
#include <Windows.h>
namespace fs=std::filesystem;
using json = nlohmann::json;
class other {
public:
    static std::string body_return;
    static void setColor(const int colorCode) {
        const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, colorCode);
    }
    static std::string exec(const char* cmd) {
        std::array<char, 102400> buffer{};
        std::string result;
        const std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
        if (!pipe) {
            throw std::runtime_error("open() failed!");
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }
        return result;
    }
    static void load_file_json_configuration(const std::string&filename,const std::string& name,const std::string& name1) {
        using json = nlohmann::json;
        std::ifstream file(filename);
        if (!file.is_open()) {
            exit(0);
        }
        json j;
        file >> j;

        if (file.fail()) {
            std::cout<<"无法解析文件为JSON: " + filename<<std::endl;
            exit(0);
        }
        if (j.contains(name) && j[name].is_object()) {
            if (const auto& name3 = j[name]; name3.contains(name1) && name3[name1].is_string()) {
                body_return = name3[name1].get<std::string>();
            }
        }
        j.clear();
    }
    static void load_json_configuration(const std::string &json_str, const std::string &name, const std::string &name1) {
        using json = nlohmann::json;
        if (json j = json::parse(json_str); j.contains(name) && j[name].is_object()) {
            if (const auto& name3 = j[name]; name3.contains(name1) && name3[name1].is_string()) {
                body_return = name3[name1].get<std::string>();
            }
        }
    }
    static int check_file(const std::string& path) {

        if(fs::exists(path)) {
            return 0;
        }
        return 1;
    }
    static void download_file(const std::string& url, const std::string& path) {
        httplib::SSLClient cl(url);
        auto res = cl.Get(url);
        if (!res) {
            std::cerr << "Failed to get response from server." << std::endl;
            return;
        }
        if (res->status != 200) {
            std::cerr << "Failed to download file. Status code: " << res->status << std::endl;
            return;
        }
        std::ofstream file(path, std::ios::binary);
        if (!file) {
            std::cerr << "Failed to open file: " << path << std::endl;
            return;
        }
        file << res->body;
        file.close();
    }
    static std::string readFirstLine(const std::string& response) {
        std::istringstream inputStream(response);
        std::string firstLine;
        std::getline(inputStream, firstLine); // 读取第一行
        return firstLine;
    }
    static bool isLoginSuccessful(const std::string& firstLine) {
        return firstLine == "登录成功:200;";
    }
    static std::string removeTrailingNewline(std::string str) {
        if (!str.empty() && (str.back() == '\n' || str.back() == '\r')) {
            str.pop_back();
        }
        return str;
    }
    static std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(' ');
        if (std::string::npos == first) {
            return str;
        }
        const size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    }





};


