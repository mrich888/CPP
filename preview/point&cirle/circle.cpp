#include <iostream>
#include "circle.h"

void circle :: setC(int x, int y, int r)
{
    m_center.setXY(x, y);
    m_r = r;
}

/* 跟圆心比较大小 */
bool circle :: judge(point &p)
{
    if (p.distance(m_center) <= m_r * m_r)
    {
        return true; /* 在圆内 */
    }
    else
    {
        return false;
    }  
}