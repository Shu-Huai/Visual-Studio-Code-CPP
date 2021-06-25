#pragma once
#ifndef __CROSS_LIST_MATRIX_NODE_H__
#define __CROSS_LIST_MATRIX_NODE_H__
#include "Triple.h"
template <class ElemType>
class CrossListMatrixNode
{
protected:
    Triple<ElemType> *elem_;
    CrossListMatrixNode<ElemType> *right_;
    CrossListMatrixNode<ElemType> *down_;
    template <class SubElemType>
    friend class CrossListMatrix;

public:
    CrossListMatrixNode();
    CrossListMatrixNode(const Triple<ElemType> &elem, CrossListMatrixNode<ElemType> *right = NULL, CrossListMatrixNode<ElemType> *down = NULL);
};
template <class ElemType>
CrossListMatrixNode<ElemType>::CrossListMatrixNode() : elem_(NULL), right_(NULL), down_(NULL)
{
}
template <class ElemType>
CrossListMatrixNode<ElemType>::CrossListMatrixNode(const Triple<ElemType> &elem, CrossListMatrixNode<ElemType> *right, CrossListMatrixNode<ElemType> *down) : right_(right), down_(down)
{
    elem_ = new Triple<ElemType>(elem.rowIndex_, elem.colIndex_, elem.elem_);
}
#endif