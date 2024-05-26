#include <iostream>

struct A
{
    int a;
    int b;
};

int main()
{
    std::cout << sizeof(A::a) << std::endl;

    printf("%d", &A::a);
    return 0;
}