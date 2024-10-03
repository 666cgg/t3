#include <iostream>
#include "t3.hpp"
#include"flash_phone.hpp"
#include"other.hpp"
#include<windows.h>
std::string version="1000";
int main() {
    SetConsoleOutputCP(65001);
    other::setColor(1);

    while (true) {
        auto*q=new std::string;
        *q=t3::new_version("http://w.t3yanzheng.com","/3B3A6F36D0CBCBFB","","");
        if(*q>version){
            std::cout<<"当前版本非最新版，请更新\n";
            system("sleep 3");
            exit(0);
        }
        if(*q<version){
            std::cout<<"非法版本！！！\n";
            exit(0);
        }
        delete q;
        mark2:
        int *a = new int;
        std::cout << "欢迎使用本工具\n";
        //goto mark5;
        std::cout << "1.卡密登录\n";
        std::cout << "2.用户登录\n";
        std::cout << "3.用户注册\n";
        std::cout << "4.用户充值\n";
        std::cout << "0.退出程序\n";
        std::cin >> *a;
        if (*a==1) {
            int i=0;
            for(i=0;i<=3;i++) {
                auto *kami=new std::string;
                auto *imei=new std::string;
                std::cout << "请输入卡密\n";
                std::cin >> *kami;
                std::cout << "请输入设备码\n";
                std::cin>>*imei;
                int b = t3::code_login("http://w.t3yanzheng.com", "/FDEB7D08755EC9A3",
                                       "e81a52c04b5f0aa3873b508282437a73", *kami, *imei, "", "");
                if (b == 0) {
                    std::cout << "登录成功\n";
                    delete kami;
                    delete imei;
                    system("sleep 2");
                    system("cls");
                    goto mark5;
                } else {
                    std::cout<<"剩余次数："<<3-i<<std::endl;
                    std::cout<<"任意键重试\n";
                    auto*c=new std::string;
                    std::cin>>*c;
                    delete c;
                    delete kami;
                    delete imei;
                    system("cls");
                    if(3-i==0){
                        std::cout<<"输入错误已达上限！！！\n";
                        exit(0);
                    }
                }
            }
        }else if(*a==3){
            auto *user=new std::string;
            auto *pass=new std::string;
            auto *pass1=new std::string;
            auto *email=new std::string;
            std::cout<<"请输入用户名\n";
            std::cin>>*user;
            mark3:
            std::cout << "请输入密码\n";
            std::cin >> *pass;
            std::cout << "请确认密码\n";
            std::cin >> *pass1;
            if (*pass != *pass1) {
                std::cout<<"两次密码不一致，请重试\n";
                system("sleep 2");
                system("cls");
                goto mark3;
            }
            std::cout << "请输入邮箱\n";
            std::cin>>*email;
            auto *v=new std::string;
            *v=t3::user_registration("http://w.t3yanzheng.com","/66FC1E825D9553EE",*user,*pass,*email,"","");
            std::cout<<*v<<std::endl;
            delete v;
            delete user;
            delete pass;
            delete pass1;
            delete email;
            system("sleep 2");
            system("cls");
            goto mark2;
        }else if(*a==2){
            int i=0;
            auto b=t3::Automatic_login("http://w.t3yanzheng.com","/684EB7A5C811AFC7","","","Profiles.json");
            if (b == 0) {
                std::cout << "登录成功\n";
                system("sleep 2");
                system("cls");
                goto mark1;
            }else if(b==1){
                std::cout<<"无法检测到用户信息，正在切换手动登录\n";
            }
            for(i=0;i<=3;i++) {
                auto *user = new std::string;
                auto *pass = new std::string;
                auto *imei = new std::string;
                std::cout << "请输入用户名\n";
                std::cin >> *user;
                std::cout << "请输入密码\n";
                std::cin >> *pass;
                std::cout << "请输入设备码\n";
                std::cin >> *imei;
                int *h = new int;
                *h = t3::user_login("http://w.t3yanzheng.com", "/684EB7A5C811AFC7", *user, *pass, *imei, "", "");
                if (*h == 0) {
                    std::cout << "登录成功\n";
                    delete h;
                    delete user;
                    delete pass;
                    delete imei;
                    system("sleep 2");
                    system("cls");
                    goto mark1;
                } else {
                    delete h;
                    delete user;
                    delete pass;
                    delete imei;
                    std::cout<<"剩余次数："<<3-i<<std::endl;
                    std::cout<<"任意键重试\n";
                    auto*c=new std::string;
                    std::cin>>*c;
                    delete c;
                    if(3-i==0){
                        std::cout<<"输入错误已达上限！！！\n";
                        exit(0);
                    }
                }
            }
        }else if(*a==4){
            auto *user = new std::string;
            auto *card = new std::string;
            auto *b=new std::string;
            std::cout<<"请输入用户名\n";
            std::cin>>*user;
            std::cout<<"请输入充值卡\n";
            std::cin>>*card;
            *b= t3::user_recharges("http://w.t3yanzheng.com","/C19367B2ABD652B1",*user,*card,"","");
            std::cout<<*b<<std::endl;
            delete user;
            delete card;
            delete b;
            system("sleep 2");
            system("cls");
            goto mark2;
        }else if(*a==20081227){
            goto mark5;
        }else{
            exit(0);
        }
        mark1:
        delete a;
        mark5:
        int *y=new int;
        std::cout<<"请输入选项\n";
        std::cout<<"1.检测设备\n";
        std::cout<<"2.解锁bootloader(仅适用老机型)\n";
        std::cout<<"3.一键root(使用通用镜像刷机)\n";
        std::cout<<"4.安装应用\n";
        std::cout<<"5.获取所有已安装应用包名\n";
        std::cout<<"6.查询已安装应用包名\n";
        std::cout<<"7.禁用应用\n";
        std::cout<<"8.启用应用\n";
        std::cin>>*y;
        if(*y==1){
            int *u=new int;
            std::cout<<"请选择连接方式\n";
            std::cout<<"0.adb\n";
            std::cout<<"1.fastboot\n";
            std::cin>>*u;
            if(*u==0){
                flash_phone::devices_phone(0);
                goto mark1;
            }else if(*u==1){
                flash_phone::devices_phone(1);
                goto mark1;
            }else{
                delete u;
                exit(0);
            }
        }else if(*y==2){
            auto *o=new std::string;
            flash_phone::devices_phone(1);
            std::cout<<"请输入设备id\n";
            std::cin>>*o;
            flash_phone::unlock_bootloader(*o);
            delete o;
        }else if(*y==3){
            int *e=new int;
            std::cout<<"您的设备id如下\n";
            flash_phone::devices_phone(0);
            int *o=new int;
            auto *h=new std::string;
            auto *g=new std::string;
            auto *v=new std::string;
            auto *c=new std::string;
            std::cout<<"请输入设备id（adb模式）\n";
            std::cin>>*h;
            *v=flash_phone::kernel_version(*h);
            std::cout<<"您的内核版本为："<<*v;
            std::cout<<"正在将您指定的设备重启到bootloader模式\n";
            std::cout<<"如果没有重启到bootloader请手动重启\n";
            flash_phone::adb_reboot_bootloader(*h);
            std::cout<<"下面是通用boot镜像，请选择与您设备相符的版本使用\n";
            system("sleep 2");
            flash_phone::all_file("boot");
            std::cout<<"请输入和你内核版本相同的内核\n";
            std::cin>>*g;
            *c="/boot/"+*g;
            mark4:
            std::cout<<"您的设备当前活动的分区如下；\n";
            std::cout<<"请选择要刷入a分区或b分区\n";
            std::cout<<"1.a\n";
            std::cout<<"2.b\n";
            std::cout<<"3.vab或无分区\n";
            std::cout<<"4.安卓13及以上需刷入init分区\n";
            std::cin>>*o;
            if(*o==1){
                flash_phone::flash_boot_a(*h,*c);
            }else if(*o==2){
                flash_phone::flash_boot_b(*h,*c);
            }else if(*o==3){
                flash_phone::flash_boot(*h,*c);
            }else if(*o==4){
                flash_phone::flash_init_boot(*h,*c);
            }else{
                goto mark4;
            }
            std::cout<<"正在尝试开机\n";
            flash_phone::fastboot_reboot(*h);
            std::cout<<"如果开机失败请更换镜像或尝试刷入init_boot\n";
            delete o;
            delete c;
            delete g;
            delete v;
            delete h;
            delete e;
        }else if(*y==4){
            std::cout<<"您的设备id如下\n";
            flash_phone::devices_phone(0);
            auto *h=new std::string;
            auto *path=new std::string;
            std::cout<<"请输入设备id（adb模式）\n";
            std::cin>>*h;
            std::cout<<"请输入应用名称（adb模式）\n";
            std::cin>>*h;
            auto b=flash_phone::adb_install_apk(*h,*path);
            std::cout<<b<<std::endl;
            delete h;
            delete path;
            goto mark5;
        }else if(*y==5){
            std::cout<<"您的设备id如下\n";
            flash_phone::devices_phone(0);
            auto *h=new std::string;
            std::cout<<"请输入设备id（adb模式）\n";
            std::cin>>*h;
            std::cout<<"以下是您设备上的所有应用包名\n";
            auto b=flash_phone::all_app(*h);
            std::cout<<b<<std::endl;
            delete h;
            goto mark5;
        }else if(*y==6){
            std::cout<<"您的设备id如下\n";
            flash_phone::devices_phone(0);
            auto *h=new std::string;
            auto *j=new std::string;
            std::cout<<"请输入设备id（adb模式）\n";
            std::cin>>*h;
            std::cout<<"请输入查询的应用名称\n";
            std::cin>>*j;
            auto b=flash_phone::app_name(*h,*j);
            delete j;
            delete h;
            goto mark5;
        }else if(*y==7){
            std::cout<<"您的设备id如下\n";
            flash_phone::devices_phone(0);
            auto *h=new std::string;
            auto *j=new std::string;
            std::cout<<"请输入设备id（adb模式）\n";
            std::cin>>*h;
            std::cout<<"请输入应用名称\n";
            std::cin>>*j;
            auto b=flash_phone::disable_app(*h,*j);
            std::cout<<*j<<std::endl;
            delete h;
            delete j;
            goto mark5;
        }else if(*y==8){
            std::cout<<"您的设备id如下\n";
            flash_phone::devices_phone(0);
            auto *h=new std::string;
            auto *j=new std::string;
            std::cout<<"请输入设备id（adb模式）\n";
            std::cin>>*h;
            std::cout<<"请输入应用名称\n";
            std::cin>>*j;
            auto b=flash_phone::enable_app(*h,*j);
            std::cout<<*j<<std::endl;
            delete h;
            delete j;
            goto mark5;
        }
        delete y;
        return 0;
    }
}