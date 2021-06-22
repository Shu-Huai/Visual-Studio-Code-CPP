#ifndef __LINK_LIST_WITHOUT_HEAD_H__
#define __LINK_LIST_WITHOUT_HEAD_H__
#include "Link List Node.h"
using namespace std;
template <class ElemType>
class LinkListWithoutHead
{
protected:
    LinkListNode<ElemType> *head_;
    int length_;

public:
    LinkListWithoutHead();
    LinkListWithoutHead(ElemType *elems, int length);
    LinkListWithoutHead(const LinkListWithoutHead<ElemType> &list);
    virtual ~LinkListWithoutHead();
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
    void Reverse();
    void Merge(LinkListWithoutHead<ElemType> &list);
    LinkListWithoutHead<ElemType> &operator=(const LinkListWithoutHead<ElemType> &list);
    ElemType &operator[](int index);
};
template <class ElemType>
LinkListWithoutHead<ElemType>::LinkListWithoutHead() : head_(NULL), length_(0)
{
}
template <class ElemType>
LinkListWithoutHead<ElemType>::LinkListWithoutHead(ElemType *elems, int length) : length_(length)
{
    head_ = new LinkListNode<ElemType>(elems[0], NULL);
    LinkListNode<ElemType> *p = head_;
    for (int i = 1; i < length; i++)
    {
        p->next_ = new LinkListNode<ElemType>(elems[i], NULL);
        p = p->next_;
    }
}
template <class ElemType>
LinkListWithoutHead<ElemType>::LinkListWithoutHead(const LinkListWithoutHead<ElemType> &list) : length_(list.length_)
{
    ElemType elem;
    head_ = new LinkListNode<ElemType>;
    for (int i = 0; i < list.length_; i++)
    {
        list.GetElem(i, elem);
        AppendElem(elem);
    }
}
template <class ElemType>
LinkListWithoutHead<ElemType>::~LinkListWithoutHead()
{
    Clear();
}
template <class ElemType>
void LinkListWithoutHead<ElemType>::Clear()
{
    LinkListNode<ElemType> *p;
    while (head_)
    {
        p = head_;
        head_ = head_->next_;
        delete p;
    }
    length_ = 0;
}
template <class ElemType>
bool LinkListWithoutHead<ElemType>::IsEmpty() const
{
    return head_ == NULL;
}
template <class ElemType>
void LinkListWithoutHead<ElemType>::Display() const
{
    LinkListNode<ElemType> *p = head_;
    while (p)
    {
        cout << p->elem_ << " ";
        if (p->next_)
        {
            cout << " -> ";
        }
        p = p->next_;
    }
    cout << endl;
    cout << "长度是：" << length_;
}
template <class ElemType>
void LinkListWithoutHead<ElemType>::Traverse() const
{
    LinkListNode<ElemType> *p = head_;
    while (p)
    {
        cout << p->elem_ << " ";
        p = p->next_;
    }
    cout << endl;
}
template <class ElemType>
void LinkListWithoutHead<ElemType>::AppendElem(const ElemType elem)
{
    if (!head_)
    {
        head_ = new LinkListNode<ElemType>(elem, NULL);
    }
    else
    {
        LinkListNode<ElemType> *p = head_;
        while (p->next_)
        {
            p = p->next_;
        }
        p->next_ = new LinkListNode<ElemType>(elem, NULL);
    }
    length_++;
}
template <class ElemType>
void LinkListWithoutHead<ElemType>::InsertElem(int index, const ElemType elem)
{
    if (index < 0 || index >= length_ + 1)
    {
        throw string("范围错误。");
    }
    LinkListNode<ElemType> *p = head_;
    LinkListNode<ElemType> *q = new LinkListNode<ElemType>(elem, NULL);
    if (!index)
    {
        q->next_ = head_;
        head_ = q;
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            p = p->next_;
        }
        q->next_ = p->next_;
        p->next_ = q;
    }
    length_++;
}
template <class ElemType>
void LinkListWithoutHead<ElemType>::DeleteElem(int index)
{
    if (index < 0 || index >= length_)
    {
        throw string("范围错误。");
    }
    LinkListNode<ElemType> *p = head_;
    if (!index)
    {
        head_ = head_->next_;
        delete p;
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            p = p->next_;
        }
        LinkListNode<ElemType> *q = p->next_;
        p->next_ = q->next_;
        delete q;
    }
    length_--;
}
template <class ElemType>
void LinkListWithoutHead<ElemType>::SetElem(int index, const ElemType elem)
{
    if (index < 0 || index >= length_)
    {
        throw string("范围错误。");
    }
    LinkListNode<ElemType> *p = head_;
    for (int i = 0; i < index; i++)
    {
        p = p->next_;
    }
    p->elem_ = elem;
}
template <class ElemType>
int LinkListWithoutHead<ElemType>::GetLength() const
{
    return length_;
}
template <class ElemType>
int LinkListWithoutHead<ElemType>::GetIndex(const ElemType elem) const
{
    LinkListNode<ElemType> *p = head_;
    int count = 0;
    while (p && p->elem_ != elem)
    {
        count++;
        p = p->next_;
    }
    return (p) ? count : -1;
}
template <class ElemType>
ElemType LinkListWithoutHead<ElemType>::GetElem(int index) const
{
    if (index < 0 || index >= length_)
    {
        throw string("范围错误。");
    }
    LinkListNode<ElemType> *p = head_;
    for (int i = 0; i < index; i++)
    {
        p = p->next_;
    }
    return p->elem_;
}
template <class ElemType>
void LinkListWithoutHead<ElemType>::Reverse()
{
    LinkListNode<ElemType> *temp = new LinkListNode<ElemType>;
    temp->next_ = head_;
    LinkListNode<ElemType> *p = temp->next_, *q;
    temp->next_ = NULL;
    while (p)
    {
        q = p->next_;
        p->next_ = temp->next_;
        temp->next_ = p;
        p = q;
    }
    head_ = temp->next_;
    delete temp;
}
template <class ElemType>
void LinkListWithoutHead<ElemType>::Merge(LinkListWithoutHead<ElemType> &list)
{
    LinkListNode<ElemType> *q = new LinkListNode<ElemType>;
    q->next_ = head_;
    LinkListNode<ElemType> *p = new LinkListNode<ElemType>;
    p->next_ = head_;
    int i = 0;
    while (p != NULL)
    {
        if (i == list.GetLength())
        {
            break;
        }
        ElemType temp;
        temp = list.GetElem(i);
        LinkListNode<ElemType> *t = new LinkListNode<ElemType>;
        t->elem_ = temp;
        if (p->elem_ >= temp && p == q->next_)
        {
            t->next_ = p;
            q->next_ = t;
            p = q;
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
    head_ = q->next_;
    Reverse();
    delete q;
}
template <class ElemType>
LinkListWithoutHead<ElemType> &LinkListWithoutHead<ElemType>::operator=(const LinkListWithoutHead<ElemType> &list)
{
    if (&list != this)
    {
        ElemType elem;
        Clear();
        for (int i = 0; i < list.length_; i++)
        {
            list.GetElem(i, elem);
            AppendElem(elem);
        }
    }
    return *this;
}
template <class ElemType>
ElemType &LinkListWithoutHead<ElemType>::operator[](int index)
{
    if (index < 0 || index >= length_)
    {
        throw string("范围错误。");
    }
    LinkListNode<ElemType> *p = head_;
    for (int i = 0; i < index; i++)
    {
        p = p->next_;
    }
    return p->elem_;
}
#endif