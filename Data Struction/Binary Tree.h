#pragma once
#ifndef __BINaRY_TREE_H__
#define __BINaRY_TREE_H__
#include "Binary Tree Node.h"
template <class ElemType>
class BinaryTree
{
protected:
    BinaryTreeNode<ElemType> *root_;
    BinaryTreeNode<ElemType> *CopyTree(BinaryTreeNode<ElemType> *BTN);
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
    BinaryTree(BinaryTreeNode<ElemType> *BTN);
    BinaryTree(const BinaryTree<ElemType> &BT);
    virtual ~BinaryTree();
    bool IsEmpty() const;
    void PreOrder(void (*Visit)(const ElemType &)) const;
    void InOrder(void (*Visit)(const ElemType &)) const;
    void PostOrder(void (*Visit)(const ElemType &)) const;
    void LevelOrder(void (*Visit)(const ElemType &)) const;
    void InsertLeftChild(BinaryTreeNode<ElemType> *p, const ElemType &e);
    void InsertRightChild(BinaryTreeNode<ElemType> *p, const ElemType &e);
    void DeleteLeftChild(BinaryTreeNode<ElemType> *p);
    void DeleteRightChild(BinaryTreeNode<ElemType> *p);
    Status SetElem(BinaryTreeNode<ElemType> *p, const ElemType &e);
    BinaryTreeNode<ElemType> *GetRoot() const;
    Status GetElem(BinaryTreeNode<ElemType> *p, ElemType &e) const;
    BinaryTreeNode<ElemType> *GetParent(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *GetLeftChild(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *GetRightChild(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *GetLeftSibling(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *GetRightSibling(const BinaryTreeNode<ElemType> *p) const;
    int GetHeight() const;
    int GetWidth() const;
    int GetLeafNumber() const;
    BinaryTreeNode<ElemType> *InitByPreOrder(queue<ElemType> &Q);
    void GetMirror(BinaryTreeNode<ElemType> *r);
    BinaryTree<ElemType> &operator=(const BinaryTree<ElemType> &BT);
};
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::CopyTree(BinaryTreeNode<ElemType> *BTN)
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
void BinaryTree<ElemType>::Destroy(BinaryTreeNode<ElemType> *&r)
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
void BinaryTree<ElemType>::PreOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
{
    if (r)
    {
        (*Visit)(r->data_);
        PreOrder(r->leftChild_, Visit);
        PreOrder(r->rightChild_, Visit);
    }
}
template <class ElemType>
void BinaryTree<ElemType>::InOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
{
    if (r)
    {
        InOrder(r->leftChild_, Visit);
        (*Visit)(r->data_);
        InOrder(r->rightChild_, Visit);
    }
}
template <class ElemType>
void BinaryTree<ElemType>::PostOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
{
    if (r)
    {
        PostOrder(r->leftChild_, Visit);
        PostOrder(r->rightChild_, Visit);
        (*Visit)(r->data_);
    }
}
template <class ElemType>
int BinaryTree<ElemType>::GetHeight(const BinaryTreeNode<ElemType> *r) const
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
int BinaryTree<ElemType>::GetLeafNumber(const BinaryTreeNode<ElemType> *r) const
{
    if (!r)
    {
        return 0;
    }
    return 1 + GetLeafNumber(r->leftChild_) + GetLeafNumber(r->rightChild_);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetParent(BinaryTreeNode<ElemType> *r, const BinaryTreeNode<ElemType> *p) const
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
BinaryTree<ElemType>::BinaryTree() : root_(NULL)
{
}
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType &e)
{
    root_ = new BinaryTreeNode<ElemType>;
    assert(root_);
    root_->data_ = e;
}
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(BinaryTreeNode<ElemType> *BTN)
{
    root_ = CopyTree(BTN);
}
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const BinaryTree<ElemType> &BT)
{
    root_ = new BinaryTreeNode<ElemType>;
    assert(root_);
    *this = BT;
}
template <class ElemType>
BinaryTree<ElemType>::~BinaryTree()
{
    Destroy(root_);
}
template <class ElemType>
bool BinaryTree<ElemType>::IsEmpty() const
{
    return root_ == NULL;
}
template <class ElemType>
void BinaryTree<ElemType>::PreOrder(void (*Visit)(const ElemType &)) const
{
    PreOrder(root_, Visit);
}
template <class ElemType>
void BinaryTree<ElemType>::InOrder(void (*Visit)(const ElemType &)) const
{
    InOrder(root_, Visit);
}
template <class ElemType>
void BinaryTree<ElemType>::PostOrder(void (*Visit)(const ElemType &)) const
{
    PostOrder(root_, Visit);
}
template <class ElemType>
void BinaryTree<ElemType>::LevelOrder(void (*Visit)(const ElemType &)) const
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
void BinaryTree<ElemType>::InsertLeftChild(BinaryTreeNode<ElemType> *p, const ElemType &e)
{
    if (!p)
    {
        return;
    }
    BinaryTreeNode<ElemType> *q = new BinaryTreeNode<ElemType>(e);
    if (p->leftChild_)
    {
        q->leftChild_ = p->leftChild_;
    }
    p->leftChild_ = q;
}
template <class ElemType>
void BinaryTree<ElemType>::InsertRightChild(BinaryTreeNode<ElemType> *p, const ElemType &e)
{
    if (!p)
    {
        return;
    }
    BinaryTreeNode<ElemType> *q = new BinaryTreeNode<ElemType>(e);
    if (p->rightChild_)
    {
        q->rightChild_ = p->rightChild_;
    }
    p->rightChild_ = q;
}
template <class ElemType>
void BinaryTree<ElemType>::DeleteLeftChild(BinaryTreeNode<ElemType> *p)
{
    Destroy(p->leftChild_);
}
template <class ElemType>
void BinaryTree<ElemType>::DeleteRightChild(BinaryTreeNode<ElemType> *p)
{
    Destroy(p->rightChild_);
}
template <class ElemType>
Status BinaryTree<ElemType>::SetElem(BinaryTreeNode<ElemType> *p, const ElemType &e)
{
    if (!p)
    {
        return UNDER_FLOW;
    }
    p->data_ = e;
    return SUCCESS;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetRoot() const
{
    return root_;
}
template <class ElemType>
Status BinaryTree<ElemType>::GetElem(BinaryTreeNode<ElemType> *p, ElemType &e) const
{
    if (!p)
    {
        return UNDER_FLOW;
    }
    e = p->data_;
    return SUCCESS;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetParent(const BinaryTreeNode<ElemType> *p) const
{
    return GetParent(root_, *p);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetLeftChild(const BinaryTreeNode<ElemType> *p) const
{
    if (!p)
    {
        return NULL;
    }
    return p->leftChild_;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetRightChild(const BinaryTreeNode<ElemType> *p) const
{
    if (!p)
    {
        return NULL;
    }
    return p->rightChild_;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetLeftSibling(const BinaryTreeNode<ElemType> *p) const
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
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetRightSibling(const BinaryTreeNode<ElemType> *p) const
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
int BinaryTree<ElemType>::GetHeight() const
{
    return GetHeight(root_);
}
template <class ElemType>
int BinaryTree<ElemType>::GetWidth() const
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
int BinaryTree<ElemType>::GetLeafNumber() const
{
    return GetLeafNumber(root_);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::InitByPreOrder(queue<ElemType> &Q)
{
    BinaryTreeNode<ElemType> *BT;
    char t;
    ElemType e = Q.front();
    Q.pop();
    if (e == "#")
    {
        return NULL;
    }
    BT = new BinaryTreeNode<ElemType>(e);
    assert(BT);
    if (!root_)
    {
        root_ = BT;
    }
    BT->leftChild_ = InitByPreOrder(Q);
    BT->rightChild_ = InitByPreOrder(Q);
    return BT;
}
template <class ElemType>
void BinaryTree<ElemType>::GetMirror(BinaryTreeNode<ElemType> *r)
{
    if (!r || !r->leftChild_ && !r->rightChild_)
    {
        return;
    }
    BinaryTreeNode<ElemType> *temp = r->leftChild_;
    r->leftChild_ = r->rightChild_;
    r->rightChild_ = temp;
    if (r->leftChild_)
    {
        GetMirror(r->leftChild_);
    }
    if (r->rightChild_)
    {
        GetMirror(r->rightChild_);
    }
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
#endif