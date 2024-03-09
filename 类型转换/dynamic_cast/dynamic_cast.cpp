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
    Person *p1 = new Person(); //自己指自己
    Person *p2 = new Student();//父类指向子类

    /* 错误示范 */
    //Student * stu1 = p1;

    /* C-强转 */
    // Student * stu1 = (Student *)p1;
    // stu1->run();
    // Student * stu2 = (Student *)p2;//其中子类指针指向父类指针没有使用dynamic_cast或许会踩内存【因为没有约束】
    // stu2->run();

    /* C++ -- dynamic强转 */
    // dynamic -- 运行时有安全检测
    Student * stu1 = dynamic_cast<Student *>(p1); //子类不能指向父类，地址空间为0
    std :: cout << "stu1:" << stu1 <<std :: endl;
    
    Student * stu2 = dynamic_cast<Student *>(p2);
    std :: cout << "stu2:" << stu2 <<std :: endl;

}