#pragma once
#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__
#include "Link List Node.h"
using namespace std;
template <class ElemType>
class LinkList
{
protected:
    LinkListNode<ElemType> *head_;
    int length_;

public:
    LinkList();
    LinkList(ElemType *elems, int n);
    LinkList(const LinkList<ElemType> &list);
    virtual ~LinkList();
    void Clear();
    bool IsEmpty() const;
    void Display() const;
    void Traverse() const;
    void AppendElem(const ElemType elem);
    void InsertElem(int index, const ElemType elem);
    void DeleteElem(int index);
    void SetElem(int index, const ElemType elem);
    int GetLength() const;
    int GetIndex(const ElemType elem) const;
    ElemType GetElem(int index) const;
    void SwapElem(int indexA, int indexB);
    void Reverse();
    void DeleteBetween(ElemType minELem, ElemType maxElem);
    void Merge(LinkList<ElemType> &list);
    LinkList<ElemType> &operator=(const LinkList<ElemType> &list);
    ElemType &operator[](int index);
};
template <class ElemType>
LinkList<ElemType>::LinkList() : length_(0)
{
    head_ = new LinkListNode<ElemType>;
}
template <class ElemType>
LinkList<ElemType>::LinkList(ElemType *elems, int n) : length_(n)
{
    head_ = new LinkListNode<ElemType>;
    LinkListNode<ElemType> *p = head_;
    for (int i = 0; i < n; i++)
    {
        p->next_ = new LinkListNode<ElemType>(elems[i], NULL);
        p = p->next_;
    }
}
template <class ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType> &list) : length_(list.GetLength())
{
    head_ = new LinkListNode<ElemType>;
    ElemType elem;
    for (int i = 0; i < list.length_; i++)
    {
        list.GetElem(i + 1, elem);
        AppendElem(elem);
    }
}
template <class ElemType>
LinkList<ElemType>::~LinkList()
{
    Clear();
    delete head_;
}
template <class ElemType>
void LinkList<ElemType>::Clear()
{
    LinkListNode<ElemType> *p = head_->next_;
    while (p)
    {
        head_->next_ = p->next_;
        delete p;
        p = head_->next_;
    }
    length_ = 0;
}
template <class ElemType>
bool LinkList<ElemType>::IsEmpty() const
{
    return head_->next_ == NULL;
}
template <class ElemType>
void LinkList<ElemType>::Display() const
{
    LinkListNode<ElemType> *p = head_->next_;
    while (p)
    {
        cout << p->elem_;
        if (p->next_)
        {
            cout << " -> ";
        }
        p = p->next_;
    }
    cout << endl
         << "The length is: " << length_ << endl;
}
template <class ElemType>
void LinkList<ElemType>::Traverse() const
{
    LinkListNode<ElemType> *p = head_->next_;
    while (p)
    {
        cout << p->elem_ << " ";
        p = p->next_;
    }
    cout << endl;
}
template <class ElemType>
void LinkList<ElemType>::AppendElem(const ElemType elem)
{
    LinkListNode<ElemType> *p = head_;
    while (p->next_)
    {
        p = p->next_;
    }
    p->next_ = new LinkListNode<ElemType>(elem, NULL);
    length_++;
}
template <class ElemType>
void LinkList<ElemType>::InsertElem(int index, const ElemType elem)
{
    if (index < 0 || index >= length_ + 1)
    {
        throw string("Range error.");
    }
    LinkListNode<ElemType> *p = head_;
    for (int i = 0; i < index; i++)
    {
        p = p->next_;
    }
    LinkListNode<ElemType> *q = new LinkListNode<ElemType>(elem, p->next_);
    p->next_ = q;
    length_++;
}
template <class ElemType>
void LinkList<ElemType>::DeleteElem(int index)
{
    if (index < 0 || index >= length_)
    {
        throw string("Range error.");
    }
    LinkListNode<ElemType> *p = head_;
    for (int i = 0; i < index; i++)
    {
        p = p->next_;
    }
    LinkListNode<ElemType> *q = p->next_;
    p->next_ = q->next_;
    delete q;
    length_--;
}
template <class ElemType>
void LinkList<ElemType>::SetElem(int index, const ElemType elem)
{
    if (index < 0 || index >= length_)
    {
        throw string("Range error.");
    }
    LinkListNode<ElemType> *p = head_->next_;
    for (int i = 0; i < index; i++)
    {
        p = p->next_;
    }
    p->elem_ = elem;
}
template <class ElemType>
int LinkList<ElemType>::GetLength() const
{
    return length_;
}
template <class ElemType>
int LinkList<ElemType>::GetIndex(const ElemType elem) const
{
    LinkListNode<ElemType> *p = head_->next_;
    int count = 0;
    while (p && p->elem_ != elem)
    {
        count++;
        p = p->next_;
    }
    return (p) ? count : -1;
}
template <class ElemType>
ElemType LinkList<ElemType>::GetElem(int index) const
{
    if (index < 0 || index >= length_)
    {
        throw string("Range error.");
    }
    LinkListNode<ElemType> *p = head_->next_;
    for (int i = 0; i < index; i++)
    {
        p = p->next_;
    }
    return p->elem_;
}
template <class ElemType>
void LinkList<ElemType>::SwapElem(int indexA, int indexB)
{
    if (indexA < 0 || indexA >= length_ || indexB < 0 || indexB >= length_)
    {
        throw string("Range error.");
    }
    LinkListNode<ElemType> *p = head_;
    for (int i = 0; i < indexA; i++)
    {
        p = p->next_;
    }
    LinkListNode<ElemType> *pointerA = p->next_;
    LinkListNode<ElemType> *q = head_;
    for (int i = 0; i < indexB; i++)
    {
        q = q->next_;
    }
    LinkListNode<ElemType> *pointerB = q->next_;
    LinkListNode<ElemType> *temp = pointerA->next_;
    pointerA->next_ = pointerB->next_;
    pointerB->next_ = temp;
    p->next_ = pointerB;
    q->next_ = pointerA;
}
template <class ElemType>
void LinkList<ElemType>::Reverse()
{
    LinkListNode<ElemType> *p = head_->next_;
    head_->next_ = NULL;
    while (p)
    {
        LinkListNode<ElemType> *q = p->next_;
        p->next_ = head_->next_;
        head_->next_ = p;
        p = q;
    }
}
template <class ElemType>
void LinkList<ElemType>::DeleteBetween(ElemType minELem, ElemType maxElem)
{
    if (minELem > maxElem)
    {
        throw(string) "Minimum element is bigger than maximum element.";
    }
    LinkListNode<ElemType> *p = head_;
    while (p && p->next_)
    {
        if (p->next_->elem_ > minELem && p->next_->elem_ < maxElem)
        {
            LinkListNode<ElemType> *q = p->next_;
            p->next_ = q->next_;
            delete q;
            length_--;
        }
        else
        {
            p = p->next_;
        }
    }
}
template <class ElemType>
void LinkList<ElemType>::Merge(LinkList<ElemType> &list)
{
    LinkListNode<ElemType> *p = head_;
    int i = 0;
    while (p)
    {
        if (i == list.GetLength())
        {
            break;
        }
        ElemType temp;
        temp = list.GetElem(i);
        LinkListNode<ElemType> *t = new LinkListNode<ElemType>;
        t->elem_ = temp;
        if (p->elem_ >= temp && p == head_->next_)
        {
            t->next_ = p;
            head_->next_ = t;
            p = head_;
            i++;
            length_++;
        }
        else if (p->elem_ < temp && !p->next_)
        {
            t->next_ = NULL;
            p->next_ = t;
            i++;
            length_++;
        }
        else if (p->elem_ < temp && p->next_->elem_ >= temp)
        {
            t->next_ = p->next_;
            p->next_ = t;
            i++;
            length_++;
        }
        p = p->next_;
    }
    Reverse();
}
template <class ElemType>
LinkList<ElemType> &LinkList<ElemType>::operator=(const LinkList<ElemType> &list)
{
    if (&list != this)
    {
        Clear();
        ElemType elem;
        for (int i = 0; i < list.length_; i++)
        {
            list.GetElem(i + 1, elem);
            AppendElem(elem);
        }
    }
    return *this;
}
template <class ElemType>
ElemType &LinkList<ElemType>::operator[](int index)
{
    if (index < 0 || index >= length_)
    {
        throw string("Range error.");
    }
    LinkListNode<ElemType> *p = head_->next_;
    for (int i = 0; i < index; i++)
    {
        p = p->next_;
    }
    return p->elem_;
}
#endif