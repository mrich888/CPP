#include <iostream>

class Drink
{
public:
    virtual void Boil() = 0;
    virtual void Brew() = 0;
    virtual void PutSomethting() = 0;

    void MakeDrink()
    {
        Boil();
        Brew();
        PutSomethting();
    }

};

class Coffee : public Drink
{
public:
    void Boil()
    {
        std::cout << " 烧水 " << std::endl;
    }
    void  Brew()
    {
        std::cout << " 倒咖啡粉 " << std::endl;
    }

    void PutSomethting()
    {
        std::cout << " 加糖 " << std::endl;
    }
};

class MilkTea: public Drink
{
public:
    void Boil()
    {
        std::cout << " 烧水 " << std::endl;
    }
    void  Brew()
    {
        std::cout << " 倒奶茶粉 " << std::endl;
    }

    void PutSomethting()
    {
        std::cout << " 加珍珠 " << std::endl;
    }
};

int main()
{
    Drink *d = new Coffee;
    d->MakeDrink();


    return 0;
}