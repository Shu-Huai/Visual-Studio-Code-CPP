#pragma once
#ifndef __LK_STACK_H__
#define __LK_STACK_H__
#include "Assistance.h"
#include "Node.h"
template <class ElemType>
class LinkStack
{
protected:
    Node<ElemType> *_top;

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
    _top = NULL;
}
template <class ElemType>
LinkStack<ElemType>::~LinkStack()
{
    Node<ElemType> *p;
    while (_top != NULL)
    {
        p = _top;
        _top = _top->next;
        delete p;
    }
}
template <class ElemType>
int LinkStack<ElemType>::GetLength() const
{
    int count = 0;
    Node<ElemType> *p = _top;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
template <class ElemType>
bool LinkStack<ElemType>::IsEmpty() const
{
    return _top == NULL;
}
template <class ElemType>
void LinkStack<ElemType>::Clear()
{
    Node<ElemType> *p;
    while (_top != NULL)
    {
        p = _top;
        _top = _top->next;
        delete p;
    }
}
template <class ElemType>
void LinkStack<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
    Node<ElemType> *p = _top;
    while (p != NULL)
    {
        (*Visit)(p->data);
        p = p->next;
    }
}
template <class ElemType>
Status LinkStack<ElemType>::Push(const ElemType e)
{
    Node<ElemType> *p = new Node<ElemType>(e, _top);
    if (p == NULL)
    {
        return OVER_FLOW;
    }
    else
    {
        _top = p;
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
        e = _top->data;
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
        Node<ElemType> *p = _top;
        e = _top->data;
        _top = _top->next;
        delete p;
        return SUCCESS;
    }
}
#endif