#include "StdMyString.h"
#include <unistd.h>
#include <cstring>

char* myStrtok(char* source, const char* delim)
{
    static char * delimHeader;
    if (source == nullptr)
    {
        if (delimHeader == nullptr)
            return nullptr;
        source = delimHeader;
    }
    char *target = strstr(source, delim);
    if (target == nullptr)
    {
        delimHeader = nullptr;
        return source;
    }
    else
    {
        *target = '\0';
        delimHeader = target + strlen(delim);
        return source;
    }
}
int main()
{
    //StdMyString s = "hello  world world word world";//“hello world”进行有参构造，然后发生隐式转换， 然后s将它构造的空间直接拿过来了。s没有发生有参构造
    //StdMyString s1 = s; //拷贝函数
    //std :: cout << s << std :: endl;

    // StdMyString s1 = s + "world";//“world”发生隐式转换， s1发生深拷贝
    // std :: cout << s1 << std :: endl;

    // s1 = s;//系统自动生成的赋值运算符重载会造成二次拷贝，故要避免这种问题需要自己写赋值运算符重载
    // std :: cout << s1 << std :: endl;

    // StdMyString s2 = s - "world";
    // std :: cout << s2 << std :: endl;

    // s = s - "world";
    // std :: cout << s << std :: endl;

    // StdMyString s3 = s - "ow";
    // std :: cout << s3 << std :: endl;

    // s += " str";
    // std :: cout << s << std :: endl;

    // std :: cin >> s;
    // s[2] = 'h';

    // char str[] = "zhangsan, lisi, wangwu";
    // char *s = myStrtok(str, ",");
    // while (s != nullptr)
    // {
    //     std::cout<< s <<std::endl;
    //     s = myStrtok(nullptr, ",");
    // }

    // for(int i = 0; i < 10; i++)
    // {
    //     printf("%d %c\n", str[i], str[i]);
    // }

    StdMyString s("zhang san, lisi");
    MyStringList list = s.splite(",");
    // std :: cout << list<< std :: endl;

    // list -= "lisi";
    // std :: cout << list<< std :: endl;

    list[1] = "sss";
    std :: cout << list<< std :: endl;
    //printf("str:%x s:%x\n", str, s);



}