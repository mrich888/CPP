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

int add(short a)
{
    std::cout<< "short :" << a << std::endl;
    return 1;
}

int main()
{
    add(1);//函数无返回值
    //add(size);  /* 自动识别short类型 */
    std::cout<< "short :" << add(size) << std::endl;//函数有返回值
    return 0;
}






