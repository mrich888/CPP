#ifndef __STDMYSQL_H_
#define __STDMYSQL_H_

#include <string>

using CStrRef = const std::string&;

struct stdMysqlPrivate;
class stdMysql
{
public:
    stdMysql(/* args */);
    ~stdMysql();
    bool connect(CStrRef host, CStrRef user, CStrRef passwd, CStrRef databaseName, unsigned int port = 3306);
    bool execute(CStrRef sql);
    std::vector<std::vector<std::string>>getTableInfo(CStrRef sql);//获得结果集
    //bool executeTransaction(conset StrArray & sqlVec);

private:
    stdMysqlPrivate *p;
};



#endif