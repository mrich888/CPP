
#include <iostream>

class Car
{
private:
    /* data */
public:
    Car(/* args */);
    ~Car();
};

Car::Car(/* args */)
{
}

Car::~Car()
{
}


class Engine
{
public:
    Engine(/* args */);
    ~Engine();


    void setEngine(std::string engine)
    {
        this->engine = engine;
    }

    void setWheel(std::string wheel)
    {
        this->wheel = wheel;
    }

    void setBoyd(std::string boyd)
    {
        this->body = body;
    }
    
    void show()

    {
        std::cout << "zaohaole" << 
    }

private: 
    std::string engine;
    std::string wheel;
    std::string body;
}

//抽象类
class Assemble
{
public:
    Assemble():(new Car){}
    virtual void AssembleEngine() = 0;
    virtual void AssembleWheel() = 0;
    virtual void AssembleBody() = 0;
    virtual Car* getCar()
    {
        a->AssembleEngine();

    }

private:
    Assemble * a;

}

int main()
{
    Assemble

}