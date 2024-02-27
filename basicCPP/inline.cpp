#include <iostream>

inline int func(int a) // 内联，减少函数跳转
{
    return a + 1;
}

int main()
{
    std :: cout << func(10) << std :: endl;
    return 0;
}