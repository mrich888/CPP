#include <iostream>
#include <string>

class Clone
{
public:
    virtual Clone * clone() = 0;
    virtual void show() = 0;

};

class Student : public Clone
{
public:
    Student(int id, const std::string &name) : id(id), name(name){}

    Clone * clone()
    {
        //拷贝对象
        Student *s = new Student(*this);
        return s;
    }

    void show() override
    {
        std::cout << "id" << id << "name" << std::endl;
    }


private:
    int id;
    std::string name;

};

int main()
{
    Student * s = new Student(1, "zhangsan");
    auto p = s->clone();
    p->show();

    printf("");

    return 0;

}