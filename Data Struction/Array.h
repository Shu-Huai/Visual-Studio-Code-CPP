#pragma once
#ifndef __ARRAY_H__
#define __ARRAY_H__
template <class ElemType>
class Array
{
protected:
    ElemType *base;  
    int dim;         
    int *bounds;     
    int *constants;
    int Locate(int sub0, va_list &va) const; // 求元素在顺序存储中的位置 public:
    //抽象数据类型方法声明及重载编译系统默认方法声明：
    Array(int d, ...);                                        //由维数d与随后的各维长度构造数组
    ~Array();                                                 // 析构函数
    ElemType &operator()(int sub0, ...);                      // 重载函数运算符
    Array(const Array<ElemType> &copy);                       // 复制构造函数模板
    Array<ElemType> ^ operator=(const Array<ElemType> &copy); //
    重载赋值运算符
};
//////////////////////////////////////////////////////////////////////
/////////////////////////////////////
//  数组类实现
//   Author：Melissa M.CAO
//   Belong：Section of software theory，School of Computer Engineering
&Science，Shanghai University
//   Version： 1.0
//////////////////////////////////////////////////////////////////////
/////////////////////////////////////

#include "MyArray.h"
#include "StdAfx.h"

    //////////////////////////////////////////////////////////////////////
    /////////////////////////////////////
    //  构造函数
    //////////////////////////////////////////////////////////////////////
    /////////////////////////////////////
    template <class ElemType>
    Array<ElemType>::Array(int d, ...)
// 操作结果：由维数 d 与随后的各维长度构造数组
{
    if (d < 1)
    {
        cout << "维数不能小于 1!！" << endl;
        exit(1);
    }

    dim = d;               // 数组维数为 d
    bounds = new int[dim]; // 分配数组各维长度存储空间
    va_list va;            // 变长参数变量
    int elemTotal = 1;     // 元素总数
    int i;                 // 临时变量

    va_start(va, d);
    // 初始化变量 va,用于存储变长参数信息,d 为省略号左侧最右边的参 数标识符
    for (i = 0; i < dim; i++)
    {                                      // 为各维长度赋值并计算数组总元素个数
        bounds[i] = va_arg(va, int);       // 取出变长参数作为各维长 度
        elemTotal = elemTotal * bounds[i]; // 统计数组总元素个数
    }
    va_end(va); // 结束变长参数的引用

    base = new ElemType[elemTotal]; // 分配数组元素空间

    constants = new int[dim]; // 分配数组映象函数常量
    constants[dim - 1] = 1;
    for (i = dim - 2; i >= 0; --i)
        constants[i] = bounds[i + 1] * constants[i + 1]; // 计算数组映 象函数常量
}

//////////////////////////////////////////////////////////////////////
/////////////////////////////////////
//  析构函数
//////////////////////////////////////////////////////////////////////
/////////////////////////////////////
template <class ElemType>
Array<ElemType>::~Array()
// 操作结果：释放数组所占用空间
{
    if (base != NULL)
        delete[] base; // 释放数组元素空间
    if (bounds != NULL)
        delete[] bounds; // 释放各维长度空 间
    if (constants != NULL)
        delete[] constants; // 释放映象函数常 量空间
}

//////////////////////////////////////////////////////////////////////
/////////////////////////////////////
// 操作结果：求元素在顺序存储中的位置
//////////////////////////////////////////////////////////////////////
/////////////////////////////////////
template <class ElemType>
int Array<ElemType>::Locate(int sub0, va_list &va) const
{
    if (!(sub0 >= 0 && sub0 < bounds[0]))
    {
        cout << "下标出界!" << endl;
        exit(1);
    }
    int off = constants[0] * sub0; // 初始化元素在顺序存储中 的位置
    for (int i = 1; i < dim; i++)
    {
        int sub = va_arg(va, int);          // 取出数组元素下标
        if (!(sub >= 0 && sub < bounds[i])) // 抛出异常
        {
            cout << "下标出界!" << endl;
            exit(1);

            //throw Error("下标出界!");
        }
        off += constants[i] * sub; // 累加乘积求元素在顺序存
        储中的位置
    }
    return off;
}

//////////////////////////////////////////////////////////////////////
/////////////////////////////////////
// 操作结果：重载函数运算符（），即访问取值符号[]的重载实现
//////////////////////////////////////////////////////////////////////
/////////////////////////////////////
template <class ElemType>
ElemType &Array<ElemType>::operator()(int sub0, ...)
{
    va_list va; // 变长参数变量
    va_start(va, sub0);
    // 初始化变量 va,用于存储变长参数信息,sub0 为省略号左侧最右边的 参数标识符
    int off = Locate(sub0, va);
    va_end(va);
    return *(base + off); // 数组元素
}

//////////////////////////////////////////////////////////////////////
/////////////////////////////////////
// 操作结果：由数组 copy 构造新数组——复制构造函数模板
//////////////////////////////////////////////////////////////////////
/////////////////////////////////////
template <class ElemType>
Array<ElemType>::Array(const Array<ElemType> &copy)
{
    dim = copy.dim; // 数组维数

    int elemTotal = 1; // 元素总数
    int i;             // 临时变量
    for (i = 0; i < dim; i++)
    {                                           // 统计数组总元素个数
        elemTotal = elemTotal * copy.bounds[i]; // 计算数组总元素个数
    }
    base = new ElemType[elemTotal]; // 为数组元素分配存储空间
    for (i = 0; i < elemTotal; i++)
    { // 复制数组元素

        base[i] = copy.base[i];
    }

    bounds = new int[dim];    // 为数组各维长度分配存储空间
    constants = new int[dim]; // 为数组映象函数常量分配存储空间
    for (i = 0; i < dim; i++)
    {                                     // 复制数组各维长度与映象函数常量
        bounds[i] = copy.bounds[i];       // 各维长度
        constants[i] = copy.constants[i]; // 映象函数常量
    }
}

//////////////////////////////////////////////////////////////////////
/////////////////////////////////////
// 操作结果：将数组 copy 赋值给当前数组——重载赋值运算符
//////////////////////////////////////////////////////////////////////
/////////////////////////////////////
template <class ElemType>
Array<ElemType>
    &Array<ElemType>::operator=(const Array<ElemType> &copy)
{
    if (&copy != this)
    {
        if (base != NULL)
            delete[] base; // 释放数组元 素空间
        if (bounds != NULL)
            delete[] bounds; // 释放各维长 度空间
        if (constants != NULL)
            delete[] constants; // 释放映象函 数常量空间

        dim = copy.dim; // 数组维数

        int elemTotal = 1; // 元素总数
        int i;             // 临时变量
        for (i = 0; i < dim; i++)
        {                                           // 统计数组总元素个数
            elemTotal = elemTotal * copy.bounds[i]; // 计算数组总
            元素个数
        }
        base = new ElemType[elemTotal]; // 为数组元素分配存储空间
        for (i = 0; i < elemTotal; i++)
        { // 复制数组元素
            base[i] = copy.base[i];
        }

        bounds = new int[dim];    // 为数组各维长度分配存储 空间
        constants = new int[dim]; // 为数组映象函数常量分配 存储空间
        for (i = 0; i < dim; i++)
        {                                     // 复制数组各维长度与映象函数常量
            bounds[i] = copy.bounds[i];       // 各维长度
            constants[i] = copy.constants[i]; // 映象函数常量
        }
    }
    return *this;
}
#endif