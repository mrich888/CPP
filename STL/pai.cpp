#include <iostream>
#include <map>
#include <set>

struct Student
{
    int id;
    std :: string name;
};


int main()
{
    std :: pair<int,Student> s;
    s.first = 1;
    s.second = {1, "lyf"};

    // std :: pair<int,Student> s1 = {1, {1, "lyf"}};
    // std :: pair<int,Student> s2 = std :: make_pair<int,Student>(2, {2, "zhangsan"});
    
    //std :: set<std :: pair<int,Student>> p;//排序


    std :: map<int,Student> p1;//不能插入相同的，根据firs排序
    p1.insert({1, {1, "zhangsan"}});
    p1.insert(s);
    p1[4] = {4, "wangwu"};//若序号相同，怎会覆盖

    p1.find();


    for (auto ite = p1.begin(); ite != p1.end(); ite++)
    {
        std :: cout << ite->first << " " << ite->second.id  << " " << ite->second.name << std :: endl; 
    }
    

    return 0;
}