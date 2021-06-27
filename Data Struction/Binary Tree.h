#pragma once
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__
#include "Binary Tree Node.h"
#include <queue>
using namespace std;
template <class ElemType>
class BinaryTree
{
protected:
    BinaryTreeNode<ElemType> *root_;
    void InitializeByPreOrder(BinaryTreeNode<ElemType> *&root, ElemType *elems, int &index, int length, ElemType referenceValue);
    void Destroy(BinaryTreeNode<ElemType> *&root);
    void PreOrderTraverse(BinaryTreeNode<ElemType> *root) const;
    void InOrderTraverse(BinaryTreeNode<ElemType> *root) const;
    void PostOrderTraverse(BinaryTreeNode<ElemType> *root) const;
    int GetHeight(const BinaryTreeNode<ElemType> *root) const;
    int GetNodeNumber(const BinaryTreeNode<ElemType> *root) const;
    BinaryTreeNode<ElemType> *GetParent(BinaryTreeNode<ElemType> *root, const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *CopyTree(BinaryTreeNode<ElemType> *BTN);

public:
    BinaryTree();
    BinaryTree(const ElemType &elem);
    BinaryTree(BinaryTreeNode<ElemType> *BTN);
    BinaryTree(const BinaryTree<ElemType> &BT);
    virtual ~BinaryTree();
    void InitializeByPreOrder(ElemType *elems, int length, ElemType referenceValue);
    bool IsEmpty() const;
    void PreOrderTraverse() const;
    void InOrderTraverse() const;
    void PostOrderTraverse() const;
    void LevelOrder() const;
    void InsertLeftChild(BinaryTreeNode<ElemType> *p, const ElemType &elem);
    void InsertRightChild(BinaryTreeNode<ElemType> *p, const ElemType &elem);
    void DeleteLeftChild(BinaryTreeNode<ElemType> *p);
    void DeleteRightChild(BinaryTreeNode<ElemType> *p);
    void SetElem(BinaryTreeNode<ElemType> *p, const ElemType &elem);
    BinaryTreeNode<ElemType> *GetRoot() const;
    void GetElem(BinaryTreeNode<ElemType> *p, ElemType &elem) const;
    BinaryTreeNode<ElemType> *GetParent(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *GetLeftChild(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *GetRightChild(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *GetLeftSibling(const BinaryTreeNode<ElemType> *p) const;
    BinaryTreeNode<ElemType> *GetRightSibling(const BinaryTreeNode<ElemType> *p) const;
    int GetHeight() const;
    int GetWidth() const;
    int GetNodeNumber() const;
    void GetMirror(BinaryTreeNode<ElemType> *r);
    BinaryTree<ElemType> &operator=(const BinaryTree<ElemType> &BT);
};
template <class ElemType>
void BinaryTree<ElemType>::InitializeByPreOrder(BinaryTreeNode<ElemType> *&root, ElemType *elems, int &index, int length, ElemType referenceValue)
{
    if (elems[index] != referenceValue && index < length)
    {
        root = new BinaryTreeNode<ElemType>(elems[index]);
        InitializeByPreOrder(root->leftChild_, elems, ++index, length, referenceValue);
        InitializeByPreOrder(root->rightChild_, elems, ++index, length, referenceValue);
    }
    else
    {
        root = NULL;
    }
}
template <class ElemType>
void BinaryTree<ElemType>::Destroy(BinaryTreeNode<ElemType> *&root)
{
    if (root)
    {
        Destroy(root->leftChild_);
        Destroy(root->rightChild_);
        delete root;
        root = NULL;
    }
}
template <class ElemType>
void BinaryTree<ElemType>::PreOrderTraverse(BinaryTreeNode<ElemType> *root) const
{
    if (root)
    {
        cout << root->elem_ << " ";
        PreOrderTraverse(root->leftChild_);
        PreOrderTraverse(root->rightChild_);
    }
}
template <class ElemType>
void BinaryTree<ElemType>::InOrderTraverse(BinaryTreeNode<ElemType> *root) const
{
    if (root)
    {
        InOrderTraverse(root->leftChild_);
        cout << root->elem_ << " ";
        InOrderTraverse(root->rightChild_);
    }
}
template <class ElemType>
void BinaryTree<ElemType>::PostOrderTraverse(BinaryTreeNode<ElemType> *root) const
{
    if (root)
    {
        PostOrderTraverse(root->leftChild_);
        PostOrderTraverse(root->rightChild_);
        cout << root->elem_ << " ";
    }
}
template <class ElemType>
int BinaryTree<ElemType>::GetHeight(const BinaryTreeNode<ElemType> *root) const
{
    if (!root)
    {
        return 0;
    }
    int leftheight = GetHeight(root->leftChild_);
    int rightheight = GetHeight(root->rightChild_);
    return 1 + (leftheight > rightheight ? leftheight : rightheight);
}
template <class ElemType>
int BinaryTree<ElemType>::GetNodeNumber(const BinaryTreeNode<ElemType> *root) const
{
    if (!root)
    {
        return 0;
    }
    return 1 + GetNodeNumber(root->leftChild_) + GetNodeNumber(root->rightChild_);
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetParent(BinaryTreeNode<ElemType> *root, const BinaryTreeNode<ElemType> *p) const
{
    if (!root)
    {
        return NULL;
    }
    if (root->leftChild_ == p || root->rightChild_ == p)
    {
        return root;
    }
    BinaryTreeNode<ElemType> *temp;
    temp = GetParent(root->leftChild_, p);
    if (temp)
    {
        return temp;
    }
    temp = GetParent(root->rightChild_, p);
    if (temp)
    {
        return temp;
    }
    return NULL;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::CopyTree(BinaryTreeNode<ElemType> *BTN)
{
    if (!BTN)
    {
        return NULL;
    }
    BinaryTreeNode<ElemType> *copy = new BinaryTreeNode<ElemType>(BTN->elem_);
    assert(copy);
    copy->leftChild_ = CopyTree(BTN->leftChild_);
    copy->rightChild_ = CopyTree(BTN->rightChild_);
    return copy;
}
template <class ElemType>
BinaryTree<ElemType>::BinaryTree() : root_(NULL)
{
}
template <class ElemType>
BinaryTree<ElemType>::BinaryTree(const ElemType &elem)
{
    root_ = new BinaryTreeNode<ElemType>;
    assert(root_);
    root_->elem_ = elem;
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
void BinaryTree<ElemType>::InitializeByPreOrder(ElemType *elems, int length, ElemType referenceValue)
{
    int index = 0;
    InitializeByPreOrder(root_, elems, index, length, referenceValue);
}
template <class ElemType>
bool BinaryTree<ElemType>::IsEmpty() const
{
    return root_ == NULL;
}
template <class ElemType>
void BinaryTree<ElemType>::PreOrderTraverse() const
{
    PreOrderTraverse(root_);
}
template <class ElemType>
void BinaryTree<ElemType>::InOrderTraverse() const
{
    InOrderTraverse(root_);
}
template <class ElemType>
void BinaryTree<ElemType>::PostOrderTraverse() const
{
    PostOrderTraverse(root_);
}
template <class ElemType>
void BinaryTree<ElemType>::LevelOrder() const
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
        cout << p->elem_ << " ";
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
void BinaryTree<ElemType>::InsertLeftChild(BinaryTreeNode<ElemType> *p, const ElemType &elem)
{
    if (!p)
    {
        return;
    }
    BinaryTreeNode<ElemType> *q = new BinaryTreeNode<ElemType>(elem);
    if (p->leftChild_)
    {
        q->leftChild_ = p->leftChild_;
    }
    p->leftChild_ = q;
}
template <class ElemType>
void BinaryTree<ElemType>::InsertRightChild(BinaryTreeNode<ElemType> *p, const ElemType &elem)
{
    if (!p)
    {
        return;
    }
    BinaryTreeNode<ElemType> *q = new BinaryTreeNode<ElemType>(elem);
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
void BinaryTree<ElemType>::SetElem(BinaryTreeNode<ElemType> *p, const ElemType &elem)
{
    if (!p)
    {
        throw(string) "The tree is empty.";
    }
    p->elem_ = elem;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinaryTree<ElemType>::GetRoot() const
{
    return root_;
}
template <class ElemType>
void BinaryTree<ElemType>::GetElem(BinaryTreeNode<ElemType> *p, ElemType &elem) const
{
    if (!p)
    {
        throw(string) "The tree is empty.";
    }
    elem = p->elem_;
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
int BinaryTree<ElemType>::GetNodeNumber() const
{
    return GetNodeNumber(root_);
}
template <class ElemType>
void BinaryTree<ElemType>::GetMirror(BinaryTreeNode<ElemType> *r)
{
    if (!r || (!r->leftChild_ && !r->rightChild_))
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