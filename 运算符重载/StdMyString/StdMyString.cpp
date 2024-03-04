#if 0
#include <iostream>
#include <cstring>
#include "StdMyString.h"

//无参构造 
StdMyString::StdMyString()
{
    std :: cout << "无参构造！\n" << std :: endl;
    this->size = 0;
    this->capacity = 15;
    this->s = new char[this->capacity];
    memset(s, 0, 15);
}

//有参构造 
StdMyString::StdMyString(const char *str)
{
    std :: cout << "有参构造！\n" << std :: endl;
    this->size = strlen(str);
    if (size <= 15)
    {
        this->capacity = 16;
        this->s = new char[this->capacity];
        memset(s, 0, 15);
        strcpy(this->s, str);
    }
    else
    {
        this->capacity = this->size;
        this->s = new char[this->capacity];
        memset(s, 0, this->capacity);
        strcpy(this->s, str);
    }
    
}

//拷贝构造 
StdMyString::StdMyString(const StdMyString &str)
{
    std :: cout << "拷贝构造！\n" << std :: endl;
    //深拷贝 -- 自定义    浅拷贝 -- 系统自动生成
    this->capacity = str.capacity;
    this->size = str.size;
    this->s = new char[this->capacity];
    memset(s, 0, this->capacity);
    strcpy(this->s, str.s);
}
 
StdMyString StdMyString :: operator+(const StdMyString & str)
{
    std :: cout << "+\n" << std :: endl;
    StdMyString result(*this);
    result.size = this->size + str.size;
    if (result.size < result.capacity)
    {
        strcat(result.s, str.s);
    }
    else
    {
        result.capacity = result.size + 1;
        char *newStr = new char[result.capacity];
        strcpy(newStr, this->s);
        strcat(newStr, str.s);
        delete []result.s;
        result.s = newStr;//复制指针给另一个，使两个指向同一个地址
    }
    return result;
}

StdMyString& StdMyString::operator+=(const StdMyString &str)
{
    *this = *this + str;
    return *this;
}

StdMyString& StdMyString::operator+=(const char c)
{
    if (this-> size + 1 == this->capacity)
    {
        this->capacity *= 2;
        char *newStr = new char[this->capacity];
        strcpy(newStr, this->s);
        delete []this->s;
        this->s = newStr;
    }
    this->s[this->size] = c;
    this->s[this->size + 1] = '\0';
    this->size++;

    return *this;
}

StdMyString StdMyString::Number(int a)
{
    StdMyString s;
    sprintf(s.s, "%d", a);
    return s;
}

StdMyString StdMyString::operator-(const StdMyString &str)
{
    StdMyString result(*this);
    char *deleteS = strstr(result.s, str.s);//s指向找到相同的的字符串的位置
    while (deleteS != nullptr)
    {
        char *backS = deleteS + str.size;
        while (*backS != '\0')
        {
            *deleteS++ = *backS++;
        }
        *deleteS = '\0';
        deleteS = strstr(result.s, str.s);
    }

    return result;
}

StdMyString& StdMyString::operator=(const StdMyString &str)
{
    std :: cout << "赋值运算符重载！\n" << std :: endl;
    this->size = str.size;
    this->capacity = str.capacity;
    delete []this->s;
    this->s = new char[str.capacity];
    strcpy(this->s ,str.s);

    return *this;//返回的是一个对象，对象作为左值发生拷贝   为减少发生拷贝构造，可以修改返回的是一个引用
}

bool StdMyString::operator==(const StdMyString &str)
{
    return strcmp(this->s, str.s) == 0;
}

bool StdMyString::operator!=(const StdMyString &str)
{
    return strcmp(this->s, str.s) != 0;
    //return !(*this == str)
}

bool StdMyString::operator>(const StdMyString &str)
{
    return strcmp(this->s, str.s) > 0;
}

bool StdMyString::operator&&(const StdMyString &str)
{
    return this->size != 0 && str.size != 0;
}

bool StdMyString::operator||(const StdMyString &str)
{
    return this->size != 0 || str.size != 0;
}

char &StdMyString::operator[](int index)
{
    return *this->s;
    // TODO: 在此处插入 return 语句
}

StdMyString::operator int()
{
    return atoi(this->s);
}

StdMyString::operator double()
{
    return atof(this->s);
}

// 析构函数
StdMyString::~StdMyString()
{
    std :: cout << "析构构造！\n" << std :: endl;
    this->size = 0;
    this->capacity = 0;
    delete []this->s;
}

/* 输出函数 */
std::ostream &operator<<(std::ostream &os, const StdMyString &str)
{
    os << "size:" << str.size << "capacity:" << str.capacity << std :: endl;
    os << str.s;
    return os;
}


std::istream &operator>>(std::istream &is, StdMyString &str)
{
    // char temp[1024] = {0};
    // is >> temp;
    // str = temp;
    char c = '\0';
    while ((c= getchar()) != '\n')
    {
        str += c;
    }
    
    return is;
    // TODO: 在此处插入 return 语句
}


MyStringList std:: ostream &operator<<(std::ostream &os, const MyStringList &str)
{
    for(int idx; idx < list.size; idx++)
    {
        os << list.string[idx] << std :: endl;
    }
    // TODO: 在此处插入 return 语句
}
#endif

#include "StdMyString.h"
#include <cstring>

StdMyString::StdMyString()
{
    std::cout<<"无参构造"<<std::endl;
    this->size = 0;
    this->capacity = 15;
    this->s = new char[this->capacity];
    memset(s, 0, 15);
}


StdMyString::StdMyString(const char *str)
{
    std::cout<<"有参构造"<<std::endl;
    this->size = strlen(str);
    if (size <= 15)
    {
        this->capacity = 16;
        this->s = new char[this->capacity];
        memset(s, 0, 15);
        strcpy(this->s, str);

    }
    else
    {
        this->capacity = this->size + 1;
        this->s = new char[this->capacity];
        memset(s, 0, this->capacity);
        strcpy(this->s, str);

    }
}

StdMyString::StdMyString(const StdMyString &str)
{
    std::cout<<"拷贝构造"<<std::endl;
    this->capacity = str.capacity;
    this->size = str.size;
    this->s = new char[this->capacity];
    memset(s, 0, this->capacity);
    strcpy(this->s, str.s);
    
}

StdMyString::~StdMyString()
{
    std::cout<<"析构函数"<<std::endl;
    this->size = 0;
    this->capacity = 0;
    delete []this->s;
}

StdMyString StdMyString::operator+(const StdMyString &str)
{
    StdMyString result(*this);
    result.size = this->size + str.size;

    /* 不需要扩容 */
    if (result.size < result.capacity)
    {
        strcat(result.s, str.s);
    }
    else
    {
        result.capacity = result.size + 1;
        char *newStr = new char[result.capacity];
        strcpy(newStr, this->s);
        strcat(newStr, str.s);
        delete []result.s;
        result.s = newStr;

    }
    return result;
}

/* 避免浅拷贝  return的是一个左值 左值不可以直接把内存给别人 所以只能发生拷贝 所以为了避免发生拷贝函数 就用了引用 */
/* 用了拷贝函数 说明就会多了一个对象 */
StdMyString& StdMyString::operator=(const StdMyString &str)
{
    this->size = str.size;
    this->capacity = str.capacity;
    delete []this->s;
    this->s = new char[str.capacity];
    strcpy(this->s, str.s);

    return *this;
}

StdMyString StdMyString::operator-(const StdMyString &str)
{
    StdMyString result(*this);
    /* 字符串匹配 */
    char * deleteS = strstr(result.s, str.s);
    while (deleteS != nullptr)
    {
        char * backS = deleteS + str.size;
        while (*backS != '\0')
            *deleteS++ = *backS++;
        *deleteS = '\0';
        
        deleteS = strstr(result.s, str.s);
    }
     
    return result;
}

StdMyString& StdMyString::operator+=(const char c)
{
    if (this->size + 1 == this->capacity)
    {
        this->capacity *= 2;
        char *newStr = new char[this->capacity];
        strcpy(newStr, this->s);
        delete []this->s;
        this->s = newStr;
    }

    this->s[this->size] = c;
    this->s[this->size + 1] = '\0';
    this->size++;
    return *this;
}

bool StdMyString::operator==(const StdMyString &str)
{

    return strcmp(this->s, str.s) == 0;
}

bool StdMyString::operator!=(const StdMyString &str)
{
    return !(*this == str);
}

bool StdMyString::operator>(const StdMyString &str)
{
    return strcmp(this->s, str.s) > 0;
}

char &StdMyString::operator[](int index)
{
    return this->s[index];
    // TODO: 在此处插入 return 语句
}

StdMyString::operator int()
{
    return atoi(this->s);
}

StdMyString::operator double()
{
    return atof(this->s);
}

MyStringList StdMyString::splite(const StdMyString &str)
{
    StdMyString temp(*this);
    MyStringList list;

    char * s = strtok(temp.s, str.s);
    while (s != nullptr)
    {
        list += s;
        s = strtok(nullptr, str.s);
    }
    return list;
}

// bool StdMyString::operator&&(const StdMyString &str)
// {
//     return this->size != 0 && str.size != 0;
// }

std::ostream &operator<<(std::ostream &os, const StdMyString &str)
{
    os<<"size:"<<str.size<<",capacity"<<str.capacity<<std::endl;
    os<<str.s;
    return os;
}

// std::istream &operator>>(std::istream &is, StdMyString &str)
// {
//     char c = '\0';
//     while ((c = getchar()) != '\n')
//     {
//         str += c;
//     }
//     return is;
// }


MyStringList::MyStringList()
{
    this->size = 0;
    this->capacity = 15;
    this->string = new StdMyString[this->capacity];
}

MyStringList::~MyStringList()
{
    this->size = 0;
    this->capacity = 0;
    delete []this->string;
}

void MyStringList::RemoveByIndex(int index)
{
    if (index < 0 && index >= this->size)
    {
        return;
    }
    for (int idx = 0; idx < this->size - 1; idx++)
    {
        this->string[idx] = this->string[idx + 1];
    }
    this->size--;
}

MyStringList &MyStringList::operator+=(const StdMyString &str)
{
    if (this->size == this->capacity)
    {
        this->capacity *= 2;
        StdMyString *newPtr = new StdMyString[this->capacity];
        for (int idx = 0; idx < this->size; idx++)
        {
            newPtr[idx] = this->string[idx];
        }
        delete []this->string;
        this->string = newPtr;
    }
    this->string[this->size++] = str;
    return *this;
}
MyStringList &MyStringList::operator-=(const StdMyString &str)
{
    for(int idx = 0; idx < this->size; idx++)
    {
        this->string[idx] == str;
        RemoveByIndex(idx);
        idx--;
    }
    return *this;
}
StdMyString &MyStringList::operator[](int index)
{
    return this->string[index];
}
std::ostream &operator<<(std::ostream &os, const MyStringList &list)
{
    for (int idx = 0; idx < list.size; idx++)
    {
        os<<list.string[idx]<<std::endl;
    }
    return os;
}

// MyStringList::MyStringList()
// {
//     this->size = 0;
//     this->capacity = 15;
//     this->string = new StdMyString[this->capacity];
// }

// MyStringList::~MyStringList()
// {
//     this->size = 0;
//     this->capacity = 0;
//     this->string;
// }
