#include <iostream>

class Complex
{
private:
    int real;
    int vir;

public:
    Complex(int real, int vir):real(real), vir(vir){}

    Complex operator+(const Complex &c)//运算符重载，相当于add 
    {
        Complex result(0 ,0);
        result.real = this->real + c.real;
        result.vir = this->vir + c.vir;
        return result;  
    }

    Complex operator-(const Complex &c)//运算符重载，相当于减法
    {
        Complex result(0 ,0);
        result.real = this->real - c.real;
        result.vir = this->vir - c.vir;
        return result;  
    }

    Complex operator++(int)//后置++，占位参数做重载，以区分前置和后置
    {
        Complex temp = *this;
        this->real++;
        this->vir++;
        return temp;
    }

    Complex operator++()//前置++，无参
    {
        this->real++;
        this->vir++;
        return *this;
    }
    

    //输出运算符重载
    std :: ostream& operator<<(std :: ostream& os)//构造函数不可用，使用引用
    {
        if (vir == 0)
        {
            os << real << std :: endl;
        }
        else
        {
            os << real << "+" << vir << "i" << std :: endl;
        }
        return os;
    }
    friend std :: ostream& operator<<(std :: ostream& os, const Complex&c);
    friend std :: istream& operator>>(std :: istream& os, Complex&c);

    ~Complex();
};

/*  输出函数重载*/
std :: ostream& operator<<(std :: ostream& os, const Complex&c)//构造函数不可用，使用引用
{
    if (c.vir == 0)
    {
        os << c.real << std :: endl;
    }
    else
    {
        os << c.real << "+" << c.vir << "i" << std :: endl;
    }
    return os;
}

/* 输入运算符重载 */
std :: istream& operator>>(std :: istream& is, Complex&c)
{
    is >> c.real >> c.vir;
    return is;
}

Complex::~Complex()
{
}

int main()
{
    Complex c(2, 3);
    Complex c1(1, 0);

    Complex c2 = c + c1;//operator+ 直接省略operator
    Complex c3 = c - c1;
    
    c2.operator<<(std :: cout);//当函数调用
    c3<<std :: cout;
    std :: cout << c2 << std :: endl;//要想达到这样的直接打印c2的值，将输出函数做友元重载

    //std :: cin >> c1; //输入函数重载
    std :: cout << c1 << std :: endl;

    std :: cout << c++ << std :: endl;
    std :: cout << c << std :: endl;

    Complex c4(1, 1);
    std :: cout << ++c4 << std :: endl;
    std :: cout << c4 << std :: endl;

    return 0;
}
