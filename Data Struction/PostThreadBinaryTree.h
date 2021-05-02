#pragma once
#ifndef __POST_THREAD_BINARY_TREE__
#define __POST_THREAD_BINARY_TREE__
#include "Binary Tree.h"
#include "Thread Binary Tree Node.h"
template <class ElemType>
class PostThreadBinaryTree
{
protected:
    ThreadBinaryTreeNode<ElemType> *root_;
    void PostThreadHelp(ThreadBinaryTreeNode<ElemType> *p, ThreadBinaryTreeNode<ElemType> *&pre);
    ThreadBinaryTreeNode<ElemType> *TransformHelp(BinaryTreeNode<ElemType> *r);
    ThreadBinaryTreeNode<ElemType> *CopyTreeHelp(ThreadBinaryTreeNode<ElemType> *t);
    void DestroyHelp(ThreadBinaryTreeNode<ElemType> *&r);
    ThreadBinaryTreeNode<ElemType> *GetParent(ThreadBinaryTreeNode<ElemType> *root, const ThreadBinaryTreeNode<ElemType> *p) const;

public:
    PostThreadBinaryTree(const BinaryTree<ElemType> &BT);
    virtual ~PostThreadBinaryTree();
    ThreadBinaryTreeNode<ElemType> *GetRoot() const;
    void PostThread();
    ThreadBinaryTreeNode<ElemType> *GetFirst() const;
    ThreadBinaryTreeNode<ElemType> *GetLast() const;
    ThreadBinaryTreeNode<ElemType> *GetNext(ThreadBinaryTreeNode<ElemType> *p) const;
    ThreadBinaryTreeNode<ElemType> *Find(const ElemType &e) const;
    void InsertRightChild(ThreadBinaryTreeNode<ElemType> *p, const ElemType &e);
    void DeleteLeftChild(ThreadBinaryTreeNode<ElemType> *p);
    void PostOrder(void (*Visit)(const ElemType &)) const;
    PostThreadBinaryTree(const PostThreadBinaryTree<ElemType> &PTBT);
    PostThreadBinaryTree<ElemType> &operator=(const PostThreadBinaryTree<ElemType> &PTBT);
    ThreadBinaryTreeNode<ElemType> *GetParent(const ThreadBinaryTreeNode<ElemType> *p) const;
};
template <class ElemType>
void DisplayBTWithTreeShapeHelp(ThreadBinaryTreeNode<ElemType> *r, int level);
template <class ElemType>
void DisplayBTWithTreeShape(PostThreadBinaryTree<ElemType> &PTBT);
template <class ElemType>
void PostThreadBinaryTree<ElemType>::PostThreadHelp(ThreadBinaryTreeNode<ElemType> *p, ThreadBinaryTreeNode<ElemType> *&pre)
{
    if (p != NULL)
    {
        PostThreadHelp(p->leftChild_, pre);
        PostThreadHelp(p->rightChild_, pre);
        if (p->leftChild_ == NULL)
        {
            p->leftChild_ = pre;
            p->lefttag_ = 1;
        }
        else
        {
            p->lefttag_ = 0;
        }
        if (pre != NULL && pre->rightChild_ == NULL)
        {
            pre->rightChild_ = p;
            pre->righttag_ = 1;
        }
        else if (pre != NULL)
        {
            pre->righttag_ = 0;
        }
        pre = p;
    }
}
template <class ElemType>
ThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::TransformHelp(BinaryTreeNode<ElemType> *r)
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
ThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::CopyTreeHelp(ThreadBinaryTreeNode<ElemType> *t)
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
void PostThreadBinaryTree<ElemType>::DestroyHelp(ThreadBinaryTreeNode<ElemType> *&r)
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
ThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::GetParent(ThreadBinaryTreeNode<ElemType> *root, const ThreadBinaryTreeNode<ElemType> *p) const
{
    if (root == NULL)
    {
        return NULL;
    }
    if (!root_->lefttag_ and root_->leftChild_ == p or !root_->righttag_ and root_->rightChild_ == p)
    {
        return root;
    }
    ThreadBinaryTreeNode<ElemType> *tmp;
    tmp = root->lefttag_ ? NULL : GetParent(root->leftChild_, p);
    if (tmp != NULL)
    {
        return tmp;
    }
    tmp = root->righttag_ ? NULL : GetParent(root->rightChild_, p);
    if (tmp != NULL)
    {
        return tmp;
    }
    return NULL;
}
template <class ElemType>
PostThreadBinaryTree<ElemType>::PostThreadBinaryTree(const BinaryTree<ElemType> &BT)
{
    root_ = TransformHelp(BT.GetRoot());
    PostThread();
}
template <class ElemType>
PostThreadBinaryTree<ElemType>::~PostThreadBinaryTree()
{
    DestroyHelp(root_);
}
template <class ElemType>
ThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::GetRoot() const
{
    return root_;
}
template <class ElemType>
void PostThreadBinaryTree<ElemType>::PostThread()
{
    ThreadBinaryTreeNode<ElemType> *pre = NULL;
    PostThreadHelp(root_, pre);
}
template <class ElemType>
ThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::GetFirst() const
{
    ThreadBinaryTreeNode<ElemType> *p = root_;
    while (!p->lefttag_ or !p->righttag_)
    {
        if (!p->lefttag_)
        {
            p = p->leftChild_;
        }
        else
        {
            p = p->rightChild_;
        }
    }
    return p;
}
template <class ElemType>
ThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::GetLast() const
{
    return root_;
}
template <class ElemType>
ThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::GetNext(ThreadBinaryTreeNode<ElemType> *p) const
{
    if (p == root_)
    {
        return NULL;
    }
    if (p->righttag_)
    {
        p = p->rightChild_;
    }
    else
    {
        ThreadBinaryTreeNode<ElemType> *parent = GetParent(p);
        if (parent->rightChild_ == p)
        {
            return parent;
        }
        ThreadBinaryTreeNode<ElemType> *q = parent;
        while (!q->righttag_ or !q->righttag_)
        {
            if (!q->lefttag_)
            {
                q = q->leftChild_;
            }
            else
            {
                q = q->rightChild_;
            }
        }
        return q;
    }
    return p;
}
template <class ElemType>
ThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::Find(const ElemType &e) const
{
    ThreadBinaryTreeNode<ElemType> *p = GetFirst();
    while (p != NULL && p->data_ != e)
    {
        p = GetNext(p);
    }
    return p;
}
template <class ElemType>
void PostThreadBinaryTree<ElemType>::InsertRightChild(ThreadBinaryTreeNode<ElemType> *p, const ElemType &e)
{
    if (p == NULL)
    {
        return;
    }
    ThreadBinaryTreeNode<ElemType> *x, *q;
    if (p->righttag_)
    {
        x = new ThreadBinaryTreeNode<ElemType>(e, p->leftChild_, p, p->lefttag_, 1);
        if (p->leftChild_->righttag_)
        {
            p->leftChild_->rightChild_ = x;
        }
    }
    else
    {
        x = new ThreadBinaryTreeNode<ElemType>(e, p->rightChild_, p->rightChild_, 1, 0);
        if (p->rightChild_->righttag_)
        {
            p->rightChild_->rightChild_ = x;
        }
        if (p->lefttag_)
        {
            p->leftChild_ = x;
        }
    }
    p->rightChild_ = x;
    p->righttag_ = 0;
}
template <class ElemType>
void PostThreadBinaryTree<ElemType>::DeleteLeftChild(ThreadBinaryTreeNode<ElemType> *p)
{
    if (p == NULL or p->lefttag_)
    {
        return;
    }
    ThreadBinaryTreeNode<ElemType> *q = GetParent(p);
    if (q->righttag_)
    {
        q->rightChild_ = p;
    }
    DestroyHelp(p->leftChild_);
    p->leftChild_ = q->leftChild_;
    p->lefttag_ = 1;
}
template <class ElemType>
void PostThreadBinaryTree<ElemType>::PostOrder(void (*Visit)(const ElemType &)) const
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
PostThreadBinaryTree<ElemType>::PostThreadBinaryTree(const PostThreadBinaryTree<ElemType> &PTBT)
{
    root_ = CopyTreeHelp(PTBT.root_);
    PostThread();
}
template <class ElemType>
PostThreadBinaryTree<ElemType> &PostThreadBinaryTree<ElemType>::operator=(const PostThreadBinaryTree<ElemType> &PTBT)
{
    if (&PTBT != this)
    {
        DestroyHelp(root_);
        root_ = CopyTreeHelp(PTBT.root_);
        PostThread();
    }
    return *this;
}
template <class ElemType>
ThreadBinaryTreeNode<ElemType> *PostThreadBinaryTree<ElemType>::GetParent(const ThreadBinaryTreeNode<ElemType> *p) const
{
    return (root_ == NULL or root_ == p) ? NULL : GetParent(root_, p);
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
void DisplayBTWithTreeShape(PostThreadBinaryTree<ElemType> &PTBT)
{
    DisplayBTWithTreeShapeHelp<ElemType>(PTBT.GetRoot(), 1);
    cout << endl;
}
#endif