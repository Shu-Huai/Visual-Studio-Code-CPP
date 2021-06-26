#pragma once
#ifndef __GENERALIZED_LIST_NODE_H__
#define __GENERALIZED_LIST_NODE_H__
#include <iostream>
using namespace std;
template <class ElemType>
class GeneralizedListNode
{
protected:
    int tag_;
    union
    {
        int referenceCount_;
        ElemType elem_;
        GeneralizedListNode<ElemType> *down_;
    };
    GeneralizedListNode<ElemType> *next_;

public:
    GeneralizedListNode(int tag = 0, GeneralizedListNode<ElemType> *next = NULL);
    template <class SubElemType>
    friend class GeneralizedList;
};
template <class ElemType>
GeneralizedListNode<ElemType>::GeneralizedListNode(int tag, GeneralizedListNode<ElemType> *next)
{
    if (tag < 0 || tag > 2)
    {
        throw string("范围错误。");
    }
    tag_ = tag;
    next_ = next;
}
#endif