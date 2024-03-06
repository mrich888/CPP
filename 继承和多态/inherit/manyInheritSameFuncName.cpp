#include <iostream>
using namespace std;
#include <stdio.h>

/* 无参构造函数想调用有参构造函数必须使用初始化列表. */

class Worker
{
public:
    Worker(int sarary) : m_sarary(sarary)
    {
        cout << "Worker(int sarary)" << endl;
    }

    void makeMoney()
    {
        cout << "Worker makeMoney" << endl;
    }
public:
    long m_sarary;
};

class Student
{
public:
    Student(int score) : m_sarary(score)
    {
        cout << "Student(int score)" << endl;
    }

    void makeMoney()
    {
        cout << "Student makeMoney" << endl;
    }
public:
    long m_sarary;
};


/* 多继承 */
class Undergraduate : public Student,  public Worker
{
public:
    Undergraduate(int score, int sarary, int grade) : Student(score), Worker(sarary), m_sarary(grade)
    {
        cout << "Undergraduate()" << endl;
    }
    ~Undergraduate()
    {
        cout << "~Undergraduate()" << endl;
    }

    void makeMoney()
    {
        cout << "Undergraduate makeMoney" << endl;
    }
public:
    long m_sarary;
};


int main()
{
    Undergraduate ug(90, 8000, 10);
    /* 同名函数 */
    ug.makeMoney();
    ug.Student :: makeMoney();
    ug.Worker :: makeMoney();

    /* 同名变量 */
    ug.m_sarary;
    ug.Student :: m_sarary;
    ug.Worker :: m_sarary;

    return 0;
}