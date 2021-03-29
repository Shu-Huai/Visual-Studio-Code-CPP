#pragma once
#ifndef __UNION_FIND_SETS_ELEM__
#define __UNION_FIND_SETS_ELEM__
#include "Assistance.h"
template <class ElemType>
class UnionFindSetsElem
{
public:
    ElemType data_;
    int parent_;
};
#endif