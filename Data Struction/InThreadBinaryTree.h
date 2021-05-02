#pragma once
#ifndef __IN_THREAD_BINARY_TREE__
#define __IN_THREAD_BINARY_TREE__
#include "Binary Tree.h"
#include "Thread Binary Tree Node.h"
template <class ElemType>
class InThreadBinaryTree
{
protected:
    ThreadBinaryTreeNode<ElemType> *root_;
    void InThreadHelp(ThreadBinaryTreeNode<ElemType> *p, ThreadBinaryTreeNode<ElemType> *&pre);
    ThreadBinaryTreeNode<ElemType> *TransformHelp(BinaryTreeNode<ElemType> *r);
    ThreadBinaryTreeNode<ElemType> *CopyTreeHelp(ThreadBinaryTreeNode<ElemType> *t);
    void DestroyHelp(ThreadBinaryTreeNode<ElemType> *&r);

public:
    InThreadBinaryTree(const BinaryTree<ElemType> &BT);
    virtual ~InThreadBinaryTree();
    ThreadBinaryTreeNode<ElemType> *GetRoot() const;
    void InThread();
    ThreadBinaryTreeNode<ElemType> *GetFirst() const;
    ThreadBinaryTreeNode<ElemType> *GetLast() const;
    ThreadBinaryTreeNode<ElemType> *GetNext(ThreadBinaryTreeNode<ElemType> *p) const;
    ThreadBinaryTreeNode<ElemType> *Find(const ElemType &e) const;
    void InsertRightChild(ThreadBinaryTreeNode<ElemType> *p, const ElemType &e);
    void DeleteLeftChild(ThreadBinaryTreeNode<ElemType> *p);
    void InOrder(void (*Visit)(const ElemType &)) const;
    InThreadBinaryTree(const InThreadBinaryTree<ElemType> &ITBT);
    InThreadBinaryTree<ElemType> &operator=(const InThreadBinaryTree<ElemType> &ITBT);
};
template <class ElemType>
void DisplayBTWithTreeShapeHelp(ThreadBinaryTreeNode<ElemType> *r, int level);
template <class ElemType>
void DisplayBTWithTreeShape(InThreadBinaryTree<ElemType> &ITBT);
template <class ElemType>
void InThreadBinaryTree<ElemType>::InThreadHelp(ThreadBinaryTreeNode<ElemType> *p, ThreadBinaryTreeNode<ElemType> *&pre)
{
    if (p != NULL)
    {
        InThreadHelp(p->leftChild_, pre);
        if (p->leftChild_ == NULL)
        {
            p->leftChild_ = pre;
            p->lefttag_ = 1;
        }
        else
        {
            p->lefttag_ = 0;
        }
        if (pre != NULL and pre->rightChild_ == NULL)
        {
            pre->rightChild_ = p;
            pre->righttag_ = 1;
        }
        else if (pre != NULL)
        {
            pre->righttag_ = 0;
        }
        pre = p;
        InThreadHelp(p->rightChild_, pre);
    }
}
template <class ElemType>
ThreadBinaryTreeNode<ElemType> *InThreadBinaryTree<ElemType>::TransformHelp(BinaryTreeNode<ElemType> *r)
{
    if (r == NULL)
    {
        return NULL;
    }
    ThreadBinaryTreeNode<ElemType> *leftchild = TransformHelp(r->leftChild_);
    ThreadBinaryTreeNode<ElemType> *rightchild = TransformHelp(r->rightChild_);
    ThreadBinaryTreeNode<ElemType> *root = new ThreadBinaryTreeNode<ElemType>(r->data_, leftchild, rightchild);
    return root;
}
template <class ElemType>
ThreadBinaryTreeNode<ElemType> *InThreadBinaryTree<ElemType>::CopyTreeHelp(ThreadBinaryTreeNode<ElemType> *t)
{
    if (t == NULL)
    {
        return NULL;
    }
    ThreadBinaryTreeNode<ElemType> *leftchild;
    ThreadBinaryTreeNode<ElemType> *rightchild;
    if (!t->lefttag_)
    {
        leftchild = CopyTreeHelp(t->leftChild_);
    }
    else
    {
        leftchild = NULL;
    }
    if (!t->righttag_)
    {
        rightchild = CopyTreeHelp(t->rightChild_);
    }
    else
    {
        rightchild = NULL;
    }
    ThreadBinaryTreeNode<ElemType> *r = new ThreadBinaryTreeNode<ElemType>(t->data_, leftchild, rightchild);
    return r;
}
template <class ElemType>
void InThreadBinaryTree<ElemType>::DestroyHelp(ThreadBinaryTreeNode<ElemType> *&r)
{
    if (r != NULL)
    {
        if (!r->lefttag_)
        {
            DestroyHelp(r->leftChild_);
        }
        if (!r->righttag_)
        {
            DestroyHelp(r->rightChild_);
        }
        delete r;
        r = NULL;
    }
}
template <class ElemType>
InThreadBinaryTree<ElemType>::InThreadBinaryTree(const BinaryTree<ElemType> &BT)
{
    root_ = TransformHelp(BT.GetRoot());
    InThread();
}
template <class ElemType>
InThreadBinaryTree<ElemType>::~InThreadBinaryTree()
{
    DestroyHelp(root_);
}
template <class ElemType>
ThreadBinaryTreeNode<ElemType> *InThreadBinaryTree<ElemType>::GetRoot() const
{
    return root_;
}
template <class ElemType>
void InThreadBinaryTree<ElemType>::InThread()
{
    ThreadBinaryTreeNode<ElemType> *pre = NULL;
    InThreadHelp(root_, pre);
    pre->righttag_ = 1;
}
template <class ElemType>
ThreadBinaryTreeNode<ElemType> *InThreadBinaryTree<ElemType>::GetFirst() const
{
    if (root_ == NULL)
    {
        return NULL;
    }
    ThreadBinaryTreeNode<ElemType> *p = root_;
    while (!p->lefttag_)
    {
        p = p->leftChild_;
    }
    return p;
}
template <class ElemType>
ThreadBinaryTreeNode<ElemType> *InThreadBinaryTree<ElemType>::GetLast() const
{
    if (root_ == NULL)
    {
        return NULL;
    }
    ThreadBinaryTreeNode<ElemType> *p = root_;
    while (!p->righttag_)
    {
        p = p->rightChild_;
    }
    return p;
}
template <class ElemType>
ThreadBinaryTreeNode<ElemType> *InThreadBinaryTree<ElemType>::GetNext(ThreadBinaryTreeNode<ElemType> *p) const
{
    if (p->righttag_)
    {
        p = p->rightChild_;
    }
    else
    {
        p = p->rightChild_;
        while (!p->lefttag_)
        {
            p = p->leftChild_;
        }
    }
    return p;
}
template <class ElemType>
ThreadBinaryTreeNode<ElemType> *InThreadBinaryTree<ElemType>::Find(const ElemType &e) const
{
    ThreadBinaryTreeNode<ElemType> *p = GetFirst();
    while (p != NULL && p->data_ != e)
    {
        p = GetNext(p);
    }
    return p;
}
template <class ElemType>
void InThreadBinaryTree<ElemType>::InsertRightChild(ThreadBinaryTreeNode<ElemType> *p, const ElemType &e)
{
    if (p == NULL)
    {
        return;
    }
    ThreadBinaryTreeNode<ElemType> *x, *q;
    x = new ThreadBinaryTreeNode<ElemType>(e, p, p->rightChild_, 1, p->righttag_);
    if (!p->righttag_)
    {
        q = p->rightChild_;
        while (!q->lefttag_)
        {
            q = q->leftChild_;
        }
        q->leftChild_ = x;
    }
    p->rightChild_ = x;
    p->righttag_ = 0;
}
template <class ElemType>
void InThreadBinaryTree<ElemType>::DeleteLeftChild(ThreadBinaryTreeNode<ElemType> *p)
{
    if (p == NULL or p->lefttag_ != 0)
    {
        return;
    }
    ThreadBinaryTreeNode<ElemType> *q;
    q = p->leftChild_;
    while (!q->lefttag_)
    {
        q = q->leftChild_;
    }
    DestroyHelp(p->leftChild_);
    p->leftChild_ = q->leftChild_;
    p->lefttag_ = 1;
}
template <class ElemType>
void InThreadBinaryTree<ElemType>::InOrder(void (*Visit)(const ElemType &)) const
{
    ThreadBinaryTreeNode<ElemType> *p;
    for (p = GetFirst(); p != NULL; p = GetNext(p))
    {
        (*Visit)(p->data_);
        if (p->lefttag_)
        {
            cout << "其左指针为线索指针，指向";
        }
        else
        {
            cout << "其左指针为孩子指针，指向";
        }
        if (p->leftChild_ != NULL)
        {
            cout << p->leftChild_->data_;
        }
        else
        {
            cout << "NULL";
        }
        if (p->righttag_)
        {
            cout << "；其右指针为线索指针，指向";
        }
        else
        {
            cout << "；其右指针为孩子指针，指向";
        }
        if (p->rightChild_ != NULL)
        {
            cout << p->rightChild_->data_ << endl;
        }
        else
        {
            cout << "NULL" << endl;
        }
    }
}
template <class ElemType>
InThreadBinaryTree<ElemType>::InThreadBinaryTree(const InThreadBinaryTree<ElemType> &ITBT)
{
    root_ = CopyTreeHelp(ITBT.root_);
    InThread();
}
template <class ElemType>
InThreadBinaryTree<ElemType> &InThreadBinaryTree<ElemType>::operator=(const InThreadBinaryTree<ElemType> &ITBT)
{
    if (&ITBT != this)
    {
        DestroyHelp(root_);
        root_ = CopyTreeHelp(ITBT.root_);
        InThread();
    }
    return *this;
}
template <class ElemType>
void DisplayBTWithTreeShapeHelp(ThreadBinaryTreeNode<ElemType> *r, int level)
{
    if (r != NULL)
    {
        if (!r->righttag_)
        {
            DisplayBTWithTreeShapeHelp<ElemType>(r->rightChild_, level + 1);
        }
        cout << endl;
        for (int i = 0; i < level - 1; i++)
        {
            cout << "  ";
        }
        cout << r->data_;
        if (!r->lefttag_)
        {
            DisplayBTWithTreeShapeHelp<ElemType>(r->leftChild_, level + 1);
        }
    }
}
template <class ElemType>
void DisplayBTWithTreeShape(InThreadBinaryTree<ElemType> &ITBT)
{
    DisplayBTWithTreeShapeHelp<ElemType>(ITBT.GetRoot(), 1);
    cout << endl;
}
#endif