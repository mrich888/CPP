#include <iostream>
#include <string>

int main()
{
    //底层逻辑是动态数组，可以自动扩容
    std :: string s;//定义一个字符串
    s = "hello world"; //字符串赋值

    std :: string s1 = s + "world";
    std :: cout << s1 << std :: endl;


    return 0;
}