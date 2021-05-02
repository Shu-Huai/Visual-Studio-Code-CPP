#pragma once
#ifndef __HUFFMAN_TREE_NODE__
#define __HUFFMAN_TREE_NODE__
#include "Assistance.h"
template <class WeightType>
class HuffmanTreeNode
{
public:
    WeightType weight_;
    int parent_, leftchild_, rightChild_;
    HuffmanTreeNode();
    HuffmanTreeNode(WeightType weight, int parent = -1, int leftchild = -1, int rightchild = -1);
};
template <class WeightType>
HuffmanTreeNode<WeightType>::HuffmanTreeNode() : parent_(-1), leftchild_(-1), rightChild_(-1)
{
}
template <class WeightType>
HuffmanTreeNode<WeightType>::HuffmanTreeNode(WeightType weight, int parent, int leftchild, int rightchild)
    : weight_(weight), parent_(parent), leftchild_(leftchild), rightChild_(rightchild)
{
}
#endif