#include <iostream>

class Light
{
public:
    void on()
    {
        std::cout << "开灯" << std::endl;
    }

    void off()
    {
        std::cout << "关灯" << std::endl;
    }
};


class TV
{
public:
    void on()
    {
        std::cout << "开电视" << std::endl;
    }

    void off()
    {
        std::cout << "关电视" << std::endl;
    }
};

class Voice
{
public:
    void on()
    {
        std::cout << "开音响" << std::endl;
    }

    void off()
    {
        std::cout << "关音响" << std::endl;
    }
};

class HomeSystem
{
public:
    void movie()
    {
        l.off();
        t.on();
        v.on();

    }

    void sleep()
    {
        l.off();
        t.off();
        v.off();
    }

private:
    Light l;
    TV t;
    Voice v;

};

int main()
{
    HomeSystem h;
    h.movie();

    return 0;
}