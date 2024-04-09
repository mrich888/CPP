#include <iostream>
#include <mutex>
#include <thread>

// 懒汉式 需要的时候创建 ---线程不安全

class Singleton
{
public:
    static Singleton* getInstance()
    {
        std::lock_guard < std::mutex> lock(m);
        if (p == nullptr)
        {

            p =  new Singleton; 
        }
        return p;
    }

    void release()
    {
        delete p;
    }

private:
    Singleton(){}
    static Singleton *p ;
    static std::mutex m;

};

Singleton * Singleton ::  p = new Singleton;

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