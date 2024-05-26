#include <iostream>
#include <vector>

class Test
{
public:
    Test(){};
    Test(const Test& t)
    {
        std::cout<<"拷贝构造"<<std::endl;
    }

    //右值才能被夺走内存
    Test(Test && t)
    {
        std::cout<<"移动语义--移动构造函数\n";
    }


};

int main()
{
    Test t1;
    Test t2 = t1;
    Test t3 = std::move(t1);//把左值变成右值

    std::vector<int> v = {1, 2, 3};
    std::vector<int> v2 = std::move(v);
    
    std::cout<<v.size()<<std::endl;
    std::cout<<v2.size()<<std::endl;

    //左值引用
    int b = 10;
    int &a = b;

    //右值引用  -- 移动内存 
    int &&c = 10;
    return 0;

}
   