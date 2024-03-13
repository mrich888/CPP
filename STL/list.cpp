#include <iostream>
#include <list>

template <typename T>
void print(const T& vec)
{
    std :: cout << vec.size() << std :: endl;
    for (auto ite = vec.begin();  ite != vec.end(); ite++)//迭代器更推荐使用这个遍历
    {
        std :: cout << *ite << "";
    }
    std :: cout << std :: endl;
}


int main()
{
    std :: list<int> l = {1, 2, 3};
    print(l);

    auto ite = l.begin();
    for (int i = 0; i < 3; i++)
    {
        ite++;//不能直接找到位置但是可以一个一个走，next
    }
    
    l.reverse();//链表逆序

    return 0;
}