#include <iostream>
#include <queue>

int main()
{
    std :: queue<int> q;
    /* 先全部放入队列中 */
    for (int idx = 0; idx <= 14; idx++)
    {
        q.push(idx);
    }
    
    int count = 0;
    while (q.size() > 1)
    {
        count++;
        int num = q.front();
        q.pop();
        /* 从队列中pop元素，若为3则出局，若不为3再将这个元素插入到队尾 */
        if (count == 3)
        {
            std :: cout << num << "出局\n";
            count = 0;
        }
        else
        {
            q.push(num);
        }
        
    }
    std :: cout << q.front() << "活了下来！\n";

    return 0;
}