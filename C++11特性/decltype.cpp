#include <iostream>

int func()
{
    std::cout<<"hello word"<<std :: endl;
}

template<typename t1, typename t2>
auto add (t1 a, t2 b)->decltype(a + b)  //返回值由结果推到
{
    return a + b;
}

int main()
{
    int a = 20;
    int b = 20;
    decltype(a + b) c;

    //1.不初始化项
    //2.表达式值是左值，推导出引用；右值推导出变量
    //3.可以推到特殊属性 & coonst

    decltype(func()) e;//不会运行但不报错  编译器编译的时候推导，运行的不执行

    return 0;
}