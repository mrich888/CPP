#include <istream>
#include <cstring>

class Point
{
public:
    friend std::ostream &operator<<(std::ostream &os, const Point& point)
    {
        os << "(" << point.m_x << "," << point.m_y << ")" ;
        return os;
    }

public:
    Point(int x, int y):m_x(x), m_y(y)
    {}
    Point operator+(const Point& point)
    {
        Point result(*this);
        result.m_x = this->m_x + point.m_x;
        result.m_y = this->m_y + point.m_y;

        return result;
    }

private:
    int m_x;
    int m_y;
};

template <typename Item>
class Array
{
public:
    Array(): Array(def_capacity){};//无参构造调用有参构造
    Array(int capacity)
    {
        if (capacity <= def_value )
        {
            capacity = def_capacity;
        }
        m_data = new Item[capacity];
        /* 清空脏数据 */
        memset(m_data, 0, sizeof(Item) * capacity);
        m_size = 0;
        m_capacity = capacity;
    }
    /* todo.........用c++的提示看一下都有哪些接口 */
    void add(Item value);
    void insert(int index, Item value);
    void get(int index);
    

    /* 重载 */
    Item operator[](int index);

    friend std :: ostream &operator<<(std :: ostream &os, const Array& array);
    
private:
    Item * m_data;
    int m_size;
    int m_capacity;
    const int def_value = 0;
    const int def_capacity = 0;
};

template <typename Item>
void Array<Item>::insert(int index, Item value)
{
}

template <typename Item> // 类模板，类外定义需要带着template
void Array<Item>::get(int index)
{
}

template <typename Item>
Item  Array<Item>::operator[](int index)
{
    if (index < 0 || index >= this->m_size)
    {
        return
    }
    
    return this->m_data[index];
}

template <typename Item>
std :: ostream &operator<<(std :: ostream &os, const Array<Item>& array)
{
    for(int idx = 0; idx < this.m_size; idx++)
    {
        os << array.m_data[idx] << std :: endl;
    }
}

int main()
{
    Array<int> array1;

}

