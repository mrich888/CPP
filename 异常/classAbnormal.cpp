#include <iostream>
#include <string>

#define BUFFER_SIZE 100000

/*
    抽象类 ：
        1、具有纯虚函数的类叫做抽象类。纯虚函数：虚函数初始化为0；
        2、抽象类不能实例化对象；
*/
/* 模拟exceptions */
class Exception
{
public:
    void play()
    {
        std :: cout << "play:" << std :: endl;
    }
public:
    virtual std :: string what() = 0;

};

class DivideException : public Exception
{
public:
    std :: string what() 
    {
        std :: cout << "不能除以0" << std :: endl;
        return "不能除以0";
    }

};
class MemoryFlowException : public Exception
{
public:
    std :: string what()
    {
        std :: cout << "内存溢出" << std :: endl;
        return "内存溢出";
    }

};
/* noexcept 同throw */
int myInvide(int val1, int val2) noexcept(false)
{
    if (val2 == 0)
    {
        throw DivideException();
    }
    
    return val1 / val2;
}

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
    virtual void run()
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
        std :: cout << "run()" << std :: endl;
    }

private:
    int m_score;
};

int simulateDynamic_castException()
{
    Person *p1 = new Person();
    Person *p2 = new Student();

    try
    {
        /* dynamic_cast 安全检查不算异常 */
        Student *stu1 = dynamic_cast<Student *>(p1);
    }
    catch(const std::exception& e)
    {
        std::cerr << "1:" << e.what() << '\n';
    }

    try
    {
        Student *stu2 = dynamic_cast<Student *>(p2);
    }
    catch(const std::exception& e)
    {
        std::cerr << "2:" << e.what() << '\n';
    }
    /* 记得释放 */
    delete p1;
    delete p2;

    return 0;
}




int main()
{
    // try
    // {
    //     int val1 = 100;
    //     int val2 = 2;
    //     int res = myInvide(val1, val2);
    //     std :: cout << res << std :: endl;
    // }
    // catch(const Exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }


    // for (int idx = 0; idx < BUFFER_SIZE; idx++)
    // {   
    //     try
    //     {
    //         std :: cout << "111" << std :: endl;
    //         int * num = new int[10000000000];
    //     }
    //         catch(const std::exception& e)
    //     {
    //         std::cerr<< "内存错错误" << e.what() << '\n';
    //         break;
    //     }
    // }
   
    simulateDynamic_castException();
    
    
    return 0;
}