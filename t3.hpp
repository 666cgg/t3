#pragma once
#include"include/httplib.h"
#include"include/nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include "other.hpp"
namespace fs = std::filesystem;
std::string other::user = "";
std::string other::pass = "";
std::string other::imei = "";
class t3 :other{
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
    static std::string new_version(const std::string&url,const std::string&path,const std::string&version,const std::string&t,const std::string&s) {
        return a16(url,path,version,t,s);
    }
private:
        static int a(const std::string& url,const std::string &path,const std::string &appkey,const std:: string& kami,const std::string &imei,const std:: string&t,const std:: string&s){
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
                }
                return 1;
            }
            return 2;
        }
        static int a2(const std::string& url,const std::string &path,const std::string&appkey,const std::string&kami,const std::string&imei,const std::string&t,const std::string&s){
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
        static int a2(const std::string& url,const std::string &path,const std::string&appkey,const std::string&user,const std::string&pass,const std::string&imei,const std::string&t,const std::string&s){
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
                        j["userdata"] = {
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
                }
                return 5;
            }
            return 2;
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
                    }
                    return 1;
                }
                return 1;
            }
            return 2;
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
            }
            return "连接失败";
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
            }
            return "连接失败";
        }
        static nlohmann::json a12(const std::string& filename) {
            std::ifstream file(filename);
            if (!file.is_open()) {
                throw std::runtime_error("无法打开文件: " + filename);
            }
            nlohmann::json j;
            file >> j;
            if (file.fail()) {
                throw std::runtime_error("无法解析文件为JSON: " + filename);
            }
            return j;
        }
        static int a13(const std::string&url,const std::string&path,const std::string&t,const std::string&s,const std::string& filename) {

            load_configuration("Profiles.json");
            const std::string user=other::user;
            const std::string pass=other::pass;
            const std::string imei=other::imei;
            return a6(url,path,user,pass,imei,t,s);
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
                }
                std::cerr << "无法打开输出文件: " << outputFile << std::endl;
            } else {
                std::cerr << "请求失败: " <<  std::endl;
            }

            return false;
        }
        static std::string a16(const std::string&url,const std::string&path,const std::string&version,const std::string&t,const std::string&s) {
            httplib::Client cl(url);
            httplib::Params params;
            params.emplace("ver",version);
            params.emplace("t",t);
            params.emplace("s",s);
            auto res=cl.Post(path,params);
            auto b=res->body;
            return b;
        }
};