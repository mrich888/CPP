#include <iostream>

class Test
{
public:
    Test(){};
    Test(const Test& t)
    {
        std::cout << "copy" <<std::endl;
    }

};

void print(int &t)
{
    std::cout << "左值引用" <<std::endl;
}

void print(int &&t)
{
    std::cout << "右值引用" <<std::endl;
}

template<typename T>
void func(T&& t)
{
    print(std::forward<T>(t));
}

int main()
{
    Test t1;
    func(t1);//左值引用
    func(10);//右值引用

    return 0;
}