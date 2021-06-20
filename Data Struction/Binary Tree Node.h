#pragma once
#ifndef __BINARY_TREE_NODE_H__
#define __BINARY_TREE_NODE_H__
#include <iostream>
template <class ElemType>
class BinaryTreeNode
{
public:
    ElemType elem_;
    BinaryTreeNode<ElemType> *leftChild_;
    BinaryTreeNode<ElemType> *rightChild_;
    BinaryTreeNode();
    BinaryTreeNode(const ElemType &data, BinaryTreeNode<ElemType> *leftChild = NULL, BinaryTreeNode<ElemType> *rightChild = NULL);
};
template <class ElemType>
BinaryTreeNode<ElemType>::BinaryTreeNode() : leftChild_(NULL), rightChild_(NULL)
{
}
template <class ElemType>
BinaryTreeNode<ElemType>::BinaryTreeNode(const ElemType &data, BinaryTreeNode<ElemType> *leftChild, BinaryTreeNode<ElemType> *rightChild)
    : elem_(data), leftChild_(leftChild), rightChild_(rightChild)
{
}
#endif