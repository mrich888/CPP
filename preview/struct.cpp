#include <iostream>
#include <cstring>

#if 0
struct student
{
    char *name;
    int age;
};

using stu = student;

/* 打印 */
void printStu(stu &stu)
{
   // std :: cout << "%s的年龄:%s\n" <<
   printf( "%s的年龄:%d\n", stu.name, stu.age);
}

int main()
{
    stu stu1;
    stu1.name = new char[10];
    strcpy(stu1.name, "zhangsan");
    stu1.age = 22;

    printStu(stu1);

    delete []stu1.name;
    
}

#else
/* 将以上形式打包成类 */
class Student
{

public:

    char *name;
    int age;

    /* 对类内部的成员执行操作 */
    void printStu()
    {
    // std :: cout << "%s的年龄:%s\n" <<
    printf( "%s的年龄:%d\n", name, age);
    }

};

int main()
{
    /* 定义一个类的对象：类不占空间，但对象占内存空间 */
    Student stu1;
    stu1.name = new char[10];
    strcpy(stu1.name, "zhangsan");
    stu1.age = 22;
    stu1.printStu();

    delete []stu1.name;
    
}


#endif