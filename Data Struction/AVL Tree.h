#pragma once
#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__
#include "AVL Tree Node.h"
template <class ElemType>
class AVLTree
{
protected:
    AVLTreeNode<ElemType> *root_;
    ElemType referenceValue_;
    void InitializeByPreOrder(AVLTreeNode<ElemType> *&root, ElemType *elems, int &index, int length);
    void PreOrderTraverse(AVLTreeNode<ElemType> *root, void (*Visit)(const ElemType &)) const;
    void InOrderTraverse(AVLTreeNode<ElemType> *root, void (*Visit)(const ElemType &)) const;
    void PostOrderTraverse(AVLTreeNode<ElemType> *root, void (*Visit)(const ElemType &)) const;
    int GetNodeNumber(const AVLTreeNode<ElemType> *p) const;
    void GetLeftNodeNumber(AVLTreeNode<ElemType> *p);
    AVLTreeNode<ElemType> *LocateNode(AVLTreeNode<ElemType> *root, int index) const;
    AVLTreeNode<ElemType> *Find(const ElemType &key, AVLTreeNode<ElemType> *&parentNode, AVLTreeNode<ElemType> *&nearestNode, AVLTreeNode<ElemType> *&nearestParentNode);

public:
    AVLTree(ElemType referrenceValue);
    void InitializeByPreOrder(ElemType *elems, int length);
    void PreOrderTraverse(void (*Visit)(const ElemType &)) const;
    void InOrderTraverse(void (*Visit)(const ElemType &)) const;
    void PostOrderTraverse(void (*Visit)(const ElemType &)) const;
    void GetLeftNodeNumber();
    AVLTreeNode<ElemType> *LocateNode(int index) const;
    AVLTreeNode<ElemType> *Find(const ElemType &key);
};
template <class ElemType>
void AVLTree<ElemType>::InitializeByPreOrder(AVLTreeNode<ElemType> *&root, ElemType *elems, int &index, int length)
{
    if (elems[index] != referenceValue_ && index < length)
    {
        root = new AVLTreeNode<ElemType>(elems[index]);
        InitializeByPreOrder(root->leftChild_, elems, ++index, length);
        InitializeByPreOrder(root->rightChild_, elems, ++index, length);
    }
    else
    {
        root = NULL;
    }
}
template <class ElemType>
void AVLTree<ElemType>::PreOrderTraverse(AVLTreeNode<ElemType> *root, void (*Visit)(const ElemType &)) const
{
    if (root)
    {
        (*Visit)(root->data_);
        PreOrderTraverse(root->leftChild_, Visit);
        PreOrderTraverse(root->rightChild_, Visit);
    }
}
template <class ElemType>
void AVLTree<ElemType>::InOrderTraverse(AVLTreeNode<ElemType> *root, void (*Visit)(const ElemType &)) const
{
    if (root)
    {
        InOrderTraverse(root->leftChild_, Visit);
        (*Visit)(root->data_);
        InOrderTraverse(root->rightChild_, Visit);
    }
}
template <class ElemType>
void AVLTree<ElemType>::PostOrderTraverse(AVLTreeNode<ElemType> *root, void (*Visit)(const ElemType &)) const
{
    if (root)
    {
        PostOrderTraverse(root->leftChild_, Visit);
        PostOrderTraverse(root->rightChild_, Visit);
        (*Visit)(root->data_);
    }
}
template <class ElemType>
int AVLTree<ElemType>::GetNodeNumber(const AVLTreeNode<ElemType> *p) const
{
    if (!p)
        return 0;
    return 1 + GetNodeNumber(p->leftChild_) + GetNodeNumber(p->rightChild_);
}
template <class ElemType>
void AVLTree<ElemType>::GetLeftNodeNumber(AVLTreeNode<ElemType> *p)
{
    if (!p)
    {
        return;
    }
    p->leftNodeNumber_ = 1 + GetNodeNumber(p->leftChild_);
    GetLeftNodeNumber(p->leftChild_);
    GetLeftNodeNumber(p->rightChild_);
}
template <class ElemType>
AVLTreeNode<ElemType> *AVLTree<ElemType>::LocateNode(AVLTreeNode<ElemType> *root, int index) const
{
    if (!root)
    {
        return NULL;
    }
    if (root->leftNodeNumber_ == index)
    {
        return root;
    }
    if (root->leftNodeNumber_ > index)
    {
        return LocateNode(root->leftChild_, index);
    }
    return LocateNode(root->rightChild_, index - root->leftNodeNumber_);
}
template <class ElemType>
AVLTreeNode<ElemType> *AVLTree<ElemType>::Find(const ElemType &key, AVLTreeNode<ElemType> *&parentNode,
                                               AVLTreeNode<ElemType> *&nearestNode, AVLTreeNode<ElemType> *&nearestParentNode)
{
    AVLTreeNode<ElemType> *p = root_;
    parentNode = NULL;
    nearestNode = NULL;
    nearestParentNode = NULL;
    while (p && p->data_ != key)
    {
        if (p->balanceFactor_)
        {
            nearestParentNode = parentNode;
            nearestNode = p;
        }
        if (key < p->data_)
        {
            parentNode = p;
            p = p->leftChild_;
        }
        if (key > p->data_)
        {
            parentNode = p;
            p = p->rightChild_;
        }
    }
    if (!nearestNode)
    {
        nearestNode = root_;
    }
    return p;
}
template <class ElemType>
AVLTree<ElemType>::AVLTree(ElemType referrenceValue) : referenceValue_(referrenceValue)
{
    root_ = new AVLTreeNode<ElemType>;
    assert(root_);
}
template <class ElemType>
void AVLTree<ElemType>::InitializeByPreOrder(ElemType *elems, int length)
{
    int index = 0;
    InitializeByPreOrder(root_, elems, index, length);
    GetLeftNodeNumber();
}
template <class ElemType>
void AVLTree<ElemType>::PreOrderTraverse(void (*Visit)(const ElemType &)) const
{
    PreOrderTraverse(root_, Visit);
}
template <class ElemType>
void AVLTree<ElemType>::InOrderTraverse(void (*Visit)(const ElemType &)) const
{
    InOrderTraverse(root_, Visit);
}
template <class ElemType>
void AVLTree<ElemType>::PostOrderTraverse(void (*Visit)(const ElemType &)) const
{
    PostOrderTraverse(root_, Visit);
}
template <class ElemType>
void AVLTree<ElemType>::GetLeftNodeNumber()
{
    GetLeftNodeNumber(root_);
}
template <class ElemType>
AVLTreeNode<ElemType> *AVLTree<ElemType>::LocateNode(int index) const
{
    return LocateNode(root_, index);
}
template <class ElemType>
AVLTreeNode<ElemType> *AVLTree<ElemType>::Find(const ElemType &key)
{
    AVLTreeNode<ElemType> *parentNode;
    AVLTreeNode<ElemType> *nearestNode;
    AVLTreeNode<ElemType> *nearestParentNode;
    return Find(key, parentNode, nearestNode, nearestParentNode);
}
#endif