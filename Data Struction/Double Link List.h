#pragma once
#ifndef __DOUBLE_LINK_LIST_H__
#define __DOUBLE_LINK_LIST_H__
#include "Double Link List Node.h"
using namespace std;
template <class ElemType>
class DoubleLinkList
{
protected:
    DoubleLinkListNode<ElemType> *head_;
    int length_;

public:
    DoubleLinkList();
    DoubleLinkList(ElemType *elems, int length);
    DoubleLinkList(const DoubleLinkList<ElemType> &DLL);
    virtual ~DoubleLinkList();
    void Clear();
    bool IsEmpty() const;
    void Traverse() const;
    void AppendElem(const ElemType &elem);
    void InsertElem(int position, const ElemType &elem);
    void DeleteElem(int position, ElemType &elem);
    void SetElem(int position, const ElemType &elem);
    void SwapElem(int positionA, int positionB);
    int GetLength() const;
    int LocateElem(const ElemType &elem) const;
    ElemType GetElem(int position) const;
    DoubleLinkList<ElemType> &operator=(const DoubleLinkList<ElemType> &DLL);
};
template <class ElemType>
DoubleLinkList<ElemType>::DoubleLinkList() : length_(0)
{
    head_ = new DoubleLinkListNode<ElemType>;
    head_->prior_ = head_;
    head_->next_ = head_;
}
template <class ElemType>
DoubleLinkList<ElemType>::DoubleLinkList(ElemType *elems, int length) : length_(length)
{
    head_ = new DoubleLinkListNode<ElemType>;
    DoubleLinkListNode<ElemType> *p = head_;
    for (int i = 0; i < length; i++)
    {
        p->next_ = new DoubleLinkListNode<ElemType>(elems[i], p, NULL);
        p = p->next_;
    }
    head_->prior_ = p;
    p->next_ = head_;
}
template <class ElemType>
DoubleLinkList<ElemType>::DoubleLinkList(const DoubleLinkList<ElemType> &DLL) : length_(DLL.length_)
{
    head_ = new DoubleLinkListNode<ElemType>;
    *this = DLL;
}
template <class ElemType>
DoubleLinkList<ElemType>::~DoubleLinkList()
{
    Clear();
    delete head_;
}
template <class ElemType>
void DoubleLinkList<ElemType>::Clear()
{
    DoubleLinkListNode<ElemType> *p = head_->next_;
    while (p != head_)
    {
        head_->next_ = p->next_;
        delete p;
        p = head_->next_;
    }
    length_ = 0;
}
template <class ElemType>
bool DoubleLinkList<ElemType>::IsEmpty() const
{
    return head_->next_ == head_;
}
template <class ElemType>
void DoubleLinkList<ElemType>::Traverse() const
{
    DoubleLinkListNode<ElemType> *p = head_->next_;
    while (p != head_)
    {
        cout << p->data_ << " ";
        p = p->next_;
    }
}
template <class ElemType>
void DoubleLinkList<ElemType>::AppendElem(const ElemType &elem)
{
    DoubleLinkListNode<ElemType> *p = new DoubleLinkListNode<ElemType>(elem, head_->prior_, head_);
    head_->prior_->next_ = p;
    head_->prior_ = p;
    length_++;
}
template <class ElemType>
void DoubleLinkList<ElemType>::InsertElem(int position, const ElemType &elem)
{
    if (position < 0 || position >= length_ + 2)
    {
        throw(string) "Range error.";
    }
    DoubleLinkListNode<ElemType> *p = head_;
    for (int i = 0; i <= position - 1; i++)
    {
        p = p->next_;
    }
    DoubleLinkListNode<ElemType> *q = new DoubleLinkListNode<ElemType>(elem, p, p->next_);
    p->next_ = q;
    length_++;
}
template <class ElemType>
void DoubleLinkList<ElemType>::DeleteElem(int position, ElemType &elem)
{
    if (position < 0 || position >= length_)
    {
        throw(string) "Range error.";
    }
    DoubleLinkListNode<ElemType> *p = head_;
    for (int i = 0; i <= position; i++)
    {
        p = p->next_;
    }
    p->prior_->next_ = p->next_;
    p->next_->prior_ = p->prior_;
    elem = p->data_;
    delete p;
    length_--;
}
template <class ElemType>
void DoubleLinkList<ElemType>::SetElem(int position, const ElemType &elem)
{
    if (position < 0 || position >= length_)
    {
        throw(string) "Range error.";
    }
    DoubleLinkListNode<ElemType> *p = head_;
    for (int i = 0; i <= position; i++)
    {
        p = p->next_;
    }
    p->data_ = elem;
}
template <class ElemType>
void DoubleLinkList<ElemType>::SwapElem(int positionA, int positionB)
{
    DoubleLinkListNode<ElemType> *p = head_->next_;
    DoubleLinkListNode<ElemType> *q = head_->next_;
    for (int i = 0; i < positionA; i++)
    {
        p = p->next_;
    }
    for (int i = 0; i < positionB; i++)
    {
        q = q->next_;
    }
    ElemType temp = p->data_;
    p->data_ = q->data_;
    q->data_ = temp;
}
template <class ElemType>
int DoubleLinkList<ElemType>::GetLength() const
{
    return length_;
}
template <class ElemType>
int DoubleLinkList<ElemType>::LocateElem(const ElemType &elem) const
{
    DoubleLinkListNode<ElemType> *p = head_->next_;
    int count = 0;
    while (p != head_ and p->data_ != elem)
    {
        count++;
        p = p->next_;
    }
    return (p != head_) ? count : 0;
}
template <class ElemType>
ElemType DoubleLinkList<ElemType>::GetElem(int position) const
{
    if (position < 0 || position >= length_)
    {
        throw(string) "Range error.";
    }
    DoubleLinkListNode<ElemType> *p = head_;
    for (int i = 0; i <= position; i++)
    {
        p = p->next_;
    }
    return p->data_;
}
template <class ElemType>
DoubleLinkList<ElemType> &DoubleLinkList<ElemType>::operator=(const DoubleLinkList<ElemType> &DLL)
{
    if (&DLL != this)
    {
        int length = DLL.length_;
        ElemType elem;
        Clear();
        for (int i = 0; i < length; i++)
        {
            DLL.GetElem(i + 1, elem);
            InsertElem(elem);
        }
    }
    return *this;
}
#endif