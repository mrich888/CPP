#include <iostream>

class Color
{
public:
    virtual void paint(const std::string& pentype, const std::string& name) = 0;

};

class Red : public Color
{
public:
    void paint(const std::string& pentype, const std::string& name)
    {
        std::cout << pentype << "红色的" << name << std::endl;
    }
};

class Blue : public Color
{
public:
    void paint(const std::string& pentype, const std::string& name)
    {
        std::cout << pentype << "蓝色的" << name << std::endl;
    }
};

class Pen
{
public:
    void SetColor(Color *c)
    {
        this->c = c;
    }
    virtual void Draw(const std::string& name) = 0;

protected:
    Color *c;//组合

};

class Pencil : public Pen
{
public:
    void Draw(const std::string& name) override
    {
        this->c->paint("铅笔", name);
    }
};

class SmallPen : public Pen
{
public:
    void Draw(const std::string& name) override
    {
        this->c->paint("毛笔", name);
    }
};

int main()
{
    Color *c1 = new Red;
    Color *c2 = new Blue;

    Pen *p1 = new Pencil;
    Pen *p2 = new SmallPen;

    p1->SetColor(c1);
    p1->Draw("太阳");

    p2->SetColor(c2);
    p2->Draw("大海");


    return 0;
}