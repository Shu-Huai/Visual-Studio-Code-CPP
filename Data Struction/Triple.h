#pragma once
#ifndef __TRIPLE_H__
#define __TRIPLE_H__
#include <iostream>
using namespace std;
template <class ElemType>
class Triple
{
protected:
    int rowIndex_;
    int colIndex_;
    ElemType elem_;

public:
    Triple();
    Triple(int rowIndex, int colIndex, ElemType elem);
    Triple<ElemType> &operator=(const Triple<ElemType> &triple);
    template <class SubElemType>
    friend ostream &operator<<(ostream &out, Triple<SubElemType> &triple);
    template <class SubElemType>
    friend class TripleSparseMatrix;
    template <class SubElemType>
    friend class CrossListMatrix;
    template <class SubElemType>
    friend class CrossListMatrixNode;
};
template <class ElemType>
Triple<ElemType>::Triple()
{
}
template <class ElemType>
Triple<ElemType>::Triple(int rowIndex, int colIndex, ElemType elem) : rowIndex_(rowIndex), colIndex_(colIndex), elem_(elem)
{
}
template <class ElemType>
Triple<ElemType> &Triple<ElemType>::operator=(const Triple<ElemType> &triple)
{
    if (&triple != this)
    {
        rowIndex_ = triple.rowIndex_;
        colIndex_ = triple.colIndex_;
        elem_ = triple.elem_;
    }
    return *this;
}
template <class SubElemType>
ostream &operator<<(ostream &out, Triple<SubElemType> &triple)
{
    out << "（" << triple.rowIndex_ << "，" << triple.colIndex_ << "，" << triple.elem_ << "）";
    return out;
}
#endif