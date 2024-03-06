#include <iostream>

/* 无参构造函数想调用有参构造函数，必须使用初始化列表 */
class Person
{
public:
    /* 使用无参构造时我们希望将成员变量进行初始化 -- 故需要调用有参函数 --且必须要使用初始化列表调用有参构造
      -- 不能在一个构造函数中直接调用另一个构造函数 （匿名函数）*/
    Person() : Person(0)
    {
        std :: cout << "Person(): Person(0)" << std :: endl;
    }
    /* 有参构造 -- 用输入值进行初始化 */
    Person(int age) : m_age(age)
    {
        std :: cout << "Person(int age) : m_age(age)" << std :: endl;
    }

    ~Person(){};

private:
    int m_age;

};

class Student : public Person
{
public:
    /* 无参构造 */
    Student() : Student(0, 0)
    {
        std :: cout << " Student() : Student(0, 0)" << std :: endl;
    }

    /* 初始化列表可以拿到 */
    Student(int age, int no) : Person(30), m_no(3)
    {
       std :: cout << "Student(int age, int no) : Person(30), m_no(3)" << std :: endl;
    }

    #if 0
    Student(int age, int no) : m_age(age), m_no(no)
    {
       /* 私有属性子类拿不到 */
    }
    Student(int age, int no) 
    {
        /* 出错 -- 因为私有的拿不到 */
        m_age = age;
        m_no = no;
    }
    #endif
    ~Student(){};

private:
    int m_no;

};


int main()
{
    Student stu(22, 3);
    return 0;
}