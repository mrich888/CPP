#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <functional>

//任务结构体
struct Task
{
    std::function<void()> func;
};

//任务队列类
class TaskQueue
{
public:
    TaskQueue();
    
    //添加任务到队列
    void addTask(const Task& task);
    //获取队列中的任务
    Task getTask();
    
    ~TaskQueue();

private:
    std::queue<int> taskQueue;//存储任务  -- 任务是什么？
    mutable std::mutex mutexBusy;//任务队列的互斥锁
    std::condition_variable condition;//条件变量，用于线程等待和唤醒

};

TaskQueue::TaskQueue(/* args */)
{
}

void TaskQueue::addTask(const Task &task)
{
    
}

Task TaskQueue::getTask()
{
    return Task();
}

TaskQueue::~TaskQueue()
{
}


class ThreadPool
{
public:
    //线程池单例
    static ThreadPool& getInstance()
    {
        static ThreadPool instance;
        return instance;
    }
    //禁止复制和赋值
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;

    bool init(int minThreads,  int maxThreads,  int queueCapacity);
    bool addTask();

    ~ThreadPool();


private:



    ThreadPool();
};

ThreadPool::ThreadPool()
{
}

//线程池初始化
bool ThreadPool::init(int minThreads, int maxThreads, int queueCapacity)
{
    return false;
}

ThreadPool::~ThreadPool()
{
}
