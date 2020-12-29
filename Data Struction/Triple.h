#pragma once
#ifndef __TRIPLE_H__
#define __TRIPLE_H__
#include "Assistance.h"
template <class ElemType>
struct Triple
{
    int row_, col_;
    ElemType value_;
    Triple();
    Triple(int r, int c, ElemType e);
};
template <class ElemType>
Triple<ElemType>::Triple()
{
}
template <class ElemType>
Triple<ElemType>::Triple(int r, int c, ElemType e) : row_(r), col_(c), value_(e)
{
}
#endif