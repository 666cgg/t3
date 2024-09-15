#pragma once
#include"include/httplib.h"
#include"include/nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <regex>
namespace fs = std::filesystem;
class t3 {
public:
    static bool downloadFile(const std::string&url,const std::string&path,const std::string&outputFile) {
        return a15(url,path,outputFile);
    }
    static int Automatic_login(const std::string&url,const std::string&path,const std::string&t,const std::string&s,const std::string&filename) {
      return a13(url,path,t,s,filename);
    }
    static int code_login(const std::string& url,const std::string &path,const std::string&appkey,const std:: string& kami,const std::string &imei,const std:: string&t,const std:: string&s){
        return a(url,path,appkey,kami,imei,t,s);
    }
    static int unbinding_code(const std::string& url,const std::string &path,const std::string&appkey,const std::string&kami,const std::string&imei,const std::string&t,const std::string&s){
       return a2(url,path,appkey,kami,imei,t,s);
    }
    static int unbinding_code(const std::string& url,const std::string &path,const std::string&appkey,const std::string&user,const std::string&pass,const std::string&imei,const std::string&t,const std::string&s){
        return a2(url,path,appkey,user,pass,imei,t,s);
    }
    static std::string verify(const std::string& url,const std::string& path,const std::string& t,const std::string& s){
      return a3(url,path,t,s );
    }
    static std::string new_version(const std::string& url,const std::string& path,const std::string& t,const std::string& s){
        return a3(url,path,t,s );
    }
    static std::string determine_version(const std::string& url,const std::string& path,const std::string&version,const std::string& t,const std::string& s){
        return a4(url, path,version,t,s);
    }
    static std::string user_registration(const std::string& url,const std::string& path,const std::string&user,const std::string&pass,const std::string&email,const std::string&t,const std::string&s){
        return a5(url,path,user,pass,email,t,s);
    }
    static int user_login(const std::string&url,const std::string&path,const std::string&user,const std::string&pass,const std::string&imei,const std::string&t,const std::string&s){
        return a6(url,path,user,pass,imei,t,s);
    }
    static std::string user_recharges(const std::string&url,const std::string&path,const std::string&user,const std::string&card,const std::string&t,const std::string&s){
        return a7(url,path,user,card,t,s);
    }
    static std::string documents_cloud(const std::string&url,const std::string&path,const std::string&token,const std::string&t,const std::string&s){
        return a8(url,path,token,t,s);
    }
    static int signature_comparison(const std::string&url,const std::string&path,const std::string&autograph,const std::string&t,const std::string&s){
        return a9(url,path,autograph,t,s);
    }
    static std::string user_pass(const std::string&url,const std::string&path,const std::string&user,const std::string&oldpass,const std::string&newpass,const std::string&t,const std::string&s){

        return a10(url,path,user,oldpass,newpass,t,s);
    }
    static std::string kami_state(const std::string&url,const std::string&path,const std::string&kami,const std::string&t,const std::string&s) {
        return a11(url,path,kami,t,s);
    }
    static nlohmann::json read_json_file(const std::string& filename) {
         return a12(filename);
     }
private:
        static inline int a(const std::string& url,const std::string &path,const std::string &appkey,const std:: string& kami,const std::string &imei,const std:: string&t,const std:: string&s){
            httplib::Client cl(url);
            httplib::Params params;
            params.emplace("kami",kami);
            params.emplace("imei",imei);
            params.emplace("",appkey);
            params.emplace("t",t);
            params.emplace("s",s);
            auto res=cl.Post(path,params);
            if(res) {
                int *status_code=new int;
                auto *content = new std::string;
                auto *fanhuiti=new std::string;
                *fanhuiti=std::to_string(res);
                *status_code=res->status;
                *content=res->body;
                if(*status_code==200) {
                    auto *firstLine = new std::string;
                    *firstLine=readFirstLine(*content);
                    *firstLine = readFirstLine(*content);
                    *firstLine = removeTrailingNewline(*firstLine);
                    *firstLine = trim(*firstLine);
                        if(*firstLine=="登录成功:200;") {
                        delete fanhuiti;
                        delete status_code;
                        delete content;
                        delete firstLine;
                        return 0;
                    }else {
                        std::cout<<*content<<std::endl;
                        delete fanhuiti;
                        delete status_code;
                        delete content;
                        delete firstLine;
                        return 1;
                    }
                }else {
                    return 1;
                }
            }else {
                return 2;
            }
        }
        static inline int a2(const std::string& url,const std::string &path,const std::string&appkey,const std::string&kami,const std::string&imei,const std::string&t,const std::string&s){
            httplib::Client cl(url);
            httplib::Params params;
            params.emplace("kami",kami);
            params.emplace("imei",imei);
            params.emplace("",appkey);
            params.emplace("t",t);
            params.emplace("s",s);
            if(auto res=cl.Post(path,params)) {
                auto *content = new std::string;
                *content=res->body;
                std::cout<<*content<<std::endl;
                delete content;
                return 0;
            }else {
                return 1;
            }
        }
        static inline int a2(const std::string& url,const std::string &path,const std::string&appkey,const std::string&user,const std::string&pass,const std::string&imei,const std::string&t,const std::string&s){
            httplib::Client cl(url);
            httplib::Params params;
            params.emplace("user",user);
            params.emplace("pass",pass);
            params.emplace("",appkey);
            params.emplace("t",t);
            params.emplace("s",s);
            params.emplace("imei",imei);
            if(auto res=cl.Post(path,params)) {
                auto *content = new std::string;
                *content=res->body;
                std::cout<<*content<<std::endl;
                delete content;
                return 0;
            }else {
                return 1;
            }
        }
        static std::string a3(const std::string& url,const std::string& path,const std::string& t,const std::string& s)
        {
            httplib::Client cl(url);
            httplib::Params params;
            params.emplace("t",t);
            params.emplace("s",s);
            auto res=cl.Post(path,params);
            if(res) {

                return res->body;
            }else{
                return "连接失败";
            }
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
        static std::string a4(const std::string& url,const std::string& path,const std::string&version,const std::string& t,const std::string& s){
            httplib::Client cl(url);
            httplib::Params params;
            params.emplace("ver",version);
            params.emplace("t",t);
            params.emplace("s",s);
            auto res=cl.Post(path,params);
            if(res) {
                return res->body;
            } else {
                return "连接失败";
            }
        }
        static std::string a5(const std::string& url,const std::string& path,const std::string&user,const std::string&pass,const std::string&email,const std::string&t,const std::string&s){
            httplib::Client cl(url);
            httplib::Params params;
            params.emplace("user",user);
            params.emplace("pass",pass);
            params.emplace("email",email);
            params.emplace("t",t);
            params.emplace("s",s);
            auto res=cl.Post(path,params);
            if(res) {

                return res->body;
            }else {
                return "连接失败";
            }
        }
        static int a6(const std::string&url,const std::string&path,const std::string&user,const std::string&pass,const std::string&imei,const std::string&t,const std::string&s){
            httplib::Client cl(url);
            httplib::Params params;
            params.emplace("user",user);
            params.emplace("pass",pass);
            params.emplace("imei",imei);
            params.emplace("t",t);
            params.emplace("s",s);
            auto res=cl.Post(path,params);
            if(res) {
                int *status_code=new int;
                auto *content = new std::string;
                auto *fanhuiti=new std::string;
                *fanhuiti=std::to_string(res);
                *status_code=res->status;
                *content=res->body;
                if(*status_code==200) {
                    auto *firstLine = new std::string;
                    *firstLine=readFirstLine(*content);
                    *firstLine = readFirstLine(*content);
                    *firstLine = removeTrailingNewline(*firstLine);
                    *firstLine = trim(*firstLine);
                    if(*firstLine=="登录成功:200;") {
                        delete fanhuiti;
                        delete status_code;
                        delete content;
                        delete firstLine;
                        using json = nlohmann::json;
                        json j;
                        j["xinxi"] = {
                            {"user", user},
                            {"pass", pass},
                            {"imei", imei},
                        };
                        std::string json_str=j.dump(4);
                        std::ofstream o("Profiles.json");
                        o << json_str;
                        o.close();
                        return 0;
                    }else {
                        std::cout<<*content<<std::endl;
                        delete fanhuiti;
                        delete status_code;
                        delete content;
                        delete firstLine;
                        return 1;
                    }
                }else {
                    return 5;
                }
            }else {
                return 2;
            }
        }
        static std::string a7(const std::string&url,const std::string&path,const std::string&user,const std::string&card,const std::string&t,const std::string&s){
            httplib::Client cl(url);
            httplib::Params params;
            params.emplace("user",user);
            params.emplace("card",card);
            params.emplace("t",t);
            params.emplace("s",s);
            auto res=cl.Post(path,params);
            if(res) {
                return res->body;
            }else {
                return "连接服务器失败";
            }
        }
        static std::string a8(const std::string&url,const std::string&path,const std::string&token,const std::string&t,const std::string&s){
            httplib::Client cl(url);
            httplib::Params params;
            params.emplace("token",token);
            params.emplace("t",t);
            params.emplace("s",s);
            auto res=cl.Post(path,params);
            if(res) {
            return res->body;
            }else {
            return "连接服务器失败";
                }
            }
        static int a9(const std::string&url,const std::string&path,const std::string&autograph,const std::string&t,const std::string&s) {
            httplib::Client cl(url);
            httplib::Params params;
            params.emplace("autograph",autograph);
            params.emplace("t",t);
            params.emplace("s",s);
            auto res=cl.Post(path,params);
            if(res) {
                int *status_code=new int;
                auto *content = new std::string;
                auto *fanhuiti=new std::string;
                *fanhuiti=std::to_string(res);
                *status_code=res->status;
                *content=res->body;
                if(*status_code==200) {
                    auto *firstLine = new std::string;
                    *firstLine=readFirstLine(*content);
                    *firstLine = readFirstLine(*content);
                    *firstLine = removeTrailingNewline(*firstLine);
                    *firstLine = trim(*firstLine);
                    if(*firstLine=="检验状态:200;") {
                        delete fanhuiti;
                        delete status_code;
                        delete content;
                        delete firstLine;
                        return 0;
                    }else{
                        return 1;
                    }
                }else {
                    return 1;
                }
            }else {
                return 2;
            }
        }
        static std::string a10(const std::string&url,const std::string&path,const std::string&user,const std::string&oldpass,const std::string&newpass,const std::string&t,const std::string&s) {
            httplib::Client cl(url);
            httplib::Params params;
            params.emplace("user",user);
            params.emplace("oldpass",oldpass);
            params.emplace("newpass",newpass);
            params.emplace("t",t);
            params.emplace("s",s);
            auto res=cl.Post(path,params);
            if(res) {
                return res->body;
            }else {
                return "连接失败";
            }
        }
        static std::string a11(const std::string&url,const std::string&path,const std::string&kami,const std::string&t,const std::string&s) {
            httplib::Client cl(url);
            httplib::Params params;
            params.emplace("kami",kami);
            params.emplace("t",t);
            params.emplace("s",s);
            auto res=cl.Post(path,params);
            if(res) {
                return res->body;
            }else {
                return "连接失败";
            }
        }
        static nlohmann::json a12(const std::string& filename) {
            std::ifstream file(filename);
            if (!file.is_open()) {
                throw std::runtime_error("无法打开文件: " + filename);
            }
            nlohmann::json j;
            file >> j; // 解析文件内容为json对象
            if (file.fail()) {
                throw std::runtime_error("无法解析文件为JSON: " + filename);
            }
            return j;
        }
        static int a13(const std::string&url,const std::string&path,const std::string&t,const std::string&s,const std::string& filename) {
            using json = nlohmann::json;
            std::ifstream file(filename);
            if (!file.is_open()) {
                return 1;
            }
            json j;
            file >> j;
            if (file.fail()) {
                throw std::runtime_error("无法解析文件为JSON: " + filename);
            }

            // 从json对象中提取信息
            if (j.contains("xinxi") && j["xinxi"].is_object()) {
                const auto& xinxi = j["xinxi"];
                if (xinxi.contains("imei") && xinxi["imei"].is_string()) {
                    std::cout << "IMEI: " << xinxi["imei"].get<std::string>() << std::endl;
                }
                if (xinxi.contains("pass") && xinxi["pass"].is_string()) {
                    std::cout << "Password: " << xinxi["pass"].get<std::string>() << std::endl;
                }
                if (xinxi.contains("user") && xinxi["user"].is_string()) {
                    std::cout << "User: " << xinxi["user"].get<std::string>() << std::endl;
                }
            std::string user=xinxi["user"].get<std::string>();
            std::string pass=xinxi["pass"].get<std::string>();
            std::string imei=xinxi["imei"].get<std::string>();
            return a6(url,path,user,pass,imei,t,s);

            }
            throw std::runtime_error("JSON文件缺少'xinxi'键或其不是一个对象: " + filename);
    }
    static int a14(const std::string&url,const std::string&path,const std::string&outputFile) {
            return a15(url,path,outputFile);
        }
    static bool a15(const std::string& url,const std::string&path, const std::string& outputFile) {
            httplib::Client cli(url);
            auto res = cli.Get(path);
            if (res) {
                std::ofstream ofs(outputFile, std::ios::binary);
                if (ofs) {
                    ofs.write(res->body.data(), res->body.size());
                    ofs.close();
                    return true;
                } else {
                    std::cerr << "无法打开输出文件: " << outputFile << std::endl;
                }
            } else {
                std::cerr << "请求失败: " <<  std::endl;
            }

            return false;
        }
};
class flash_phone {
public:
    static int devices_phone(int a) {
        return a1(a);
    }
    static std::string get_version() {
        return a2();
    }
    static int get_id() {
        return a3();
    }

    static int fastboot_clean_userdata(const std::string &id) {
        return a4(id);
    }
    static int unlock_bootloader(const std::string &id) {
        return a5(id);
    }
    static int flash_boot(const std::string &id,const std::string&path) {
        return a6(id,path);
    }
    static int flash_init_boot(const std::string &id,const std::string&path){
        return a7(id,path);
    }
    static std::string kernel_version(const std::string &id){
        return a8(id);
    }
private:
    static int a1(int a) {
       if(a==0){
           system("adb devices");
       }
        system("fastboot devices");
        return 0;
    }
    static std::string a2() {
        std::string deviceId = exec("getprop ro.build.version.release").substr(0, exec("getprop ro.build.version.release").find('\n'));
        return deviceId;
    }
    static int a3() {
        system("adb devices");
        return 0;
    }
    static std::string exec(const char* cmd) {
        std::array<char, 128> buffer{};
        std::string result;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }
        return result;
    }
    static int a4(const std::string &id) {
        std::string a="fastboot -s "+id+" erase userdata";
        auto b=system(a.c_str());
        return b;
    }
    static int a5(const std::string &id) {
        std::string a="fastboot -s "+id+" oem unlock";
        auto b=system(a.c_str());
        return b;
    }
    static int a6(const std::string &id,const std::string&path) {
        std::string a="fastboot -s "+id+" flash boot "+path;
        auto b =system(a.c_str());
        return b;
    }
    static int a7(const std::string &id,const std::string&path){
        std::string a="fastboot -s "+id+" flash init_boot "+path;
        auto b =system(a.c_str());
        return b;
    }
    static std::string a8(const std::string &id){
        std::string a="adb -s "+id+" shell uname -r ";
        auto b=exec(a.c_str());
        return b;
    }

};