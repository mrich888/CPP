#include <iostream>
#include <string>

//真正产品 -- 用来放产品
class Tea
{
public:
    virtual void show() = 0;

protected:
    std::string name;
};

//抽象装饰 -- 准备装饰谁
class  MilkTea : public Tea
{
public:
    MilkTea()
    {
        this->name = "奶茶";
    }

    void show() override
    {
        std::cout << name << std::endl;
    }
};

//真正装饰 -- 用来存放真正的装饰
class Decorate : public Tea
{
public:
    Decorate(Tea * milkTea)
    {
        this->milkTea = milkTea;
    }
   
protected:
    Tea * milkTea;

};

// 真真的装饰
class addZhenzhu : public Decorate
{
public:
    using Decorate::Decorate;
    void show()
    {
        std::cout << "珍珠";
        milkTea->show();
    }

};

class addYeguo : public Decorate
{
public:
    using Decorate::Decorate;
    void show()
    {
        std::cout << "椰果";
        milkTea->show();
    }

};

class addReaBean : public Decorate
{
public:
    using Decorate::Decorate;
    void show()
    {
        std::cout << "红豆";
        milkTea->show();
    }

};

int main()
{
    Tea * tea = new MilkTea;
    Decorate *z = new addZhenzhu(tea);
    Decorate *y = new addYeguo(z);
    tea->show();
    z->show();
    y->show();


    return 0;
}