#include <iostream>
#include <set>

//使用类对不同的需求进行扩展 -- 仿函数 -- 在不改变函数的情况下，添加成员变量并在构造函数中赋值
class Func
{
public:
    Func(int n):m_n(n)
    {}
    bool operator()(int num)
    {
        return num > 3 && (num % m_n == 0);
    }
    ~Func()
    {}

private:
    int m_n;
};



#if 0
bool isGreaterThan(int number)
{
    return number;
}
#endif

int count(int *num, int size, Func f)
{
    int count = 0;
    for(int idx = 0; idx < size; idx++)
    {
        if (f(num[idx]) == true)
        {
            count++;
        }   
    }
    return count;
}


int main()
{
    int num[] = {1, 2, 3, 6, 7};
    Func func1(2);
    std::cout<<count(num, 4, func1)<<std::endl;

    //排序函数
    // std::set<int, std::greater<int>> s;//std::greater仿函数，set默认没有第二个参数，故从小到大排序 重载了<>
    // s.insert(1);
    // s.insert(1);
    // s.insert(1);
    // for (auto ite = s.begin(); ite != s.end(); ite++)
    // {
    //     std :: cout << *ite << std :: endl;
    // }
    
    return 0;
}