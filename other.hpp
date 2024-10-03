#pragma once
#include<windows.h>
#include"include/nlohmann/json.hpp"
#include <fstream>
#include <iostream>
class other {
public:
    static std::string user;
    static std::string pass;
    static std::string imei;
    static void load_configuration(const std::string& filename) {
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
        if (j.contains("userdata") && j["userdata"].is_object()) {
            const auto& userdata = j["userdata"];
            if (userdata.contains("imei") && userdata["imei"].is_string()) {
                imei = userdata["imei"].get<std::string>();
            }
            if (userdata.contains("pass") && userdata["pass"].is_string()) {
                pass = userdata["pass"].get<std::string>();
            }
            if (userdata.contains("user") && userdata["user"].is_string()) {
                user = userdata["user"].get<std::string>();
            }
        }

    }
    static void setColor(int colorCode) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, colorCode);
    }
    static std::string exec(const char* cmd) {
        std::array<char, 102400> buffer{};
        std::string result;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
        if (!pipe) {
            throw std::runtime_error("open() failed!");
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }
        return result;
    }
};

