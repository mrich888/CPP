#include <iostream>

struct StdTcpServer
{
    int a;
    int b;
};

using TcpS = StdTcpServer;// 用using 代替 typedef StdTcpServer cpS
int main()
{

    TcpS s;
    s.a = 10;
    s.b = 20;

    return 0;
}