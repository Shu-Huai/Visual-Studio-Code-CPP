#pragma once
#ifndef __MINIMUM_HEAP_H__
#define __MINIMUM_HEAP_H__
#include "Assistance.h"
template <class ElemType>
class MinimumHeap
{
protected:
    ElemType *elems_;
    int size_;
    int maxSize_;
    void FilterDown(int start);
    void FilterUp(int end);

public:
    MinimumHeap(int maxsize = DEFAULT_SIZE);
    MinimumHeap(ElemType e[], int n, int maxsize = DEFAULT_SIZE);
    ~MinimumHeap();
    void Clear();
    bool IsEmpty() const;
    bool IsFull() const;
    void Traverse(void (*Visit)(const ElemType &)) const;
    Status InsertElem(const ElemType &e);
    Status DeleteTop(ElemType &e);
    int GetSize() const;
    Status GetTop(ElemType &e) const;
};
template <class ElemType>
void MinimumHeap<ElemType>::FilterDown(int start)
{
    int i = start;
    ElemType temp = elems_[i];
    int j = 2 * i + 1;
    while (j <= size_ - 1)
    {
        if (j < size_ - 1 && elems_[j] > elems_[j + 1])
        {
            j++;
        }
        if (temp <= elems_[j])
        {
            break;
        }
        else
        {
            elems_[i] = elems_[j];
            i = j;
            j = 2 * j + 1;
        }
    }
    elems_[i] = temp;
}
template <class ElemType>
void MinimumHeap<ElemType>::FilterUp(int end)
{
    int j = end;
    ElemType temp = elems_[j];
    int i = (j - 1) / 2;
    while (j > 0)
    {
        if (elems_[i] <= temp)
        {
            break;
        }
        else
        {
            elems_[j] = elems_[i];
            j = i;
            i = (j - 1) / 2;
        }
        elems_[j] = temp;
    }
}
template <class ElemType>
MinimumHeap<ElemType>::MinimumHeap(int maxsize) : size_(0), maxSize_(maxsize)
{
    elems_ = new ElemType[maxsize];
    assert(elems_);
}
template <class ElemType>
MinimumHeap<ElemType>::MinimumHeap(ElemType e[], int n, int maxsize) : size_(n), maxSize_(maxsize)
{
    elems_ = new ElemType[maxsize];
    assert(elems_);
    for (int i = 0; i < n; i++)
    {
        elems_[i] = e[i];
    }
    int i = (size_ - 2) / 2;
    while (i >= 0)
    {
        FilterDown(i);
        i--;
    }
}
template <class ElemType>
MinimumHeap<ElemType>::~MinimumHeap()
{
    delete[] elems_;
}
template <class ElemType>
void MinimumHeap<ElemType>::Clear()
{
    size_ = 0;
}
template <class ElemType>
bool MinimumHeap<ElemType>::IsEmpty() const
{
    return size_ == 0;
}
template <class ElemType>
bool MinimumHeap<ElemType>::IsFull() const
{
    return size_ == maxSize_;
}
template <class ElemType>
void MinimumHeap<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
    for (int i = 0; i < size_; i++)
    {
        cout << elems_[i] << " ";
    }
    cout << endl;
}
template <class ElemType>
Status MinimumHeap<ElemType>::InsertElem(const ElemType &e)
{
    if (IsFull())
    {
        return OVER_FLOW;
    }
    elems_[size_] = e;
    FilterUp(size_);
    size_++;
    return SUCCESS;
}
template <class ElemType>
Status MinimumHeap<ElemType>::DeleteTop(ElemType &e)
{
    if (IsEmpty())
    {
        return UNDER_FLOW;
    }
    e = elems_[0];
    elems_[0] = elems_[--size_];
    FilterDown(0);
    return SUCCESS;
}
template <class ElemType>
int MinimumHeap<ElemType>::GetSize() const
{
    return size_;
}
template <class ElemType>
Status MinimumHeap<ElemType>::GetTop(ElemType &e) const
{
    if (IsEmpty())
    {
        return UNDER_FLOW;
    }
    e = elems_[0];
    return SUCCESS;
}
#endif