#include <iostream>

class Person
{
public:
    Person();
    void run();
    ~Person();

public:
    int m_age;
};

class Student : public Person
{
public:
    Student();
    void study();
    ~Student();

public:
    int m_no; 
};

Student::Student()
{
}

Student::~Student()
{
}


Person::Person()
{
}

void Person::run()
{
    std :: cout << "Person::run()" << std :: endl;
}

Person::~Person()
{
}

void Student::study()
{
    std :: cout << "Person::stduy()" << std :: endl;
}

int main()
{
    Person person;
    std :: cout << "sizeof person:" << sizeof(person) << std :: endl;
    Student student;
    student.m_age = 22;
    student.m_no = 111;
    std :: cout << "sizeof person:" << sizeof(student) << std :: endl;
    std :: cout << "student.age:" << student.m_age    << "student.no:" << student.m_no << std :: endl;
};
