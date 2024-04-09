#include <iostream>

//抽象的被代理对象
class AbstractSystem
{
public:
    virtual void run() = 0;

};

class Windows : public AbstractSystem
{
public:
    void run()
    {
        std::cout << "window 系统启动\n";
    }
};

class Linux : public AbstractSystem
{
public:
    void run()
    {
        std::cout << "Liunx 系统启动\n";
    }
};

class Proxy
{
public:
    Proxy(const std::string &user, const std::string &passwd, AbstractSystem)
    {
        this->user = user;
        this->passwd = passwd;
        this->s = s;
    }

    void run()
    {
        if (user == "admin" && passwd == "123456")
        {
            s = new Windows;
            s->run();
        }
        else if (user == "root" && passwd == "1")
        {
            s = new Linux;
            s->run();

        }
        else
        {
            std::cout << " " << std::endl;
        }
    }

private:
    std::string user;
    std::string passwd;
    AbstractSystem *s;
};



int main()
{
    Proxy p("root", "1");
    p.run();

    return 0;
}