#pragma once
#ifndef __BINaRY_TREE_H__
#define __BINaRY_TREE_H__
#include "BinaryTreeNode.h"
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
    int NodeCount(const BinaryTreeNode<ElemType> *r) const;
    BinaryTreeNode<ElemType> *Parent(BinaryTreeNode<ElemType> *r, const BinaryTreeNode<ElemType> *p) const;

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
    int NodeCount() const;
    BinaryTreeNode<ElemType> *LeftChild(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *RightChild(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *LeftSibling(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *RightSibling(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *Parent(const BinaryTreeNode<ElemType> *p) const;
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
        Destroy(r->rightchil_);
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
        PreOrder(r->leftChild_, Visit);
        PreOrder(r->rightChild_, Visit);
    }
}
template <class ElemType>
void BinaryTree<ElemType>::InOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
{
    if (r != NULL)
    {
        InOreder(r->leftChild_, Visit);
        (*Visit)(r->data_);
        InOrder(r->rightChild_, Visit);
    }
}
template <class ElemType>
void BinaryTree<ElemType>::PostOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
{
    if (r != NULL)
    {
        PostOder(r->leftChild_, Visit);
        PostOder(r->rightChild_, Visit);
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
int BinaryTree<ElemType>::NodeCount(const BinaryTreeNode<ElemType> *r) const
{
    if (r == NULL)
    {
        return 0;
    }
    return 1 + NodeCount(r->leftchild_) + NodeCount(r->leftchild_);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::Parent(BinaryTreeNode<ElemType> *r, const BinaryTreeNode<ElemType> *p) const
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
    tmp = Parent(r->leftchild_, p);
    if (tmp != NULL)
    {
        return tmp;
    }
    tmp = Parent(r->rightchild_, p);
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