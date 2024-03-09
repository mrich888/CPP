#include <iostream>

class Person
{
public:
    Person()
    {
        std :: cout << "Person()" << std :: endl;
    }
    virtual ~Person()
    {
        std :: cout << "~Person()" << std :: endl;
    }
    void run()
    {
        std :: cout << "run()" << std :: endl;
    }

private:
    int m_age;
};

class Student : public Person
{
public:
    Student()
    {
        std :: cout << "Student()" << std :: endl;
    }
    ~Student()
    {
        std :: cout << "~Student()" << std :: endl;
    }
    void run()
    {
        std :: cout << " run()" << std :: endl;
    }
    void study()
    {
        std :: cout << "study()" << std :: endl;
    }

private:
    int m_score;
};

int main()
{
    int *p = reinterpret_cast<int *>(100);
    std :: cout << "p:\t" << p << std :: endl;

    int num = reinterpret_cast<long>(p);
    std :: cout << "num:" << num << std :: endl;
}