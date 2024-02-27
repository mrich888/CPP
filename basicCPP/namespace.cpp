#include <iostream>
#include <cstring> //要想用c的头文件，去掉.h

/* using namespace std; 避免使用，没有办法区分c和c++的库 */

#if 0

namespace A
{
    void InsertTail()
    {
        // :: / :   域解析符
        std :: cout << "first" << std :: endl;
    }
    int a = 10;
    
}

namespace B
{
    void InsertTail()
    {
        // :: / :   域解析符
        std :: cout << "first" << std :: endl;
    }
    int a = 20;
}

int main()
{
    using namespace A;//using的使用范围越小越好
    InsertTail();
    std :: cout << a << std :: endl;
    // 两种使用方式
    B :: InsertTail();
    std :: cout << B :: a << std :: endl; 

    return 0;
}
#else

namespace A
{
    void InsertTail()
    {
        // :: / :   域解析符
        std :: cout << "first" << std :: endl;
    }
    int a = 10;

    namespace B
    {
        void InsertTail()
        {
            // :: / :   域解析符
            std :: cout << "second" << std :: endl;
        }
        int a = 20;
    }
    
}


int main()
{
    using namespace A;//using的使用范围越小越好
    InsertTail();
    std :: cout << a << std :: endl;
    //命名空间的嵌套
    std :: cout << A :: B :: a << std :: endl; 

    return 0;
}
#endif