#include <iostream>

class Person
{
public:
    Person()
    {
        std :: cout << "Person()" << std :: endl;
    }
    ~Person()
    {

    }
    /* 虚函数 */
    virtual void makeMoney()
    {
        std :: cout << "person -  makeMoney() -- " << std :: endl;
    }

    virtual void shop()
    {
        std :: cout << "person -  shop() -- " << std :: endl;
    }

private:
    int m_age;
};



class Student : public Person
{
public:
    Student()
    {
        std :: cout << "Student ()" << std :: endl;
    }
    ~Student()
    {

    }
    void makeMoney()
    {
        std :: cout << "Student  -  makeMoney() -- 兼职" << std :: endl;
    }
    virtual void shop()
    {
        std :: cout << "Student  -  shop() -- " << std :: endl;
    }



private:
    int m_no;
};

class Teacher : public Person
{
public:
    Teacher()
    {
        std :: cout << "Teacher()" << std :: endl;
    }
    ~Teacher()
    {
        
    }
    void makeMoney()
    {
        std :: cout << "Teacher -  makeMoney() --出书 " << std :: endl;
    }
    virtual void shop()
    {
        std :: cout << "Teacher -  shop() -- " << std :: endl;
    }

private:
    int m_hair;

};

int main()
{
    Person *per = new Student();
    per->makeMoney(); //在person中用virtual修饰了makeMoney()函数，所以实现了stduent和teacher的makeMoney的重写override

    per = new Teacher();
    per->makeMoney();

    return 0;
}