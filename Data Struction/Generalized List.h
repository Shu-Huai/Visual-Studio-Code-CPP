#ifndef __GENERALIZED_LIST_H__
#define __GENERALIZED_LIST_H__
#include "Generalized List Node.h"
template <class ElemType>
class GeneralizedList
{
protected:
    GeneralizedListNode<ElemType> *head_;
    void Create(GeneralizedListNode<ElemType> *&first);
    void Clear(GeneralizedListNode<ElemType> *head);
    void Display(GeneralizedListNode<ElemType> *head) const;
    int GetDepth(const GeneralizedListNode<ElemType> *head);
    void Copy(const GeneralizedListNode<ElemType> *sourceHead, GeneralizedListNode<ElemType> *&destHead);

public:
    GeneralizedList();
    GeneralizedList(GeneralizedListNode<ElemType> *head);
    GeneralizedList(const GeneralizedList<ElemType> &list);
    ~GeneralizedList();
    bool IsEmpty() const;
    void Create();
    void Display() const;
    void Insert(const ElemType elem);
    void Insert(GeneralizedList<ElemType> &list);
    void Delete(int index);
    int GetLength();
    int GetDepth();
    GeneralizedListNode<ElemType> *GetFirst() const;
    GeneralizedListNode<ElemType> *GetNext(GeneralizedListNode<ElemType> *node) const;
    GeneralizedList<ElemType> &operator=(const GeneralizedList<ElemType> &list);
};
template <class ElemType>
void GeneralizedList<ElemType>::Create(GeneralizedListNode<ElemType> *&first)
{
    char character = getchar();
    GeneralizedListNode<ElemType> *subHead;
    ElemType elem = 0;
    switch (character)
    {
    case ')':
        return;
    case '(':
        first = new GeneralizedListNode<ElemType>(2);
        subHead = new GeneralizedListNode<ElemType>(0);
        subHead->referenceCount_ = 1;
        first->down_ = subHead;
        Create(subHead->next_);
        break;
    default:
        cin.putback(character);
        cin >> elem;
        first = new GeneralizedListNode<ElemType>(1);
        first->elem_ = elem;
        break;
    }
    character = getchar();
    if (character != ',')
    {
        cin.putback(character);
    }
    Create(first->next_);
}
template <class ElemType>
void GeneralizedList<ElemType>::Clear(GeneralizedListNode<ElemType> *head)
{
    head->referenceCount_--;
    if (!head->referenceCount_)
    {
        GeneralizedListNode<ElemType> *p = head;
        for (GeneralizedListNode<ElemType> *q = head->next_; q; q = q->next_)
        {
            delete p;
            p = q;
            if (q->tag_ == 2)
            {
                Clear(q->down_);
            }
        }
        delete p;
    }
}
template <class ElemType>
void GeneralizedList<ElemType>::Display(GeneralizedListNode<ElemType> *head) const
{
    cout << "（";
    for (GeneralizedListNode<ElemType> *p = head->next_; p; p = p->next_)
    {
        if (p != head->next_)
        {
            cout << "，";
        }
        if (p->tag_ == 1)
        {
            cout << p->elem_;
        }
        else
        {
            Display(p->down_);
        }
    }
    cout << "）";
}
template <class ElemType>
int GeneralizedList<ElemType>::GetDepth(const GeneralizedListNode<ElemType> *head)
{
    if (!head->next_)
    {
        return 1;
    }
    int subMaxDepth = 0;
    for (GeneralizedListNode<ElemType> *p = head->next_; p; p = p->next_)
    {
        if (p->tag_ == 2)
        {
            int subDepth = GetDepth(p->down_);
            if (subMaxDepth < subDepth)
                subMaxDepth = subDepth;
        }
    }
    return subMaxDepth + 1;
}
template <class ElemType>
void GeneralizedList<ElemType>::Copy(const GeneralizedListNode<ElemType> *sourceHead, GeneralizedListNode<ElemType> *&destHead)
{
    destHead = new GeneralizedListNode<ElemType>(0);
    GeneralizedListNode<ElemType> *q = destHead;
    destHead->referenceCount_ = 1;
    for (GeneralizedListNode<ElemType> *p = sourceHead->next_; p; p = p->next_)
    {
        q = new GeneralizedListNode<ElemType>(p->tag_);
        q->next_ = new GeneralizedListNode<ElemType>(p->tag_);
        if (p->tag_ == 2)
        {
            Copy(p->down_, q->down_);
        }
        else
        {
            q->elem_ = p->elem_;
        }
    }
}
template <class ElemType>
GeneralizedList<ElemType>::GeneralizedList()
{
    head_ = new GeneralizedListNode<ElemType>(0);
    head_->referenceCount_ = 1;
}
template <class ElemType>
GeneralizedList<ElemType>::GeneralizedList(GeneralizedListNode<ElemType> *head) : head_(head)
{
}
template <class ElemType>
GeneralizedList<ElemType>::GeneralizedList(const GeneralizedList<ElemType> &list)
{
    Copy(list.head_, head_);
}
template <class ElemType>
GeneralizedList<ElemType>::~GeneralizedList()
{
    Clear(head_);
}
template <class ElemType>
bool GeneralizedList<ElemType>::IsEmpty() const
{
    return head_->next_ == NULL;
}
template <class ElemType>
void GeneralizedList<ElemType>::Create()
{
    Clear(head_);
    head_ = new GeneralizedListNode<ElemType>(0);
    head_->referenceCount_ = 1;
    getchar();
    GeneralizedList<ElemType>::Create(head_->next_);
}
template <class ElemType>
void GeneralizedList<ElemType>::Display() const
{
    Display(head_);
}
template <class ElemType>
void GeneralizedList<ElemType>::Insert(const ElemType elem)
{
    GeneralizedListNode<ElemType> *p = new GeneralizedListNode<ElemType>(1, head_->next_);
    p->elem_ = elem;
    head_->next_ = p;
}
template <class ElemType>
void GeneralizedList<ElemType>::Insert(GeneralizedList<ElemType> &list)
{
    GeneralizedListNode<ElemType> *p = new GeneralizedListNode<ElemType>(2, head_->next_);
    p->down_ = list.head_;
    list.head_->referenceCount_++;
    head_->next_ = p;
}
template <class ElemType>
void GeneralizedList<ElemType>::Delete(int index)
{
    if (index < 1 || index > GetLength())
    {
        throw string("范围错误。");
    }
    GeneralizedListNode<ElemType> *p = head_->next_;
    GeneralizedListNode<ElemType> *q = head_;
    for (int i = 1; i < index; i++)
    {
        q = p;
        p = p->next_;
    }
    q->next_ = p->next_;
    if (p->tag_ == 2)
    {
        Clear(p->down_);
    }
    delete p;
}
template <class ElemType>
int GeneralizedList<ElemType>::GetLength()
{
    GeneralizedListNode<ElemType> *p = head_->next_;
    int length = 0;
    while (p)
    {
        p = p->next_;
        length++;
    }
    return length;
}
template <class ElemType>
int GeneralizedList<ElemType>::GetDepth()
{
    return GetDepth(head_);
}
template <class ElemType>
GeneralizedListNode<ElemType> *GeneralizedList<ElemType>::GetFirst() const
{
    return head_->next_;
}
template <class ElemType>
GeneralizedListNode<ElemType> *GeneralizedList<ElemType>::GetNext(GeneralizedListNode<ElemType> *node) const
{
    return node->next_;
}
template <class ElemType>
GeneralizedList<ElemType> &GeneralizedList<ElemType>::operator=(const GeneralizedList<ElemType> &list)
{
    if (&list != this)
    {
        Clear(head_);
        Copy(list.head_, head_);
    }
    return *this;
}
#endif