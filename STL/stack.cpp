#include <iostream>
#include <stack>


int main()
{
    std :: stack<int> s;
    

    while (s.empty() == false)
    {
        int a = s.top();//拿到栈顶元素. 返回值是引用，故直接拿对象
        s.pop();
    }
    

    return 0;
}