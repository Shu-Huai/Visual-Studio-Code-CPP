#pragma once
#ifndef __HUFFMAN_TREE_NODE__
#define __HUFFMAN_TREE_NODE__
template <class WeightType>
class HuffmanTreeNode
{
protected:
    WeightType m_weight;
    int m_parent;
    int m_leftChild;
    int m_rightChild;

public:
    HuffmanTreeNode();
    HuffmanTreeNode(WeightType weight, int parent = -1, int leftChild = -1, int rightChild = -1);
    template <class CharType, class TreeType>
    friend class HuffmanTree;
};
template <class WeightType>
HuffmanTreeNode<WeightType>::HuffmanTreeNode() : m_parent(-1), m_leftChild(-1), m_rightChild(-1)
{
}
template <class WeightType>
HuffmanTreeNode<WeightType>::HuffmanTreeNode(WeightType weight, int parent, int leftChild, int rightChild)
    : m_weight(weight), m_parent(parent), m_leftChild(leftChild), m_rightChild(rightChild)
{
}
#endif