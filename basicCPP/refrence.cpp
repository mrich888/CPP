#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    a = temp;
}

int main()
{
    // int a = 10;
    // int &b = a; //引用定义必须初始化,b就是a的小名 （用指针实现，相当于指针常量）

    // int c = 20;
    // b = c; //与指针不同，初始化以后不在改变朝向 这里相当于b还是指向a，现在a = 20；

    // int a = 10;
    // int *b = &a;
    // int c = 20;
    // b = c; //这里b又指向c了

    /*  引用
    int a = 10;
    int &b = a;

    std :: cout << a << std :: endl;
    std :: cout << &a << std :: endl;
    std :: cout << b << std :: endl;
    std :: cout << &b << std :: endl;
    */

    int a = 20;
    int b = 10;
    swap(a, b);
    std :: cout << a << ","<< b << std :: endl;


}