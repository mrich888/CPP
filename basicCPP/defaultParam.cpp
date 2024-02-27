#include <iostream>
#include <cstring>

// int add(int a, int b, int c = 0);

// int add(int a, int b, int c)
// {
//     return a + b + c;
// }

/* 占位参数:如果不需要传入第三个参数，可以直接省略参数而不用写默认值。这样可以提高代码的简洁性和可读性 */
int add (int a, int)  /* int add (int a, int b, int = 0)  占位默认参数 */
{
    return a;
}

bool func(int a, char * errorMsg = NULL)
{
    if(errorMsg != NULL)
    {
        strcpy(errorMsg, "connect error!\n");
        return false;
    }
       
    return true;
}

int add(int a, int b, int c)
{
    return a + b;
}

int main()
{
    //std::cout<< add(10, 20, 0) <<std::endl;

    // char msg[1024] = {0};
    // if (func(1, msg) == false)
    // {
    //     std::cout<< msg <<std::endl;
    // }

    //func(1);

    // add(1 ,2, 3);

    int a = 10;
    int b = 30;
    int c = 40;

    //占位参数函数
    add(a, b);
    add(a, b, c);
    std :: cout <<  add(a, b) << std :: endl;
    std :: cout <<  add(a, b, c) << std :: endl;
    
    char * errorMessage = new char[20];
    std :: cout <<  func(10, errorMessage) << std :: endl;
    std :: cout <<  func(10) << std :: endl;
    /* 释放资源 */
    delete []errorMessage;

    return 0;
}
