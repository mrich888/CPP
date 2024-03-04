#ifndef __StdMyString_H_
#define __StdMyString_H_

#include <iostream>

/* 类的前置声明 */
class MyStringList;

/* 字符串类 */
class StdMyString
{  
public:
    /* 构造重载 */
    StdMyString();
    StdMyString(const char * str);
    StdMyString(const StdMyString & str);
    ~StdMyString();

    /* 运算符重载，可以使用你已经重新定义的运算符 */
    StdMyString operator+(const StdMyString & str);//内存空间有变化
    StdMyString& operator=(const StdMyString& str);
    StdMyString& operator+=(StdMyString& str);
    StdMyString operator-(const StdMyString& str);
    StdMyString& operator-=(const StdMyString& str);

    /* 追加字符 */
    StdMyString& operator+=(const char c);

    /* 将整形转成字符串类型 */
    StdMyString Number(int a);

    /* 比较算符重载 */
    bool operator==(const StdMyString& str);
    bool operator!=(const StdMyString& str);
    bool operator>(const StdMyString& str);

    /* 逻辑运算符 -- 尽量不重载这两个 */
    bool operator&&(const StdMyString &str);
    bool operator||(const StdMyString &str);

    /* 字符串中[]重载 */
    char& operator[](int index);

    /* 强转类型 */
    operator int();
    operator double();

    
    /* 字符串列表切割 */
    StdMyString splite1(const StdMyString& str);

    /* 字符串列表切割 */
    MyStringList splite(const StdMyString& str);

    /* 重载输入输出函数，且设置友元，使其可以访问到私有成员 */
    friend std::ostream& operator<<(std::ostream& os, const StdMyString& str);
    friend std::istream& operator>>(std::istream& is, StdMyString& str);

private:
    char * s;
    int size;
    int capacity;

};

/* 输入输出函数 */
std::ostream& operator<<(std::ostream& os, const StdMyString& str);
std::istream& operator>>(std::istream& is, StdMyString& str);

/* 字符转列表类 */
class MyStringList
{
public:
    MyStringList();
    ~MyStringList();

    /* 删除列表中的一个字符串 */
    void RemoveByIndex(int index);

    /* 运算符重载 */
    MyStringList& operator+=(const StdMyString& str);
    MyStringList& operator-=(const StdMyString& str);
    StdMyString& operator[](int index);

    /* 成员函数并设置友元，使其能访问类内私有成员 */
    friend std::ostream& operator<<(std::ostream& os, const MyStringList& list);
    //friend std::istream& operator>>(std::istream& is, MyStringList& list);

private:
    /* 字符串 */
    StdMyString *string;
    /* 列表大小 */
    int size;
    /* 列表容量 */
    int capacity;
};

std::ostream& operator<<(std::ostream& os, const MyStringList& list);

#endif