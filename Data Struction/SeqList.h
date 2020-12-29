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
    ElemType *elems_;

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
    SeqList(const SeqList<ElemType> &SL);
    SeqList<ElemType> &operator=(const SeqList<ElemType> &SL);
    void DeleteRepeat();
    void Reverse();
    Status DeleteBetween(ElemType low, ElemType high);
};
template <class ElemType>
SeqList<ElemType>::SeqList(int size) : _maxlength(size), _length(0)
{
    elems_ = new ElemType[_maxlength];
    assert(elems_);
}
template <class ElemType>
SeqList<ElemType>::SeqList(ElemType &v, int n, int size) : _maxlength(size), _length(n)
{
    elems_ = new ElemType[_maxlength];
    assert(elems_);
    for (int i = 0; i < _length; i++)
    {
        elems_[i] = v[i];
    }
}
template <class ElemType>
SeqList<ElemType>::~SeqList()
{
    delete[] elems_;
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
        (*visit)(elems_[i]);
    }
}
template <class ElemType>
int SeqList<ElemType>::LocateElem(const ElemType &e) const
{
    for (int i = 0; i < _length; i++)
    {
        if (elems_[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}
template <class ElemType>
Status SeqList<ElemType>::GetElem(int i, ElemType &e) const
{
    if (i < 1 or i > _length)
    {
        return NOT_PRESENT;
    }
    e = elems_[i - 1];
    return ENTRY_FOUND;
}
template <class ElemType>
Status SeqList<ElemType>::SetElem(int i, const ElemType &e)
{
    if (i < 1 or i > _length)
    {
        return RANGE_ERROR;
    }
    elems_[i - 1] = e;
    return SUCCESS;
}
template <class ElemType>
Status SeqList<ElemType>::DeleteElem(int i, ElemType &e)
{
    if (i < 1 or i > _length)
    {
        return RANGE_ERROR;
    }
    e = elems_[i - 1];
    for (int j = i - 1; j < _length - 1; j++)
    {
        elems_[j] = elems_[j + 1];
    }
    elems_[_length - 1] = 0;
    _length--;
    return SUCCESS;
}
template <class ElemType>
Status SeqList<ElemType>::InsertElem(int i, const ElemType &e)
{
    if (_length == _maxlength)
    {
        return OVER_FLOW;
    }
    if (i < 1 or i > _length + 1)
    {
        return RANGE_ERROR;
    }
    for (int j = _length; j > i - 1; j--)
    {
        elems_[j] = elems_[j - 1];
    }
    elems_[i - 1] = e;
    _length++;
    return SUCCESS;
}
template <class ElemType>
Status SeqList<ElemType>::InsertElem(const ElemType &e)
{
    if (_length == _maxlength)
    {
        return OVER_FLOW;
    }
    elems_[_length] = e;
    _length++;
    return SUCCESS;
}
template <class ElemType>
SeqList<ElemType>::SeqList(const SeqList<ElemType> &SL) : _maxlength(SL._maxlength), _length(SL._length)
{
    elems_ = new ElemType[_maxlength];
    assert(elems_);
    for (int i = 0; i < _length; i++)
    {
        elems_[i] = SL.elems_[i];
    }
}
template <class ElemType>
SeqList<ElemType> &SeqList<ElemType>::operator=(const SeqList<ElemType> &SL)
{
    if (&SL == this)
    {
        return *this;
    }
    delete[] elems_;
    _maxlength = SL._maxlength;
    _length = SL._length;
    elems_ = new ElemType[_maxlength];
    assert(elems_);
    for (int i = 0; i < _length; i++)
    {
        for (int i = 0; i < _length; i++)
        {
            elems_[i] = SL.elems_[i];
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
            if (elems_[i] == elems_[j])
            {
                DeleteElem(j + 1, elems_[j]);
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
        ElemType temp = elems_[i];
        elems_[i] = elems_[_length - 1 - i];
        elems_[_length - 1 - i] = temp;
    }
}
template <class ElemType>
Status SeqList<ElemType>::DeleteBetween(ElemType low, ElemType high)
{
    if (low >= high)
    {
        return RANGE_ERROR;
    }
    if (_length == 0)
    {
        return UNDER_FLOW;
    }
    for (int i = 0; i < _length; i++)
    {
        if (elems_[i] > low and elems_[i] < high)
        {
            DeleteElem(i + 1, elems_[i]);
            i--;
        }
    }
    return SUCCESS;
}
#endif