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
    SequenceList(ElemType *elems, int n, int maxSize = 1000);
    SequenceList(const SequenceList<ElemType> &list);
    virtual ~SequenceList();
    void Clear();
    bool IsEmpty() const;
    void Display() const;
    void Traverse() const;
    void AppendElem(const ElemType &elem);
    void InsertElem(int index, const ElemType &elem);
    void DeleteElem(int index);
    void SetElem(int index, const ElemType &elem);
    int GetLength() const;
    int GetIndex(const ElemType &elem) const;
    ElemType GetElem(int index) const;
    void SwapElem(int firstIndex, int secondIndex);
    void Reverse();
    void DeleteBetween(ElemType &minElem, ElemType &maxElem);
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
SequenceList<ElemType>::SequenceList(ElemType *elems, int n, int maxSize) : length_(n), maxSize_(maxSize)
{
    elems_ = new ElemType[maxSize_];
    for (int i = 0; i < length_; i++)
    {
        elems_[i] = elems[i];
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
void SequenceList<ElemType>::AppendElem(const ElemType &elem)
{
    if (length_ == maxSize_)
    {
        throw string("范围错误。");
    }
    elems_[length_++] = elem;
}
template <class ElemType>
void SequenceList<ElemType>::InsertElem(int index, const ElemType &elem)
{
    if (length_ == maxSize_)
    {
        throw(string) "溢出。";
    }
    if (index < 0 || index >= length_ + 1)
    {
        throw string("范围错误。");
    }
    for (int j = length_; j > index; j--)
    {
        elems_[j] = elems_[j - 1];
    }
    elems_[index] = elem;
    length_++;
}
template <class ElemType>
void SequenceList<ElemType>::DeleteElem(int index)
{
    if (index < 0 || index >= length_)
    {
        throw string("范围错误。");
    }
    for (int j = index; j < length_ - 1; j++)
    {
        elems_[j] = elems_[j + 1];
    }
    length_--;
}
template <class ElemType>
void SequenceList<ElemType>::SetElem(int index, const ElemType &elem)
{
    if (index < 0 || index >= length_)
    {
        throw string("范围错误。");
    }
    elems_[index] = elem;
}
template <class ElemType>
int SequenceList<ElemType>::GetLength() const
{
    return length_;
}
template <class ElemType>
int SequenceList<ElemType>::GetIndex(const ElemType &elem) const
{
    for (int i = 0; i < length_; i++)
    {
        if (elems_[i] == elem)
        {
            return i;
        }
    }
    return 0;
}
template <class ElemType>
ElemType SequenceList<ElemType>::GetElem(int index) const
{
    if (index < 0 || index >= length_)
    {
        throw string("范围错误。");
    }
    return elems_[index];
}
template <class ElemType>
void SequenceList<ElemType>::SwapElem(int firstIndex, int secondIndex)
{
    ElemType temp = elems_[firstIndex];
    elems_[firstIndex] = elems_[secondIndex];
    elems_[secondIndex] = temp;
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
void SequenceList<ElemType>::DeleteBetween(ElemType &minElem, ElemType &maxElem)
{
    if (minElem >= maxElem)
    {
        throw string("范围错误。");
    }
    if (!length_)
    {
        throw(string) "顺序表空。";
    }
    for (int i = 0; i < length_; i++)
    {
        if (elems_[i] > minElem and elems_[i] < maxElem)
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
            elems_[i] = list.elems_[i];
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