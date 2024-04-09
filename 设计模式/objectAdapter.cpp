#include <iostream>

//对象适配器

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

class Adapter : public USB
{
public:
    void show()
    {
        c.show();
    }

private:
    TypeC c;

};


int main()
{
    USB *u = new Adapter;
    u->show();
    
    return 0;
}