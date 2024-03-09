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
    char str[] = "hello world";
#if 0
    /* const 转非const */
    char * buffer = const_cast<char *>(str);
#elif 0
    /* 错误使用场景 */
    char * buffer = dynamic_cast<char *>(str);
#elif 1
    /* 非const转const -- 没有安全性转化 */
    const char * buffer = static_cast<const char *>(str);
    std :: cout <<  buffer  << std :: endl;

    int num = 100;
    const int num1 = static_cast<const int&>(num);
    std :: cout <<  num1  << std :: endl;

#endif
}