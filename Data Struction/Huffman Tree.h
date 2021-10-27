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
    HuffmanTreeNode<WeightType> *m_nodes;
    CharType *m_leafChars;
    string *m_leafCharCodes;
    int m_number;
    void Select(int number, int &rootA, int &rootB);

public:
    HuffmanTree(CharType *chars, WeightType *weights, int number);
    virtual ~HuffmanTree();
    string Encode(CharType c);
    string Decode(string strCode);
};
template <class CharType, class WeightType>
void HuffmanTree<CharType, WeightType>::Select(int number, int &rootA, int &rootB)
{
    rootA = -1;
    rootB = -1;
    for (int i = 0; i < number; i++)
    {
        if (m_nodes[i].m_parent == -1)
        {
            if (rootA == -1)
            {
                rootA = i;
            }
            else if (m_nodes[i].m_weight < m_nodes[rootA].m_weight)
            {
                rootB = rootA;
                rootA = i;
            }
            else if (rootB == -1 || m_nodes[i].m_weight < m_nodes[rootB].m_weight)
            {
                rootB = i;
            }
        }
    }
}
template <class CharType, class WeightType>
HuffmanTree<CharType, WeightType>::HuffmanTree(CharType *chars, WeightType *weights, int number) : m_number(number)
{
    m_nodes = new HuffmanTreeNode<WeightType>[2 * number - 1];
    m_leafChars = new CharType[number];
    m_leafCharCodes = new string[number]{""};
    for (int i = 0; i < number; i++)
    {
        m_nodes[i].m_weight = weights[i];
        m_nodes[i].m_leftChild = -1;
        m_nodes[i].m_rightChild = -1;
        m_nodes[i].m_parent = -1;
        m_leafChars[i] = chars[i];
    }
    for (int i = number; i < 2 * number - 1; i++)
    {
        int rootA, rootB;
        Select(i, rootA, rootB);
        if (m_nodes[rootA].m_weight < m_nodes[rootB].m_weight)
        {
            swap(rootA, rootB);
        }
        m_nodes[rootA].m_parent = i;
        m_nodes[rootB].m_parent = i;
        m_nodes[i].m_leftChild = rootA;
        m_nodes[i].m_rightChild = rootB;
        m_nodes[i].m_parent = -1;
        m_nodes[i].m_weight = m_nodes[rootA].m_weight + m_nodes[rootB].m_weight;
    }
    for (int i = 0; i < number; i++)
    {
        int current = i;
        int parent = m_nodes[current].m_parent;
        while (parent != -1)
        {
            if (m_nodes[parent].m_leftChild == current)
            {
                m_leafCharCodes[i] = "0" + m_leafCharCodes[i];
            }
            else
            {
                m_leafCharCodes[i] = "1" + m_leafCharCodes[i];
            }
            current = parent;
            parent = m_nodes[current].m_parent;
        }
    }
}
template <class CharType, class WeightType>
HuffmanTree<CharType, WeightType>::~HuffmanTree()
{
    delete[] m_nodes;
    delete[] m_leafChars;
    delete[] m_leafCharCodes;
}
template <class CharType, class WeightType>
string HuffmanTree<CharType, WeightType>::Encode(CharType c)
{
    for (int i = 0; i < m_number; i++)
    {
        if (m_leafChars[i] == c)
        {
            return m_leafCharCodes[i];
        }
    }
    throw string("非法字符。");
}
template <class CharType, class WeightType>
string HuffmanTree<CharType, WeightType>::Decode(string strCode)
{
    string result;
    int parent = 2 * m_number - 2;
    for (int i = 0; i < strCode.length(); i++)
    {
        if (strCode[i] == '0')
        {
            parent = m_nodes[parent].m_leftChild;
        }
        else
        {
            parent = m_nodes[parent].m_rightChild;
        }
        if (m_nodes[parent].m_leftChild == -1 && m_nodes[parent].m_rightChild == -1)
        {
            result += (string)m_leafChars[parent];
            parent = 2 * m_number - 2;
        }
    }
    if (parent != 2 * m_number - 2)
    {
        throw string("非法字符。");
    }
    return result;
}
#endif