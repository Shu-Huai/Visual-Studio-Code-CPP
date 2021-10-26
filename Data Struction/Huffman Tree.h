#pragma once
#ifndef __HUFFMAN_TREE__
#define __HUFFMAN_TREE__
#include "Huffman Tree Node.h"
#include "iostream"
using namespace std;
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
    HuffmanTree(CharType ch[], WeightType w[], int n);
    virtual ~HuffmanTree();
    string Encode(CharType ch);
    string Decode(string strCode);
    HuffmanTree(const HuffmanTree<CharType, WeightType> &t);
    HuffmanTree<CharType, WeightType> &operator=(const HuffmanTree<CharType, WeightType> &t);
};
template <class CharType, class WeightType>
void HuffmanTree<CharType, WeightType>::Select(int n, int &r1, int &r2)
{
    r1 = -1;
    r2 = -1;
    for (int i = 0; i < n; i++)
    {
        if (nodes_[i].m_parent == -1)
        {
            if (r1 == -1)
            {
                r1 = i;
            }
            else if (nodes_[i].m_weight < nodes_[r1].m_weight)
            {
                r2 = r1;
                r1 = i;
            }
        }
        else if (r2 == -1 || nodes_[i].m_weight < nodes_[r2].m_weight)
        {
            r2 = i;
        }
    }
}
template <class CharType, class WeightType>
void HuffmanTree<CharType, WeightType>::CreatHuffmanTree(CharType ch[], WeightType w[], int n)
{
    num_ = n;
    int m = 2 * n - 1;
    nodes_ = new HuffmanTreeNode<WeightType>[m];
    leafchars_ = new CharType[n];
    leafcharcodes_ = new string[n];
    int i, p, q;
    for (i = 0; i < n; i++)
    {
        nodes_[i].m_weight = w[i];
        nodes_[i].m_leftChild = -1;
        nodes_[i].m_rightChild = -1;
        nodes_[i].m_parent = -1;
        leafchars_[i] = ch[i];
    }
    for (i = n; i < m; i++)
    {
        int rl, r2;
        Select(i, rl, r2);
        nodes_[rl].m_parent = nodes_[r2].m_parent = i;
        nodes_[i].m_leftChild = rl;
        nodes_[i].m_rightChild = r2;
        nodes_[i].m_parent = -1;
        nodes_[i].m_weight = nodes_[rl].m_weight + nodes_[r2].m_weight;
    }
    for (i = 0; i < n; i++)
    {
        string charCode;
        q = i;
        p = nodes_[q].m_parent;
        while (p != -1)
        {
            if (nodes_[p].m_leftChild == q)
            {
                charCode = "0" + charCode;
            }
            else
            {
                charCode = "1" + charCode;
            }
            q = p;
            p = nodes_[q].m_parent;
        };
        leafcharcodes_[i] = charCode;
    }
}
template <class CharType, class WeightType>
HuffmanTree<CharType, WeightType>::HuffmanTree(CharType ch[], WeightType w[], int n)
{
    CreatHuffmanTree(ch, w, n);
}
template <class CharType, class WeightType>
HuffmanTree<CharType, WeightType>::~HuffmanTree()
{
    delete[] nodes_;
    delete[] leafchars_;
    delete[] leafcharcodes_;
}
template <class CharType, class WeightType>
string HuffmanTree<CharType, WeightType>::Encode(CharType ch)
{
    for (int i = 0; i < num_; i++)
    {
        if (leafchars_[i] == ch)
        {
            return leafcharcodes_[i];
        }
        throw string("非法字符， 无法编码！");
    }
}
template <class CharType, class WeightType>
string HuffmanTree<CharType, WeightType>::Decode(string strCode)
{
    string charList;
    int p = 2 * num_ - 2;
    for (int i = 0; i < strCode.length(); i++)
    {
        if (strCode[i] == '0')
        {
            p = nodes_[p].m_leftChild;
        }
        else
        {
            p = nodes_[p].m_rightChild;
        }
        if (nodes_[p].m_leftChild == -1 && nodes_[p].m_rightChild == -1)
        {
            charList += (string)leafchars_[p];
            p = 2 * num_ - 2;
        }
    }
    if (p != 2 * num_ - 2)
    {
        throw string("编码不对，无法译码！");
    }
    return charList;
}
#endif