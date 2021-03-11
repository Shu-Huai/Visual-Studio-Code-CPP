#pragma once
#ifndef __HUFFMAN_TREE__
#define __HUFFMAN_TREE__
#include "HuffmanTreeNode.h"
template <class CharType, class WeightType>
class HuffmanTree
{
protected:
        HuffmanTreeNode<WeightType> *nodes_;
        CharType *leafchars_;
        string *leafcharcodes_;
        int num_;
        void Select(int n, int &rl, int &r2);
        void CreatHuffmanTree(CharType ch[], WeightType w[], int n);

public:
    HuffmanTree(CharType ch[], WeightType w[J, int n);
    virtual ~HuffmanTree();
    string Encode(CharType ch);
    LinkList<CharType> Decode(String strCode);
    HuffmanTree(const HuffmanTree<CharType, WeightType> &t);
    HuffmanTree<CharType, WeightType> &operator=(const HuffmanTree<CharType, WeightType> &t);
};
#endif