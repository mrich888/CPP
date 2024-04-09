#include <iostream>

//具体产品
class   Car
{
public :
    virtual void show() = 0;

protected:
    std::string name;
};

//抽象装饰
class BMW: public  Car
{
private:
    /* data */
public:
    BMW()
    {
        this->name = "宝马";
    }

    void show()
    {
        std::cout << name << std::endl; 
    }
};

//具体装饰
class Decorate : public  Car
{
public: 
    Decorate(Car *c)
    {
        this->c = c;
    }

protected:
    Car * c;
};

class Navigator : public Decorate
{
public:
    using Decorate :: Decorate;
    void show()
    {
        std::cout<< "导航";
        c->show();
    }
};

class SelfDriver : public Decorate
{
public:
    using Decorate :: Decorate;
    void show()
    {
        std::cout<< "自动驾驶";
        c->show();
    }
};

class control : public Decorate
{
public:
    using Decorate :: Decorate;
    void show()
    {
        std::cout<< "语音控制";
        c->show();
    }
};


int main()
{
    Car *c = new BMW;
    Decorate *s = new SelfDriver(c);
    Decorate *d = new Navigator(s);
    Decorate * t = new control(d);
    
    t->show();

    return 0;
}