#include <iostream>

class Interger
{
public:
    //防止隐式转换 explicit
    Interger(int a)
    {
        m_a = a;
    }

    int GetInteger()
    {
        return m_a;
    }

private:
    int m_a;

};


int main()
{
    Interger i(10);
    //i = 20; //构造函数的隐式转换  数值会被隐式构造成类的对象
    
    std :: cout << i.GetInteger() << std :: endl;

    return 0;

}
