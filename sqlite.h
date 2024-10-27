#ifndef SQLITE_H
#define SQLITE_H

#ifdef BUILDING_MY_DLL
#define MY_DLL_API __declspec(dllexport)
#else
#define MY_DLL_API __declspec(dllimport)
#endif
#include <sstream>
class MY_DLL_API sqlite {
public:
    static int start_sqlite(const std::string& path);
    static std::string sql_create_table(const std::string& path, const std::string &sql_create_table);
    static std::string sql_insert_data(const std::string& path, const std::string& table,const std::string& table_name,const std::string& table_data);
    static std::string sql_select_data(const std::string& path,  const std::string& table,const std::string& table_name);
    static std::string delete_table(const std::string &path,const std::string &table_name);
    static std::string sql_exec(const std::string &path,const std::string &sql);
private:
    static int callback(void *data, int argc, char **argv, char **azColName);
};
#endif



