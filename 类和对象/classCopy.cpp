#include <iostream>

class Student
{
public:
    //无参构造
    Student(){}

    //带参构造
    Student(int age, const std :: string& name)
    {
        m_age = age;
        m_name = name;
        std :: cout << "带参构造！\n";
    }

    //拷贝构造 : 不能直接传类，而应该传类的引用
    Student(const Student& s)
    {
        std :: cout << "拷贝构造函数"<< std :: endl;
        m_age = s.m_age;
        m_name = s.m_name;
    }

    //赋值重载函数
    void operator = (const Student& s)
    {
        std :: cout << "赋值运算符的重载" << std :: endl;
        m_age = s.m_age;
        m_name = s.m_name;
    }

    //析构函数
    ~Student()
    {
        std :: cout << "析构函数" << std :: endl;
    }

    //类内声明
    void SetAge(int age);
    int GetAge();
    /* const 解决不能传递右值的问题 */
    void SetName(const std :: string& name);
    std :: string GetName();

private:
    int m_age;
    std :: string m_name;
};

// 类外声明
void Student::SetAge(int age)
{
    m_age = age;
}

int Student::GetAge()
{
    return m_age;
}

void Student::SetName(const std::string &name)
{
    m_name = name;
}

std :: string Student :: GetName()
{
    return m_name;
}

int main()
{
    Student s(10, "zhangsan");
    Student s1(s); //s1 = s; // 拷贝构造

    Student s2;//先执行无参构造
    s2 = s; //在进行赋值运算服的重载函数 默认生成
    
    std :: cout << s.GetAge() << std :: endl;
}
class classCopy
{
private:
    /* data */
public:
    classCopy(/* args */);
    ~classCopy();
};

classCopy::classCopy(/* args */)
{
}

classCopy::~classCopy()
{
}
