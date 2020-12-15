#pragma once
#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__
#include "Assistance.h"
template <class ElemType>
class SeqList
{
protected:
    int length;
    int MaxLength;
    ElemType *elems;

public:
    SeqList(int size = DEFAULT_SIZE);
    SeqList(ElemType v[], int n, int size = DEFAULT_SIZE);
    virtual ~SeqList();
    int GetLength() const;
    bool IsEmpty() const;
    void Clear();
    void Traverse(void (*Visit)(const ElemType &)) const;
    int LocateElem(const ElemType &e) const;
    Status GetElem(int i, ElemType &e) const;
    Status SetElem(int i, const ElemType &e);
    Status DeleteElem(int i, ElemType &e);
    Status InsertElem(int i, const ElemType &e);
    Status InsertElem(const ElemType &e);
    SeqList(const SeqList<ElemType> &sa);
    SeqList<ElemType> &operator=(const SeqList<ElemType> &sa);
    void DeleteRepeat();
    void Reverse();
    Status DeleteBetween(ElemType s, ElemType t);
};
template <class ElemType>
SeqList<ElemType>::SeqList(int size) : MaxLength(size), length(0)
{
    elems = new ElemType[MaxLength];
    assert(elems);
}
template <class ElemType>
SeqList<ElemType>::SeqList(ElemType v[], int n, int size) : MaxLength(size), length(n)
// 操作结果：根据数组v中的内容构造顺序表
{
    elems = new ElemType[MaxLength];
    assert(elems);
    for (int i = 0; i < length; i++)
    {
        elems[i] = v[i];
    }
}

template <class ElemType>
SeqList<ElemType>::~SeqList()
// 功能：回收顺序表的存储空间
{
    delete[] elems; // 释放存储空间
}

template <class ElemType>
int SeqList<ElemType>::GetLength() const
// 功能：返回顺序表中元素个数
{
    return length;
}

template <class ElemType>
bool SeqList<ElemType>::IsEmpty() const
// 功能：如顺序表为空，则返回true，否则返回false
{
    return length == 0;
}

template <class ElemType>
void SeqList<ElemType>::Clear()
// 功能：清空顺序表
{
    length = 0;
}

template <class ElemType>
void SeqList<ElemType>::Traverse(void (*visit)(const ElemType &)) const
// 功能：依次对顺序表的每个元素调用函数(*visit)进行访问
{
    for (int i = 0; i < length; i++)
        (*visit)(elems[i]);
}

template <class ElemType>
int SeqList<ElemType>::LocateElem(const ElemType &e) const
// 功能：求元素e在顺序表中的序号,如果顺序表中不存在元素e则返回0
{
    int i = 0;
    while (i < length && elems[i] != e)
        i++;
    return i < length ? i + 1 : 0;
}

template <class ElemType>
Status SeqList<ElemType>::GetElem(int i, ElemType &e) const
// 功能：当顺序表存在第i个元素时，用e返回其值，函数返回ENTRY_FOUND,否则函数返回NOT_PRESENT
{
    if (i < 1 || i > length)
        return NOT_PRESENT; // 返回元素不存在
    else
    {
        e = elems[i - 1];
        return ENTRY_FOUND; // 元素存在
    }
}

template <class ElemType>
Status SeqList<ElemType>::SetElem(int i, const ElemType &e)
// 功能：将顺序表的第i个位置的元素赋值为e。i的取值范围为1≤i≤length,i合法时函数返回SUCCESS,否则函数返回RANGE_ERROR
{
    if (i < 1 || i > length)
        return RANGE_ERROR; // 返回位置错
    else
    {
        elems[i - 1] = e;
        return SUCCESS; // 返回修改成功
    }
}

template <class ElemType>
Status SeqList<ElemType>::DeleteElem(int i, ElemType &e)
// 功能：删除顺序表第i个位置的元素, 并前用e返回其值。i的的取值范围为1≤i≤length,i合法时函数返回SUCCESS,否则函数返回RANGE_ERROR
{
    if (i < 1 || i > length)
        return RANGE_ERROR; // 返回位置错
    else
    {
        e = elems[i - 1];                // 用e返回被删除元素的值
        for (int j = i; j < length; j++) // 被删除元素之后的元素依次左移一个位置
            elems[j - 1] = elems[j];
        length--;       // 删除后顺序表元素个数减1
        return SUCCESS; // 返回删除成功
    }
}

template <class ElemType>
Status SeqList<ElemType>::InsertElem(int i, const ElemType &e)
// 功能：在顺序表的第i个位置插入元素e,i的的取值范围为1≤i≤Length()+1。
//	如顺序表已满,则返回OVER_FLOW,
//	如i合法, 则返回SUCCESS, 否则函数返回RANGE_ERROR
{
    if (length == MaxLength)
        return OVER_FLOW;             // 顺序表已满,返回OVER_FLOW
    else if (i < 1 || i > length + 1) // i范围错,返回位置错
        return RANGE_ERROR;
    else
    {
        for (int j = length; j >= i; j--) // 插入位置之后的元素右移
            elems[j] = elems[j - 1];
        elems[i - 1] = e; // 将e赋值到顺序表i位置
        length++;         // 插入后元素个数加1
        return SUCCESS;   // 返回插入成功
    }
}

template <class ElemType>
Status SeqList<ElemType>::InsertElem(const ElemType &e)
// 功能：在顺序表的表尾插入元素e,并则返回SUCCESS，如顺序表已满,则返回OVER_FLOW
{
    if (length == MaxLength) // 顺序表已满返回OVER_FLOW
        return OVER_FLOW;
    else
    {
        elems[length] = e; // 将元素e插入到表尾
        length++;          // 插入后，顺序表元素个数加1
        return SUCCESS;    // 返回插入成功
    }
}

template <class ElemType>
SeqList<ElemType>::SeqList(const SeqList<ElemType> &sa)
// 功能：复制构造函数，由顺序表sa构造新顺序表
{
    int saLength = sa.GetLength(); // 取顺序表sa的长度
    ElemType e;

    MaxLength = sa.MaxLength;        // 取顺序表的最大容量
    elems = new ElemType[MaxLength]; // 分配存储空间
    assert(elems);                   // 分配存储空间失败
    length = 0;                      // 空顺序表元素个数为0

    for (int i = 1; i <= saLength; i++)
    {
        sa.getElem(i, e); // 取出顺序表sa中第i个元素
        insertElem(e);    // 将e插入到当前顺序表的表尾
    }
}

template <class ElemType>
SeqList<ElemType> &SeqList<ElemType>::operator=(const SeqList<ElemType> &sa)
// 功能：赋值语句重载，将顺序表sa赋值给当前顺序表
{
    if (&sa != this)
    {
        int saLength = sa.GetLength(); // 取顺序表sa的长度
        ElemType e;

        MaxLength = sa.MaxLength;        // 取顺序表的最大容量
        delete[] elems;                  // 释放顺序表原来的存储空间
        elems = new ElemType[MaxLength]; // 分配存储空间
        assert(elems);                   // 分配存储空间失败
        length = 0;                      // 空顺序表元素个数为0
        for (int i = 1; i <= saLength; i++)
        {
            sa.getElem(i, e); // 取出顺序表sa中第i个元素
            insert(e);        // 将e插入到当前顺序表的表尾
        }
    }
    return *this;
}
template <class ElemType>
void SeqList<ElemType>::DeleteRepeat()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (elems[i] == elems[j])
            {
                DeleteElem(j + 1, elems[j]);
                j--;
            }
        }
    }
}
template <class ElemType>
void SeqList<ElemType>::Reverse()
{
    ElemType e;
    for (int i = 0; i < length / 2; i++)
    {
        e = elems[i];
        elems[i] = elems[length - 1 - i];
        elems[length - 1 - i] = e;
    }
}
template <class ElemType>
Status SeqList<ElemType>::DeleteBetween(ElemType s, ElemType t)
{
    if (s >= t or length == 0)
        return RANGE_ERROR;
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (elems[i] > s and elems[i] < t)
            {
                for (int j = i + 1; j < length; j++)
                {
                    elems[j - 1] = elems[j];
                }
                length--;
                i--;
            }
        }
        return SUCCESS;
    }
}
#endif
