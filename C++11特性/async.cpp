#include <iostream>
#include <thread>
#include <future>

void print()
{
    std::cout<< " " <<std::endl;
}

int main()
{
    auto f = std::async(std::launch::deferred, print);//同步

    std::cout<< "main" << std::endl;

    f.get();

    return 0;

}