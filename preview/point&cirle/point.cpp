#include <iostream>
#include "point.h"

/* 获取点的位置 */
void point :: setXY(int x, int y)
{
    m_x = x;
    m_y = y;
}

/* 获取两点的距离 */
int point :: distance(point &p)
{
    int dis = (p.m_x - m_x) * (p.m_x + m_x) + (p.m_y - m_y) * (p.m_y + m_y);
    return dis;
}