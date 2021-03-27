#pragma once
#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__
#include "Assistance.h"
template <class ElemType>
class SeqList
{
protected:
    int length_;
    int maxsize_;
    ElemType *elems_;

public:
    SeqList(int size = DEFAULT_SIZE);
    SeqList(ElemType *v, int n, int size = DEFAULT_SIZE);
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
    Status AppendElem(const ElemType &e);
    SeqList(const SeqList<ElemType> &SL);
    SeqList<ElemType> &operator=(const SeqList<ElemType> &SL);
    void DeleteRepeat();
    void Reverse();
    Status DeleteBetween(ElemType low, ElemType high);
    void Sort();
};
template <class ElemType>
SeqList<ElemType>::SeqList(int size) : maxsize_(size), length_(0)
{
    elems_ = new ElemType[maxsize_];
    assert(elems_);
}
template <class ElemType>
SeqList<ElemType>::SeqList(ElemType *v, int n, int size) : maxsize_(size), length_(n)
{
    elems_ = new ElemType[maxsize_];
    assert(elems_);
    for (int i = 0; i < length_; i++)
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
    return length_;
}
template <class ElemType>
bool SeqList<ElemType>::IsEmpty() const
{
    return length_ == 0;
}
template <class ElemType>
void SeqList<ElemType>::Clear()
{
    length_ = 0;
}
template <class ElemType>
void SeqList<ElemType>::Traverse(void (*visit)(const ElemType &)) const
{
    for (int i = 0; i < length_; i++)
    {
        (*visit)(elems_[i]);
    }
}
template <class ElemType>
int SeqList<ElemType>::LocateElem(const ElemType &e) const
{
    for (int i = 0; i < length_; i++)
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
    if (i < 1 or i > length_)
    {
        return NOT_PRESENT;
    }
    e = elems_[i - 1];
    return ENTRY_FOUND;
}
template <class ElemType>
Status SeqList<ElemType>::SetElem(int i, const ElemType &e)
{
    if (i < 1 or i > length_)
    {
        return RANGE_ERROR;
    }
    elems_[i - 1] = e;
    return SUCCESS;
}
template <class ElemType>
Status SeqList<ElemType>::DeleteElem(int i, ElemType &e)
{
    if (i < 1 or i > length_)
    {
        return RANGE_ERROR;
    }
    e = elems_[i - 1];
    for (int j = i - 1; j < length_ - 1; j++)
    {
        elems_[j] = elems_[j + 1];
    }
    length_--;
    return SUCCESS;
}
template <class ElemType>
Status SeqList<ElemType>::InsertElem(int i, const ElemType &e)
{
    if (length_ == maxsize_)
    {
        return OVER_FLOW;
    }
    if (i < 1 or i > length_ + 1)
    {
        return RANGE_ERROR;
    }
    for (int j = length_; j > i - 1; j--)
    {
        elems_[j] = elems_[j - 1];
    }
    elems_[i - 1] = e;
    length_++;
    return SUCCESS;
}
template <class ElemType>
Status SeqList<ElemType>::AppendElem(const ElemType &e)
{
    if (length_ == maxsize_)
    {
        return OVER_FLOW;
    }
    elems_[length_++] = e;
    return SUCCESS;
}
template <class ElemType>
SeqList<ElemType>::SeqList(const SeqList<ElemType> &SL) : maxsize_(SL.maxsize_), length_(SL.length_)
{
    elems_ = new ElemType[maxsize_];
    assert(elems_);
    for (int i = 0; i < length_; i++)
    {
        elems_[i] = SL.elems_[i];
    }
}
template <class ElemType>
SeqList<ElemType> &SeqList<ElemType>::operator=(const SeqList<ElemType> &SL)
{
    if (&SL != this)
    {
        delete[] elems_;
        maxsize_ = SL.maxsize_;
        length_ = SL.length_;
        elems_ = new ElemType[maxsize_];
        assert(elems_);
        for (int i = 0; i < length_; i++)
        {
            for (int i = 0; i < length_; i++)
            {
                elems_[i] = SL.elems_[i];
            }
        }
    }
    return *this;
}
template <class ElemType>
void SeqList<ElemType>::DeleteRepeat()
{
    for (int i = 0; i < length_; i++)
    {
        for (int j = i + 1; j < length_; j++)
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
    for (int i = 0; i < length_ / 2; i++)
    {
        ElemType temp = elems_[i];
        elems_[i] = elems_[length_ - 1 - i];
        elems_[length_ - 1 - i] = temp;
    }
}
template <class ElemType>
Status SeqList<ElemType>::DeleteBetween(ElemType low, ElemType high)
{
    if (low >= high)
    {
        return RANGE_ERROR;
    }
    if (!length_)
    {
        return UNDER_FLOW;
    }
    for (int i = 0; i < length_; i++)
    {
        if (elems_[i] > low and elems_[i] < high)
        {
            DeleteElem(i + 1, elems_[i]);
            i--;
        }
    }
    return SUCCESS;
}
template <class ElemType>
void SeqList<ElemType>::Sort()
{
    for (int i = 0; i < length_; i++)
    {
        for (int j = 0; j < length_ - i - 1; j++)
        {
            if (elems_[j] > elems_[j + 1])
            {
                ElemType temp = elems_[j];
                elems_[j] = elems_[j + 1];
                elems_[j + 1] = temp;
            }
        }
    }
}
#endif