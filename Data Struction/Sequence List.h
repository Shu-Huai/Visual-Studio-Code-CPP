#pragma once
#ifndef __SEQUENCE_LIST_H__
#define __SEQUENCE_LIST_H__
#include "Assistance.h"
template <class ElemType>
class SequenceList
{
protected:
    int length_;
    int maxSize_;
    ElemType *elems_;

public:
    SequenceList(int size = DEFAULT_SIZE);
    SequenceList(ElemType *v, int n, int size = DEFAULT_SIZE);
    SequenceList(const SequenceList<ElemType> &SL);
    virtual ~SequenceList();
    void Clear();
    bool IsEmpty() const;
    void Traverse(void (*Visit)(const ElemType &)) const;
    int GetLength() const;
    Status AppendElem(const ElemType &e);
    Status InsertElem(int i, const ElemType &e);
    Status DeleteElem(int i, ElemType &e);
    Status SetElem(int i, const ElemType &e);
    int LocateElem(const ElemType &e) const;
    Status GetElem(int i, ElemType &e) const;
    void DeleteRepeat();
    void Reverse();
    void Sort();
    Status DeleteBetween(ElemType low, ElemType high);
    SequenceList<ElemType> &operator=(const SequenceList<ElemType> &SL);
};
template <class ElemType>
SequenceList<ElemType>::SequenceList(int size) : length_(0), maxSize_(size)
{
    elems_ = new ElemType[maxSize_];
    assert(elems_);
}
template <class ElemType>
SequenceList<ElemType>::SequenceList(ElemType *v, int n, int size) : length_(n), maxSize_(size)
{
    elems_ = new ElemType[maxSize_];
    assert(elems_);
    for (int i = 0; i < length_; i++)
    {
        elems_[i] = v[i];
    }
}
template <class ElemType>
SequenceList<ElemType>::SequenceList(const SequenceList<ElemType> &SL) : maxSize_(SL.maxSize_), length_(SL.length_)
{
    elems_ = new ElemType[maxSize_];
    assert(elems_);
    for (int i = 0; i < length_; i++)
    {
        elems_[i] = SL.elems_[i];
    }
}
template <class ElemType>
SequenceList<ElemType>::~SequenceList()
{
    delete[] elems_;
}
template <class ElemType>
void SequenceList<ElemType>::Clear()
{
    length_ = 0;
}
template <class ElemType>
bool SequenceList<ElemType>::IsEmpty() const
{
    return length_ == 0;
}
template <class ElemType>
void SequenceList<ElemType>::Traverse(void (*visit)(const ElemType &)) const
{
    for (int i = 0; i < length_; i++)
    {
        (*visit)(elems_[i]);
    }
}
template <class ElemType>
int SequenceList<ElemType>::GetLength() const
{
    return length_;
}
template <class ElemType>
Status SequenceList<ElemType>::AppendElem(const ElemType &e)
{
    if (length_ == maxSize_)
    {
        return OVER_FLOW;
    }
    elems_[length_++] = e;
    return SUCCESS;
}
template <class ElemType>
Status SequenceList<ElemType>::InsertElem(int i, const ElemType &e)
{
    if (length_ == maxSize_)
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
Status SequenceList<ElemType>::DeleteElem(int i, ElemType &e)
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
Status SequenceList<ElemType>::SetElem(int i, const ElemType &e)
{
    if (i < 1 or i > length_)
    {
        return RANGE_ERROR;
    }
    elems_[i - 1] = e;
    return SUCCESS;
}
template <class ElemType>
Status SequenceList<ElemType>::GetElem(int i, ElemType &e) const
{
    if (i < 1 or i > length_)
    {
        return NOT_PRESENT;
    }
    e = elems_[i - 1];
    return ENTRY_FOUND;
}
template <class ElemType>
int SequenceList<ElemType>::LocateElem(const ElemType &e) const
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
void SequenceList<ElemType>::DeleteRepeat()
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
void SequenceList<ElemType>::Reverse()
{
    for (int i = 0; i < length_ / 2; i++)
    {
        ElemType temp = elems_[i];
        elems_[i] = elems_[length_ - 1 - i];
        elems_[length_ - 1 - i] = temp;
    }
}
template <class ElemType>
void SequenceList<ElemType>::Sort()
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
template <class ElemType>
Status SequenceList<ElemType>::DeleteBetween(ElemType low, ElemType high)
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
SequenceList<ElemType> &SequenceList<ElemType>::operator=(const SequenceList<ElemType> &SL)
{
    if (&SL != this)
    {
        delete[] elems_;
        maxSize_ = SL.maxSize_;
        length_ = SL.length_;
        elems_ = new ElemType[maxSize_];
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
#endif