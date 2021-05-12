#pragma once
#ifndef __BINNARY_SORT_TREE_H__
#define __BINNARY_SORT_TREE_H__
#include "Binary Tree.h"
template <class ElemType>
class BinarySortTree : public BinaryTree<ElemType>
{
protected:
    BinaryTreeNode<ElemType> *Find(const ElemType &key, BinaryTreeNode<ElemType> *&parentNode) const;

public:
    Status InsertElem(const ElemType &elem);
    Status DeleteElem(const ElemType &key);
    BinaryTreeNode<ElemType> *Find(const ElemType &key) const;
};
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::Find(const ElemType &key, BinaryTreeNode<ElemType> *&parentNode) const
{
    BinaryTreeNode<ElemType> *p = this->root_;
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
Status BinarySortTree<ElemType>::InsertElem(const ElemType &elem)
{
    BinaryTreeNode<ElemType> *parentNode;
    if (Find(elem, parentNode))
    {
        return FAIL;
    }
    BinaryTreeNode<ElemType> *p = new BinaryTreeNode<ElemType>(elem);
    if (this->IsEmpty())
    {
        this->root_ = p;
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
Status BinarySortTree<ElemType>::DeleteElem(const ElemType &key)
{
    BinaryTreeNode<ElemType> *parentNode = NULL;
    BinaryTreeNode<ElemType> *p = Find(key, parentNode);
    if (!p)
    {
        return FAIL;
    }
    if (!parentNode)
    {
        DeleteElem(p->data_);
    }
    else if (key < parentNode->data_)
    {
        DeleteElem(parentNode->leftChild_->data_);
    }
    else
    {
        DeleteElem(parentNode->rightChild_->data_);
    }
    return SUCCESS;
}
template <class ElemType>
BinaryTreeNode<ElemType> *BinarySortTree<ElemType>::Find(const ElemType &key) const
{
    BinaryTreeNode<ElemType> *parentNode;
    return Find(key, parentNode);
}
#endif