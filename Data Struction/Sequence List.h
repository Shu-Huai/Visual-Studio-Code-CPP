#pragma once
#ifndef __SEQUENCE_LIST_H__
#define __SEQUENCE_LIST_H__
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
    SequenceList(int maxSize = 1000);
    SequenceList(ElemType *v, int n, int maxSize = 1000);
    SequenceList(const SequenceList<ElemType> &list);
    virtual ~SequenceList();
    void Clear();
    bool IsEmpty() const;
    void Display() const;
    void Traverse() const;
    void AppendElem(const ElemType &e);
    void InsertElem(int i, const ElemType &e);
    void DeleteElem(int i);
    void SetElem(int i, const ElemType &e);
    int GetLength() const;
    int GetIndex(const ElemType &e) const;
    ElemType GetElem(int i) const;
    void SwapElem(int indexA, int indexB);
    void Reverse();
    void DeleteBetween(ElemType low, ElemType high);
    void DeleteRepeat();
    void Sort();
    SequenceList<ElemType> &operator=(const SequenceList<ElemType> &list);
    ElemType &operator[](int index);
};
template <class ElemType>
SequenceList<ElemType>::SequenceList(int maxSize) : length_(0), maxSize_(maxSize)
{
    elems_ = new ElemType[maxSize_];
}
template <class ElemType>
SequenceList<ElemType>::SequenceList(ElemType *v, int n, int maxSize) : length_(n), maxSize_(maxSize)
{
    elems_ = new ElemType[maxSize_];
    for (int i = 0; i < length_; i++)
    {
        elems_[i] = v[i];
    }
}
template <class ElemType>
SequenceList<ElemType>::SequenceList(const SequenceList<ElemType> &list) : length_(list.length_), maxSize_(list.maxSize_)
{
    elems_ = new ElemType[maxSize_];
    for (int i = 0; i < length_; i++)
    {
        elems_[i] = list.elems_[i];
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
void SequenceList<ElemType>::Display() const
{
    for (int i = 0; i < length_; i++)
    {
        cout << elems_[i] << " ";
        if (i != length_ - 1)
        {
            cout << "，";
        }
    }
    cout << endl
         << "长度是：" << length_ << endl;
}
template <class ElemType>
void SequenceList<ElemType>::Traverse() const
{
    for (int i = 0; i < length_; i++)
    {
        cout << elems_[i] << " ";
    }
    cout << endl;
}
template <class ElemType>
void SequenceList<ElemType>::AppendElem(const ElemType &e)
{
    if (length_ == maxSize_)
    {
        throw string("范围错误。");
    }
    elems_[length_++] = e;
}
template <class ElemType>
void SequenceList<ElemType>::InsertElem(int i, const ElemType &e)
{
    if (length_ == maxSize_)
    {
        throw(string) "溢出。";
    }
    if (i < 0 or i >= length_ + 1)
    {
        throw string("范围错误。");
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
        throw string("范围错误。");
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
        throw string("范围错误。");
    }
    elems_[i] = e;
}
template <class ElemType>
int SequenceList<ElemType>::GetLength() const
{
    return length_;
}
template <class ElemType>
int SequenceList<ElemType>::GetIndex(const ElemType &e) const
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
ElemType SequenceList<ElemType>::GetElem(int i) const
{
    if (i < 0 or i >= length_)
    {
        throw string("范围错误。");
    }
    return elems_[i];
}
template <class ElemType>
void SequenceList<ElemType>::SwapElem(int indexA, int indexB)
{
    ElemType temp = elems_[indexA];
    elems_[indexA] = elems_[indexB];
    elems_[indexB] = temp;
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
void SequenceList<ElemType>::DeleteBetween(ElemType low, ElemType high)
{
    if (low >= high)
    {
        throw string("范围错误。");
    }
    if (!length_)
    {
        throw(string) "顺序表空。";
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
void SequenceList<ElemType>::Sort()
{
    for (int i = 0; i < length_; i++)
    {
        for (int j = 0; j < length_ - i - 1; j++)
        {
            if (elems_[j] > elems_[j + 1])
            {
                SwapElem(j, j + 1);
            }
        }
    }
}
template <class ElemType>
SequenceList<ElemType> &SequenceList<ElemType>::operator=(const SequenceList<ElemType> &list)
{
    if (&list != this)
    {
        delete[] elems_;
        maxSize_ = list.maxSize_;
        length_ = list.length_;
        elems_ = new ElemType[maxSize_];
        for (int i = 0; i < length_; i++)
        {
            for (int i = 0; i < length_; i++)
            {
                elems_[i] = list.elems_[i];
            }
        }
    }
    return *this;
}
template <class ElemType>
ElemType &SequenceList<ElemType>::operator[](int index)
{
    if (index < 0 || index > length_)
    {
        throw string("范围错误。");
    }
    return elems_[index];
}
#endif