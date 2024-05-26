#include <iostream>
#include <vector>

auto func(auto a )
{
    std :: cout << a << std :: endl;
    return a;
}

int main()
{
    auto a = 10;
    std :: vector<int> v;
    //自动类型推导 auto
    auto ite = v.begin(); 
    //1.auto定义需要初始化 有基础才能推导
    //2.auto不能同时推导多个类型
    //3.特殊属性无法推导
    //4.不能推导数组类型，但可以推导指针
    //5.不能推模板
    //6.c++20中auto可以推到参数和返回值

    //auto a;
    //auto a = 1， b = 1.0;

    //const int a = 10;
    //auto b = a;

    int a[10] = {0};
    //auto a[10] = {0};
    auto b = a;

    // std::vector<int> v;
    // std::vector<auto> f = v ;
    
    return 0;
}