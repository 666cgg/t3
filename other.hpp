#pragma once
#include<windows.h>
#include"include/nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <cstdarg>
class other {
public:
    static std::string body_return;
    static void setColor(int colorCode) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
    static void load_configuration(const std::string& filename,const std::string& name,const std::string& name1) {
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
            const auto& name3 = j[name];
            if (name3.contains(name1) && name3[name1].is_string()) {
                body_return = name3[name1].get<std::string>();
            }
        }
    }
};

