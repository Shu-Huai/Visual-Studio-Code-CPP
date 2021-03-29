#pragma once
#ifndef __UNION_FIND_SETS__
#define __UNION_FIND_SETS__
#include "UnionFindSetsElem.h"
template <class ElemType>
class UnionFindSets
{
protected:
    UnionFindSetsElem<ElemType> *sets_;
    int size_;
    int Find(ElemType e) const;

public:
    UnionFindSets(ElemType *v, int n);
    virtual ~UnionFindSets();
    ElemType GetElem(int p) const;
    int GetOrder(ElemType e) const;
    void Union(ElemType a, ElemType b);
    bool Differ(ElemType a, ElemType b);
    UnionFindSets(const UnionFindSets &UFS);
    UnionFindSets &operator=(const UnionFindSets &UFS);
};
template <class ElemType>
int UnionFindSets<ElemType>::Find(ElemType e) const
{
    int p = GetOrder(e);
    if (p == -1)
    {
        return -1;
    }
    while (sets_[p].parent_ > -1)
    {
        p = sets_[p].parent_;
    }
    return p;
}
template <class ElemType>
UnionFindSets<ElemType>::UnionFindSets(ElemType *v, int n) : size_(n)
{
    sets_ = new UnionFindSetsElem<ElemType>[size_];
    assert(sets_);
    for (int i = 0; i < size_; i++)
    {
        sets_[i].data_ = v[i];
        sets_[i].parent_ = -1;
    }
}
template <class ElemType>
UnionFindSets<ElemType>::~UnionFindSets()
{
    delete[] sets_;
}
template <class ElemType>
ElemType UnionFindSets<ElemType>::GetElem(int p) const
{
    return sets_[p].data_;
}
template <class ElemType>
int UnionFindSets<ElemType>::GetOrder(ElemType e) const
{
    int p = 0;
    while (p < size_)
    {
        if (sets_[p].data_ != e)
        {
            p++;
        }
        else
        {
            return p;
        }
    }
    return -1;
}
template <class ElemType>
void UnionFindSets<ElemType>::Union(ElemType a, ElemType b)
{
    int r1 = Find(a);
    int r2 = Find(b);
    if (r1 != r2 and r1 != -1 and r2 != -1)
    {
        if (sets_[r1].parent_ <= sets_[r2].parent_)
        {
            sets_[r1].parent_ += sets_[r2].parent_;
            sets_[r2].parent_ = r1;
        }
        else
        {
            sets_[r2].parent_ += sets_[r1].parent_;
            sets_[r1].parent_ = r2;
        }
    }
}
template <class ElemType>
bool UnionFindSets<ElemType>::Differ(ElemType a, ElemType b)
{
    return Find(a) != Find(b);
}
template <class ElemType>
UnionFindSets<ElemType>::UnionFindSets(const UnionFindSets &UFS) : size_(UFS.size_)
{
    sets_ = new UnionFindSetsElem<ElemType>[size_];
    for (int i = 0; i < size_; i++)
    {
        sets_[i] = UFS.sets_[i];
    }
}
template <class ElemType>
UnionFindSets<ElemType> &UnionFindSets<ElemType>::operator=(const UnionFindSets<ElemType> &UFS)
{
    if (&UFS != this)
    {
        size_ = UFS.size_;
        delete[] sets_;
        sets_ = new UnionFindSetsElem<ElemType>[size_];
        for (int i = 0; i < size_; i++)
        {
            sets_[i] = UFS.sets_[i];
        }
    }
    return *this;
}
#endif