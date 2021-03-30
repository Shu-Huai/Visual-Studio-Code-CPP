#pragma once
#ifndef __CHILD_SIBLING_TREE_NODE_H__
#define __CHILD_SIBLING_TREE_NODE_H__
#include "Assistance.h"
template <class ElemType>
class ChildSiblingTreeNode
{
public:
    ElemType data_;
    ChildSiblingTreeNode<ElemType> *firstchild_;
    ChildSiblingTreeNode<ElemType> *nextsibling_;
    ChildSiblingTreeNode();
    ChildSiblingTreeNode(ElemType data, ChildSiblingTreeNode<ElemType> *firstchild = NULL, ChildSiblingTreeNode<ElemType> *nextsibling = NULL);
};
template <class ElemType>
ChildSiblingTreeNode<ElemType>::ChildSiblingTreeNode() : firstchild_(NULL), nextsibling_(NULL)
{
}
template <class ElemType>
ChildSiblingTreeNode<ElemType>::ChildSiblingTreeNode(ElemType data, ChildSiblingTreeNode<ElemType> *firstchild, ChildSiblingTreeNode<ElemType> *nextsibling)
    : data_(data), firstchild_(firstchild), nextsibling_(nextsibling)
{
}
#endif