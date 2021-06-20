#pragma once
#ifndef __AVL_TREE_NODE_H__
#define __AVL_TREE_NODE_H__
#include "Assistance.h"
template <class ElemType>
class AVLTreeNode
{
public:
    ElemType elem_;
    int balanceFactor_;
    int leftNodeNumber_;
    AVLTreeNode<ElemType> *leftChild_;
    AVLTreeNode<ElemType> *rightChild_;
    AVLTreeNode();
    AVLTreeNode(const ElemType &data, int balanceFactor = 0, AVLTreeNode<ElemType> *leftChild = NULL, AVLTreeNode<ElemType> *rightChild = NULL);
};
template <class ElemType>
AVLTreeNode<ElemType>::AVLTreeNode() : leftChild_(NULL), rightChild_(NULL)
{
}
template <class ElemType>
AVLTreeNode<ElemType>::AVLTreeNode(const ElemType &data, int balanceFactor, AVLTreeNode<ElemType> *leftChild, AVLTreeNode<ElemType> *rightChild)
    : elem_(data), balanceFactor_(balanceFactor), leftChild_(leftChild), rightChild_(rightChild)
{
}
#endif