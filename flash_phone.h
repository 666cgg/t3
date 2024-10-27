#ifndef FLASH_PHONE_H
#define FLASH_PHONE_H

#include <iostream>
#include <filesystem>
#include "other.h"
namespace fs = std::filesystem;

#ifdef BUILDING_MY_DLL
#define MY_DLL_API __declspec(dllexport)
#else
#define MY_DLL_API __declspec(dllimport)
#endif

class MY_DLL_API flash_phone {
public:
    static std::string exec(const char *cmd);
    static int devices_phone(int a);
    static std::string get_version();
    static int get_id();
    static std::basic_string<char> fastboot_clean_userdata(const std::string &id);
    static std::basic_string<char> unlock_bootloader(const std::string &id);
    static std::basic_string<char> flash_boot(const std::string &id, const std::string& path);
    static std::basic_string<char> flash_init_boot(const std::string &id, const std::string& path);
    static std::string kernel_version(const std::string &id);
    static std::basic_string<char> run_shell(const std::string& path);
    static int all_file(const std::string &directoryPath);
    static std::basic_string<char> transmit(const std::string &path1, const std::string &path2);
    static std::basic_string<char> adb_reboot_bootloader(const std::string& id);
    static std::basic_string<char> fastboot_reboot(const std::string& id);
    static std::basic_string<char> flash_boot_a(const std::string &id, const std::string& path);
    static std::basic_string<char> flash_boot_b(const std::string &id, const std::string& path);
    static std::basic_string<char> current_slot();
    static std::string adb_install_apk(const std::string &id, const std::string& path);
    static std::string all_app(const std::string &id);
    static std::string app_name(const std::string &id, const std::string &app_name);
    static std::string disable_app(const std::string &id, const std::string &app_name);
    static std::string enable_app(const std::string &id, const std::string &app_name);
    static std::string adb_shell(const std::string &id, const std::string &adb);
};

#endif // FLASH_PHONE_H