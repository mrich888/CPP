#include <iostream>
#include <vector>
#include <algorithm>

//抽象策略类
class Sort
{
public:
    virtual void sort(std::vector<int> & v) = 0;

};

class BubbleSort : public Sort
{
public:
    void sort(std::vector<int> & v)
    {
        for (int idx = 0; idx < v.size(); idx++)
        {
            for (int jdx = 0; jdx < v.size() - idx; jdx++)
            {
                std::swap(v[jdx], v[jdx + 1]);
            }
        } 
        std::cout << "冒泡排序" <<std::endl;
    }
};

class FastSort : public Sort
{
public:
    void sort(std::vector<int> & v)
    {
        std::cout << "kp" <<std::endl;
        std::sort(v.begin(), v.end());
    }
};


int main()
{
    std::vector<int> v = {1,2,1,6,5};
    std::random_shuffle(v.begin(), v.end());

    std::for_each(v.begin(), v.end(), [](int num){std::cout<<num<<" ";});
    std::cout<<std::endl;

    Sort *s = new FastSort;
    s->sort(v);

    std::for_each(v.begin(), v.end(), [](int num){std::cout<<num<<" ";});
    std::cout<<std::endl;

    return 0;
}