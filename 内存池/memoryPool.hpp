#include <iostream>
#include <cstring>

//重载new
#define MEMORYPOOL(T, COUNT) void* operator new(size_t size)\
{\
    std::cout<< "重载new\n";\
    return MemoryPool<sizeof(T), 1024>::globalInstance()->malloc();\
}\
void operator delete(void *p)\
{\
    std::cout<< "重载delete\n";\
    return MemoryPool<sizeof(T), 1024>::globalInstance()->free(p);\
}\


template<int NODESIZE, int NODECOUNT>
// #define NODESIZE 8
// #define NODECOUNT 1024

class MemoryPool
{
public:
    static MemoryPool * globalInstance()
    {
        static MemoryPool pool;
        return &pool;
    }

    void * malloc();//分配
    void free(void *p);//收回空间
   
    ~MemoryPool()
    {
        nodeHeader = nullptr;
        //释放大内存
        while (blockHeader != nullptr)
        {
            auto ptr = blockHeader->next;
            delete blockHeader;
            blockHeader = ptr;
        }
    }

private:
    MemoryPool()
    {
        nodeHeader = nullptr;
        blockHeader = nullptr;
    }

    union freeNode//指针于数据域用以片内存空间
    {
        char data[NODESIZE];
        freeNode *next;//嵌入式指针，提高利用率
    };

    struct memBlock//大块内存
    {
        freeNode node[NODECOUNT];
        memBlock *next;
    };

    freeNode * nodeHeader;
    memBlock * blockHeader;
};

template<int NODESIZE, int NODECOUNT>

void *MemoryPool<NODESIZE, NODECOUNT>::malloc()
{
    if (nodeHeader == nullptr)
    {
        memBlock * newBlock = new memBlock;
        //把大内存块的小内存都连接起来
        for (int idx = 0; idx < NODECOUNT - 1; idx++)
        {
            newBlock->node[idx].next = &newBlock->node[idx + 1];
        }
        newBlock->node[NODECOUNT - 1].next = nullptr;

        //头插
        newBlock->next = blockHeader;
        blockHeader = newBlock;
        //把大内存的第一个节点地址给到nedeheader
        nodeHeader = blockHeader->node;

    }
    auto ptr = nodeHeader;
    nodeHeader = nodeHeader->next;
    
    memset(ptr, 0, NODESIZE);
    return ptr;

}

template<int NODESIZE, int NODECOUNT>
void MemoryPool<NODESIZE, NODECOUNT>::free(void *p)
{
    freeNode *node = static_cast<freeNode *>(p);
    memset(node, 0, NODESIZE);
    //头插
    node->next = nodeHeader;
    nodeHeader = node;
}



// class Test
// {
// public:
//     Test()
//     {
//         std::cout<<"构造函数！\n";
//     }

//     MEMORYPOOL(Test, 1024);//侵入式槽

//     ~Test()
//     {}


//     int a;
// };

// int main()
// {
//     Test *t = new Test;
//     t->a =10;
//     std::cout<< t->a << std::endl;

//     delete t;
//     return 0;
// }

