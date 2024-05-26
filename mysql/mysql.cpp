#include <iostream>
#include "stdMysql.h"

int main()

#if 0
    MYSQL mysql;
    mysql_init(&mysql);
    //连接
    if(mysql_real_connect(&mysql, "172.31.173.217 ", "root", "123456", "xjy", 3306, nullptr, 0) == nullptr)
    {
        std :: cout << "连接失败\n";
        return -1;
    }


    std::cout << "连接成功\n";
#endif
{
   stdMysql mysql;
   if(mysql.connect("192.168.88.128", "root", "123456", "student254"))
   {
        return -1;
   }

   auto Array = mysql.getTableInfo("select * from student;");

   for(auto &StrArr : Array)
   {
        for(auto &str : StrArr)
        {
            std::cout << str << " ";
        }
        std::cout << std::endl;
   }

    return 0;
}

