#pragma once
#ifndef __THREAD_BINARY_TREE_NODE_H__
#define __THREAD_BINARY_TREE_NODE_H__
#include "Assistance.h"
template <class ElemType>
class ThreadBinaryTreeNode
{
public:
    ElemType data_;
    ThreadBinaryTreeNode<ElemType> *leftchild_;
    ThreadBinaryTreeNode<ElemType> *rightchild_;
    int lefttag_;
    int righttag_;
    ThreadBinaryTreeNode();
    ThreadBinaryTreeNode(const ElemType &data,
                         ThreadBinaryTreeNode<ElemType> *leftchild = NULL, ThreadBinaryTreeNode<ElemType> *rightchild = NULL,
                         int lefttag = 0, int righttag = 0);
};
template <class ElemType>
ThreadBinaryTreeNode<ElemType>::ThreadBinaryTreeNode() : leftchild_(NULL), rightchild_(NULL), lefttag_(0), righttag_(0)
{
}
template <class ElemType>
ThreadBinaryTreeNode<ElemType>::ThreadBinaryTreeNode(const ElemType &data,
                                                     ThreadBinaryTreeNode<ElemType> *leftchild, ThreadBinaryTreeNode<ElemType> *rightchild,
                                                     int lefttag, int righttag)
    : data_(data), leftchild_(leftchild), rightchild_(rightchild), lefttag_(lefttag), righttag_(righttag)
{
}
#endif