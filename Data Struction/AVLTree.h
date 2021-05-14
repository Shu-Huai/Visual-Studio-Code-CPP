#pragma once
#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__
#include "AVLTreeNode.h"
template <class ElemType>
class AVLTree
{
protected:
    AVLTreeNode<ElemType> *_root;
    ElemType _refValue;
    // 辅助函数
    void CreateBinTree_PreOrder_array(AVLTreeNode<ElemType> *&root,
                                      ElemType *data, int &index, int length); // 传入先序遍历数组创建二叉树
    int GetNodeNum(const AVLTreeNode<ElemType> *p) const;                   // 获取p结点为根的子树节点个数
    void GetLsize(AVLTreeNode<ElemType> *p);                                // 获取p结点左子树节点个数+1
    AVLTreeNode<ElemType> *LocateNode(AVLTreeNode<ElemType> *p, int k);
    void PreOrder(AVLTreeNode<ElemType> *&root);
    void InOrder(AVLTreeNode<ElemType> *&root);

public:
    AVLTree(ElemType refValue) : _refValue(refValue) { _root = new AVLTreeNode<ElemType>; }
    void GetLsize() { GetLsize(_root); }
    void CreateBinTree_PreOrder_array(ElemType *data, int length)
    {
        int index = 0;
        CreateBinTree_PreOrder_array(_root, data, index, length);
        GetLsize();
    }
    AVLTreeNode<ElemType> *LocateNode(int k) { return LocateNode(_root, k); } // 查找第k小的结点
    void PreOrder() { PreOrder(_root); }
    void InOrder() { InOrder(_root); }
};
template <class ElemType>
int AVLTree<ElemType>::GetNodeNum(const AVLTreeNode<ElemType> *p) const
{
    if (!p)
        return 0;
    return 1 + GetNodeNum(p->leftChild_) + GetNodeNum(p->rightChild_);
}
template <class ElemType>
void AVLTree<ElemType>::GetLsize(AVLTreeNode<ElemType> *p)
{
    if (!p)
        return;
    p->_lsize = 1 + GetNodeNum(p->leftChild_);
    GetLsize(p->leftChild_);
    GetLsize(p->rightChild_);
}

template <class ElemType>
void AVLTree<ElemType>::CreateBinTree_PreOrder_array(AVLTreeNode<ElemType> *&root,
                                                 ElemType *data, int &index, int length)
{
    if (data[index] != _refValue && index < length)
    {
        root = new AVLTreeNode<ElemType>(data[index]);
        CreateBinTree_PreOrder_array(root->leftChild_, data, ++index, length);  //递归创建左子树
        CreateBinTree_PreOrder_array(root->rightChild_, data, ++index, length); //递归创建右子树
    }
    else
        root = NULL;
}

template <class ElemType>
AVLTreeNode<ElemType> *AVLTree<ElemType>::LocateNode(AVLTreeNode<ElemType> *p, int k)
{
    if (!p)
        return NULL;
    if (p->_lsize == k)
        return p;
    else if (p->_lsize > k)
        return LocateNode(p->leftChild_, k);
    else
        return LocateNode(p->rightChild_, k - p->_lsize);
}
template <class ElemType>
void AVLTree<ElemType>::PreOrder(AVLTreeNode<ElemType> *&root)
{
    if (root != NULL)
    {
        cout << root->_data << " ";
        PreOrder(root->leftChild_);
        PreOrder(root->rightChild_);
    }
}
template <class ElemType>
void AVLTree<ElemType>::InOrder(AVLTreeNode<ElemType> *&root)
{
    if (root != NULL)
    {
        InOrder(root->leftChild_);
        cout << root->_data << " ";
        InOrder(root->rightChild_);
    }
}
#endif