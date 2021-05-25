#pragma once
#ifndef __SEQUENCE_LIST_H__
#define __SEQUENCE_LIST_H__
#include <assert.h>
#include <iostream>
using namespace std;
template <class ElemType>
class SequenceList
{
protected:
    int length_;
    int maxSize_;
    ElemType *elems_;

public:
    SequenceList(int size = 1000);
    SequenceList(ElemType *v, int n, int size = 1000);
    SequenceList(const SequenceList<ElemType> &SL);
    virtual ~SequenceList();
    void Clear();
    bool IsEmpty() const;
    void Traverse() const;
    int GetLength() const;
    void AppendElem(const ElemType &e);
    void InsertElem(int i, const ElemType &e);
    void DeleteElem(int i);
    void SetElem(int i, const ElemType &e);
    void Swap(int indexA, int indexB);
    int LocateElem(const ElemType &e) const;
    ElemType GetElem(int i) const;
    void DeleteRepeat();
    void Reverse();
    void Sort();
    void DeleteBetween(ElemType low, ElemType high);
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
void SequenceList<ElemType>::Traverse() const
{
    for (int i = 0; i < length_; i++)
    {
        cout << elems_[i] << " ";
    }
}
template <class ElemType>
int SequenceList<ElemType>::GetLength() const
{
    return length_;
}
template <class ElemType>
void SequenceList<ElemType>::AppendElem(const ElemType &e)
{
    if (length_ == maxSize_)
    {
        throw(string) "Range error.";
    }
    elems_[length_++] = e;
}
template <class ElemType>
void SequenceList<ElemType>::InsertElem(int i, const ElemType &e)
{
    if (length_ == maxSize_)
    {
        throw(string) "Over flow.";
    }
    if (i < 0 or i >= length_ + 1)
    {
        throw(string) "Range error.";
    }
    for (int j = length_; j > i; j--)
    {
        elems_[j] = elems_[j - 1];
    }
    elems_[i] = e;
    length_++;
}
template <class ElemType>
void SequenceList<ElemType>::DeleteElem(int i)
{
    if (i < 0 or i >= length_)
    {
        throw(string) "Range error.";
    }
    for (int j = i; j < length_ - 1; j++)
    {
        elems_[j] = elems_[j + 1];
    }
    length_--;
}
template <class ElemType>
void SequenceList<ElemType>::SetElem(int i, const ElemType &e)
{
    if (i < 0 or i >= length_)
    {
        throw(string) "Range error.";
    }
    elems_[i] = e;
}
template <class ElemType>
void SequenceList<ElemType>::Swap(int indexA, int indexB)
{
    ElemType temp = elems_[indexA];
    elems_[indexA] = elems_[indexB];
    elems_[indexB] = temp;
}
template <class ElemType>
ElemType SequenceList<ElemType>::GetElem(int i) const
{
    if (i < 0 or i >= length_)
    {
        throw(string) "Range error.";
    }
    return elems_[i];
}
template <class ElemType>
int SequenceList<ElemType>::LocateElem(const ElemType &e) const
{
    for (int i = 0; i < length_; i++)
    {
        if (elems_[i] == e)
        {
            return i;
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
                elems_[j] = GetElem(j + 1);
                DeleteElem(j + 1);
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
void SequenceList<ElemType>::DeleteBetween(ElemType low, ElemType high)
{
    if (low >= high)
    {
        throw(string) "Range error.";
    }
    if (!length_)
    {
        throw(string) "Under flow.";
    }
    for (int i = 0; i < length_; i++)
    {
        if (elems_[i] > low and elems_[i] < high)
        {
            elems_[i] = GetElem(i + 1);
            DeleteElem(i + 1);
            i--;
        }
    }
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