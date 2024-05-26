#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>

std::mutex m;

std::atomic<int> count = 0;//线程安全  原子量 
void add()
{
    for (int idx = 0; idx < 1000; idx++)
    {
        //std::lock_guard<std::mutex> lock(m);//加锁运行时间变长，性能开销较高
        count++;
    }
}

int main()
{
    
    std::thread t1(add);
    std::thread t2(add);

    t1.join();
    t2.join();
    std::cout << count << std::endl;

}