#include <iostream>
#include <set>

template <typename T>
void print(const T& vec)
{
    std :: cout << "size:" << vec.size() << std :: endl;
    for (auto ite = vec.begin();  ite != vec.end(); ite++)//迭代器更推荐使用这个遍历
    {
        std :: cout << *ite << " ";
    }
    std :: cout << std :: endl;
}

int main()
{
    std :: set<int> s;
    s.insert(9);
    s.insert(5);
    s.insert(4);
    print(s);

    auto ite = s.find(2);
    std :: cout << *ite << std :: endl;

    //s.count();看元素是否存在

    std ::multiset <int> s1;//允许插入重复值


    return 0;
}