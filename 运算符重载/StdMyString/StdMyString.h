#ifndef __StdMyString_H_
#define __StdMyString_H_

#include <iostream>
class MyStringList;
class StdMyString
{  
public:

    StdMyString();
    StdMyString(const char * str);
    StdMyString(const StdMyString & str);
    ~StdMyString();

    StdMyString operator+(const StdMyString & str);
    StdMyString& operator=(const StdMyString& str);
    StdMyString operator-(const StdMyString& str);
    StdMyString& operator+=(const char c);
    StdMyString Number(int a);

    bool operator==(const StdMyString& str);
    bool operator!=(const StdMyString& str);
    bool operator>(const StdMyString& str);

    char& operator[](int index);
    operator int();
    operator double();

    //bool operator&&(const StdMyString& str);
    MyStringList splite(const StdMyString& str);
    friend std::ostream& operator<<(std::ostream& os, const StdMyString& str);
    friend std::istream& operator>>(std::istream& is, StdMyString& str);
private:
    char * s;
    int size;
    int capacity;

};
std::ostream& operator<<(std::ostream& os, const StdMyString& str);
std::istream& operator>>(std::istream& is, StdMyString& str);


class MyStringList
{
public:
    MyStringList();
    ~MyStringList();

    void RemoveByIndex(int index);
    MyStringList& operator+=(const StdMyString& str);
    MyStringList& operator-=(const StdMyString& str);
    StdMyString& operator[](int index);

    friend std::ostream& operator<<(std::ostream& os, const MyStringList& list);
    friend std::istream& operator>>(std::istream& is, MyStringList& list);


private:
    StdMyString *string;
    int size;
    int capacity;
};

std::ostream& operator<<(std::ostream& os, const MyStringList& list);

#endif