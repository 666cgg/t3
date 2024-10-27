#define BUILDING_MY_DLL
#include <filesystem>
#include "flash_phone.h"
#include <array>
namespace fs = std::filesystem;

std::string flash_phone::exec(const char *cmd) {
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
int flash_phone::devices_phone(const int a) {
    if(a==0){
        const std::string b=exec("adb devices");
        std::cout<<b<<std::endl;
    }
    std::string b=exec("fastboot devices");
    std::cout<<b<<std::endl;
    return 0;
}
std::string flash_phone::get_version() {
    std::string deviceId = exec("getprop ro.build.version.release").substr(0, exec("getprop ro.build.version.release").find('\n'));
    return deviceId;
}
int flash_phone::get_id() {
    exec("adb devices");
    return 0;
}
std::basic_string<char> flash_phone::fastboot_clean_userdata(const std::string &id) {
    const std::string a="fastboot -s "+id+" erase userdata";
    auto b=exec(a.c_str());
    return b;
}
std::basic_string<char> flash_phone::unlock_bootloader(const std::string &id) {
    const std::string a="fastboot -s "+id+" oem unlock";
    auto b=exec(a.c_str());
    return b;
}
std::basic_string<char> flash_phone::flash_boot(const std::string &id, const std::string&path) {
    const std::string a="fastboot -s "+id+" flash boot "+path;
    auto b =exec(a.c_str());
    return b;
}
std::basic_string<char> flash_phone::flash_init_boot(const std::string &id, const std::string&path) {
    const std::string a="fastboot -s "+id+" flash init_boot "+path;
    auto b =exec(a.c_str());
    return b;
}
std::string flash_phone::kernel_version(const std::string &id) {
    const std::string a="adb -s "+id+" shell uname -r ";
    auto b=exec(a.c_str());
    return b;
}
std::basic_string<char> flash_phone::run_shell(const std::string&path) {
    auto b=exec(path.c_str());
    return b;
}
int flash_phone::all_file(const std::string &directoryPath) {
    for (const auto &entry : fs::directory_iterator(directoryPath)) {
        std::cout << entry.path().filename() << std::endl;
    }
    return 0;
}
std::basic_string<char> flash_phone::transmit(const std::string &path1, const std::string &path2) {
    const std::string a="dd if= "+path1+" of="+path2;
    auto b=exec(a.c_str());
    return b;
}
std::basic_string<char> flash_phone::adb_reboot_bootloader(const std::string&id) {
    const std::string a="adb -s "+id+" reboot bootloader";
    auto b=exec(a.c_str());
    return b;
}
std::basic_string<char> flash_phone::fastboot_reboot(const std::string&id) {
    const std::string a="fastboot -s "+id+" reboot";
    auto b=exec(a.c_str());
    return b;
}
std::basic_string<char> flash_phone::flash_boot_a(const std::string &id, const std::string&path) {
    const std::string a="fastboot -s "+id+" flash boot_a "+path;
    auto b =exec(a.c_str());
    return b;
}
std::basic_string<char> flash_phone::flash_boot_b(const std::string &id, const std::string&path) {
    const std::string a="fastboot -s "+id+" flash boot_b "+path;
    auto b =exec(a.c_str());
    return b;
}
std::basic_string<char> flash_phone::current_slot() {
    const std::string a="fastboot getvar current-slot";
    auto b =exec(a.c_str());
    return b;
}
std::string flash_phone::adb_install_apk(const std::string &id, const std::string&path) {
    const std::string a="adb -s "+id+" install "+path;
    auto b= exec(a.c_str());
    return b;
}
std::string flash_phone::all_app(const std::string &id) {
    const std::string a="adb -s "+id+" shell pm list packages";
    auto b= exec(a.c_str());
    return b;
}
std::string flash_phone::app_name(const std::string &id,const std::string &app_name) {
    const std::string a="adb -s "+id+" pm list packages -f | grep "+app_name;
    auto b= exec(a.c_str());
    return b;
}
std::string flash_phone::disable_app(const std::string &id,const std::string &app_name) {
    const std::string a="adb -s "+id+" shell pm disable "+app_name;
    auto b= exec(a.c_str());
    return b;
}
std::string flash_phone::enable_app(const std::string &id,const std::string &app_name) {
    const std::string a="adb -s "+id+" shell pm enable "+app_name;
    auto b= exec(a.c_str());
    return b;
}
std::string flash_phone::adb_shell(const std::string &id,const std::string &adb) {
    const std::string a="adb -s "+id+" shell "+adb;
    auto b= exec(a.c_str());
    return b;
}





