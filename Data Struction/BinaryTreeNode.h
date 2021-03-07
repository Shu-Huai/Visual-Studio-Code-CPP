#pragma once
#ifndef __BINARY_TREE_NODE_H__
#define __BINARY_TREE_NODE_H__
#include "Assistance.h"
template <class ElemType>
class BinaryTreeNode
{
public:
    ElemType data_;
    BinaryTreeNode<ElemType> *leftchild_;
    BinaryTreeNode<ElemType> *rightchild_;
    BinaryTreeNode();
    BinaryTreeNode(const ElemType &data, BinaryTreeNode<ElemType> *leftchild = NULL, BinaryTreeNode<ElemType> *rightchild = NULL);
};
template <class ElemType>
BinaryTreeNode<ElemType>::BinaryTreeNode() : leftchild_(NULL), rightchild_(NULL)
{
}
template <class ElemType>
BinaryTreeNode<ElemType>::BinaryTreeNode(const ElemType &data, BinaryTreeNode<ElemType> *leftchild, BinaryTreeNode<ElemType> *rightchild) : data_(data), leftchild_(leftchild), rightchild_(rightchild)
{
}
#endif