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

    void shop()
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
        Person :: makeMoney(); //调用父类的成员函数  若需求只比父类中的函数多一点点，就可以直接在调用父类的成员函数后添加需求 减少代码量
        std :: cout << "Student  -  makeMoney() -- 兼职" << std :: endl;
    }
    void shop()
    {
        std :: cout << "Student  -  shop() -- " << std :: endl;
    }

    virtual void study()//这个虚函数和继承父类的虚函数的地址放在同一张虚表中
    {
        std :: cout << "Student  -  study() -- " << std :: endl;
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
    per->makeMoney(); 
    

    return 0;
}