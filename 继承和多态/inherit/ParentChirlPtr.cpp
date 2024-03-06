#include <iostream>
using namespace std;
#include <stdio.h>

/* 无参构造函数想调用有参构造函数必须使用初始化列表. */
class Person
{
public:
    Person()
    {
        cout << "Person()" << endl;
    }

    void printInfo()
    {
        printf("this:%p\n", this);

        cout << "m_age:" << m_age << endl;
    }
public:
    int m_age;
};

class Student : public Person
{
public:
    Student() 
    {
        cout << "Student()" << endl;
    }

    void printInfo()
    {
        printf("this:%p\n", this);

        cout << "m_age:" << m_age << "\tm_no:" << m_no << endl;
    }
public:
    int m_no;
};


int main()
{
    #if 1
    /* 父类指针指向子类 */
    Person * per = new Student();
    per->m_age = 60;
    per->printInfo();
    #endif 

    #if 1
    /* 子类指针指向父类对象是不合法的 */
    Student * pStu = (Student *)new Person();
    pStu->m_age = 30;
    pStu->m_no  = 10;
    pStu->printInfo();
    #endif

    
    return 0;
}