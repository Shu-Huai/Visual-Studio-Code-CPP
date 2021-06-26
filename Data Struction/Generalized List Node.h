#pragma once
#ifndef __GENERALIZED_LIST_NODE_H__
#define __GENERALIZED_LIST_NODE_H__
#include <iostream>
template <class ElemType>
class GenListNode
{
protected:
    int tag_;
    union
    {
        int referenceCount_;
        ElemType elem_;
        GenListNode<ElemType> *down_;
    };
    GenListNode<ElemType> *next_;

public:
    GenListNode(int tag = 0, GenListNode<ElemType> *next = NULL);
};
template <class ElemType>
GenListNode<ElemType>::GenListNode(int tag, GenListNode<ElemType> *next)
{
    if (tag)
    tag = tg;
    tLink = next;
}
#endif