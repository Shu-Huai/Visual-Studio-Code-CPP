#pragma once
#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__
#include "Assistance.h"
template <class ElemType>
class SeqList
{
protected:
    int _length;
    int _maxlength;
    ElemType *_elems;

public:
    SeqList(int size = DEFAULT_SIZE);
    SeqList(ElemType &v, int n, int size = DEFAULT_SIZE);
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
SeqList<ElemType>::SeqList(int size) : _maxlength(size), _length(0)
{
    _elems = new ElemType[_maxlength];
    assert(_elems);
}
template <class ElemType>
SeqList<ElemType>::SeqList(ElemType &v, int n, int size) : _maxlength(size), _length(n)
{
    _elems = new ElemType[_maxlength];
    assert(_elems);
    for (int i = 0; i < _length; i++)
    {
        _elems[i] = v[i];
    }
}
template <class ElemType>
SeqList<ElemType>::~SeqList()
{
    delete[] _elems;
}
template <class ElemType>
int SeqList<ElemType>::GetLength() const
{
    return _length;
}
template <class ElemType>
bool SeqList<ElemType>::IsEmpty() const
{
    return _length == 0;
}
template <class ElemType>
void SeqList<ElemType>::Clear()
{
    _length = 0;
}
template <class ElemType>
void SeqList<ElemType>::Traverse(void (*visit)(const ElemType &)) const
{
    for (int i = 0; i < _length; i++)
    {
        (*visit)(_elems[i]);
    }
}
template <class ElemType>
int SeqList<ElemType>::LocateElem(const ElemType &e) const
{
    for (int i = 0; i < _length; i++)
    {
        if (_elems[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}
template <class ElemType>
Status SeqList<ElemType>::GetElem(int i, ElemType &e) const
{
    if (i >= 1 and i <= _length)
    {
        e = _elems[i - 1];
        return ENTRY_FOUND;
    }
    else
    {
        return NOT_PRESENT;
    }
}
template <class ElemType>
Status SeqList<ElemType>::SetElem(int i, const ElemType &e)
{
    if (i >= 1 and i <= _length)
    {
        _elems[i - 1] = e;
        return SUCCESS;
    }
    else
    {
        return RANGE_ERROR;
    }
}
template <class ElemType>
Status SeqList<ElemType>::DeleteElem(int i, ElemType &e)
{
    if (i >= 1 and i <= _length)
    {
        e = _elems[i - 1];
        for (int j = i - 1; j < _length - 1; j++)
        {
            _elems[j] = _elems[j + 1];
        }
        _elems[_length - 1] = 0;
        _length--;
        return SUCCESS;
    }
    else
    {
        return RANGE_ERROR;
    }
}
template <class ElemType>
Status SeqList<ElemType>::InsertElem(int i, const ElemType &e)
{
    if (_length == _maxlength)
    {
        return OVER_FLOW;
    }
    if (i >= 1 and i <= _length + 1)
    {
        for (int j = _length; j > i - 1; j--)
        {
            _elems[j] = _elems[j - 1];
        }
        _elems[i - 1] = e;
        _length++;
        return SUCCESS;
    }
    else
    {
        return RANGE_ERROR;
    }
}
template <class ElemType>
Status SeqList<ElemType>::InsertElem(const ElemType &e)
{
    if (_length == _maxlength)
    {
        return OVER_FLOW;
    }
    else
    {
        _elems[_length] = e;
        _length++;
        return SUCCESS;
    }
}
template <class ElemType>
SeqList<ElemType>::SeqList(const SeqList<ElemType> &SL) : _maxlength(SL._maxlength), _length(SL._length)
{
    _elems = new ElemType[_maxlength];
    assert(_elems);
    for (int i = 0; i < _length; i++)
    {
        _elems[i] = SL._elems[i];
    }
}
template <class ElemType>
SeqList<ElemType> &SeqList<ElemType>::operator=(const SeqList<ElemType> &SL)
{
    if (SL == *this)
    {
        return *this;
    }
    delete[] _elems;
    _maxlength = SL._maxlength;
    _length = SL._length;
    _elems = new ElemType[_maxlength];
    assert(_elems);
    for (int i = 0; i < _length; i++)
    {
        for (int i = 0; i < _length; i++)
        {
            _elems[i] = SL._elems[i];
        }
    }
    return *this;
}
template <class ElemType>
void SeqList<ElemType>::DeleteRepeat()
{
    for (int i = 0; i < _length; i++)
    {
        for (int j = i + 1; j < _length; j++)
        {
            if (_elems[i] == _elems[j])
            {
                DeleteElem(j + 1, _elems[j]);
                j--;
            }
        }
    }
}
template <class ElemType>
void SeqList<ElemType>::Reverse()
{
    for (int i = 0; i < _length / 2; i++)
    {
        ElemType temp = _elems[i];
        _elems[i] = _elems[_length - 1 - i];
        _elems[_length - 1 - i] = temp;
    }
}
template <class ElemType>
Status SeqList<ElemType>::DeleteBetween(ElemType s, ElemType t)
{
    if (s >= t)
    {
        return RANGE_ERROR;
    }
    else if (_length == 0)
    {
        return UNDER_FLOW;
    }
    else
    {
        for (int i = 0; i < _length; i++)
        {
            if (_elems[i] > s and _elems[i] < t)
            {
                DeleteElem(i + 1, _elems[i]);
                i--;
            }
        }
        return SUCCESS;
    }
}
#endif
