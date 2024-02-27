#include <iostream>

enum COLOR
{
    black,
    white
};

enum RGB
{
    red,
    green,
    blue
};

int main()
{
    if (COLOR :: black == RGB :: red) //能够编译但会有警告，c++有更严格的类型控制
    {
        std :: cout << "equal" << std :: endl;
    }
    
}

