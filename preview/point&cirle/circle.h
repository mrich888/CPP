#ifndef _cricle_h
#define _cricle_h

#include "point.h"

class circle
{
private:
    point m_center;
    int m_r;

public:
    void setC(int x, int y, int r);
    bool judge(point &p);
    // circle(/* args */);
    // ~circle();
};

// circle::circle(/* args */)
// {
// }

// circle::~circle()
// {
// }


#endif//_point_h