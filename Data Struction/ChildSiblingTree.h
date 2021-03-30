#pragma once
#ifndef __CHILD_SIBLING_TREE_H__
#define __CHILD_SIBLING_TREE_H__
#include "ChildSiblingTreeNode.h"
#include "LinkQueue.h"
template <class ElemType>
class ChildSiblingTree
{
protected:
    ChildSiblingTreeNode<ElemType> *root_;
    ChildSiblingTreeNode<ElemType> *CreateTree(ElemType *v, int *parents, int n, int rootindex);
    void Destroy(ChildSiblingTreeNode<ElemType> *&r);
    int GetHeight(ChildSiblingTreeNode<ElemType> *r) const;
    int GetNodeDegree(ChildSiblingTreeNode<ElemType> *r) const;
    int GetDegree(ChildSiblingTreeNode<ElemType> *r) const;
    ChildSiblingTreeNode<ElemType> *GetFirstChild(ChildSiblingTreeNode<ElemType> *r) const;
    ChildSiblingTreeNode<ElemType> *GetNextSibling(ChildSiblingTreeNode<ElemType> *r) const;

public:
    ChildSiblingTree();
    ChildSiblingTree(ElemType nodes[], int parents[], int n);
    virtual ~ChildSiblingTree();
    ChildSiblingTreeNode<ElemType> *GetRoot() const;
    bool IsEmpty() const;
    int GetHeight() const;
    int GetDegree() const;
};
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::CreateTree(ElemType *v, int *parents, int n, int rootindex)
{
    if (rootindex >= 0 and rootindex < n)
    {
        ChildSiblingTreeNode<ElemType> *root = new ChildSiblingTreeNode<ElemType>(v[rootindex]);
        ChildSiblingTreeNode<ElemType> *subRoot, *cur;
        for (int i = 0; i < n; i++)
        {
            if (parents[i] == rootindex)
            {
                subRoot = CreateTree(v, parents, n, i);
                if (!root->firstchild_)
                {
                    root->firstchild_ = subRoot;
                }
                else
                {
                    cur->nextsibling_ = subRoot;
                }
                cur = subRoot;
            }
        }
        return root;
    }
    return NULL;
}
template <class ElemType>
void ChildSiblingTree<ElemType>::Destroy(ChildSiblingTreeNode<ElemType> *&r)
{
    if (r)
    {
        Destroy(r->firstchild_);
        Destroy(r->nextsibling_);
        delete r;
        r = NULL;
    }
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetHeight(ChildSiblingTreeNode<ElemType> *r) const
{
    if (!r)
    {
        return 0;
    }
    ChildSiblingTreeNode<ElemType> *p = GetFirstChild(r);
    int subMaxHeight = 0;
    while (p)
    {
        int subHeight = GetHeight(p);
        subMaxHeight = subMaxHeight > subHeight ? subMaxHeight : subHeight;
        p = GetNextSibling(p);
    }
    return subMaxHeight + 1;
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetNodeDegree(ChildSiblingTreeNode<ElemType> *r) const
{
    ChildSiblingTreeNode<ElemType> *p = GetFirstChild(r);
    int count = 0;
    while (p)
    {
        count++;
        p = GetNextSibling(p);
    }
    return count;
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetDegree(ChildSiblingTreeNode<ElemType> *r) const
{
    ChildSiblingTreeNode<ElemType> *p = GetFirstChild(r);
    int maxDegree = GetNodeDegree(r);
    while (p)
    {
        int subMaxDegree = GetDegree(p);
        maxDegree = maxDegree > subMaxDegree ? maxDegree : subMaxDegree;
        p = GetNextSibling(p);
    }
    return maxDegree;
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetFirstChild(ChildSiblingTreeNode<ElemType> *r) const
{
    return r ? r->firstchild_ : NULL;
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetNextSibling(ChildSiblingTreeNode<ElemType> *r) const
{
    return r ? r->nextsibling_ : NULL;
}
template <class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree() : root_(NULL)
{
}
template <class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(ElemType *v, int *parents, int n)
{
    root_ = CreateTree(v, parents, n, 0);
}
template <class ElemType>
ChildSiblingTree<ElemType>::~ChildSiblingTree()
{
    Destroy(root_);
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetRoot() const
{
    return root_;
}
template <class ElemType>
bool ChildSiblingTree<ElemType>::IsEmpty() const
{
    return root_ == NULL;
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetHeight() const
{
    return GetHeight(root_);
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetDegree() const
{
    return GetDegree(root_);
}
#endif