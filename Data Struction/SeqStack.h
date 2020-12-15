#pragma once
#include "Assistance.h"
template <class ElemType>
class SeqStack
{
protected:
    int _top;
    int _maxsize;
    ElemType *_elems;

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
    SeqStack(const SeqStack<ElemType> &s);
    SeqStack<ElemType> &operator=(const SeqStack<ElemType> &s);
};
template <class ElemType>
SeqStack<ElemType>::SeqStack(int size)
{
    _maxsize = size;
    _elems = new ElemType[_maxsize];
    _top = -1;
}
template <class ElemType>
SeqStack<ElemType>::~SeqStack()
{
    delete[] _elems;
}
template <class ElemType>
int SeqStack<ElemType>::GetLength() const
{
    return (_top + 1);
}
template <class ElemType>
bool SeqStack<ElemType>::IsEmpty() const
{
    return (_top == -1);
}
template <class ElemType>
void SeqStack<ElemType>::Clear()
{
    _top = -1;
}
template <class ElemType>
void SeqStack<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
    for (int i = _top; i >= 0; i--)
    {
        (*Visit)(_elems[i]);
    }
}
template <class ElemType>
Status SeqStack<ElemType>::Push(const ElemType e)
{
    if (_top == _maxsize)
    {
        return OVER_FLOW;
    }
    else
    {
        _elems[++_top] = e;
        return SUCCESS;
    }
}
template <class ElemType>
Status SeqStack<ElemType>::Top(ElemType &e) const
{
    if (IsEmpty())
    {
        return UNDER_FLOW;
    }
    else
    {
        e = _elems[_top];
        return SUCCESS;
    }
}
template <class ElemType>
Status SeqStack<ElemType>::Pop(ElemType &e)
{
    if (IsEmpty())
    {
        return UNDER_FLOW;
    }
    else
    {
        e = _elems[_top--];
        return SUCCESS;
    }
}
template <class ElemType>
SeqStack<ElemType>::SeqStack(const SeqStack<ElemType> &s)
{
    ElemType e;
    _maxsize = s._maxsize;
    _elems = new ElemType[_maxsize];
    _top = s._top;
    for (int i = 0; i < s.GetLength(); i++)
    {
        _elems[i] = s._elems[i];
    }
}
template <class ElemType>
SeqStack<ElemType> &SeqStack<ElemType>::operator=(const SeqStack<ElemType> &s)
{
    if (&s != this)
    {
        ElemType e;
        _maxsize = s._maxsize;
        if (_elems)
        {
            delete[] _elems;
        }
        _elems = new ElemType[_maxsize];
        _top = s._top;
        for (int i = 0; i < s.GetLength(); i++)
        {
            _elems[i] = s._elems[i];
        }
    }
    return *this;
}