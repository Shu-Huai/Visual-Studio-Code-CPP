#pragma once
#ifndef __BINNARY_SORT_TREE_H__
#define __BINNARY_SORT_TREE_H__
#include "Binary Tree Node.h"
template <class ElemType>
class BinarySortTree
{
protected:
    BinaryTreeNode<ElemType> *root_;
    BinaryTreeNode<ElemType> *CopyTree(BinaryTreeNode<ElemType> *BTN);
    void Destroy(BinaryTreeNode<ElemType> *&r);
    void PreOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;
    void InOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;
    void PostOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;
    void Delete(BinaryTreeNode<ElemType> *&p);
    int GetHeight(const BinaryTreeNode<ElemType> *r) const;
    int GetNodeNumber(const BinaryTreeNode<ElemType> *r) const;
    BinaryTreeNode<ElemType> *GetParent(BinaryTreeNode<ElemType> *r, const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *Find(const ElemType &key, BinaryTreeNode<ElemType> *&parentNode) const;

public:
    BinarySortTree();
    BinarySortTree(const ElemType &elem);
    BinarySortTree(BinaryTreeNode<ElemType> *BTN);
    BinarySortTree(const BinarySortTree<ElemType> &BST);
    virtual ~BinarySortTree();
    bool IsEmpty() const;
    void PreOrder(void (*Visit)(const ElemType &)) const;
    void InOrder(void (*Visit)(const ElemType &)) const;
    void PostOrder(void (*Visit)(const ElemType &)) const;
    void LevelOrder(void (*Visit)(const ElemType &)) const;
    Status Insert(const ElemType &elem);
    Status Delete(const ElemType &key);
    Status SetElem(BinaryTreeNode<ElemType> *p, const ElemType &elem);
    BinaryTreeNode<ElemType> *GetRoot() const;
    Status GetElem(BinaryTreeNode<ElemType> *p, ElemType &elem) const;
    BinaryTreeNode<ElemType> *GetParent(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *GetLeftChild(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *GetRightChild(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *GetLeftSibling(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *GetRightSibling(const BinaryTreeNode<ElemType> *p) const;
    int GetHeight() const;
    int GetWidth() const;
    int GetNodeNumber() const;
    BinaryTreeNode<ElemType> *Find(const ElemType &key) const;
    BinarySortTree<ElemType> &operator=(const BinarySortTree<ElemType> &BST);
};
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::CopyTree(BinaryTreeNode<ElemType> *BTN)
{
    if (!BTN)
    {
        return NULL;
    }
    BinaryTreeNode<ElemType> *copy = new BinaryTreeNode<ElemType>(BTN->data_);
    assert(copy);
    copy->leftChild_ = CopyTree(BTN->leftChild_);
    copy->rightChild_ = CopyTree(BTN->rightChild_);
    return copy;
}
template <class ElemType>
void BinarySortTree<ElemType>::Destroy(BinaryTreeNode<ElemType> *&r)
{
    if (r)
    {
        Destroy(r->leftChild_);
        Destroy(r->rightChild_);
        delete r;
        r = NULL;
    }
}
template <class ElemType>
void BinarySortTree<ElemType>::PreOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
{
    if (r)
    {
        (*Visit)(r->data_);
        PreOrder(r->leftChild_, Visit);
        PreOrder(r->rightChild_, Visit);
    }
}
template <class ElemType>
void BinarySortTree<ElemType>::InOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
{
    if (r)
    {
        InOrder(r->leftChild_, Visit);
        (*Visit)(r->data_);
        InOrder(r->rightChild_, Visit);
    }
}
template <class ElemType>
void BinarySortTree<ElemType>::PostOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
{
    if (r)
    {
        PostOrder(r->leftChild_, Visit);
        PostOrder(r->rightChild_, Visit);
        (*Visit)(r->data_);
    }
}
template <class ElemType>
void BinarySortTree<ElemType>::Delete(BinaryTreeNode<ElemType> *&p)
{
    if (!p->leftChild_ && !p->rightChild_)
    {
        delete p;
        p = NULL;
    }
    else if (!p->leftChild_)
    {
        BinaryTreeNode<ElemType> *q = p;
        p = p->rightChild_;
        delete q;
    }
    else if (!p->rightChild_)
    {
        BinaryTreeNode<ElemType> *q = p;
        p = p->leftChild_;
        delete q;
    }
    else
    {
        BinaryTreeNode<ElemType> *parentNode = p;
        BinaryTreeNode<ElemType> *q = p->leftChild_;
        while (q->rightChild_)
        {
            parentNode = q;
            q = q->rightChild_;
        }
        p->data_ = q->data_;
        if (parentNode->rightChild_ == q)
        {
            Delete(parentNode->rightChild_);
        }
        else
        {
            Delete(parentNode->leftChild_);
        }
    }
}
template <class ElemType>
int BinarySortTree<ElemType>::GetHeight(const BinaryTreeNode<ElemType> *r) const
{
    if (!r)
    {
        return 0;
    }
    int leftheight = GetHeight(r->leftChild_);
    int rightheight = GetHeight(r->rightChild_);
    return 1 + (leftheight > rightheight ? leftheight : rightheight);
}
template <class ElemType>
int BinarySortTree<ElemType>::GetNodeNumber(const BinaryTreeNode<ElemType> *r) const
{
    if (!r)
    {
        return 0;
    }
    return 1 + GetNodeNumber(r->leftChild_) + GetNodeNumber(r->rightChild_);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::GetParent(BinaryTreeNode<ElemType> *r, const BinaryTreeNode<ElemType> *p) const
{
    if (!r)
    {
        return NULL;
    }
    if (r->leftChild_ == p || r->rightChild_ == p)
    {
        return r;
    }
    BinaryTreeNode<ElemType> *temp;
    temp = GetParent(r->leftChild_, p);
    if (temp)
    {
        return temp;
    }
    temp = GetParent(r->rightChild_, p);
    if (temp)
    {
        return temp;
    }
    return NULL;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::Find(const ElemType &key, BinaryTreeNode<ElemType> *&parentNode) const
{
    BinaryTreeNode<ElemType> *p = root_;
    parentNode = NULL;
    while (p && p->data_ != key)
    {
        if (key < p->data_)
        {
            parentNode = p;
            p = p->leftChild_;
        }
        else
        {
            parentNode = p;
            p = p->rightChild_;
        }
    }
    return p;
}
template <class ElemType>
BinarySortTree<ElemType>::BinarySortTree() : root_(NULL)
{
}
template <class ElemType>
BinarySortTree<ElemType>::BinarySortTree(const ElemType &elem)
{
    root_ = new BinaryTreeNode<ElemType>(elem);
    assert(root_);
}
template <class ElemType>
BinarySortTree<ElemType>::BinarySortTree(BinaryTreeNode<ElemType> *BTN)
{
    root_ = CopyTree(BTN);
}
template <class ElemType>
BinarySortTree<ElemType>::BinarySortTree(const BinarySortTree<ElemType> &BST)
{
    root_ = CopyTree(BST.root_);
}
template <class ElemType>
BinarySortTree<ElemType>::~BinarySortTree()
{
    Destroy(root_);
}
template <class ElemType>
bool BinarySortTree<ElemType>::IsEmpty() const
{
    return root_ == NULL;
}
template <class ElemType>
void BinarySortTree<ElemType>::PreOrder(void (*Visit)(const ElemType &)) const
{
    PreOrder(root_, Visit);
}
template <class ElemType>
void BinarySortTree<ElemType>::InOrder(void (*Visit)(const ElemType &)) const
{
    InOrder(root_, Visit);
}
template <class ElemType>
void BinarySortTree<ElemType>::PostOrder(void (*Visit)(const ElemType &)) const
{
    PostOrder(root_, Visit);
}
template <class ElemType>
void BinarySortTree<ElemType>::LevelOrder(void (*Visit)(const ElemType &)) const
{
    queue<BinaryTreeNode<ElemType> *> Q;
    BinaryTreeNode<ElemType> *p;
    if (root_)
    {
        Q.push(root_);
    }
    while (!Q.empty())
    {
        p = Q.front();
        Q.pop();
        (*Visit)(p->data_);
        if (p->leftChild_)
        {
            Q.push(p->leftChild_);
        }
        if (p->rightChild_)
        {
            Q.push(p->rightChild_);
        }
    }
}
template <class ElemType>
Status BinarySortTree<ElemType>::Insert(const ElemType &elem)
{
    BinaryTreeNode<ElemType> *parentNode;
    if (Find(elem, parentNode))
    {
        return FAIL;
    }
    BinaryTreeNode<ElemType> *p = new BinaryTreeNode<ElemType>(elem);
    if (IsEmpty())
    {
        root_ = p;
    }
    else if (elem < parentNode->data_)
    {
        parentNode->leftChild_ = p;
    }
    else
    {
        parentNode->rightChild_ = p;
    }
    return SUCCESS;
}
template <class ElemType>
Status BinarySortTree<ElemType>::Delete(const ElemType &key)
{
    BinaryTreeNode<ElemType> *parentNode = NULL;
    BinaryTreeNode<ElemType> *p = Find(key, parentNode);
    if (!p)
    {
        return FAIL;
    }
    if (!parentNode)
    {
        Delete(p);
    }
    else if (key < parentNode->data_)
    {
        Delete(parentNode->leftChild_);
    }
    else
    {
        Delete(parentNode->rightChild_);
    }
    return SUCCESS;
}
template <class ElemType>
Status BinarySortTree<ElemType>::SetElem(BinaryTreeNode<ElemType> *p, const ElemType &e)
{
    if (!p)
    {
        return UNDER_FLOW;
    }
    p->data_ = e;
    return SUCCESS;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::GetRoot() const
{
    return root_;
}
template <class ElemType>
Status BinarySortTree<ElemType>::GetElem(BinaryTreeNode<ElemType> *p, ElemType &e) const
{
    if (!p)
    {
        return UNDER_FLOW;
    }
    e = p->data_;
    return SUCCESS;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::GetParent(const BinaryTreeNode<ElemType> *p) const
{
    return GetParent(root_, *p);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::GetLeftChild(const BinaryTreeNode<ElemType> *p) const
{
    if (!p)
    {
        return NULL;
    }
    return p->leftChild_;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::GetRightChild(const BinaryTreeNode<ElemType> *p) const
{
    if (!p)
    {
        return NULL;
    }
    return p->rightChild_;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::GetLeftSibling(const BinaryTreeNode<ElemType> *p) const
{
    BinaryTreeNode<ElemType> *r = GetParent(root_, p);
    if (!r)
    {
        return NULL;
    }
    if (r->rightChild_ == p)
    {
        return r->leftChild_;
    }
    return NULL;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::GetRightSibling(const BinaryTreeNode<ElemType> *p) const
{
    BinaryTreeNode<ElemType> *r = GetParent(root_, p);
    if (!r)
    {
        return NULL;
    }
    if (r->leftChild_ == p)
    {
        return r->rightChild_;
    }
    return NULL;
}
template <class ElemType>
int BinarySortTree<ElemType>::GetHeight() const
{
    return GetHeight(root_);
}
template <class ElemType>
int BinarySortTree<ElemType>::GetWidth() const
{
    queue<BinaryTreeNode<ElemType> *> Q;
    BinaryTreeNode<ElemType> *temp;
    int maxWidth = 0;
    int number = 0;
    int nextNumber = 0;
    if (root_)
    {
        Q.push(root_);
        maxWidth = 1;
        number = 1;
    }
    while (!Q.empty())
    {
        nextNumber = 0;
        for (int i = 0; i < number; i++)
        {
            temp = Q.front();
            Q.pop();
            if (temp->leftChild_)
            {
                Q.push(temp->leftChild_);
                nextNumber++;
            }
            if (temp->rightChild_)
            {
                Q.push(temp->rightChild_);
                nextNumber++;
            }
        }
        number = nextNumber;
        if (nextNumber > maxWidth)
        {
            maxWidth = nextNumber;
        }
    }
    return maxWidth;
}
template <class ElemType>
int BinarySortTree<ElemType>::GetNodeNumber() const
{
    return GetNodeNumber(root_);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::Find(const ElemType &key) const
{
    BinaryTreeNode<ElemType> *parentNode;
    return Find(key, parentNode);
}
template <class ElemType>
BinarySortTree<ElemType> &BinarySortTree<ElemType>::operator=(const BinarySortTree<ElemType> &BST)
{
    if (&BST != this)
    {
        Destroy(root_);
        root_ = CopyTree(BST.root_);
    }
    return *this;
}
#endif