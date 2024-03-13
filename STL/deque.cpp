#include <iostream>
#include <deque>

template <typename T>
void print(const T& vec)
{
    std :: cout << vec.size() << std :: endl;
    for (auto ite = vec.begin();  ite != vec.end(); ite++)//迭代器更推荐使用这个遍历
    {
        std :: cout << *ite << "";
    }
    std :: cout << std :: endl;
};


int main()
{
    std :: deque<int> d;
    d.push_back(1);
    d.push_front(1);

    d.pop_back();
    d.pop_front();

    print(d);

    return 0;
}