#include <iostream>

namespace A
{
    // 由于c++中对define无约束力，所以推荐使用const 来约束，以达到c语言中define的效果（常量效果）
    const int size = 10;
}

namespace B
{
    const int size = 20;
}


int main()
{
    std :: cout << A :: size << std :: endl;
    return 0;
}