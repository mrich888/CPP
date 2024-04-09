#include <iostream>

//房子
class House
{
public:
    virtual void show() = 0;
};

//普通房子
class SimpleHose : public House
{
public:
    void show()override
    {
        std::cout << "普通房子" << std::endl; 
    }

};

//高级房子
class HigherHose : public House
{
public:
    void show()override
    {
        std::cout << "高级房子" << std::endl; 
    }

};

//工厂 -- 建房子
class Factory
{
public:
    virtual House * createHouse() = 0;
};

//普通工厂 
class SimpeFactory : public Factory
{
public:
    House *createHouse() override
    {
        return new SimpleHose;
    }
};

//高级工厂
class HigherFactory : public Factory
{
public:
    House * createHouse() override
    {
        return new HigherHose;
    }
};

int main()
{
    Factory *f = new HigherFactory();
    House *h = f->createHouse();
    h->show();

    return 0;
}