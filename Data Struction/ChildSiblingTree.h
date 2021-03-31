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
    int GetDegree(ChildSiblingTreeNode<ElemType> *r) const;
    int GetHeight(ChildSiblingTreeNode<ElemType> *r) const;
    ChildSiblingTreeNode<ElemType> *GetFirstChild(ChildSiblingTreeNode<ElemType> *r) const;
    ChildSiblingTreeNode<ElemType> *GetNextSibling(ChildSiblingTreeNode<ElemType> *r) const;
    int GetNodeDegree(ChildSiblingTreeNode<ElemType> *r) const;
    int GetNodeNumber(ChildSiblingTreeNode<ElemType> *r) const;

public:
    ChildSiblingTree();
    ChildSiblingTree(ElemType nodes[], int parents[], int n);
    virtual ~ChildSiblingTree();
    ChildSiblingTreeNode<ElemType> *GetRoot() const;
    bool IsEmpty() const;
    int GetDegree() const;
    int GetHeight() const;
    int GetNodeNumber() const;
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
int ChildSiblingTree<ElemType>::GetDegree(ChildSiblingTreeNode<ElemType> *r) const
{
    if (!r)
    {
        return 0;
    }
    ChildSiblingTreeNode<ElemType> *p = r->firstchild_;
    int maxdegree = GetNodeDegree(r);
    while (p)
    {
        int degree = GetDegree(p);
        maxdegree = maxdegree > degree ? maxdegree : degree;
        p = p->nextsibling_;
    }
    return maxdegree;
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetHeight(ChildSiblingTreeNode<ElemType> *r) const
{
    if (!r)
    {
        return 0;
    }
    ChildSiblingTreeNode<ElemType> *p = r->firstchild_;
    int maxheight = 0;
    while (p)
    {
        int height = GetHeight(p);
        maxheight = maxheight > height ? maxheight : height;
        p = p->nextsibling_;
    }
    return maxheight + 1;
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
int ChildSiblingTree<ElemType>::GetNodeDegree(ChildSiblingTreeNode<ElemType> *r) const
{
    if (!r)
    {
        return 0;
    }
    ChildSiblingTreeNode<ElemType> *p = r->firstchild_;
    int count = 0;
    while (p)
    {
        count++;
        p = p->nextsibling_;
    }
    return count;
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetNodeNumber(ChildSiblingTreeNode<ElemType> *r) const
{
    if (!r)
    {
        return 0;
    }
    return GetNodeNumber(r->firstchild_) + GetNodeNumber(r->nextsibling_) + 1;
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
int ChildSiblingTree<ElemType>::GetDegree() const
{
    return GetDegree(root_);
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetHeight() const
{
    return GetHeight(root_);
}
template<class ElemType>
int ChildSiblingTree<ElemType>::GetNodeNumber() const
{
    return GetNodeNumber(root_);
}
#endif