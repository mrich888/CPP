#include <iostream>

class Test
{

public:
    Test(int a, int b) : a(a), b(b)
    {
        this->a = a; //区分本类a和形参a
        std :: cout << "构造:" << this << std :: endl;
    }

    // Test(const Test& t)
    // {
    //     Test t;
    //     return t;
    // }

    void clone()
    {
        std :: cout << "拷贝:" << std :: endl;
    }

    void show()
    {
        std :: cout << "show\n"; 
    }

    ~Test()
    {
        std :: cout << "析构\n"; 
    }
private:
    int a;
    int b;

};


int main()
{
    Test t(1, 2);
    std :: cout << "t address:" << &t <<std :: endl;
    
}