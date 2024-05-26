#include <iostream>

class Test
{
public:
    Test() = default;//编译器自动生成默认的无参构造
    Test(int a);
    ~Test();


private:
    int a;
};




int main()
{
    return 0;
}