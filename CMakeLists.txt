cmake_minimum_required(VERSION 3.29)
project(t3_32)

set(CMAKE_CXX_STANDARD 20)

# 设置头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 设置 OpenSSL 的路径
set(OPENSSL_ROOT_DIR "C:/OpenSSL")
set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")
set(OPENSSL_LIBRARY_DIR "${OPENSSL_ROOT_DIR}/lib")

# 查找 OpenSSL
find_package(OpenSSL REQUIRED)

if (OPENSSL_FOUND)
    # 包含 OpenSSL 的头文件目录
    include_directories(${OPENSSL_INCLUDE_DIR})

    # 添加可执行文件
    add_executable(t3_32
            main.cpp
            t3.hpp
            include/httplib.h
            include/nlohmann/json.hpp
    )

    # 链接 OpenSSL 库和其他所需库
    target_link_libraries(t3_32
            OpenSSL::SSL
            OpenSSL::Crypto
            crypt32
            ws2_32
            kernel32
            user32
            gdi32
            winspool
            shell32
            ole32
            oleaut32
            uuid
            comdlg32
            advapi32
    )

    # 设置静态链接标志
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
    target_link_libraries(t3_32 -static)
else ()
    message(FATAL_ERROR "OpenSSL not found.")
endif ()