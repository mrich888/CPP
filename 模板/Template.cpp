#include <iostream>

class Point
{
public:
    int m_x;
    int m_y;
};

#if 0
int add(int val1, int val2)
{
    return val1 + val2;
}
#endif

/* 模板的语法规定，这个地方尽量使用typename */
/* 模板的使用可以减少代码量  */
template <typename T>
T add(T  val1, T val2)
{
    return val1 + val2;
}

int main()
{
    int num1 = 100, num2 = 200;
    int sum = add<int>(num1, num2);
    std :: cout << "sum" << sum << std :: endl;

    float v1 = 7.5, v2 = 9.9;
    float v3 = add<float>(v1 , v2);
    std :: cout << "v3:" << v3 << std :: endl;

    Point point1;
    point1.m_x = 10;
    point1.m_y = 11;

    Point point2;
    point2.m_x = 10.3;
    point2.m_y = 14.3;
    
    Point point3 = add(point1, point2);
}