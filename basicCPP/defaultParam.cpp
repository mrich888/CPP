#include <iostream>
#include <cstring>

// int add(int a, int b, int c = 0);

// int add(int a, int b, int c)
// {
//     return a + b + c;
// }

/* 占位参数 */
int add (int a, int b, int)  /* int add (int a, int b, int = 0)  占位默认参数 */
{
    return a + b;
}

bool func(int a, char * errorMsg = NULL)
{
    if(errorMsg != NULL)
        strcpy(errorMsg, "connect error!\n");
    return false;
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

    return 0;
}
