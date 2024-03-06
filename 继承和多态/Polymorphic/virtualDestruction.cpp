#include <iostream>
#include <cstring>

class Person
{
public:
    Person()
    {
        std :: cout << "Person()" << std :: endl;
    }
    /* 虚析构 释放父类，才会调用子类的析构 */
    virtual ~Person()
    {
        std :: cout << "~Person()" << std :: endl;
    }
    /* 虚函数 */
    virtual void makeMoney()
    {
        std :: cout << "person -  makeMoney() -- " << std :: endl;
    }


private:
    int m_age;

};



class Student : public Person
{
public:
    Student(const char * name)
    {
        m_name = new char(15);
        strncpy(m_name, name, strlen(name) + 1);
        std :: cout << "Student ()" << std :: endl;
    }
    ~Student()
    {
        if (m_name)
        {
            delete []m_name;
        }
        std :: cout << " ~Student" << std :: endl;
    }
    void makeMoney()
    {
        Person :: makeMoney(); //调用父类的成员函数  若需求只比父类中的函数多一点点，就可以直接在调用父类的成员函数后添加需求 减少代码量
        std :: cout << "Student  -  makeMoney() -- 兼职" << std :: endl;
    }

private:
    int m_no;
    char * m_name;
};


int main()
{
    Person *per = new Student("zhangsan");
    
    delete per;

    return 0;
}