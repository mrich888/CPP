#pragma once //避免头文件包含

/* 定义和声明放一个.hpp文件中，而不能将两个分开放到.h和.cpp中 */
template <typename T>
T myAdd(T val1,T val2)
{
    return val1 + val2;
}