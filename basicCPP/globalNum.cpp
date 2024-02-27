#include <iostream>

int a = 10;

int main()
{
    int a = 20;
    //::a代表这个a的作用域是全局的,所以尽可能不用全局变量
    std :: cout << ::a << std :: endl;
    //a代表局部变量
    std :: cout << a << std :: endl;
    return 0;
}