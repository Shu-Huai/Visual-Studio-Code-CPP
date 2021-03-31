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
    ChildSiblingTreeNode<ElemType> *CopyTree(ChildSiblingTreeNode<ElemType> *r);
    ChildSiblingTreeNode<ElemType> *CreateTree(ElemType *datas, int *parents, int n, int rootindex);
    ChildSiblingTreeNode<ElemType> *GetParent(ChildSiblingTreeNode<ElemType> *r, ChildSiblingTreeNode<ElemType> *CSTN) const;
    int GetDegree(ChildSiblingTreeNode<ElemType> *r) const;
    int GetHeight(ChildSiblingTreeNode<ElemType> *r) const;
    int GetNodeDegree(ChildSiblingTreeNode<ElemType> *r) const;
    int GetNodeNumber(ChildSiblingTreeNode<ElemType> *r) const;
    void Destroy(ChildSiblingTreeNode<ElemType> *&r);

public:
    ChildSiblingTree();
    ChildSiblingTree(ElemType nodes[], int parents[], int n);
    ChildSiblingTree(const ChildSiblingTree<ElemType> &CST);
    virtual ~ChildSiblingTree();
    bool IsEmpty() const;
    ChildSiblingTree<ElemType> &operator=(const ChildSiblingTree<ElemType> &CST);
    ChildSiblingTreeNode<ElemType> *GetFirstChild(ChildSiblingTreeNode<ElemType> *CSTN) const;
    ChildSiblingTreeNode<ElemType> *GetNextSibling(ChildSiblingTreeNode<ElemType> *CSTN) const;
    ChildSiblingTreeNode<ElemType> *GetParent(ChildSiblingTreeNode<ElemType> *CSTN) const;
    ChildSiblingTreeNode<ElemType> *GetRoot() const;
    int GetDegree() const;
    int GetHeight() const;
    int GetNodeNumber() const;
    Status GetElem(ChildSiblingTreeNode<ElemType> *CSTN, ElemType &e) const;
    Status SetElem(ChildSiblingTreeNode<ElemType> *CSTN, const ElemType &e);
};
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::CopyTree(ChildSiblingTreeNode<ElemType> *CSTN)
{
    if (!CSTN)
    {
        return NULL;
    }
    ChildSiblingTreeNode<ElemType> *r = new ChildSiblingTreeNode<ElemType>(CSTN->data);
    ChildSiblingTreeNode<ElemType> *cur;
    ChildSiblingTreeNode<ElemType> *p = CSTN->firstchild_;
    while (p)
    {
        ChildSiblingTreeNode<ElemType> *subTreeRoot = CopyTree(p);
        if (!r->firstchild_)
        {
            r->firstchild_ = subTreeRoot;
        }
        else
        {
            cur->nextsibling_ = subTreeRoot;
        }
        cur = subTreeRoot;
        p = p->nextsibling_;
    }
    return r;
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::CreateTree(ElemType *datas, int *parents, int n, int rootindex)
{
    if (rootindex >= 0 and rootindex < n)
    {
        ChildSiblingTreeNode<ElemType> *root = new ChildSiblingTreeNode<ElemType>(datas[rootindex]);
        ChildSiblingTreeNode<ElemType> *subRoot, *cur;
        for (int i = 0; i < n; i++)
        {
            if (parents[i] == rootindex)
            {
                subRoot = CreateTree(datas, parents, n, i);
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
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetParent(ChildSiblingTreeNode<ElemType> *r, ChildSiblingTreeNode<ElemType> *CSTN) const
{
    if (!r)
    {
        return NULL;
    }
    ChildSiblingTreeNode<ElemType> *p = r->firstchild_;
    while (p)
    {
        if (p == CSTN)
        {
            return r;
        }
        p = p->nextsibling_;
    }
    p = r->firstchild_;
    while (p)
    {
        ChildSiblingTreeNode<ElemType> *q = GetParent(p, CSTN);
        if (q)
        {
            return q;
        }
        p = p->nextsibling_;
    }
    return NULL;
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
ChildSiblingTree<ElemType>::ChildSiblingTree() : root_(NULL)
{
}
template <class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(ElemType *datas, int *parents, int n)
{
    root_ = CreateTree(datas, parents, n, 0);
}
template<class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(const ChildSiblingTree<ElemType> &CST)
{
    root_ = CopyTree(CST.GetRoot());
}
template <class ElemType>
ChildSiblingTree<ElemType>::~ChildSiblingTree()
{
    Destroy(root_);
}
template <class ElemType>
bool ChildSiblingTree<ElemType>::IsEmpty() const
{
    return root_ == NULL;
}
template <class ElemType>
ChildSiblingTree<ElemType> &ChildSiblingTree<ElemType>::operator=(const ChildSiblingTree<ElemType> &CST)
{
    if (&CST != this)
    {
        Destroy(root_); 
        root_ = CopyTree(CST.GetRoot());
    }
    return *this;
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetFirstChild(ChildSiblingTreeNode<ElemType> *CSTN) const
{
    return CSTN ? CSTN->firstchild_ : NULL;
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetNextSibling(ChildSiblingTreeNode<ElemType> *CSTN) const
{
    return CSTN ? CSTN->nextsibling_ : NULL;
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetParent(ChildSiblingTreeNode<ElemType> *CSTN) const
{
    return GetParent(root_, CSTN);
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetRoot() const
{
    return root_;
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
template <class ElemType>
int ChildSiblingTree<ElemType>::GetNodeNumber() const
{
    return GetNodeNumber(root_);
}
template <class ElemType>
Status ChildSiblingTree<ElemType>::GetElem(ChildSiblingTreeNode<ElemType> *CSTN, ElemType &e) const
{
    if (!CSTN)
    {
        return UNDER_FLOW;
    }
    e = CSTN->data_;
    return SUCCESS;
}
template <class ElemType>
Status ChildSiblingTree<ElemType>::SetElem(ChildSiblingTreeNode<ElemType> *CSTN, const ElemType &e)
{
    if (!CSTN)
    {
        return UNDER_FLOW;
    }
    CSTN->data_ = e;
    return SUCCESS;
}
#endif