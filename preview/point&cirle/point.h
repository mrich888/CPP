#ifndef _point_h
#define _point_h

class point
{
private:
    int m_x;//横坐标
    int m_y;//纵坐标
    
public:

    void setXY(int x, int y);//获得点的位置
    int distance(point &p);//获得点到圆心的距离

    // point(/* args */);
    // ~point();
};

// point::point(/* args */)
// {
// }

// point::~point()
// {
// }


#endif//_point_h