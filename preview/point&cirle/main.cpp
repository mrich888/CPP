#include <iostream>
#include "point.h"
#include "circle.h"


int main()
{
    /* 创建点的对象，输入想要判断的点 */
    point point1;
    point1.setXY(1,2);

    /* 创建圆的对象，输入想要判断的圆心和半径 */
    circle cricle1;
    cricle1.setC(3, 5, 1);

    if (cricle1.judge(point1))
    {
        std :: cout << "该点在圆内" << std :: endl;
    }
    else
    {
        std :: cout << "该点不在圆内" << std :: endl;
    }
    


}