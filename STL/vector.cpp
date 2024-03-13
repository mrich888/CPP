#include <iostream>
#include <vector>


void print(const std :: vector<int>& vec)
{
    std :: cout << vec.size() << std :: endl;
    for (auto ite = vec.begin();  ite != vec.end(); ite++)//迭代器更推荐使用这个遍历
    {
        std :: cout << *ite << std :: endl;
    }
    std :: cout << std :: endl;
}

int main()
{
    #if 0
    std :: vector<int> vec = {1, 2, 3, 4, 5, 6};//也可以无参构造
    std :: cout << vec.size() << std :: endl;
    for (int idx = 0; idx < vec.size(); idx++)
    {
        std :: cout << vec[idx] << std :: endl;
    }

    #else
    std :: vector<int> vec;//
    vec.push_back(1);//尾插
    vec.push_back(1);
    vec.push_back(1);

    vec.pop_back();//尾删

    vec.insert(vec.begin() + 1, 99);//插入，使用迭代器
    print(vec);

    vec.erase(vec.begin() + 1);//删除
    print(vec);

    std :: cout << vec.at(2)  << std :: endl;//at拿数据时，若越界系统会抛出异常 -- 底层是【】，但多了一个越界检查
    std :: cout << vec[2]  << std :: endl;//但[]不会进行越界检查
 
    #endif

    #if 0
    std :: vector<int> :: iterator ite = vec.begin();//相当于首元素指针
    #else
    auto ite = vec.begin();
    std :: cout << *ite << std :: endl;//*取值
    #endif

    auto ite_end = vec.end();
    std :: cout << *(ite_end - 1) << std :: endl;

    vec.resize(100);
    std :: cout << vec.capacity() << std :: endl;
    vec.shrink_to_fit();
    std :: cout << vec.capacity()  << std :: endl;   //在删除元素之后进行缩减容量至合适的大小（基本上是 = size）
    
}