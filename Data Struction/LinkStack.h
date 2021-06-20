#pragma once
#ifndef __LK_STACK_H__
#define __LK_STACK_H__
#include "Node.h"
template <class ElemType>
class LinkStack
{
protected:
    LinkListNode<ElemType> *top_;

public:
    LinkStack();
    virtual ~LinkStack();
    int GetLength() const;
    bool IsEmpty() const;
    void Clear();
    void Traverse(void (*Visit)(const ElemType &)) const;
    Status Push(const ElemType e);
    Status Top(ElemType &e) const;
    Status Pop(ElemType &e);
    LinkStack(const LinkStack<ElemType> &s);
    LinkStack<ElemType> &operator=(const LinkStack<ElemType> &s);
};
template <class ElemType>
LinkStack<ElemType>::LinkStack()
{
    top_ = NULL;
}
template <class ElemType>
LinkStack<ElemType>::~LinkStack()
{
    LinkListNode<ElemType> *p;
    while (top_ != NULL)
    {
        p = top_;
        top_ = top_->next_;
        delete p;
    }
}
template <class ElemType>
int LinkStack<ElemType>::GetLength() const
{
    int count = 0;
    LinkListNode<ElemType> *p = top_;
    while (p != NULL)
    {
        count++;
        p = p->next_;
    }
    return count;
}
template <class ElemType>
bool LinkStack<ElemType>::IsEmpty() const
{
    return top_ == NULL;
}
template <class ElemType>
void LinkStack<ElemType>::Clear()
{
    LinkListNode<ElemType> *p;
    while (top_ != NULL)
    {
        p = top_;
        top_ = top_->next_;
        delete p;
    }
}
template <class ElemType>
void LinkStack<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
    LinkListNode<ElemType> *p = top_;
    while (p != NULL)
    {
        (*Visit)(p->elem_);
        p = p->next_;
    }
}
template <class ElemType>
Status LinkStack<ElemType>::Push(const ElemType e)
{
    LinkListNode<ElemType> *p = new LinkListNode<ElemType>(e, top_);
    if (p == NULL)
    {
        return OVER_FLOW;
    }
    else
    {
        top_ = p;
        return SUCCESS;
    }
}
template <class ElemType>
Status LinkStack<ElemType>::Top(ElemType &e) const
{
    if (IsEmpty())
    {
        return UNDER_FLOW;
    }
    else
    {
        e = top_->elem_;
        return SUCCESS;
    }
}
template <class ElemType>
Status LinkStack<ElemType>::Pop(ElemType &e)
{
    if (IsEmpty())
    {
        return UNDER_FLOW;
    }
    else
    {
        LinkListNode<ElemType> *p = top_;
        e = top_->elem_;
        top_ = top_->next_;
        delete p;
        return SUCCESS;
    }
}
#endif