#include <iostream>
#include <cmath>

/* 求最大公约数 */
int gcd(int x, int y)
{
    int max = std :: max(x, y);
    int min = std :: min(x, y);
    int r = max % min;
    while (r != 0)
    {
        max = min;
        min = r;
        r = max % min;
    }
    return min;
}

class Line;
class Point
{
public:
    friend double Distance(const Point& p1, const Point& p2);
    friend class Line;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void show()
    {
        std :: cout << "(" << x << "," << y << ")" << std :: endl;
    }
    ~Point();


private:
    int x;
    int y;
};

Point::~Point()
{
}

double Distance(const Point& p1, const Point& p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

class Line
{
private:
    double A;
    double B;
    double C;

public:
    //一般公式
    Line(double A, double B, double C):A(A), B(B), C(C)
    {}
    //两点求直线
    Line(const Point& p1, const Point& p2)
    {
        A = p1.y - p2.y;
        B = p2.x - p1.y;
        C = p1.x * p2.y - p1.y * p2.x;

        int r = gcd(gcd(A, B), C);
        std :: cout << r << std :: endl;
        A /= r;
        B /= r;
        C /= r;
    }
    void show()
    {
        if (A == 1 && B != 1)
        {
            std :: cout<< "x+" << B << "y+" << C << "=0" << std :: endl;
        }
        else if (B == 1 && A != 1)
        {
            std :: cout<< "x+" <<"y+" << C << "=0" << std :: endl;
        }
        
        
        std :: cout << A << "x+" << B << "y+" << std :: endl;
    }

    double Distan(const Point& p)
    {
        double distance = 1.0 * abs(A * p.x + B * p.y) / (sqrt(A * A + B * B));
    }
    ~Line();
};

Line::~Line()
{
}


int main()
{
    Point p1(1, 1);
    Point p2(2, 2);
    Line l1(p1, p2);
    l1.show();

    l1.Distan(p1);
    std :: cout << Distance(p1, p2) << std :: endl;

}
