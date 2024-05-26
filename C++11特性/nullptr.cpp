#include <iostream>

void func(void *p)
{
    std::cout<< "func ptr" <<std::endl;
}

void func(int a)
{
    std::cout<< "int" <<std::endl;
}

int main()
{
    func(nullptr);
    func(0);
    //func(NULL);//存在二义性 因为它就是0

    return 0;
}