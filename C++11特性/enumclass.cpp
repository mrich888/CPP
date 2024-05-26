#include <iostream>

enum color //位域
{
    red,
    blue,
    green
};

enum thickness
{
    thin,
    fat
};

int main()
{
    std :: cout << sizeof(color::red) << std :: endl;

    return 0;
}