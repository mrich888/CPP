#include "stdMysql.h"
#include <mysql/mysql.h>
#include <iostream>
#include <vector>

struct stdMysqlPrivate
{
    MYSQL mysql;
    bool isConnected;//是否连接

};

stdMysql::stdMysql():p(new stdMysqlPrivate)
{
    mysql_init(&p->mysql);
    p->isConnected = false;
}

stdMysql::~stdMysql()
{
    if (p->isConnected == true)
    {
        mysql_close(&p->mysql);
    }
    delete p;
}

bool stdMysql::connect(CStrRef host, CStrRef user, CStrRef passwd, CStrRef databaseName, unsigned int port)
{
    if (mysql_real_connect(&p->mysql, host.c_str(), user.c_str(), passwd.c_str(), databaseName.c_str(), port, nullptr, 0) != nullptr)
    {
        std :: cout << "数据库连接失败" << mysql_error(&p->mysql);
        return false;
    }
    p->isConnected = true;
    return true;
}

bool stdMysql::execute(CStrRef sql)
{
    if (mysql_real_query(&p->mysql, sql.c_str(), sql.size()) != 0)
    {
        std :: cout << "语句执行失败" << mysql_error(&p->mysql) << std::endl;
        return false;
    }
    return true;

}

std::vector<std::vector<std::string>> stdMysql::getTableInfo(CStrRef sql)
{
    MYSQL_RES *result = mysql_store_result(&p->mysql);
    if (result == nullptr)
    {
        std::cout<<"获取结果集为空";
        return {};
    }
    //获取列名
    auto field = mysql_fetch_field(result);
    //获取列数
    int filedCount = mysql_field_count(&p->mysql);

    std::vector<std::vector<std::string>> resultArray;
    for (int idx = 0; idx < filedCount; idx++)
    {
        std::cout<<field[idx].name<<" ";
    }
        //从结果集中按行取数据
    while (auto sqlRow = mysql_fetch_row(result))
    {
        std::vector<std::string> arr;
        for (int idx = 0; idx < filedCount; idx++)
        {
                arr.push_back(sqlRow[idx]);
        }
        resultArray.push_back(std::move(arr));
    }
    //释放结果集
    mysql_free_result(result);
    return std::vector<std::vector<std::string>>();
}

// bool stdMysql::executeTransaction(conset StrArray &sqlVec)
// {
    
//     return false;
// }
