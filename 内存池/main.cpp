#include <iostream>
#include "memoryPool.hpp"

class Test
{
public:

    MEMORYPOOL(Test, 1024);//侵入式宏

private:
    int a;
    int b;
    int c;
};

int main()
{
    Test *t = new Test;

    delete t;
    return 0;
}
