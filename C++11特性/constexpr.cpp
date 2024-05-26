#include <iostream>

constexpr int func(int a)
{
    return a * 10;
}

template<int size>
class Test
{
public:
   
private:
    char str;
};

class A
{
public:
   
private:
    int a;
};

constexpr int sum(int x)
{
    int count = 0;
    while (x != 0)
    {
        x--;
        count++;
    }
    return count;

}

int main()
{
    constexpr int a = 10 * 10; //编译期就是编译了
    std::cout << func(a) << std::endl;

    constexpr int a = sizeof(A);
    Test<a> t;

    int size = 10;
    char str[sum(4)];

    //编译慢，运行快，在运行期计算

    return 0;
}