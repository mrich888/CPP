#include <iostream>
#include"singletonTemplate.hpp"

class Test : public Singleton<Test>
{
public:



};

int main()
{
    Test *t = Test::getInstance();
    Test *t1 = Test::getInstance();
    
    printf("t1:%x  t:%x \n", t1, t);

    return 0;
}