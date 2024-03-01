#include <iostream>

class Student
{
public:
    //无参构造
    Student()
    {
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
    {
        m_age = age;
    }

}

int Student::GetAge()
{
    {
        return m_age;
    }
}

void Student::SetName(const std::string &name)
{
    {
        m_name = name;
    }

}

std :: string Student :: GetName()
{

}

int main()
{
    Student s;
    s.SetAge(10);
    std :: cout << s.GetAge() << std :: endl;
}
