#include <iostream>

#define BUFFER_SIZE 100000

/* 异常  */
void test01()
{
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {   
        /* try{}catch(){} */
        try
        {
            std :: cout << "111" << std :: endl;
            int * num = new int[1000000];
        }
        catch(...)/* ...捕捉任意异常 */
        {
            std :: cout << "内存不够" << std :: endl;
            break;
        }
        /* 如果程序出现异常，出现异常之后的代码就不会执行了 */
        /* 如果不处理异常，程序就会自动停止 */
      
    }
}


int myInvide(int val1, int val2)
{
    if (val2 == 0)
    {
        throw"除数不能为0";
    }
    
    return val1 / val2;
}

/* 进行异常声明为了团队开发 */
/* 异常声明：
    case1: 可能会抛出任何异常 -- 不建议 */
int func1()
{

}

int func1() noexcept(false) //可能会抛出
{

}

/* 异常声明：
    case2: 不抛出任何异常 */
int func2() throw()
{
    
}
int func3() noexcept
{
    
}
int func4() noexcept(true)//不抛出异常
{
    
}

#if 0
/* 异常声明：
    case3: 只可能抛出int double类型的异常 */
    /* 动态类型已不被支持，异常只能由抛异常和不抛异常，同noexcept */
int func1() throw(int, double)
{
    
}
#endif


int main()
{
    //test01();
    try
    {
        myInvide(100, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }   
    
}