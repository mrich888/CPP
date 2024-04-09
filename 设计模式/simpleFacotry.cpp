#include <iostream>

class Car
{
public:
    virtual void create() = 0;
};

class BENZ : public Car
{
public:
    void create()
    {
        std::cout << "创benz" << std::endl;
    }
};

class BYD : public Car
{
public:
    void create()
    {
        std::cout << "创byd" << std::endl;
    }
};

//解耦
class Factory
{
public:
    Car * createBenz()
    {
        return new BENZ();
    }
};




int main()
{
    Factory f;
    Car * c = f.createBenz();
    c->create();


    return 0;
}