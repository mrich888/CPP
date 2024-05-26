#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::condition_variable v;

void print(int num)
{
    v.notify_all();//唤醒所有线程
}

std::mutex m;
void print(int a)
{
    std::lock_guard < std::mutex> lock(m);//自动加锁解锁

    std::unique_lock< std::mutex> lock(m);//可以手动解锁
    //m.lock();
    std::cout << "he" << a << std::endl;
    //m.unlock();

}


int main()
{   
    // std::thread t(print, 10); //可变参数
    // std::cout<< t.get_id() <<std::endl;
    // std::cout<< std::this_thread::get_id() <<std::endl;

    //t.detach();

    // if (t.joinable() == true)
    // {
    //     t.join();
    // }
    
    //std::cout<< std::thread::hardware_concurrency() <<std::endl;

    int i;
    std::thread t1[10];
    for (auto &thread : t1)
    {
        i++;
        thread = std::thread(print, i);//右值引用 - 移动语义
    }
    

    return 0;
}

