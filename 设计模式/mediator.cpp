#include <iostream>

class House;

//抽象中介者
class Mediator
{
public:
    void setHouse(House *sell, House* buy)
    {
        h1 = sell;
        h2 = buy;
    }

    virtual void sendMsg(const std::string& msg, House *h) = 0;

protected:
    House * h1;
    House * h2;
};

class House
{
public:
    House(Mediator *m):m(m){}
    virtual void sendMsg(const std::string& msg) = 0;
    virtual void RecvMsg(const std::string& msg) = 0;
protected:
    Mediator *m;
};

class SellHouse : public House
{
public:
    using House::House;
    void sendMsg(const std::string& msg)
    {
        m->sendMsg(msg, this);
    }
    void RecvMsg(const std::string& msg)
    {
        std::cout << " 卖房子的人收到消息 " << std::endl;
    }
protected:
    Mediator *m;
};

class  BuyHouse : public House
{
public:
    using House::House;
    void sendMsg(const std::string& msg)
    {
        m->sendMsg(msg, this);
    }
    void RecvMsg(const std::string& msg)
    {
        std::cout << " 买房子的人收到消息 " << std::endl;
    }
protected:
    Mediator *m;
};

class ConcretMediator : public Mediator 
{
public:

    void sendMsg(const std::string& msg, House *h)
    {
        if (h == h1)
        {
            h2->RecvMsg(msg);
        }
        else
        {
            h1->RecvMsg(msg);
        }   
    }
    void RecvMsg(const std::string& msg)
    {
        std::cout << " 卖子的人收到消息 " << std::endl;
    }
};

int main()
{
    Mediator *m =new ConcretMediator;
    House * h1 = new SellHouse(m);
    House * h2 = new SellHouse(m);

    m->setHouse(h1, h2);

    h2->sendMsg("300卖不卖");
    h1->sendMsg("不卖");

    return 0;
}
