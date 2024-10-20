#pragma once
#define OTHER
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
class flash_phone:other{
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
    static std::basic_string<char> fastboot_clean_userdata(const std::string &id) {
        return a4(id);
    }
    static std::basic_string<char> unlock_bootloader(const std::string &id) {
        return a5(id);
    }
    static std::basic_string<char> flash_boot(const std::string &id, const std::string&path) {
        return a6(id,path);
    }
    static std::basic_string<char> flash_init_boot(const std::string &id, const std::string&path){
        return a7(id,path);
    }
    static std::string kernel_version(const std::string &id){
        return a8(id);
    }
    static std::basic_string<char> run_shell(const std::string&path){
        return a9(path);
    }
    static int all_file(const std::string &directoryPath){
        return a10(directoryPath);
    }
    static std::basic_string<char> transmit(const std::string &path1, const std::string &path2){
        return a11(path1,path2);
    }
    static std::basic_string<char> adb_reboot_bootloader(const std::string&id){
        return a12(id);
    }
    static std::basic_string<char> fastboot_reboot(const std::string&id){
        return a13(id);
    }
    static std::basic_string<char> flash_boot_a(const std::string &id, const std::string&path){
        return a14(id,path);
    }
    static std::basic_string<char> flash_boot_b(const std::string &id, const std::string&path){
        return a15(id,path);
    }
    static std::basic_string<char> current_slot(){
        return a16();
    }
    static std::string adb_install_apk(const std::string &id, const std::string&path){
        return a17(id,path);
    }
    static std::string all_app(const std::string &id){
        return a18(id);
    }
    static std::string app_name(const std::string &id,const std::string &app_name){
        return a19(id,app_name);
    }
    static std::string disable_app(const std::string &id,const std::string &app_name){
        return a20(id,app_name);
    }
    static std::string enable_app(const std::string &id,const std::string &app_name){
        return a21(id,app_name);
    }
    static std::string adb_shell(const std::string &id,const std::string &adb) {
        return a22(id,adb);
    }
private:
    static int a1(int a) {
        if(a==0){
            std::string b=exec("adb devices");
            std::cout<<b<<std::endl;
        }
        std::string b=exec("fastboot devices");
        std::cout<<b<<std::endl;
        return 0;
    }
    static std::string a2() {
        std::string deviceId = exec("getprop ro.build.version.release").substr(0, exec("getprop ro.build.version.release").find('\n'));
        return deviceId;
    }
    static int a3() {
        exec("adb devices");
        return 0;
    }
    static std::basic_string<char> a4(const std::string &id) {
        std::string a="fastboot -s "+id+" erase userdata";
        auto b=exec(a.c_str());
        return b;
    }
    static std::basic_string<char> a5(const std::string &id) {
        std::string a="fastboot -s "+id+" oem unlock";
        auto b=exec(a.c_str());
        return b;
    }
    static std::basic_string<char> a6(const std::string &id, const std::string&path) {
        std::string a="fastboot -s "+id+" flash boot "+path;
        auto b =exec(a.c_str());
        return b;
    }
    static std::basic_string<char> a7(const std::string &id, const std::string&path){
        std::string a="fastboot -s "+id+" flash init_boot "+path;
        auto b =exec(a.c_str());
        return b;
    }
    static std::string a8(const std::string &id){
        std::string a="adb -s "+id+" shell uname -r ";
        auto b=exec(a.c_str());
        return b;
    }
    static std::basic_string<char> a9(const std::string &path){
        auto b=exec(path.c_str());
        return b;
    }
    static int a10(const std::string &directoryPath){
        for (const auto &entry : fs::directory_iterator(directoryPath)) {
            std::cout << entry.path().filename() << std::endl;
        }
        return 0;
    }
    static std::basic_string<char> a11(const std::string &path1, const std::string &path2){
        std::string a="dd if= "+path1+" of="+path2;
        auto b=exec(a.c_str());
        return b;
    }
    static std::basic_string<char> a12(const std::string&id){
        std::string a="adb -s "+id+" reboot bootloader";
        auto b=exec(a.c_str());
        return b;
    }
    static std::string a13(const std::string&id){
        std::string a="fastboot -s "+id+" reboot";
        auto b=exec(a.c_str());
        return b;
    }
    static std::basic_string<char> a14(const std::string &id, const std::string&path) {
        std::string a="fastboot -s "+id+" flash boot_a "+path;
        auto b =exec(a.c_str());
        return b;
    }
    static std::basic_string<char> a15(const std::string &id, const std::string&path) {
        std::string a="fastboot -s "+id+" flash boot_b "+path;
        auto b =exec(a.c_str());
        return b;
    }
    static std::basic_string<char> a16(){
        std::string a="fastboot getvar current-slot";
        auto b =exec(a.c_str());
        return b;
    }
    static std::string a17(const std::string &id, const std::string&path){
        std::string a="adb -s "+id+" install "+path;
        auto b= exec(a.c_str());
        return b;
    }
    static std::string a18(const std::string &id){
        std::string a="adb -s "+id+" shell pm list packages";
        auto b= exec(a.c_str());
        return b;
    }
    static std::string a19(const std::string &id,const std::string&app_name){
        std::string a="adb -s "+id+" pm list packages -f | grep "+app_name;
        auto b= exec(a.c_str());
        return b;
    }
    static std::string a20(const std::string &id,const std::string&app_name){
        std::string a="adb -s "+id+" shell pm disable "+app_name;
        auto b= exec(a.c_str());
        return b;
    }
    static std::string a21(const std::string &id,const std::string&app_name){
        std::string a="adb -s "+id+" shell pm enable "+app_name;
        auto b= exec(a.c_str());
        return b;
    }
    static std::string a22(const std::string &id,const std::string &adb) {
        std::string a="adb -s "+id+" shell "+adb;
        auto b= exec(a.c_str());
        return b;
    }
#ifdef OTHER
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
#else
#endif
};