#include <iostream>


class Person
{
public:
    Person()
    {

    }

private:
    int m_age;
};

int main()
{
    const char * str = "hello world";
    /* 将const属性 转换为非const属性 */
    char * buffer = const_cast<char *>(str);

    const Person *p1 = new Person;
}