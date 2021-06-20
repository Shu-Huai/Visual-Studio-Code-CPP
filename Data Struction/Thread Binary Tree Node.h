#pragma once
#ifndef __THREAD_BINARY_TREE_NODE_H__
#define __THREAD_BINARY_TREE_NODE_H__
#include "Assistance.h"
template <class ElemType>
class ThreadBinaryTreeNode
{
public:
    ElemType elem_;
    ThreadBinaryTreeNode<ElemType> *leftChild_;
    ThreadBinaryTreeNode<ElemType> *rightChild_;
    int lefttag_;
    int righttag_;
    ThreadBinaryTreeNode();
    ThreadBinaryTreeNode(const ElemType &data,
                         ThreadBinaryTreeNode<ElemType> *leftchild = NULL, ThreadBinaryTreeNode<ElemType> *rightchild = NULL,
                         int lefttag = 0, int righttag = 0);
};
template <class ElemType>
ThreadBinaryTreeNode<ElemType>::ThreadBinaryTreeNode() : leftChild_(NULL), rightChild_(NULL), lefttag_(0), righttag_(0)
{
}
template <class ElemType>
ThreadBinaryTreeNode<ElemType>::ThreadBinaryTreeNode(const ElemType &data,
                                                     ThreadBinaryTreeNode<ElemType> *leftchild, ThreadBinaryTreeNode<ElemType> *rightchild,
                                                     int lefttag, int righttag)
    : elem_(data), leftChild_(leftchild), rightChild_(rightchild), lefttag_(lefttag), righttag_(righttag)
{
}
#endif