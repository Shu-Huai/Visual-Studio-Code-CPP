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
    int Height(const BinaryTreeNode<ElemType> *r) const;
    int GetNLeafNumber(const BinaryTreeNode<ElemType> *r) const;
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
    int GetNLeafNumber() const;
    BinaryTreeNode<ElemType> *LeftChild(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *RightChild(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *LeftSibling(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *RightSibling(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *GetParent(const BinaryTreeNode<ElemType> *p) const;
    void InsertLeftChild(BinaryTreeNode<ElemType> *p, const ElemType &e);
    void InsertRightChild(BinaryTreeNode<ElemType> *p, const ElemType &e);
    void DeleteLeftChild(BinaryTreeNode<ElemType> *p);
    void DeleteRightChild(BinaryTreeNode<ElemType> *p);
    int Height() const;
    BinaryTree(const BinaryTree<ElemType> &t);
    BinaryTree(BinaryTreeNode<ElemType> *r);
    BinaryTree<ElemType> &operator=(const BinaryTree<ElemType> &t);
};
#endif
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::CopyTree(BinaryTreeNode<ElemType> *t)
{
    if (t == NULL)
    {
        return NULL;
    }
    BinaryTreeNode<ElemType> *copy = BinaryTree(t->data_);
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
int BinaryTree<ElemType>::Height(const BinaryTreeNode<ElemType> *r) const
{
    if (r == NULL)
    {
        return 0;
    }
    return 1 + Height(r->leftchild_) > Height(r->leftchild_) ? Height(r->leftchild_) : Height(r->leftchild_);
}
template <class ElemType>
int BinaryTree<ElemType>::GetNLeafNumber(const BinaryTreeNode<ElemType> *r) const
{
    if (r == NULL)
    {
        return 0;
    }
    return 1 + GetNLeafNumber(r->leftchild_) + GetNLeafNumber(r->leftchild_);
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
    root_ = new BinaryTreeNode<ElemType>;
    assert(root_);
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
int BinaryTree<ElemType>::GetNLeafNumber() const
{
    return GetNLeafNumber(root_);
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