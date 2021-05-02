#pragma once
#ifndef __BINaRY_TREE_H__
#define __BINaRY_TREE_H__
#include "Binary Tree Node.h"
#include "Link Queue.h"
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
    BinaryTreeNode<ElemType> *InitByPreOrder(LinkQueue<ElemType> &LQ);
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
    copy->leftchild_ = CopyTree(BTN->leftchild_);
    copy->rightchild_ = CopyTree(BTN->rightchild_);
    return copy;
}
template <class ElemType>
void BinaryTree<ElemType>::Destroy(BinaryTreeNode<ElemType> *&r)
{
    if (r)
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
    if (r)
    {
        (*Visit)(r->data_);
        PreOrder(r->leftchild_, Visit);
        PreOrder(r->rightchild_, Visit);
    }
}
template <class ElemType>
void BinaryTree<ElemType>::InOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
{
    if (r)
    {
        InOrder(r->leftchild_, Visit);
        (*Visit)(r->data_);
        InOrder(r->rightchild_, Visit);
    }
}
template <class ElemType>
void BinaryTree<ElemType>::PostOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
{
    if (r)
    {
        PostOrder(r->leftchild_, Visit);
        PostOrder(r->rightchild_, Visit);
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
    int leftheight = GetHeight(r->leftchild_);
    int rightheight = GetHeight(r->rightchild_);
    return 1 + (leftheight > rightheight ? leftheight : rightheight);
}
template <class ElemType>
int BinaryTree<ElemType>::GetLeafNumber(const BinaryTreeNode<ElemType> *r) const
{
    if (!r)
    {
        return 0;
    }
    return 1 + GetLeafNumber(r->leftchild_) + GetLeafNumber(r->rightchild_);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetParent(BinaryTreeNode<ElemType> *r, const BinaryTreeNode<ElemType> *p) const
{
    if (!r)
    {
        return NULL;
    }
    if (r->leftchild_ == p || r->rightchild_ == p)
    {
        return r;
    }
    BinaryTreeNode<ElemType> *temp;
    temp = GetParent(r->leftchild_, p);
    if (temp)
    {
        return temp;
    }
    temp = GetParent(r->rightchild_, p);
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
    assert(root_);
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
        if (p->leftchild_)
        {
            Q.push(p->leftchild_);
        }
        if (p->rightchild_)
        {
            Q.push(p->rightchild_);
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
    if (p->leftchild_)
    {
        q->leftchild_ = p->leftchild_;
    }
    p->leftchild_ = q;
}
template <class ElemType>
void BinaryTree<ElemType>::InsertRightChild(BinaryTreeNode<ElemType> *p, const ElemType &e)
{
    if (!p)
    {
        return;
    }
    BinaryTreeNode<ElemType> *q = new BinaryTreeNode<ElemType>(e);
    if (p->rightchild_)
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
    return p->leftchild_;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetRightChild(const BinaryTreeNode<ElemType> *p) const
{
    if (!p)
    {
        return NULL;
    }
    return p->rightchild_;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetLeftSibling(const BinaryTreeNode<ElemType> *p) const
{
    BinaryTreeNode<ElemType> *r = GetParent(root_, p);
    if (!r)
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
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetRightSibling(const BinaryTreeNode<ElemType> *p) const
{
    BinaryTreeNode<ElemType> *r = GetParent(root_, p);
    if (!r)
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
int BinaryTree<ElemType>::GetHeight() const
{
    return GetHeight(root_);
}
template <class ElemType>
int BinaryTree<ElemType>::GetWidth() const
{
    LinkQueue<BinaryTreeNode<ElemType> *> LQ;
    BinaryTreeNode<ElemType> *BTN;
    int max = 0;
    int number = 0;
    int nextnumber = 0;
    if (root_)
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
            if (BTN->leftchild_)
            {
                LQ.EnQueue(BTN->leftchild_);
                nextnumber++;
            }
            if (BTN->rightchild_)
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
int BinaryTree<ElemType>::GetLeafNumber() const
{
    return GetLeafNumber(root_);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::InitByPreOrder(LinkQueue<ElemType> &LQ)
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
    if (!root_)
    {
        root_ = BT;
    }
    BT->leftchild_ = InitByPreOrder(LQ);
    BT->rightchild_ = InitByPreOrder(LQ);
    return BT;
}
template <class ElemType>
void BinaryTree<ElemType>::GetMirror(BinaryTreeNode<ElemType> *r)
{
    if (!r || !r->leftchild_ && !r->rightchild_)
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