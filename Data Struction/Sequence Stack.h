#pragma once
#ifndef __SEQUENCE_STACK_H__
#define __SEQUENCE_STACK_H__
#include <iostream>
using namespace std;
template <class ElemType>
class SequenceStack
{
protected:
    int top_;
    int maxSize_;
    ElemType *elems_;

public:
    SequenceStack(int maxSize = 1000);
    SequenceStack(const SequenceStack<ElemType> &stack);
    virtual ~SequenceStack();
    void Clear();
    bool IsEmpty() const;
    void Display() const;
    void Traverse() const;
    void Push(const ElemType elem);
    void Pop();
    int GetLength() const;
    ElemType GetTop() const;
    SequenceStack<ElemType> &operator=(const SequenceStack<ElemType> &stack);
};
template <class ElemType>
SequenceStack<ElemType>::SequenceStack(int maxSize) : top_(-1), maxSize_(maxSize)
{
    elems_ = new ElemType[maxSize_];
}
template <class ElemType>
SequenceStack<ElemType>::SequenceStack(const SequenceStack<ElemType> &stack) : top_(stack.top_), maxSize_(stack.maxSize_)
{
    elems_ = new ElemType[maxSize_];
    for (int i = 0; i < top_ + 1; i++)
    {
        elems_[i] = stack.elems_[i];
    }
}
template <class ElemType>
SequenceStack<ElemType>::~SequenceStack()
{
    delete[] elems_;
}
template <class ElemType>
void SequenceStack<ElemType>::Clear()
{
    top_ = -1;
}
template <class ElemType>
bool SequenceStack<ElemType>::IsEmpty() const
{
    return top_ == -1;
}
template <class ElemType>
void SequenceStack<ElemType>::Display() const
{
    for (int i = top_; i >= 0; i--)
    {
        cout << elems_[i];
        if (i == top_)
        {
            cout << " <- 栈顶";
        }
        cout << endl;
    }
    cout << "最大大小是：" << maxSize_ << endl;
}
template <class ElemType>
void SequenceStack<ElemType>::Traverse() const
{
    for (int i = top_; i >= 0; i--)
    {
        cout << elems_[i] << " ";
    }
    cout << endl;
}
template <class ElemType>
void SequenceStack<ElemType>::Push(const ElemType elem)
{
    if (top_ == maxSize_)
    {
        throw string("栈满。");
    }
    elems_[++top_] = elem;
}
template <class ElemType>
void SequenceStack<ElemType>::Pop()
{
    if (IsEmpty())
    {
        throw string("栈空。");
    }
    top_--;
}
template <class ElemType>
int SequenceStack<ElemType>::GetLength() const
{
    return top_ + 1;
}
template <class ElemType>
ElemType SequenceStack<ElemType>::GetTop() const
{
    if (IsEmpty())
    {
        throw string("栈空。");
    }
    return elems_[top_];
}
template <class ElemType>
SequenceStack<ElemType> &SequenceStack<ElemType>::operator=(const SequenceStack<ElemType> &stack)
{
    if (&stack != this)
    {
        delete[] elems_;
        maxSize_ = stack.maxSize_;
        top_ = stack.top_;
        elems_ = new ElemType[maxSize_];
        for (int i = 0; i < top_ + 1; i++)
        {
            elems_[i] = stack.elems_[i];
        }
    }
    return *this;
}
#endif