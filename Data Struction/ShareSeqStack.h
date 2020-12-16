#pragma once
#include "Assistance.h"
template <class ElemType>
class ShareSeqStack
{
protected:
    int _top1;
    int _top2;
    int _maxsize;
    ElemType *_elems;

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
ShareSeqStack<ElemType>::ShareSeqStack(int size) : _maxsize(size), _top1(-1), _top2(size)
{
    _elems = new ElemType[_maxsize];
    assert(_elems);
}
template <class ElemType>
ShareSeqStack<ElemType>::~ShareSeqStack()
{
    delete[] _elems;
}
template <class ElemType>
int ShareSeqStack<ElemType>::GetLength(int No) const
{
    if (No == 1)
    {
        return _top1 + 1;
    }
    return _maxsize - _top2;
}
template <class ElemType>
bool ShareSeqStack<ElemType>::IsEmpty(int No) const
{
    if (No == 1)
    {
        return _top1 == -1;
    }
    return _top2 == _maxsize;
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
        _top2 = _maxsize;
    }
}
template <class ElemType>
void ShareSeqStack<ElemType>::Traverse(void (*Visit)(const ElemType &), int No) const
{
    if (No == 1)
    {
        for (int i = _top1; i >= 0; i--)
        {
            (*Visit)(_elems[i]);
        }
    }
    else
    {
        for (int i = _top2; i < _maxsize; i++)
        {
            (*Visit)(_elems[i]);
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
        _elems[++_top1] = e;
    }
    else
    {
        _elems[--_top2] = e;
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
        e = _elems[_top1];
        return SUCCESS;
    }
    e = _elems[_top2];
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
        e = _elems[_top1--];
        return SUCCESS;
    }
    e = _elems[_top2++];
    return SUCCESS;
}
template <class ElemType>
ShareSeqStack<ElemType>::ShareSeqStack(const ShareSeqStack<ElemType> &SSS) : _maxsize(SSS._maxsize), _top1(SSS._top1), _top2(SSS, _top2)
{
    _elems = new ElemType[_maxsize];
    assert(_elems);
    for (int i = 0; i < _top1 + 1; i++)
    {
        _elems[i] = SSS > _elems[i];
    }
    for (int i = _maxsize - 1; i > _top2 - 1; i--)
    {
        _elems[i] = SSS > _elems[i];
    }
}
template <class ElemType>
ShareSeqStack<ElemType> &ShareSeqStack<ElemType>::operator=(const ShareSeqStack<ElemType> &SSS)
{
    if (&SSS == this)
    {
        return *this;
    }
    delete[] _elems;
    _maxsize = SSS._maxsize;
    _top1 = SSS._top1;
    _top2 = SSS._top2;
    _elems = new ElemType[_maxsize];
    assert(_elems);
    for (int i = 0; i < _top1 + 1; i++)
    {
        _elems[i] = SSS._elems[i];
    }
    for (int i = _maxsize - 1; i > _top2 - 1; i--)
    {
        _elems[i] = SSS > _elems[i];
    }
    return *this;
}