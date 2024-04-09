#include <iostream>
#include <set>

//观察者基类
class observeBase
{
public:
    virtual std::string GetName() = 0;//获取观察者名称
    virtual void update(const std::string & news) = 0;//更新订阅消息

};

class observe : public observeBase
{
public:
    observe(const std::string & name): name(name){}
    std::string GetName()
    {
        return name;
    }
    void update(const std::string & news)
    {
        this->news = news;
        std::cout << "我是" << name << ","<< "我收到了消息" << news <<std::endl;
    }

private:
    std::string name;
    std::string news;

};

//被观察者基类
class TargetBase
{
public:
    virtual void AddObserver(observeBase *ob) = 0;
    virtual void RMObserver(observeBase *ob) = 0;
    virtual void Broadcast(const std::string & news) = 0;


protected:
    

};

class Target : public  TargetBase
{
public:
    Target(const std::string & name): name(name){}
    void AddObserver(observeBase *ob)
    {
        s.insert(ob);
        std::cout<< ob->GetName() << "绑定了" << name << "的消息" << std::endl;
    }

    void RMObserver(observeBase *ob) 
    {
        auto ite = s.find(ob);
        if (ite == s.end())
        {
            std::cout<< "该用户不是你的观察者" << std::endl;
        }
        else
        {
            s.erase(ite);
            std::cout<<"该用户不再是你的观察者" << std::endl;
        }
        
    }

    void Broadcast(const std::string & news)
    {
        for (auto & ob:s)
        {
            ob->update(news);
        }
        
    }
private:
    std::set<observeBase *> s;
    std::string name;
};

int main()
{

    TargetBase *t = new Target("主播张三");

    observeBase *b1 = new observe("lisi");
    observeBase *b2 = new observe("wagnwu");

    t->AddObserver(b1);
    t->AddObserver(b2);


    return 0;
}