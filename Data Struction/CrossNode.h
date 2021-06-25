#pragma once
#ifndef __CRoSS_NODE__
#define __CRoSS_NODE__
#include "Triple.h"
template <class ElemType>
class CrossNode
{
public:
    Triple<ElemType> *elem_;
    CrossNode<ElemType> *right_;
    CrossNode<ElemType> *down_;
    CrossNode();
    CrossNode(const Triple<ElemType> &e, CrossNode<ElemType> *right = NULL, CrossNode<ElemType> *down = NULL);
};
template <class ElemType>
CrossNode<ElemType>::CrossNode() : right_(NULL), down_(NULL)
{
}
template <class ElemType>
CrossNode<ElemType>::CrossNode(const Triple<ElemType> &e, CrossNode<ElemType> *right, CrossNode<ElemType> *down) : right_(right), down_(down)
{
    elem_ = new Triple<ElemType>(e.rowIndex_, e.colIndex_, e.elem_);
}
#endif