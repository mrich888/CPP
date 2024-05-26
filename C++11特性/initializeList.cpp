#include <iostream>
#include <vector>
#include <initializer_list>

class A
{

public:
    // A(int a){}
    A( std::initializer_list<int> list){}
    ~A(){}
};

std::vector<int> func()
{
    return {};
}

void Log(std::initializer_list<std::string> list)
{
    for(auto ite = list.begin(); ite != list.end(); ite++)
    {
        std::cout<<*ite<<" ";
    }
    std::cout<<std::endl;
}

int main()
{
    //A a{1};//列表初始化
    std::vector<int> v = {1};//列表初始化
    std::initializer_list<int> list;////初始化列表

    A a{1, 2, 3};//初始化列表
    Log({"1.cpp", "line 30", "空指针错误"});

    return 0;
}