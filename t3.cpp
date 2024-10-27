#define BUILDING_MY_DLL
#include "t3.h"
#include<json.hpp>
std::string t3::body_return_t3;
std::string readFirstLine(const std::string &response) {
    std::istringstream inputStream(response);
    std::string firstLine;
    std::getline(inputStream, firstLine); // 读取第一行
    return firstLine;
}
bool isLoginSuccessful(const std::string &firstLine) {
    return firstLine == "登录成功:200;";
}
std::string removeTrailingNewline(std::string str) {
    if (!str.empty() && (str.back() == '\n' || str.back() == '\r')) {
        str.pop_back();
    }
    return str;
}
std::string trim(const std::string &str) {
    const size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first) {
        return str;
    }
    const size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
void load_file_json_configuration(const std::string &filename, const std::string &name, const std::string &name1) {
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
            t3::body_return_t3 = name3[name1].get<std::string>();
        }
    }
    j.clear();
}
bool t3::downloadFile(const std::string&url,const std::string&path,const std::string&outputFile) {
    httplib::Client cli(url);
    if (auto res = cli.Get(path)) {
        if (std::ofstream ofs(outputFile, std::ios::binary); ofs) {
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
int t3::Automatic_login(const std::string&url,const std::string&path,const std::string&t,const std::string&s,const std::string&filename) {
    load_file_json_configuration("Profiles.json","userdata","user");
    const std::string user=t3::body_return_t3;
    load_file_json_configuration("Profiles.json","userdata","imei");
    const std::string imei=body_return_t3;
    load_file_json_configuration("Profiles.json","userdata","pass");
    const std::string pass=body_return_t3;
    return user_login(url,path,user,pass,imei,t,s);
}
int t3::code_login(const std::string& url,const std::string &path,const std::string&appkey,const std:: string& kami,const std::string &imei,const std:: string&t,const std:: string&s) {
    httplib::Client cl(url);
    httplib::Params params;
    params.emplace("kami",kami);
    params.emplace("imei",imei);
    params.emplace("",appkey);
    params.emplace("t",t);
    params.emplace("s",s);
    if(auto res=cl.Post(path,params)) {
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
            }
            std::cout<<*content<<std::endl;
            delete fanhuiti;
            delete status_code;
            delete content;
            delete firstLine;
            return 1;
        }
        return 1;
    }
    return 2;
}
std::string t3::unbinding_code(const std::string& url,const std::string &path,const std::string&appkey,const std::string&kami,const std::string&imei,const std::string&t,const std::string&s) {
    httplib::Client cl(url);
    httplib::Params params;
    params.emplace("kami",kami);
    params.emplace("imei",imei);
    params.emplace("",appkey);
    params.emplace("t",t);
    params.emplace("s",s);
    if(auto res=cl.Post(path,params)) {
        return res->body;
    }
    return "";
}
std::string t3::unbinding_code(const std::string& url,const std::string &path,const std::string&appkey,const std::string&user,const std::string&pass,const std::string&imei,const std::string&t,const std::string&s) {
    httplib::Client cl(url);
    httplib::Params params;
    params.emplace("user",user);
    params.emplace("pass",pass);
    params.emplace("",appkey);
    params.emplace("t",t);
    params.emplace("s",s);
    params.emplace("imei",imei);
    if(auto res=cl.Post(path,params)) {

        return res->body;
    }
    return "";
}
std::string t3::verify(const std::string& url,const std::string& path,const std::string& t,const std::string& s) {
    httplib::Client cl(url);
    httplib::Params params;
    params.emplace("t",t);
    params.emplace("s",s);
    if(auto res=cl.Post(path,params)) {
        return res->body;
    }
    return "连接失败";
}
std::string t3::new_version(const std::string& url,const std::string& path,const std::string& t,const std::string& s) {
    httplib::Client cl(url);
    httplib::Params params;
    params.emplace("t",t);
    params.emplace("s",s);
    if(auto res=cl.Post(path,params)) {

        return res->body;
    }
    return "连接失败";
}
std::string t3::determine_version(const std::string& url,const std::string& path,const std::string&version,const std::string& t,const std::string& s) {
    httplib::Client cl(url);
    httplib::Params params;
    params.emplace("ver",version);
    params.emplace("t",t);
    params.emplace("s",s);
    if(auto res=cl.Post(path,params)) {
        return res->body;
    }
    return "连接失败";
}
std::string t3::user_registration(const std::string& url,const std::string& path,const std::string&user,const std::string&pass,const std::string&email,const std::string&t,const std::string&s) {
    httplib::Client cl(url);
    httplib::Params params;
    params.emplace("user",user);
    params.emplace("pass",pass);
    params.emplace("email",email);
    params.emplace("t",t);
    params.emplace("s",s);
    if(auto res=cl.Post(path,params)) {
        return res->body;
    }
    return "连接失败";
}
int t3::user_login(const std::string&url,const std::string&path,const std::string&user,const std::string&pass,const std::string&imei,const std::string&t,const std::string&s) {
    httplib::Client cl(url);
    httplib::Params params;
    params.emplace("user",user);
    params.emplace("pass",pass);
    params.emplace("imei",imei);
    params.emplace("t",t);
    params.emplace("s",s);
    if(auto res=cl.Post(path,params)) {
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
                nlohmann::json j;
                j["userdata"] = {
                    {"user", user},
                    {"pass", pass},
                    {"imei", imei}
                };
                std::string json_str=j.dump(4);
                std::ofstream o("Profiles.json");
                o << json_str;
                o.close();
                return 0;
            }
            std::cout<<*content<<std::endl;
            delete fanhuiti;
            delete status_code;
            delete content;
            delete firstLine;
            return 1;
        }
        return 5;
    }
    return 2;
}
std::string t3::user_recharges(const std::string&url,const std::string&path,const std::string&user,const std::string&card,const std::string&t,const std::string&s) {
    httplib::Client cl(url);
    httplib::Params params;
    params.emplace("user",user);
    params.emplace("card",card);
    params.emplace("t",t);
    params.emplace("s",s);
    if(auto res=cl.Post(path,params)) {
        return res->body;
    }
    return "连接服务器失败";
}
std::string t3::documents_cloud(const std::string&url,const std::string&path,const std::string&token,const std::string&t,const std::string&s) {
    httplib::Client cl(url);
    httplib::Params params;
    params.emplace("token",token);
    params.emplace("t",t);
    params.emplace("s",s);
    if(auto res=cl.Post(path,params)) {
        return res->body;
    }
    return "连接服务器失败";

}
int t3::signature_comparison(const std::string&url,const std::string&path,const std::string&autograph,const std::string&t,const std::string&s) {
    httplib::Client cl(url);
    httplib::Params params;
    params.emplace("autograph",autograph);
    params.emplace("t",t);
    params.emplace("s",s);
    if(auto res=cl.Post(path,params)) {
        const auto status_code=new int;
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
std::string t3::user_pass(const std::string&url,const std::string&path,const std::string&user,const std::string&oldpass,const std::string&newpass,const std::string&t,const std::string&s) {
    httplib::Client cl(url);
    httplib::Params params;
    params.emplace("user",user);
    params.emplace("oldpass",oldpass);
    params.emplace("newpass",newpass);
    params.emplace("t",t);
    params.emplace("s",s);
    if(auto res=cl.Post(path,params)) {
        return res->body;
    }
    return "连接失败";
}
std::string t3::kami_state(const std::string&url,const std::string&path,const std::string&kami,const std::string&t,const std::string&s) {
    httplib::Client cl(url);
    httplib::Params params;
    params.emplace("kami",kami);
    params.emplace("t",t);
    params.emplace("s",s);
    if(auto res=cl.Post(path,params)) {
        return res->body;
    }
    return "连接失败";
}
nlohmann::json t3::read_json_file(const std::string& filename) {
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
std::string t3::new_version(const std::string&url,const std::string&path,const std::string&version,const std::string&t,const std::string&s) {
    httplib::Client cl(url);
    httplib::Params params;
    params.emplace("ver",version);
    params.emplace("t",t);
    params.emplace("s",s);
    auto res=cl.Post(path,params);
    auto b=res->body;
    return b;
}
std::string t3::heart_verify(const std::string&url,const std::string&path,const std::string&user,const std::string&pass,const std::string&statecode,const std::string&t,const std::string&s) {
    httplib::Client cl(url);
    httplib::Params params;
    params.emplace("user",user);
    params.emplace("pass",pass);
    params.emplace("statecode",statecode);
    params.emplace("t",t);
    params.emplace("s",s);
    auto res=cl.Post(path,params);
    auto b=res->body;
    return b;
}





