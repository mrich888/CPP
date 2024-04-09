#include <iostream>
#include <thread>

//饿汉式 初始化创建 线程安全

class Singleton
{
public:
    static Singleton* getInstance()
    {
        return p;
    }

    

private:
    Singleton(){}
    static Singleton *p ;

};

Singleton * Singleton :: p = new Singleton;

void createObj()
{
    auto p1 = Singleton::getInstance();
    printf("%x\n", p1);
}

int main()
{
    std::thread t[10];
    for (auto & thrd : t)
    {
        thrd = std::thread(createObj);
    }
    
    for (auto & thrd : t)
    {
       thrd.join();
    }

    return 0;   
}