#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <string>

#define connect(signal, slot) Signal::GlobalInstance()->Connect(signal, slot)
#define disconnect(signal, slot) Signal::GlobalInstance()->disConnect(signal, slot)
#define emit(signal, arg) Signal::GlobalInstance()->emitSignal(signal, arg)

using FuncArray = std::vector<std::function<void(void *)>>;

class Signal
{
public:
    static Signal * GlobalInstance()
    {
        static Signal s;
        return &s;
    }

    void Connect(const std::string& signal, const std::function<void(void *)> & func)
    {
        auto ite = callbacks.find(signal);
        if (ite != callbacks.end())
        {
            ite->second.push_back(func);
        }
        else{
            FuncArray arr; //函数转换形式
            arr.push_back(func);
            callbacks.insert({signal, arr});
        }
    }
    void disConnect(const std::string& signal, const std::function<void(void *)> & func)
    {
        auto ite = callbacks.find(signal);
        if (ite == callbacks.end())
        {
            return;
        }

        auto &v = ite->second;
        for (auto vecIte = v.begin(); vecIte != v.end(); vecIte++)
        {
            if (func.target_type() == vecIte->target_type())
            {
                v.erase(vecIte);
                return;
            }
        }
    }

    void emitSignal(const std::string & signal, void * arg)
    {
        auto ite = callbacks.find(signal);
        if (ite == callbacks.end())
        {
            return;
        }

        for (auto &func : ite->second)
        {
            func(arg);
        }
    }

private:
    std::map<std::string, FuncArray> callbacks;//回调列表
};

void func4(void *arg)
{
    std::cout << "网络初始化成功！\n";
}

void func1(void *arg)
{
    std::cout << "网络初始化！\n";
    emit("网络启动", nullptr);
}

void func2(void *arg)
{
    std::cout << "数据库初始化！\n";
    emit("数据库启动", nullptr);
}

void func3(void *arg)
{
    std::cout << "界面初始化！\n";
    emit("界面启动", nullptr);
}
int main()
{
    func4(nullptr);
    connect("网络启动", func1);
    connect("数据库启动", func2);
    connect("界面启动", func3);
    

    return 0;
}