#pragma once
#ifndef __BINaRY_TREE_H__
#define __BINaRY_TREE_H__
#include "BinaryTreeNode.h"
#include "LinkQueue.h"
template <class ElemType>
class BinaryTree
{
protected:
    BinaryTreeNode<ElemType> *root_;
    BinaryTreeNode<ElemType> *CopyTree(BinaryTreeNode<ElemType> *t);
    void Destroy(BinaryTreeNode<ElemType> *&r);
    void PreOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;
    void InOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;
    void PostOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;
    int GetHeight(const BinaryTreeNode<ElemType> *r) const;
    int GetLeafNumber(const BinaryTreeNode<ElemType> *r) const;
    BinaryTreeNode<ElemType> *GetParent(BinaryTreeNode<ElemType> *r, const BinaryTreeNode<ElemType> *p) const;

public:
    BinaryTree();
    BinaryTree(const ElemType &e);
    virtual ~BinaryTree();
    BinaryTreeNode<ElemType> *GetRoot() const;
    bool IsEmpty() const;
    Status GetElem(BinaryTreeNode<ElemType> *p, ElemType &e) const;
    Status SetElem(BinaryTreeNode<ElemType> *p, const ElemType &e);
    void InOrder(void (*Visit)(const ElemType &)) const;
    void PreOrder(void (*Visit)(const ElemType &)) const;
    void PostOrder(void (*Visit)(const ElemType &)) const;
    void LevelOrder(void (*Visit)(const ElemType &)) const;
    int GetLeafNumber() const;
    BinaryTreeNode<ElemType> *LeftChild(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *RightChild(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *LeftSibling(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *RightSibling(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *GetParent(const BinaryTreeNode<ElemType> *p) const;
    void InsertLeftChild(BinaryTreeNode<ElemType> *p, const ElemType &e);
    void InsertRightChild(BinaryTreeNode<ElemType> *p, const ElemType &e);
    void DeleteLeftChild(BinaryTreeNode<ElemType> *p);
    void DeleteRightChild(BinaryTreeNode<ElemType> *p);
    int GetHeight() const;
    BinaryTree(const BinaryTree<ElemType> &BT);
    BinaryTree(BinaryTreeNode<ElemType> *BTN);
    BinaryTree<ElemType> &operator=(const BinaryTree<ElemType> &BT);
    BinaryTreeNode<ElemType> *InitByPre(LinkQueue<ElemType> &LQ);
    int GetWidth() const;
    void GetMirror(BinaryTreeNode<ElemType> *r);
};
#endif
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::CopyTree(BinaryTreeNode<ElemType> *t)
{
    if (t == NULL)
    {
        return NULL;
    }
    BinaryTreeNode<ElemType> *copy = new BinaryTreeNode<ElemType>(t->data_);
    copy->leftchild_ = CopyTree(t->leftchild_);
    copy->rightchild_ = CopyTree(t->rightchild_);
    return copy;
}
template <class ElemType>
void BinaryTree<ElemType>::Destroy(BinaryTreeNode<ElemType> *&r)
{
    if (r != NULL)
    {
        Destroy(r->leftchild_);
        Destroy(r->rightchild_);
        delete r;
        r = NULL;
    }
}
template <class ElemType>
void BinaryTree<ElemType>::PreOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
{
    if (r != NULL)
    {
        (*Visit)(r->data_);
        PreOrder(r->leftchild_, Visit);
        PreOrder(r->rightchild_, Visit);
    }
}
template <class ElemType>
void BinaryTree<ElemType>::InOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
{
    if (r != NULL)
    {
        InOrder(r->leftchild_, Visit);
        (*Visit)(r->data_);
        InOrder(r->rightchild_, Visit);
    }
}
template <class ElemType>
void BinaryTree<ElemType>::PostOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
{
    if (r != NULL)
    {
        PostOrder(r->leftchild_, Visit);
        PostOrder(r->rightchild_, Visit);
        (*Visit)(r->data_);
    }
}
template <class ElemType>
int BinaryTree<ElemType>::GetHeight(const BinaryTreeNode<ElemType> *r) const
{
    if (r == NULL)
    {
        return 0;
    }
    int leftheight = GetHeight(r->leftchild_);
    int rightheight = GetHeight(r->rightchild_);
    return 1 + (leftheight > rightheight ? leftheight : rightheight);
}
template <class ElemType>
int BinaryTree<ElemType>::GetLeafNumber(const BinaryTreeNode<ElemType> *r) const
{
    if (r == NULL)
    {
        return 0;
    }
    return 1 + GetLeafNumber(r->leftchild_) + GetLeafNumber(r->rightchild_);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetParent(BinaryTreeNode<ElemType> *r, const BinaryTreeNode<ElemType> *p) const
{
    if (r == NULL)
    {
        return NULL;
    }
    if (r->leftchild_ == p or r->rightchild_ == p)
    {
        return r;
    }
    BinaryTreeNode<ElemType> *tmp;
    tmp = GetParent(r->leftchild_, p);
    if (tmp != NULL)
    {
        return tmp;
    }
    tmp = GetParent(r->rightchild_, p);
    if (tmp != NULL)
    {
        return tmp;
    }
    return NULL;
}
template <class ElemType>
BinaryTree<ElemType>::BinaryTree()
{
    root_ = NULL;
}
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType &e)
{
    root_ = new BinaryTreeNode<ElemType>;
    assert(root_);
    root_->data_ = e;
}
template <class ElemType>
BinaryTree<ElemType>::~BinaryTree()
{
    Destroy(root_);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetRoot() const
{
    return root_;
}
template <class ElemType>
bool BinaryTree<ElemType>::IsEmpty() const
{
    return root_ == NULL;
}
template <class ElemType>
Status BinaryTree<ElemType>::GetElem(BinaryTreeNode<ElemType> *p, ElemType &e) const
{
    if (p == NULL)
    {
        return UNDER_FLOW;
    }
    e = p->data_;
    return SUCCESS;
}
template <class ElemType>
Status BinaryTree<ElemType>::SetElem(BinaryTreeNode<ElemType> *p, const ElemType &e)
{
    if (p == NULL)
    {
        return UNDER_FLOW;
    }
    p->data_ = e;
    return SUCCESS;
}
template <class ElemType>
void BinaryTree<ElemType>::InOrder(void (*Visit)(const ElemType &)) const
{
    InOrder(root_, Visit);
}
template <class ElemType>
void BinaryTree<ElemType>::PreOrder(void (*Visit)(const ElemType &)) const
{
    PreOrder(root_, Visit);
}
template <class ElemType>
void BinaryTree<ElemType>::PostOrder(void (*Visit)(const ElemType &)) const
{
    PostOrder(root_, Visit);
}
template <class ElemType>
void BinaryTree<ElemType>::LevelOrder(void (*Visit)(const ElemType &)) const
{
    LinkQueue<BinaryTreeNode<ElemType> *> LQ;
    BinaryTreeNode<ElemType> *p;
    if (root_ != NULL)
    {
        LQ.EnQueue(root_);
    }
    while (!LQ.IsEmpty())
    {
        LQ.DelQueue(p);
        (*Visit)(p->data_);
        if (p->leftchild_ != NULL)
        {
            LQ.EnQueue(p->leftchild_);
        }
        if (p->rightchild_ != NULL)
        {
            LQ.EnQueue(p->rightchild_);
        }
    }
}
template <class ElemType>
int BinaryTree<ElemType>::GetLeafNumber() const
{
    return GetLeafNumber(root_);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::LeftChild(const BinaryTreeNode<ElemType> *p) const
{
    if (p == NULL)
    {
        return NULL;
    }
    return p->leftchild_;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::RightChild(const BinaryTreeNode<ElemType> *p) const
{
    if (p == NULL)
    {
        return NULL;
    }
    return p->rightchild_;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::LeftSibling(const BinaryTreeNode<ElemType> *p) const
{
    BinaryTreeNode<ElemType> *r = GetParent(root_, p);
    if (r == NULL)
    {
        return NULL;
    }
    if (r->rightchild_ == p)
    {
        return r->leftchild_;
    }
    return NULL;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::RightSibling(const BinaryTreeNode<ElemType> *p) const
{
    BinaryTreeNode<ElemType> *r = GetParent(root_, p);
    if (r == NULL)
    {
        return NULL;
    }
    if (r->leftchild_ == p)
    {
        return r->rightchild_;
    }
    return NULL;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetParent(const BinaryTreeNode<ElemType> *p) const
{
    return GetParent(root_, *p);
}
template <class ElemType>
void BinaryTree<ElemType>::InsertLeftChild(BinaryTreeNode<ElemType> *p, const ElemType &e)
{
    if (p == NULL)
    {
        return;
    }
    BinaryTreeNode<ElemType> *q = new BinaryTreeNode<ElemType>(e);
    if (p->leftchild_ != NULL)
    {
        q->leftchild_ = p->leftchild_;
    }
    p->leftchild_ = q;
}
template <class ElemType>
void BinaryTree<ElemType>::InsertRightChild(BinaryTreeNode<ElemType> *p, const ElemType &e)
{
    if (p == NULL)
    {
        return;
    }
    BinaryTreeNode<ElemType> *q = new BinaryTreeNode<ElemType>(e);
    if (p->rightchild_ != NULL)
    {
        q->rightchild_ = p->rightchild_;
    }
    p->rightchild_ = q;
}
template <class ElemType>
void BinaryTree<ElemType>::DeleteLeftChild(BinaryTreeNode<ElemType> *p)
{
    Destroy(p->leftchild_);
}
template <class ElemType>
void BinaryTree<ElemType>::DeleteRightChild(BinaryTreeNode<ElemType> *p)
{
    Destroy(p->rightchild_);
}
template <class ElemType>
int BinaryTree<ElemType>::GetHeight() const
{
    return GetHeight(root_);
}
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const BinaryTree<ElemType> &BT)
{
    root_ = new BinaryTreeNode<ElemType>;
    assert(root_);
    *this = BT;
}
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(BinaryTreeNode<ElemType> *BTN)
{
    root_ = CopyTree(BTN);
    assert(root_);
}
template <class ElemType>
BinaryTree<ElemType> &BinaryTree<ElemType>::operator=(const BinaryTree<ElemType> &BT)
{
    if (&BT != this)
    {
        Destroy(root_);
        root_ = CopyTree(BT.root_);
    }
    return *this;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::InitByPre(LinkQueue<ElemType> &LQ)
{
    BinaryTreeNode<ElemType> *BT;
    char t;
    ElemType e;
    LQ.DelQueue(e);
    if (e == "#")
    {
        return NULL;
    }
    BT = new BinaryTreeNode<ElemType>(e);
    assert(BT);
    if (root_ == NULL)
    {
        root_ = BT;
    }
    BT->leftchild_ = InitByPre(LQ);
    BT->rightchild_ = InitByPre(LQ);
    return BT;
}
template <class ElemType>
int BinaryTree<ElemType>::GetWidth() const
{
    LinkQueue<BinaryTreeNode<ElemType> *> LQ;
    BinaryTreeNode<ElemType> *BTN;
    int max = 0;
    int number = 0;
    int nextnumber = 0;
    if (root_ != NULL)
    {
        LQ.EnQueue(root_);
        max = 1;
        number = 1;
    }
    while (!LQ.IsEmpty())
    {
        nextnumber = 0;
        for (int i = 0; i < number; i++)
        {
            LQ.DelQueue(BTN);
            if (BTN->leftchild_ != NULL)
            {
                LQ.EnQueue(BTN->leftchild_);
                nextnumber++;
            }
            if (BTN->rightchild_ != NULL)
            {
                LQ.EnQueue(BTN->rightchild_);
                nextnumber++;
            }
        }
        number = nextnumber;
        if (nextnumber > max)
        {
            max = nextnumber;
        }
    }
    return max;
}
template <class ElemType>
void BinaryTree<ElemType>::GetMirror(BinaryTreeNode<ElemType> *r)
{
    if (r == NULL or r->leftchild_ == NULL and r->rightchild_ == NULL)
    {
        return;
    }
    BinaryTreeNode<ElemType> *temp = r->leftchild_;
    r->leftchild_ = r->rightchild_;
    r->rightchild_ = temp;
    if (r->leftchild_)
    {
        GetMirror(r->leftchild_);
    }
    if (r->rightchild_)
    {
        GetMirror(r->rightchild_);
    }
}