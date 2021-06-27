#pragma once
#ifndef __DOUBLE_LINK_LIST_NODE_H__
#define __DOUBLE_LINK_LIST_NODE_H__
#include <iostream>
template <class ElemType>
class DoubleLinkListNode
{
protected:
    ElemType elem_;
    DoubleLinkListNode<ElemType> *prior_;
    DoubleLinkListNode<ElemType> *next_;

public:
    DoubleLinkListNode();
    DoubleLinkListNode(ElemType elem, DoubleLinkListNode<ElemType> *prior = NULL, DoubleLinkListNode<ElemType> *next = NULL);
    template <class SubElemType>
    friend class DoubleLinkList;
};
template <class ElemType>
DoubleLinkListNode<ElemType>::DoubleLinkListNode() : prior_(NULL), next_(NULL)
{
}
template <class ElemType>
DoubleLinkListNode<ElemType>::DoubleLinkListNode(ElemType elem, DoubleLinkListNode<ElemType> *prior, DoubleLinkListNode<ElemType> *next) : elem_(elem), prior_(prior), next_(next)
{
}
#endif