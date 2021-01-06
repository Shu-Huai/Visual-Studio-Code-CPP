#pragma once
#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__
#include "Assistance.h"
template <class ElemType>
class SeqStack
{
protected:
    int top_;
    int maxsize_;
    ElemType *elems_;

public:
    SeqStack(int size = DEFAULT_SIZE);
    virtual ~SeqStack();
    int GetLength() const;
    bool IsEmpty() const;
    void Clear();
    void Traverse(void (*Visit)(const ElemType &)) const;
    Status Push(const ElemType e);
    Status Top(ElemType &e) const;
    Status Pop(ElemType &e);
    SeqStack(const SeqStack<ElemType> &SS);
    SeqStack<ElemType> &operator=(const SeqStack<ElemType> &SS);
};
template <class ElemType>
SeqStack<ElemType>::SeqStack(int size) : maxsize_(size), top_(-1)
{
    elems_ = new ElemType[maxsize_];
    assert(elems_);
}
template <class ElemType>
SeqStack<ElemType>::~SeqStack()
{
    delete[] elems_;
}
template <class ElemType>
int SeqStack<ElemType>::GetLength() const
{
    return top_ + 1;
}
template <class ElemType>
bool SeqStack<ElemType>::IsEmpty() const
{
    return top_ == -1;
}
template <class ElemType>
void SeqStack<ElemType>::Clear()
{
    top_ = -1;
}
template <class ElemType>
void SeqStack<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
    for (int i = top_; i >= 0; i--)
    {
        (*Visit)(elems_[i]);
    }
}
template <class ElemType>
Status SeqStack<ElemType>::Push(const ElemType e)
{
    if (top_ == maxsize_)
    {
        return OVER_FLOW;
    }
    elems_[++top_] = e;
    return SUCCESS;
}
template <class ElemType>
Status SeqStack<ElemType>::Top(ElemType &e) const
{
    if (IsEmpty())
    {
        return UNDER_FLOW;
    }
    e = elems_[top_];
    return SUCCESS;
}
template <class ElemType>
Status SeqStack<ElemType>::Pop(ElemType &e)
{
    if (IsEmpty())
    {
        return UNDER_FLOW;
    }
    e = elems_[top_--];
    return SUCCESS;
}
template <class ElemType>
SeqStack<ElemType>::SeqStack(const SeqStack<ElemType> &SS) : maxsize_(SS.maxsize_), top_(SS.top_)
{
    elems_ = new ElemType[maxsize_];
    assert(elems_);
    for (int i = 0; i < top_ + 1; i++)
    {
        elems_[i] = SS.elems_[i];
    }
}
template <class ElemType>
SeqStack<ElemType> &SeqStack<ElemType>::operator=(const SeqStack<ElemType> &SS)
{
    if (&SS != this)
    {
        delete[] elems_;
        maxsize_ = SS.maxsize_;
        top_ = SS.top_;
        elems_ = new ElemType[maxsize_];
        assert(elems_);
        for (int i = 0; i < top_ + 1; i++)
        {
            elems_[i] = SS.elems_[i];
        }
    }
    return *this;
}
#endif