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

//抽象工厂类
class Factory 
{
public:
    virtual Car * createCar() = 0;

};

class BenzFactroy: public Factory
{
public:
    virtual Car * createCar() override
    {
        return new BENZ();
    }
    
};

class Factory2
{
public:
    Factory * createBenzFactory()
    {
        return new BenzFactroy;
    }
};


int main()
{
    Factory2 f2;
    Factory *f = f2.createBenzFactory();

    Car * c = f->createCar();
    c->create();

    return 0;
}