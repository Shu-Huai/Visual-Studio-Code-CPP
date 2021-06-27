#pragma once
#ifndef __LINK_LIST_NODE_H__
#define __LINK_LIST_NODE_H__
#include <iostream>
template <class ElemType>
class LinkListNode
{
protected:
    ElemType elem_;
    LinkListNode<ElemType> *next_;

public:
    LinkListNode();
    LinkListNode(ElemType elem, LinkListNode<ElemType> *next = NULL);
    template <class SubElemType>
    friend class LinkList;
    template <class SubElemType>
    friend class LinkListWithoutHead;
    template <class SubElemType>
    friend class LinkStack;
    template <class SubElemType>
    friend class LinkQueue;
};
template <class ElemType>
LinkListNode<ElemType>::LinkListNode() : next_(NULL)
{
}
template <class ElemType>
LinkListNode<ElemType>::LinkListNode(ElemType elem, LinkListNode<ElemType> *next) : elem_(elem), next_(next)
{
}
#endif
