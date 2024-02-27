#include <iostream>
#include <cstdlib>
#include <cstring>

#if 0
int main()
{
    /* 一维数组 */
    // char* str = (char *)malloc(sizeof(char) * 10);
    // if (str == NULL)
    // {
    //     return -1;
    // }

    // strcpy(str, "hello");
    // std :: cout << str << std :: endl;
    // free(str);

    /* 二维数组 */
    char** str = (char **)malloc(sizeof(char *) * 3);
    for(int idx = 0; idx < 3; idx++)
    {
        str[idx] = (char *)malloc(sizeof(char) * 10);
        if (str[idx] == NULL)
        {
            std :: cout << "malloc error\n" << std :: endl;
        }
        strcpy(str[idx], "hello");
    }
    
    for(int idx = 0; idx < 3; idx++)
    {
        std :: cout << str[idx] << std :: endl;
    }

    for(int idx = 0; idx < 3; idx++)
    {
        free(str[idx]);
    }

    free(str);

    return 0;
}
#endif

int main()
{
    // char *s = new char[10];//1、不需要计算内存大小 2、不需要对指针进行转换 3、不需要判断指针是否为空（为空会抛出异常，终止程序）
    // strcpy(s, "hello");
    // std :: cout << s << std :: endl;
    
    // delete []s;//释放数组


    // int *a = new int(10);//*a = 10 小括号赋值，中括号赋值
    // delete a; // 释放值

    char **s = new char*[3];
    for(int idx = 0; idx < 3; idx++)
    {
        s[idx] = new char[10];
        strcpy(s[idx] , "hello");
    }

    for(int idx = 0; idx < 3; idx++)
    {
        std :: cout << s[idx] << std :: endl;
    }

    for(int idx = 0; idx < 3; idx++)
    {
        delete []s[idx];
    }
    
    delete []s;

    return 0;

}