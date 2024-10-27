#define BUILDING_MY_DLL
#include "sqlite.h"
#include<sqlite3.h>
int sqlite::start_sqlite(const std::string& path) {
    sqlite3 *db;
    const auto res=sqlite3_open(path.c_str(),&db);
    sqlite3_close(db);
    return res;
}
std::string sqlite::sql_create_table(const std::string& path, const std::string &sql_create_table) {
    char *zErrMsg = nullptr;
    sqlite3 *db;
    std::stringstream resultStream;
    sqlite3_open(path.c_str(),&db);
    const auto res=sqlite3_exec(db,sql_create_table.c_str(),callback,&resultStream,&zErrMsg);
    sqlite3_close(db);
    if(res != SQLITE_OK){
        return zErrMsg;
    }
    return resultStream.str();
}
std::string sqlite::sql_insert_data(const std::string& path, const std::string& table,const std::string& table_name,const std::string& table_data) {
    const std::string sql="INSERT INTO "+table+" ("+table_name+") "+" VALUES "+"("+table_data+")";
    char *zErrMsg = nullptr;
    sqlite3 *db;
    std::stringstream resultStream;
    sqlite3_open(path.c_str(),&db);
    const auto res=sqlite3_exec(db,sql.c_str(),callback,&resultStream,&zErrMsg);
    sqlite3_close(db);
    if(res != SQLITE_OK){
        return zErrMsg;
    }
    return resultStream.str();
}
std::string sqlite::sql_select_data(const std::string& path,  const std::string& table,const std::string& table_name) {
    std::string sql="SELECT "+table+" FROM "+table_name;
    char *zErrMsg = nullptr;
    sqlite3 *db;
    std::stringstream resultStream;
    int rc = sqlite3_open(path.c_str(), &db);
    if (rc != SQLITE_OK) {
        sqlite3_close(db);
        return "";
    }
    rc = sqlite3_exec(db, sql.c_str(), callback, &resultStream, &zErrMsg);
    sqlite3_close(db);
    if (rc != SQLITE_OK) {
        return zErrMsg;
    }
    return resultStream.str();
}
std::string sqlite::delete_table(const std::string &path,const std::string &table_name) {
    const std::string sql="DROP TABLE "+table_name;
    sqlite3*db;
    char *zErrMsg = nullptr;
    std::stringstream resultStream;
    int rc = sqlite3_open(path.c_str(), &db);
    if (rc != SQLITE_OK) {
        sqlite3_close(db);
        return "";
    }
    rc=sqlite3_exec(db,sql.c_str(),callback,&resultStream,&zErrMsg);
    if (rc != SQLITE_OK) {
        return zErrMsg;
    }
    return resultStream.str();
}
std::string sqlite::sql_exec(const std::string &path,const std::string &sql) {
    char *zErrMsg = nullptr;
    sqlite3 *db;
    std::stringstream resultStream;
    auto rc=sqlite3_open(path.c_str(), &db);
    if (rc != SQLITE_OK) {

        sqlite3_close(db);
        return "";
    }
    rc=sqlite3_exec(db,sql.c_str(),callback,&resultStream,&zErrMsg);
    if (rc != SQLITE_OK) {
        return zErrMsg;
    }
    sqlite3_close(db);
    return resultStream.str();
}
int sqlite::callback(void *data, const int argc, char **argv, char **azColName) {
    auto *resultStream = static_cast<std::stringstream*>(data);
    *resultStream << azColName[0] << ": ";
    for (int i = 0; i < argc; i++) {
        if (argv[i]) {
            *resultStream << azColName[i] << " = " << argv[i];
        } else {
            *resultStream << azColName[i] << " = NULL";
        }
        if (i < argc - 1) {
            *resultStream << ", ";
        }
    }
    *resultStream << "\n";
    delete resultStream;
    return 0;
}

