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
    DoubleLinkList(const DoubleLinkList<ElemType> &list);
    virtual ~DoubleLinkList();
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
    void SwapElem(int positionA, int positionB);
    DoubleLinkList<ElemType> &operator=(const DoubleLinkList<ElemType> &list);
    ElemType &operator[](int index);
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
DoubleLinkList<ElemType>::DoubleLinkList(const DoubleLinkList<ElemType> &list) : length_(list.length_)
{
    head_ = new DoubleLinkListNode<ElemType>;
    int length = list.length_;
    ElemType elem;
    Clear();
    for (int i = 0; i < length; i++)
    {
        list.GetElem(i + 1, elem);
        InsertElem(elem);
    }
    *this = list;
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
void DoubleLinkList<ElemType>::Display() const
{
    DoubleLinkListNode<ElemType> *p = head_->next_;
    cout << "头 -> ";
    while (p != head_)
    {
        cout << p->elem_;
        if (p != head_)
        {
            cout << " -> ";
        }
        p = p->next_;
    }
    cout << "长度是：" << length_ << endl;
}
template <class ElemType>
void DoubleLinkList<ElemType>::Traverse() const
{
    DoubleLinkListNode<ElemType> *p = head_->next_;
    while (p != head_)
    {
        cout << p->elem_ << " ";
        p = p->next_;
    }
    cout << endl;
}
template <class ElemType>
void DoubleLinkList<ElemType>::AppendElem(const ElemType elem)
{
    DoubleLinkListNode<ElemType> *p = new DoubleLinkListNode<ElemType>(elem, head_->prior_, head_);
    head_->prior_->next_ = p;
    head_->prior_ = p;
    length_++;
}
template <class ElemType>
void DoubleLinkList<ElemType>::InsertElem(int index, const ElemType elem)
{
    if (index < 0 || index >= length_ + 2)
    {
        throw(string) "范围错误。";
    }
    DoubleLinkListNode<ElemType> *p = head_;
    for (int i = 0; i <= index - 1; i++)
    {
        p = p->next_;
    }
    DoubleLinkListNode<ElemType> *q = new DoubleLinkListNode<ElemType>(elem, p, p->next_);
    p->next_ = q;
    length_++;
}
template <class ElemType>
void DoubleLinkList<ElemType>::DeleteElem(int index)
{
    if (index < 0 || index >= length_)
    {
        throw(string) "范围错误。";
    }
    DoubleLinkListNode<ElemType> *p = head_;
    for (int i = 0; i <= index; i++)
    {
        p = p->next_;
    }
    p->prior_->next_ = p->next_;
    p->next_->prior_ = p->prior_;
    delete p;
    length_--;
}
template <class ElemType>
void DoubleLinkList<ElemType>::SetElem(int index, const ElemType elem)
{
    if (index < 0 || index >= length_)
    {
        throw(string) "范围错误。";
    }
    DoubleLinkListNode<ElemType> *p = head_;
    for (int i = 0; i <= index; i++)
    {
        p = p->next_;
    }
    p->elem_ = elem;
}
template <class ElemType>
int DoubleLinkList<ElemType>::GetLength() const
{
    return length_;
}
template <class ElemType>
int DoubleLinkList<ElemType>::GetIndex(const ElemType elem) const
{
    DoubleLinkListNode<ElemType> *p = head_->next_;
    int count = 0;
    while (p != head_ and p->elem_ != elem)
    {
        count++;
        p = p->next_;
    }
    return (p != head_) ? count : -1;
}
template <class ElemType>
ElemType DoubleLinkList<ElemType>::GetElem(int index) const
{
    if (index < 0 || index >= length_)
    {
        throw(string) "范围错误。";
    }
    DoubleLinkListNode<ElemType> *p = head_;
    for (int i = 0; i <= index; i++)
    {
        p = p->next_;
    }
    return p->elem_;
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
    ElemType temp = p->elem_;
    p->elem_ = q->elem_;
    q->elem_ = temp;
}
template <class ElemType>
DoubleLinkList<ElemType> &DoubleLinkList<ElemType>::operator=(const DoubleLinkList<ElemType> &list)
{
    if (&list != this)
    {
        int length = list.length_;
        ElemType elem;
        Clear();
        for (int i = 0; i < length; i++)
        {
            list.GetElem(i + 1, elem);
            InsertElem(elem);
        }
    }
    return *this;
}
template <class ElemType>
ElemType &DoubleLinkList<ElemType>::operator[](int index)
{
    if (index < 0 || index >= length_)
    {
        throw(string) "范围错误。";
    }
    DoubleLinkListNode<ElemType> *p = head_;
    for (int i = 0; i <= index; i++)
    {
        p = p->next_;
    }
    return p->elem_;
}
#endif