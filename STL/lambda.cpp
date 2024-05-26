#include <iostream>

class Test
{
public:
    Test(/* args */);
    ~Test();

    void show()
    {
        std :: cout << "hello world" << std :: endl;
    }

    void lambda()
    {
        //捕获this指针
        auto f = [this](){this->show();};
    
        f();
    }

private:
    /* data */

};

Test::Test(/* args */)
{
}

Test::~Test()
{
}



int main()
{
    //捕获列表：捕获上下文中的变量
    //()参数列表
    //{}函数主体
    //[]()->返回类型 -- 一般情况下不需要写返回类型
    auto f = []()
    {
        return 10;
    };
    std :: cout << f() << std :: endl;

    //&引用捕获
    //[=]:以值得形式捕获所有变量
    int a = 11;
    auto f1 = [&a]()
    {
        a++;
        std::cout << a << std :: endl;
        return 10;
    };
    std::cout << f1() << std :: endl;

    int b = 20;
    int c;
    auto f2 = [=,&a]()
    {
        a++;
        std::cout << a << std :: endl;
    };

    Test t;
    t.lambda
   

    return 0;
}