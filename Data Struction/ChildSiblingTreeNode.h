#pragma once
#ifndef __CHILD_SIBLING_TREE_NODE_H__
#define __CHILD_SIBLING_TREE_NODE_H__
#include "Assistance.h"
template <class ElemType>
class ChildSiblingTreeNode
{
public:
    ElemType data_;
    ChildSiblingTreeNode<ElemType> *firstChild_;
    ChildSiblingTreeNode<ElemType> *nextSibling_;
    ChildSiblingTreeNode();
    ChildSiblingTreeNode(ElemType data, ChildSiblingTreeNode<ElemType> *firstChild = NULL, ChildSiblingTreeNode<ElemType> *nextSibling = NULL);
};
template <class ElemType>
ChildSiblingTreeNode<ElemType>::ChildSiblingTreeNode() : firstChild_(NULL), nextSibling_(NULL)
{
}
template <class ElemType>
ChildSiblingTreeNode<ElemType>::ChildSiblingTreeNode(ElemType data, ChildSiblingTreeNode<ElemType> *firstChild, ChildSiblingTreeNode<ElemType> *nextSibling)
    : data_(data), firstChild_(firstChild), nextSibling_(nextSibling)
{
}
#endif