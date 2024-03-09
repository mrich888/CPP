#include <iostream>

class Test
{
public:
    static int count;//把它放到静态全局区,由该类的所有对象共享 
    Test()
    {
        count++;
        std :: cout << "构造函数" << std :: endl;

    }

    //析构函数
    ~Test()
    {
        count--;
        std :: cout << "析构函数" << std :: endl;
    }

    static void func() //static可以修饰跟类内私有属性无关的函数，以达到共享 静态函数跟内存无关，故不能访问私有属性
    {
        std :: cout << "hello word" << std :: endl;
    }

};

//静态函数变量的初始化
int Test :: count = 0;

int main()
{
    // Test t1;
    // t1.c = 10;
    // std :: cout << t1.c << std :: endl; //第一次使用 10

    // Test t2;
    // t2.c = 20;
    // std :: cout <<  t2.c << std :: endl; //第二次使用 20 

    // std :: cout << Test :: c << std :: endl; //保存第二次的结果 20
    Test *t1 = new Test();
    Test *t2 = new Test();

    delete t1;
    delete t2;

    std :: cout << Test :: count << std :: endl; //在构造中加1， 在析构中减1

    return 0;
}