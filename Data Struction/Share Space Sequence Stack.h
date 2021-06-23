#pragma once
#ifndef __SHARE_SPACE_SQUENCE_STACK_H__
#define __SHARE_SPACE_SQUENCE_STACK_H__
#include <iostream>
using namespace std;
template <class ElemType>
class ShareSpaceSequenceStack
{
protected:
    int firstTop_;
    int secondTop_;
    int maxSize_;
    ElemType *elems_;

public:
    ShareSpaceSequenceStack(int maxSize = 1000);
    ShareSpaceSequenceStack(const ShareSpaceSequenceStack<ElemType> &stacks);
    virtual ~ShareSpaceSequenceStack();
    void Clear(int number);
    bool IsEmpty(int number) const;
    void Display() const;
    void Traverse(int number) const;
    void Push(int number, const ElemType elem);
    void Pop(int number);
    int GetLength(int number) const;
    ElemType GetTop(int number) const;
    ShareSpaceSequenceStack<ElemType> &operator=(const ShareSpaceSequenceStack<ElemType> &stacks);
};
template <class ElemType>
ShareSpaceSequenceStack<ElemType>::ShareSpaceSequenceStack(int maxSize) : firstTop_(-1), secondTop_(maxSize), maxSize_(maxSize)
{
    elems_ = new ElemType[maxSize_];
}
template <class ElemType>
ShareSpaceSequenceStack<ElemType>::ShareSpaceSequenceStack(const ShareSpaceSequenceStack<ElemType> &stacks) : firstTop_(stacks.firstTop_), secondTop_(stacks, secondTop_), maxSize_(stacks.maxSize_)
{
    elems_ = new ElemType[maxSize_];
    for (int i = 0; i < firstTop_ + 1; i++)
    {
        elems_[i] = stacks.elems_[i];
    }
    for (int i = maxSize_ - 1; i > secondTop_ - 1; i--)
    {
        elems_[i] = stacks.elems_[i];
    }
}
template <class ElemType>
ShareSpaceSequenceStack<ElemType>::~ShareSpaceSequenceStack()
{
    delete[] elems_;
}
template <class ElemType>
void ShareSpaceSequenceStack<ElemType>::Clear(int number)
{
    if (number != 0 && number != 1)
    {
        throw string("范围错误。");
    }
    if (!number)
    {
        firstTop_ = -1;
    }
    else
    {
        secondTop_ = maxSize_;
    }
}
template <class ElemType>
bool ShareSpaceSequenceStack<ElemType>::IsEmpty(int number) const
{
    if (number != 0 && number != 1)
    {
        throw string("范围错误。");
    }
    if (!number)
    {
        return firstTop_ == -1;
    }
    return secondTop_ == maxSize_;
}
template <class ElemType>
void ShareSpaceSequenceStack<ElemType>::Display() const
{
    for (int i = firstTop_; i > -1; i--)
    {
        cout << elems_[i];
        if (i == firstTop_)
        {
            cout << " <- 头";
        }
        cout << endl;
    }
    for (int i = secondTop_; i < maxSize_; i++)
    {
        cout << elems_[i] << " ";
        if (i == secondTop_)
        {
            cout << " <- 头";
        }
        cout << endl;
    }
}
template <class ElemType>
void ShareSpaceSequenceStack<ElemType>::Traverse(int number) const
{
    if (number != 0 && number != 1)
    {
        throw string("范围错误。");
    }
    if (!number)
    {
        for (int i = firstTop_; i > -1; i--)
        {
            cout << elems_[i] << " ";
        }
    }
    else
    {
        for (int i = secondTop_; i < maxSize_; i++)
        {
            cout << elems_[i] << " ";
        }
    }
    cout << endl;
}
template <class ElemType>
void ShareSpaceSequenceStack<ElemType>::Push(int number, const ElemType elem)
{
    if (number != 0 && number != 1)
    {
        throw string("范围错误。");
    }
    if (firstTop_ == secondTop_ - 1)
    {
        throw string("栈满。");
    }
    if (!number)
    {
        elems_[++firstTop_] = elem;
    }
    else
    {
        elems_[--secondTop_] = elem;
    }
}
template <class ElemType>
void ShareSpaceSequenceStack<ElemType>::Pop(int number)
{
    if (number != 0 && number != 1)
    {
        throw string("范围错误。");
    }
    if (IsEmpty(number))
    {
        throw string("栈空。");
    }
    if (!number)
    {
        firstTop_--;
    }
    else
    {
        secondTop_++;
    }
}
template <class ElemType>
int ShareSpaceSequenceStack<ElemType>::GetLength(int number) const
{
    if (number != 0 && number != 1)
    {
        throw string("范围错误。");
    }
    if (number == 1)
    {
        return firstTop_ + 1;
    }
    return maxSize_ - secondTop_;
}
template <class ElemType>
ElemType ShareSpaceSequenceStack<ElemType>::GetTop(int number) const
{
    if (number != 0 && number != 1)
    {
        throw string("范围错误。");
    }
    if (IsEmpty(number))
    {
        throw string("栈空。");
    }
    if (!number)
    {
        return elems_[firstTop_];
    }
    return elems_[secondTop_];
}
template <class ElemType>
ShareSpaceSequenceStack<ElemType> &ShareSpaceSequenceStack<ElemType>::operator=(const ShareSpaceSequenceStack<ElemType> &stacks)
{
    if (&stacks != this)
    {
        delete[] elems_;
        firstTop_ = stacks.firstTop_;
        secondTop_ = stacks.secondTop_;
        maxSize_ = stacks.maxSize_;
        elems_ = new ElemType[maxSize_];
        for (int i = 0; i <= firstTop_; i++)
        {
            elems_[i] = stacks.elems_[i];
        }
        for (int i = maxSize_ - 1; i >= secondTop_; i--)
        {
            elems_[i] = stacks.elems_[i];
        }
    }
    return *this;
}
#endif