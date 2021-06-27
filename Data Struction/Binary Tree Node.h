#pragma once
#ifndef __BINARY_TREE_NODE_H__
#define __BINARY_TREE_NODE_H__
#include <iostream>
using namespace std;
template <class ElemType>
class BinaryTreeNode
{
public:
    ElemType elem_;
    BinaryTreeNode<ElemType> *leftChild_;
    BinaryTreeNode<ElemType> *rightChild_;
    BinaryTreeNode();
    BinaryTreeNode(const ElemType &elem, BinaryTreeNode<ElemType> *leftChild = NULL, BinaryTreeNode<ElemType> *rightChild = NULL);
    template <class SubElemType>
    class BinaryTree;
    template <class SubElemType>
    friend ostream &operator<<(ostream &out, BinaryTreeNode<ElemType> &node);
};
template <class ElemType>
BinaryTreeNode<ElemType>::BinaryTreeNode() : leftChild_(NULL), rightChild_(NULL)
{
}
template <class ElemType>
BinaryTreeNode<ElemType>::BinaryTreeNode(const ElemType &elem, BinaryTreeNode<ElemType> *leftChild, BinaryTreeNode<ElemType> *rightChild)
    : elem_(elem), leftChild_(leftChild), rightChild_(rightChild)
{
}
template<class ElemType>
ostream& operator<<(ostream &out,BinaryTreeNode<ElemType> &node)
{
    out << node.elem_;
    return out;
}
#endif