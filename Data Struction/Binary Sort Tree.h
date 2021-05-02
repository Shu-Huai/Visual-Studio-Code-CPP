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
    int GetLeafNumber(const BinaryTreeNode<ElemType> *r) const;
    BinaryTreeNode<ElemType> *GetParent(BinaryTreeNode<ElemType> *r, const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *Find(const ElemType &key, BinaryTreeNode<ElemType> *&f) const;

public:
    BinarySortTree();
    BinarySortTree(const ElemType &e);
    BinarySortTree(BinaryTreeNode<ElemType> *BTN);
    BinarySortTree(const BinarySortTree<ElemType> &BST);
    virtual ~BinarySortTree();
    bool IsEmpty() const;
    void PreOrder(void (*Visit)(const ElemType &)) const;
    void InOrder(void (*Visit)(const ElemType &)) const;
    void PostOrder(void (*Visit)(const ElemType &)) const;
    void LevelOrder(void (*Visit)(const ElemType &)) const;
    bool Insert(const ElemType &e);
    bool Delete(const ElemType &key);
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
    BinaryTreeNode<ElemType> *Find(const ElemType &key) const;
    BinarySortTree<ElemType> &operator=(const BinarySortTree<ElemType> &BST);
};
template <class ElemType>
void DisplayBTWithTreeShapeHelp(const BinaryTreeNode<ElemType> *r, int level);
template <class ElemType>
void DisplayBTWithTreeShape(const BinarySortTree<ElemType> &bt);
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
    BinaryTreeNode<ElemType> *tmpPtr, *tmpF;
    if (!p->leftChild_ && !p->rightChild_)
    {
        delete p;
        p = NULL;
    }
    else if (!p->leftChild_)
    {
        tmpPtr = p;
        p = p->rightChild_;
        delete tmpPtr;
    }
    else if (!p->rightChild_)
    {
        tmpPtr = p;
        p = p->leftChild_;
        delete tmpPtr;
    }
    else
    {
        tmpF = p;
        tmpPtr = p->leftChild_;
        while (tmpPtr->rightChild_)
        {
            tmpF = tmpPtr;
            tmpPtr = tmpPtr->rightChild_;
        }
        p->data_ = tmpPtr->data_;
        if (tmpF->rightChild_ == tmpPtr)
        {
            Delete(tmpF->rightChild_);
        }
        else
        {
            Delete(tmpF->leftChild_);
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
int BinarySortTree<ElemType>::GetLeafNumber(const BinaryTreeNode<ElemType> *r) const
{
    if (!r)
    {
        return 0;
    }
    return 1 + GetLeafNumber(r->leftChild_) + GetLeafNumber(r->rightChild_);
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
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::Find(const ElemType &key, BinaryTreeNode<ElemType> *&f) const
{
    BinaryTreeNode<ElemType> *p = root_;
    f = NULL;
    while (p && p->data_ != key)
    {
        if (key < p->data_)
        {
            cout << "比" << p->data_ << "小" << endl;
            f = p;
            p = p->leftChild_;
        }
        else
        {
            cout << "比" << p->data_ << "大" << endl;
            f = p;
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
BinarySortTree<ElemType>::BinarySortTree(const ElemType &e)
{
    root_ = new BinaryTreeNode<ElemType>(e);
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
bool BinarySortTree<ElemType>::Insert(const ElemType &e)
// 操作结果: 插入数据元素e
{
    BinaryTreeNode<ElemType> *f; // 指向被查找结点的双亲

    cout << "插入数据元素" << e << "的搜索过程：" << endl;
    if (Find(e, f) == NULL)
    {                                // 查找失败, 插入成功
        BinaryTreeNode<ElemType> *p; // 插入的新结点
        p = new BinaryTreeNode<ElemType>(e);
        if (IsEmpty()) // 空二叉树,新结点为根结点
            root_ = p;
        else if (e < f->data_) // e小于其双亲,插入结点为f的左孩子
            f->leftChild_ = p;
        else // e大于其双亲,插入结点为f的右孩子
            f->rightChild_ = p;
        return true;
    }
    else // 查找成功, 插入失败
        return false;
}
template <class ElemType>
bool BinarySortTree<ElemType>::Delete(const ElemType &key)
{
    BinaryTreeNode<ElemType> *p, *f;
    p = Find(key, f);
    if (!p)
    {
        return false;
    }
    else
    {
        if (!f)
        {
            Delete(p);
        }
        else if (key < f->data_)
        {
            Delete(f->leftChild_);
        }
        else
        {
            Delete(f->rightChild_);
        }
    }
    return true;
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
int BinarySortTree<ElemType>::GetLeafNumber() const
{
    return GetLeafNumber(root_);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::Find(const ElemType &key) const
{
    BinaryTreeNode<ElemType> *f;
    return Find(key, f);
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

template <class ElemType>
void DisplayBTWithTreeShapeHelp(const BinaryTreeNode<ElemType> *r, int level)
//	操作结果：按树状形式显示以r为根的二叉排序树，level为层次数，可设根结点的层次数为1
{
    if (r != NULL)
    {                                                                   //空树不显式，只显式非空树
        DisplayBTWithTreeShapeHelp<ElemType>(r->rightChild_, level + 1); //显示右子树
        cout << endl
             << endl; //显示新行
        for (int i = 0; i < level - 1; i++)
            cout << "   ";                                             //确保在第level列显示结点
        cout << r->data_;                                               //显示结点
        DisplayBTWithTreeShapeHelp<ElemType>(r->leftChild_, level + 1); //显示左子树
    }
}

template <class ElemType>
void DisplayBTWithTreeShape(const BinarySortTree<ElemType> &bt)
//	操作结果：树状形式显示二叉排序树
{
    DisplayBTWithTreeShapeHelp<ElemType>(bt.GetRoot(), 1);
    // 树状显示以bt.GetRoot()为根的二叉排序树
    cout << endl;
}

#endif