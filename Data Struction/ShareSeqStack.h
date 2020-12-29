#pragma once
#ifndef __SHARE_SQ_STACK_H__
#define __SHARE_SQ_STACK_H__
#include "Assistance.h"
template <class ElemType>
class ShareSeqStack
{
protected:
    int _top1;
    int _top2;
    int maxsize_;
    ElemType *elems_;

public:
    ShareSeqStack(int size = DEFAULT_SIZE);
    virtual ~ShareSeqStack();
    int GetLength(int No) const;
    bool IsEmpty(int No) const;
    void Clear(int No);
    void Traverse(void (*Visit)(const ElemType &), int No) const;
    Status Push(const ElemType e, int No);
    Status Top(ElemType &e, int No) const;
    Status Pop(ElemType &e, int No);
    ShareSeqStack(const ShareSeqStack<ElemType> &s);
    ShareSeqStack<ElemType> &operator=(const ShareSeqStack<ElemType> &s);
};
template <class ElemType>
ShareSeqStack<ElemType>::ShareSeqStack(int size) : maxsize_(size), _top1(-1), _top2(size)
{
    elems_ = new ElemType[maxsize_];
    assert(elems_);
}
template <class ElemType>
ShareSeqStack<ElemType>::~ShareSeqStack()
{
    delete[] elems_;
}
template <class ElemType>
int ShareSeqStack<ElemType>::GetLength(int No) const
{
    if (No == 1)
    {
        return _top1 + 1;
    }
    return maxsize_ - _top2;
}
template <class ElemType>
bool ShareSeqStack<ElemType>::IsEmpty(int No) const
{
    if (No == 1)
    {
        return _top1 == -1;
    }
    return _top2 == maxsize_;
}
template <class ElemType>
void ShareSeqStack<ElemType>::Clear(int No)
{
    if (No == 1)
    {
        _top1 = -1;
    }
    else
    {
        _top2 = maxsize_;
    }
}
template <class ElemType>
void ShareSeqStack<ElemType>::Traverse(void (*Visit)(const ElemType &), int No) const
{
    if (No == 1)
    {
        for (int i = _top1; i >= 0; i--)
        {
            (*Visit)(elems_[i]);
        }
    }
    else
    {
        for (int i = _top2; i < maxsize_; i++)
        {
            (*Visit)(elems_[i]);
        }
    }
}
template <class ElemType>
Status ShareSeqStack<ElemType>::Push(const ElemType e, int No)
{
    if (No < 1 or No > 2)
    {
        return RANGE_ERROR;
    }
    if (_top1 == _top2 - 1)
    {
        return OVER_FLOW;
    }
    if (No == 1)
    {
        elems_[++_top1] = e;
    }
    else
    {
        elems_[--_top2] = e;
    }
    return SUCCESS;
}
template <class ElemType>
Status ShareSeqStack<ElemType>::Top(ElemType &e, int No) const
{
    if (No < 1 or No > 2)
    {
        return RANGE_ERROR;
    }
    if (IsEmpty(No))
    {
        return UNDER_FLOW;
    }
    if (No == 1)
    {
        e = elems_[_top1];
        return SUCCESS;
    }
    e = elems_[_top2];
    return SUCCESS;
}
template <class ElemType>
Status ShareSeqStack<ElemType>::Pop(ElemType &e, int No)
{
    if (No < 1 or No > 2)
    {
        return RANGE_ERROR;
    }
    if (IsEmpty(No))
    {
        return UNDER_FLOW;
    }
    if (No == 1)
    {
        e = elems_[_top1--];
        return SUCCESS;
    }
    e = elems_[_top2++];
    return SUCCESS;
}
template <class ElemType>
ShareSeqStack<ElemType>::ShareSeqStack(const ShareSeqStack<ElemType> &SSS) : maxsize_(SSS.maxsize_), _top1(SSS._top1), _top2(SSS, _top2)
{
    elems_ = new ElemType[maxsize_];
    assert(elems_);
    for (int i = 0; i < _top1 + 1; i++)
    {
        elems_[i] = SSS > elems_[i];
    }
    for (int i = maxsize_ - 1; i > _top2 - 1; i--)
    {
        elems_[i] = SSS > elems_[i];
    }
}
template <class ElemType>
ShareSeqStack<ElemType> &ShareSeqStack<ElemType>::operator=(const ShareSeqStack<ElemType> &SSS)
{
    if (&SSS == this)
    {
        return *this;
    }
    delete[] elems_;
    maxsize_ = SSS.maxsize_;
    _top1 = SSS._top1;
    _top2 = SSS._top2;
    elems_ = new ElemType[maxsize_];
    assert(elems_);
    for (int i = 0; i < _top1 + 1; i++)
    {
        elems_[i] = SSS.elems_[i];
    }
    for (int i = maxsize_ - 1; i > _top2 - 1; i--)
    {
        elems_[i] = SSS > elems_[i];
    }
    return *this;
}
#endif