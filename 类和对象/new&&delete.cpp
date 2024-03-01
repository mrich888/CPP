#include <iostream>
#include <cstring>

class Test
{
public:
    Test()
    {
        //p = new int;//函数结束会自动释放内存
        std :: cout << "无参构造\n";
    }

    Test(const Test& t)
    {
        // p = new int;
        // *p = *t.p;
        std :: cout << "拷贝构造\n";
    }

    ~Test()
    {
        //delete p;
        std :: cout << "析构函数\n";
    }

//private:
    //int *p;

};


/**3、
Test func()
{
    Test t;//创建名为t的对象
    return t; //将亡值
}
**/

/** 4、
Test& func()
{
    static Test t;//返回引用时需要确保返回的对象在函数结束后仍然有效，故+ static
    return t; //返回的是t的引用
}
**/

Test func(Test& t)
{
    return t;
}


int main()
{
    // Test *t = new Test();
    // Test *t1 = t;
    /**
    Test *t1 = (Test *)malloc(sizeof(Test));
    不会调用构造函数，同时free时也不会调用析构
    **/

    /** ⭐1、
        Test t;//名为t的对象，最后执行完释放
        Test();//匿名对象，生命周期只有一行代码
    **/

    /** ⭐2、
    Test t = Test();//先创建Test()对象,由于它无名本应该被释放但此时t成了它的名字，他就存活下来了
                    //在该过程中只执行了一次构造，然后进行了对象内容的拷贝，也就是把这个空间拷贝给了t，故这个空间以t的名字继续存活
    **/

    /** ⭐3、
    Test t = func();
    //一次构造和析构，不发生拷贝构造
    //本来是应该先调用func，再func中创建名为t的对象，然后返回的也是名为t的那段的地址空间
    //然后回到主函数中本应该发生拷贝构造的，但c++中可以实现优化函数返回值的拷贝（RVO），故将亡对象t的内存直接创建在了主函数中的对象t中
    //总的来说，虽然Test t的名字仍然是t，但实际上内存空间是在函数内部创建的临时对象，通过返回值优化直接构造在t所占用的内存空间中，而不是通过拷贝的方式得到的。
    **/    

    
    /** ⭐4、
    Test t = func();
    //首先再func中执行无参构造，然后返回引用
    //然后由于返回的是引用，故在t中实现的是拷贝构造 -- 深拷贝（如果没有写拷贝构造函数，系统也会自动执行拷贝构造 -- 浅拷贝）
    **/  

    /** ⭐4、
    Test t = func();
    //首先再func中执行无参构造，然后返回引用
    //然后由于返回的是引用，故在t中实现的是拷贝构造 -- 深拷贝（如果没有写拷贝构造函数，系统也会自动执行拷贝构造 -- 浅拷贝）
    **/  
   Test t1;
   Test t = func(t1);


   
}