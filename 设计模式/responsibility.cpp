#include <iostream>

struct request
{
    int money;
};


//抽象类
class Manager
{
public:
    Manager(const std::string &name): name(name){}
    virtual void setManage(Manager *m)
    {
        this->m = m;
    }
    virtual void getRequest(request *r) = 0;

protected:
    std::string name;
    Manager *m;
};

class CommonManager : public Manager
{
public:
    using Manager::Manager;
    void getRequest(request *r)
    {
        if (r->money <= 1000)
        {
            std::cout << " 经理同意涨薪 " << std::endl;
        }
        else{
            m->getRequest(r);
        }
    }

};

class Major : public Manager
{
public:
    using Manager::Manager;
    void getRequest(request *r)
    {
        if (r->money <= 2000)
        {
            std::cout << " 总监同意涨薪 " << std::endl;
        }
        else{
            m->getRequest(r);
        }
    }

};

class generaManager : public Manager
{
public:
    using Manager::Manager;
    void getRequest(request *r)
    {
        std::cout << " 董事长同意涨薪 " << std::endl;
    }

};

int main()
{
    Manager *m1 = new CommonManager("经理");
    Manager *m2 = new Major("总监");
    Manager *m3 = new generaManager("董事长");
    m1->setManage(m2);
    m2->setManage(m3);

    request r = {1000};
    m1->getRequest(&r);

    request r1 = {3000};
    m1->getRequest(&r1);


    return 0;
}