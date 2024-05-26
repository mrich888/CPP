#include <iostream>

class Test
{
public:
    Test(int a):a(a)
    {
        d = new int;
    }
    //委托构造
    Test(int a, int b):Test(a)
    {
        this->b = b;
    }
    Test(int a, int b, int c):Test(a, b)
    {
        this->c = c;
    }

private:
    int a;
    int b;
    int c;
    int *d;
};

class Derived : public Test
{
public:
    //继承构造
    using Test::Test;
};



int main()
{

    return 0;
}