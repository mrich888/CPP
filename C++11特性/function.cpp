#include <iostream>
#include <functional>
#include <map>


//函数指针 仿函数 lambda表达式

void print()
{
    std::cout<< "hello world" <<std::endl;
}

class func
{

public:
    void operator()()
    {
        std::cout<< "hello world func" <<std::endl;
    }

    void printf()
    {
        std::cout<< "hello world prinf" <<std::endl;
    }
};

int add(int a, int b)
{
    return a + b;
}

int Minus(int a, int b)
{
    return a * b;
}

int divide(int a, int b, int c)
{
    return a / b / c;
}

//计算器容器
std::map<char, std::function<int(int,int)>> calculation;

int calculate(char symbol, int a, int b)
{
    auto f = calculation[symbol];
    return f(a,b);
}

int main()
{
    std::function<void()> f = print;//接收函数指针
    f();

    func func1;
    std::function<void()> f1 = func1.operator()();
    f1();

    std::function<void()> f2 = [](){std::cout<<"lambda"<<std::endl;};//接收函数指针
    f2();

    
    calculation['+'] = add;
    calculation['-'] = Minus;
    calculation['*'] = [](int a, int b){return a * b;};
    std::cout << calculate('-', 1, 2) << std::endl;

    //函数格式不匹配
    auto d = std::bind(divide, std::placeholders::_1, std::placeholders::_2, 1);
    calculation['/'] = d;
    std::cout<<  calculate('/', 10, 2) << std::endl;

    //一个函数属于特定的对象
    func func2;
    auto f3 = std::bind(&func::printf, &func2);//绑定器

    return 0;
}