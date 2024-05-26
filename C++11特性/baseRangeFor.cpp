#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::vector<int> v = {1, 2, 3, 4};
    for(auto value : v)
    {
        std::cout << value << std::endl;
    }


    std::vector<std::string> v2 = {"abc"," b"," b", "c"};
    for(auto value : v2)
    {
        std::cout << value << std::endl;
    }

    std::vector<int> v3 = {1, 2, 3, 4};
    for(auto &value : v3)
    {
        value++;
        std::cout << value << std::endl;
    }

    std::map<int,std::string> mp = 
    {
        {1, "zhangsan"},
        {2, "lisi"},
        {3, "wangwu"},
    };
    for(auto &value : mp)
    {
        std::cout << value.first<< " " << value.second <<std::endl;
    }

    return 0;
}