#include <iostream>

class Test
{
private:
    int a;
public:
    Test(int a): a(a){}
    const int* func()//修饰函数返回值，可以拿到指针但不能修改里面的值
    {
        return &a;
    }

    void func2(const int &a)//保护传进来的引用形参
    {

    }

    void func3()const//保护整个参数
    {

    }

    ~Test();
};

Test::~Test()
{
}

int main()
{


    return 0;
}