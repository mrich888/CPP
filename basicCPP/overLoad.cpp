#include <iostream>

// int add(int a, int b)
// {
//     return a + b;
// }


// double add(double a, double b)
// {
//     return a + b;
// }

const short size = 10;

void add(int a)
{
    std::cout<< "int :"<< a <<std::endl;
}

void add(short a)
{
    std::cout<< "short :" << a << std::endl;
}

int main()
{
    //std::cout<< add(1, 2) <<std::endl;
    //std::cout<< add(1.2, 2.2) <<std::endl;  /* 自动识别double类型 */

    add(size);
    return 0;
}






