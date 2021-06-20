#pragma once
#ifndef __UNION_FIND_SETS_ELEM_H__
#define __UNION_FIND_SETS_ELEM_H__
#include "Assistance.h"
template <class ElemType>
class UnionFindSetsElem
{
public:
    ElemType elem_;
    int parent_;
    UnionFindSetsElem();
    Status SetData(ElemType data);
    Status SetParent(int parent);
    ElemType GetData() const;
    int GetParent() const;
    UnionFindSetsElem &operator=(const UnionFindSetsElem &UFSE);
};
template <class ElemType>
UnionFindSetsElem<ElemType>::UnionFindSetsElem()
{
}
template <class ElemType>
Status UnionFindSetsElem<ElemType>::SetData(ElemType data)
{
    elem_ = data;
    return SUCCESS;
}
template <class ElemType>
Status UnionFindSetsElem<ElemType>::SetParent(int parent)
{
    parent_ = parent;
    return SUCCESS;
}
template <class ElemType>
ElemType UnionFindSetsElem<ElemType>::GetData() const
{
    return elem_;
}
template <class ElemType>
int UnionFindSetsElem<ElemType>::GetParent() const
{
    return parent_;
}
template <class ElemType>
UnionFindSetsElem<ElemType> &UnionFindSetsElem<ElemType>::operator=(const UnionFindSetsElem &UFSE)
{
    if (&UFSE != this)
    {
        elem_ = UFSE.elem_;
        parent_ = UFSE.parent_;
    }
    return *this;
}
#endif