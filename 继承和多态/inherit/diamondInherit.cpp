#include <iostream>

class Person
{
public:
    int m_age;
    int m_age1;
    int m_age2;
    int m_age3;
    int m_age4;

    int m_age5;
};

class Student : virtual public Person
{
public:
    int m_score;
};

class Worker : virtual public Person
{
public:
    int m_sarary;

};

class Undergraduate : public Student,public Worker//菱形继承会发生冗余，用虚继承解决 
{
public:
    int m_grade;
};

int main()
{
    Undergraduate ug;
    std :: cout << sizeof(ug) << std :: endl;//菱形继承会发生冗余，用虚继承解决
    //--- 虽然多了一个虚表地址的内存空间，但当继承的父类的成员变量特别多的时候优势就很突出了
}