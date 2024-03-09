#include <iostream>
using namespace std;
#include <memory>

class Person
{
public:
    Person()
    {
        cout << "Person()" << endl;
    }

    ~Person()
    {
        cout << "~Person()" << endl;
    }

public:
    void run()
    {
        cout << "Person run()" << endl;
    }
private:
    int m_age;
    char * m_name;
};


/* 模板 */
template <typename T>
class smartPtr
{
public:
    smartPtr(T * obj)
    {
        ptr = obj;
        // cout << "smartPtr()" << endl;
    }

    ~smartPtr()
    {
        delete ptr;
        // cout << "~smartPtr()" << endl;
    }

public:
    T * operator->()
    {
        return ptr;
    }

private:
    T * ptr;
};

int main()
{
#if 0
    {
        Person *p2 = new Person[3];

        p2->run();
        /* 只有调用了delete才会调用析构 */
        delete [] p2;
    }
#endif


#if 1
    /* auto_ptr 的使用 不适用于数组*/
    auto_ptr<Person> p1(new Person);    // p1 = new Person[]

    // p1->run()    // 1
    // p1.run()     // 2
    p1->run();
#endif


#if 1
    smartPtr<Person> sp(new Person);
    sp->run();
#endif


#if 0
    int * ptr = new int[100];
    delete [] ptr;
#endif

    return 0;
}