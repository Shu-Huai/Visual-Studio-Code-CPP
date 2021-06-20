#pragma once
#ifndef __LINK_STACK_H__
#define __LINK_STACK_H__
#include "Link List Node.h"
using namespace std;
template <class ElemType>
class LinkStack
{
protected:
    LinkListNode<ElemType> *top_;

public:
    LinkStack();
    LinkStack(const LinkStack<ElemType> &stack);
    virtual ~LinkStack();
    void Clear();
    bool IsEmpty() const;
    void Display() const;
    void Traverse() const;
    void Push(const ElemType elem);
    void Pop();
    int GetLength() const;
    ElemType Top() const;
    LinkStack<ElemType> &operator=(const LinkStack<ElemType> &stack);
};
template <class ElemType>
LinkStack<ElemType>::LinkStack()
{
    top_ = NULL;
}
template <class ElemType>
LinkStack<ElemType>::LinkStack(const LinkStack<ElemType> &stack)
{
    top_ = new LinkListNode<ElemType>;
    LinkListNode<ElemType> *p = stack.top_;
    top_->elem_ = p->elem_;
    LinkListNode<ElemType> *q = new LinkListNode<ElemType>;
    top_->next_ = q;
    q = q->next_;
    ElemType elem;
    while (p)
    {
        q->elem_ = p->elem_;
        if (p->next_)
        {
            q->next_ = new LinkListNode<ElemType>;
        }
        else
        {
            q->next_ = NULL;
        }
        p = p->next_;
        q = q->next_;
    }
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
bool LinkStack<ElemType>::IsEmpty() const
{
    return top_ == NULL;
}
template <class ElemType>
void LinkStack<ElemType>::Display() const
{
    LinkListNode<ElemType> *p = top_;
    while (p)
    {
        cout << p->elem_;
        if (p == top_)
        {
            cout << " <- top";
        }
        cout << endl;
        p = p->next_;
    }
}
template <class ElemType>
void LinkStack<ElemType>::Traverse() const
{
    LinkListNode<ElemType> *p = top_;
    while (p)
    {
        cout << p->elem_ << " ";
        p = p->next_;
    }
    cout << endl;
}
template <class ElemType>
void LinkStack<ElemType>::Push(const ElemType elem)
{
    LinkListNode<ElemType> *p = new LinkListNode<ElemType>(elem, top_);
    top_ = p;
}
template <class ElemType>
void LinkStack<ElemType>::Pop()
{
    if (IsEmpty())
    {
        throw string("The stack is empty.");
    }
    LinkListNode<ElemType> *p = top_;
    top_ = top_->next_;
    delete p;
}
template <class ElemType>
int LinkStack<ElemType>::GetLength() const
{
    int count = 0;
    LinkListNode<ElemType> *p = top_;
    while (p)
    {
        count++;
        p = p->next_;
    }
    return count;
}
template <class ElemType>
ElemType LinkStack<ElemType>::Top() const
{
    if (IsEmpty())
    {
        throw string("The stack is empty.");
    }
    return top_->elem_;
}
template <class ElemType>
LinkStack<ElemType> &LinkStack<ElemType>::operator=(const LinkStack<ElemType> &stack)
{
    if (&stack != this)
    {
        Clear();
        top_ = new LinkListNode<ElemType>;
        LinkListNode<ElemType> *p = stack.top_;
        top_->elem_ = p->elem_;
        LinkListNode<ElemType> *q = new LinkListNode<ElemType>;
        top_->next_ = q;
        q = q->next_;
        ElemType elem;
        while (p)
        {
            q->elem_ = p->elem_;
            if (p->next_)
            {
                q->next_ = new LinkListNode<ElemType>;
            }
            else
            {
                q->next_ = NULL;
            }
            p = p->next_;
            q = q->next_;
        }
    }
    return *this;
}
#endif