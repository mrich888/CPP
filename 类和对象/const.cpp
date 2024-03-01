#include <iostream>

class Test
{
public:
    Test(int a, int b) : m_a(a), b(b) //初始化变量，减少构造函数
    {
        
    }
    void show()
    {
        std :: cout << m_a << "," << b << std :: endl;
    }
private:
    const int m_a;//常成员变量
    int b;
};

int main()
{
    Test t1(1 , 2);
    t1.show();


    return 0;
}