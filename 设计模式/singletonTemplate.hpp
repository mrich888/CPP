#ifndef __SINGLETEMPLATE
#define __SINGLETEMPLATE

#include <iostream>
#include <mutex>
#include <thread>

// 懒汉式 需要的时候创建 ---线程不安全
template <typename T> 
class Singleton
{
public:
    static T* getInstance()
    {
        std::lock_guard < std::mutex> lock(m);
        if (p == nullptr)
        {

            p =  new T(); 
        }
        return p;
    }

    void release()
    {
        delete p;
    }

protected:  //需要被继承用protect
    Singleton(){}
    static T *p ;
    static std::mutex m;

};

template <typename T> 
T * Singleton<T>::p = nullptr;

template <typename T> 
std::mutex Singleton<T>::m = std::mutex();


#endif//__SINGLETEMPLATE