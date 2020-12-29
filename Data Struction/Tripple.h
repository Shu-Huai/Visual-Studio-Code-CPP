#pragma once
#ifndef __TRIPPLE_H__
#define __TRIPPLE_H__
#include "Assistance.h"
template <class ElemType>
struct Tripple
{
    int row_, col_;
    ElemType value_;
    Tripple();
    Tripple(int r, int c, ElemType e);
};
template <class ElemType>
Tripple<ElemType>::Tripple()
{
}
template <class ElemType>
Tripple<ElemType>::Tripple(int r, int c, ElemType e) : row_(r), col_(c), value_(e)
{
}
#endif