#include <iostream>

/* 单例 */
class Singleton
{
public:
    static Singleton* Instance()
    {
        static Singleton s;
        return &s;
    }
    ~Singleton()
    {
        std :: cout << "析构!\n";
    }

private:
    Singleton()
    {
        std :: cout << "构造!\n";
    }
};


int main()
{
    Singleton *s1 = Singleton :: Instance();
    Singleton *s2 = Singleton :: Instance();
    Singleton *s3 = Singleton :: Instance();
    std :: cout << s1 <<" " << s2 << " "<< s3 << std :: endl;
    //三次调用访问的是一个地址空间，也就是一次构造，一次析构

}