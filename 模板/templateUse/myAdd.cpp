#include <iostream>
#include "myAdd.hpp"

/* 头文件在做什么：处理#include指令，将指定的头文件内容插入到当前文件中，以便在编译时能够使用头文件中定义的内容 */


class Point
{
public:
    friend std::ostream &operator<<(std::ostream &os, const Point& point);

public:
    Point(int x, int y):m_x(x), m_y(y)
    {}
    Point operator+(const Point& point);

private:
    int m_x;
    int m_y;
};

Point Point::operator+(const Point &point)
{
    Point result(*this);
    result.m_x = this->m_x + point.m_x;
    result.m_y = this->m_y + point.m_y;

    return result;
}

/* 自定义输出格式 */
std::ostream &operator<<(std::ostream &os, const Point &point)
{
    os << "(" << point.m_x << "," << point.m_y << ")" ;
    return os;
}


int main()
{
    std :: cout << myAdd(10, 20) << std :: endl;
    std :: cout << myAdd<float>(12.1, 2.2) << std :: endl;

    Point p1(1, 1);
    Point p2(2, 2);

    Point p3 = p1 + p2;

    std :: cout << p3 << std :: endl;

}


