#include <iostream>

class Test
{
public:
    Test(){};
    Test(const Test& t) = delete;
    void operator=(const Test &t) = delete;
    ~Test();


private:
    int *a;
};

int main()
{
    Test t1;
    Test t2 = t1;//已删除
    auto ptr = ;
    t2 = t1;

    return 0;
}