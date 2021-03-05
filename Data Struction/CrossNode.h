#pragma once
#ifndef __CRoSS_NODE__
#define __CRoSS_NODE__
#include "Triple.h"
template <class ElemType>
class CrossNode
{
    Triple<ElemType> *elems_;
    CrossNode<ElemType> *right_;
    CrossNode<ElemType> *down_;
    CrossNode();
    CrossNode(const Triple<ElemType> &e, CrossNode<ElemType> *right = NULL, CrossNode<ElemType> *down=NULL);
};
template <class ElemType>
CrossNode<ElemType>::CrossNode():right_(NULL),down_(NULL)
{
}
template <class ElemType>
CrossNode<ElemType>::CrossNode(const Triple<ElemType> &e, CrossNode<ElemType> *right, CrossNode<ElemType> *down) : right_(right), down_(right)
{
    elems_ = new Triple<ElemType>(e.row_, e.col_, e.data_);
}
#endif