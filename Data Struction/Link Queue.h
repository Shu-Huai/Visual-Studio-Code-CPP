#pragma once
#ifndef __LINK_QUEUE_H__
#define __LINK_QUEUE_H__
#include "Link List Node.h"
using namespace std;
template <class ElemType>
class LinkQueue
{
protected:
    LinkListNode<ElemType> *front_;
    LinkListNode<ElemType> *rear_;

public:
    LinkQueue();
    LinkQueue(const LinkQueue<ElemType> &queue);
    virtual ~LinkQueue();
    void Clear();
    bool IsEmpty() const;
    void Display() const;
    void Traverse() const;
    void Push(const ElemType elem);
    void Pop();
    int GetLength() const;
    ElemType GetFront() const;
    LinkQueue<ElemType> &operator=(const LinkQueue<ElemType> &queue);
};
template <class ElemType>
LinkQueue<ElemType>::LinkQueue()
{
    rear_ = new LinkListNode<ElemType>;
    front_ = new LinkListNode<ElemType>;
}
template <class ElemType>
LinkQueue<ElemType>::LinkQueue(const LinkQueue<ElemType> &queue)
{
    rear_ = new LinkListNode<ElemType>;
    front_ = new LinkListNode<ElemType>;
    for (LinkListNode<ElemType> *p = queue.front_->next_; p; p = p->next_)
    {
        Push(p->elem_);
    }
}
template <class ElemType>
LinkQueue<ElemType>::~LinkQueue()
{
    Clear();
    delete front_;
}
template <class ElemType>
void LinkQueue<ElemType>::Clear()
{
    LinkListNode<ElemType> *p = front_->next_;
    while (p)
    {
        front_->next_ = p->next_;
        delete p;
        p = front_->next_;
    }
    rear_ = front_;
}
template <class ElemType>
bool LinkQueue<ElemType>::IsEmpty() const
{
    return rear_ == front_;
}
template <class ElemType>
void LinkQueue<ElemType>::Display() const
{
    for (LinkListNode<ElemType> *p = front_->next_; p; p = p->next_)
    {
        cout << p->elem_ << " ";
        if (p == front_->next_)
        {
            cout << " <- 头";
        }
        else if (!p->next_)
        {
            cout << " <- 尾";
        }
        cout << endl;
    }
    cout << "长度是：" << GetLength() << endl;
}
template <class ElemType>
void LinkQueue<ElemType>::Traverse() const
{
    for (LinkListNode<ElemType> *p = front_->next_; p; p = p->next_)
    {
        cout << p->elem_ << " ";
    }
    cout << endl;
}
template <class ElemType>
void LinkQueue<ElemType>::Push(const ElemType elem)
{
    LinkListNode<ElemType> *p = new LinkListNode<ElemType>(elem, NULL);
    rear_->next_ = p;
    rear_ = rear_->next_;
}
template <class ElemType>
void LinkQueue<ElemType>::Pop()
{
    if (rear_ == front_)
    {
        throw string("队空。");
    }
    LinkListNode<ElemType> *p = front_->next_;
    front_->next_ = p->next_;
    if (rear_ == p)
    {
        rear_ = front_;
    }
    delete p;
}
template <class ElemType>
int LinkQueue<ElemType>::GetLength() const
{
    int count = 0;
    for (LinkListNode<ElemType> *p = front_->next_; p; p = p->next_)
    {
        count++;
    }
    return count;
}
template <class ElemType>
ElemType LinkQueue<ElemType>::GetFront() const
{
    if (rear_ == front_)
    {
        throw string("队空。");
    }
    return front_->next_->elem_;
}
template <class ElemType>
LinkQueue<ElemType> &LinkQueue<ElemType>::operator=(const LinkQueue<ElemType> &queue)
{
    if (&queue != this)
    {
        Clear();
        for (LinkListNode<ElemType> *p = queue.front_->next_; p; p = p->next_)
        {
            Push(p->elem_);
        }
    }
    return *this;
}
#endif
