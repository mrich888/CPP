#include <iostream>

class USB
{
public:
    virtual void show()
    {
        std::cout << "USB接口" << std::endl;
    }
};


class TypeC
{
public:
    virtual void show()
    {
        std::cout << "TypeC接口" << std::endl;
    }
};

class Adapter : public USB, public TypeC
{
public:
    void show()
    {
        TypeC::show();
    }

};


int main()
{
    USB *u = new Adapter;
    u->show();
    
    return 0;
}