#pragma once
#ifndef __DOUBLE_LINK_LIST_NODE_H__
#define __DOUBLE_LINK_LIST_NODE_H__
#include <iostream>
template <class ElemType>
struct DoubleLinkListNode
{
    ElemType data_;
    DoubleLinkListNode<ElemType> *prior_;
    DoubleLinkListNode<ElemType> *next_;
    DoubleLinkListNode();
    DoubleLinkListNode(ElemType data, DoubleLinkListNode<ElemType> *prior = NULL, DoubleLinkListNode<ElemType> *next = NULL);
};
template <class ElemType>
DoubleLinkListNode<ElemType>::DoubleLinkListNode() : prior_(NULL), next_(NULL)
{
}
template <class ElemType>
DoubleLinkListNode<ElemType>::DoubleLinkListNode(ElemType data, DoubleLinkListNode<ElemType> *prior, DoubleLinkListNode<ElemType> *next) : data_(data), prior_(prior), next_(next)
{
}
#endif