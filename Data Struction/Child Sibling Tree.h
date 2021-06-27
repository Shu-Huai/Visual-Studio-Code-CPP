#pragma once
#ifndef __CHILD_SIBLING_TREE_H__
#define __CHILD_SIBLING_TREE_H__
#include "Child Sibling Tree Node.h"
#include "Link Queue.h"
template <class ElemType>
class ChildSiblingTree
{
protected:
    ChildSiblingTreeNode<ElemType> *root_;
    ChildSiblingTreeNode<ElemType> *Copy(ChildSiblingTreeNode<ElemType> *r);
    ChildSiblingTreeNode<ElemType> *Create(ElemType *datas, int *parents, int n, int rootIndex);
    void Clear(ChildSiblingTreeNode<ElemType> *&r);
    void PreOrderTraverse(ChildSiblingTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;
    void PostOrderTraverse(ChildSiblingTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;
    ChildSiblingTreeNode<ElemType> *GetParent(ChildSiblingTreeNode<ElemType> *r, ChildSiblingTreeNode<ElemType> *CSTN) const;
    int GetDegree(ChildSiblingTreeNode<ElemType> *r) const;
    int GetHeight(ChildSiblingTreeNode<ElemType> *r) const;
    int GetNodeDegree(ChildSiblingTreeNode<ElemType> *r) const;
    int GetNodeNumber(ChildSiblingTreeNode<ElemType> *r) const;

public:
    ChildSiblingTree();
    ChildSiblingTree(const ElemType &e);
    ChildSiblingTree(ChildSiblingTreeNode<ElemType> *r);
    ChildSiblingTree(ElemType *datas, int *parents, int n);
    ChildSiblingTree(const ChildSiblingTree<ElemType> &CST);
    virtual ~ChildSiblingTree();
    bool IsEmpty() const;
    void PreOrderTraverse(void (*Visit)(const ElemType &)) const;
    void PostOrderTraverse(void (*Visit)(const ElemType &)) const;
    ChildSiblingTreeNode<ElemType> *GetFirstChild(ChildSiblingTreeNode<ElemType> *CSTN) const;
    ChildSiblingTreeNode<ElemType> *GetNextSibling(ChildSiblingTreeNode<ElemType> *CSTN) const;
    ChildSiblingTreeNode<ElemType> *GetParent(ChildSiblingTreeNode<ElemType> *CSTN) const;
    ChildSiblingTreeNode<ElemType> *GetRoot() const;
    int GetDegree() const;
    int GetHeight() const;
    int GetNodeNumber() const;
    Status InsertChild(ChildSiblingTreeNode<ElemType> *CSTN, int position, const ElemType &e);
    Status DeleteChild(ChildSiblingTreeNode<ElemType> *CSTN, int position, ElemType &e);
    Status SetElem(ChildSiblingTreeNode<ElemType> *CSTN, const ElemType &e);
    Status GetElem(ChildSiblingTreeNode<ElemType> *CSTN, ElemType &e) const;
    ChildSiblingTree<ElemType> &operator=(const ChildSiblingTree<ElemType> &CST);
};
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::Copy(ChildSiblingTreeNode<ElemType> *CSTN)
{
    if (!CSTN)
    {
        return NULL;
    }
    ChildSiblingTreeNode<ElemType> *r = new ChildSiblingTreeNode<ElemType>(CSTN->elem_);
    ChildSiblingTreeNode<ElemType> *p = CSTN->firstChild_;
    ChildSiblingTreeNode<ElemType> *q = NULL;
    while (p)
    {
        ChildSiblingTreeNode<ElemType> *subTreeRoot = Copy(p);
        if (!r->firstChild_)
        {
            r->firstChild_ = subTreeRoot;
        }
        else
        {
            q->nextSibling_ = subTreeRoot;
        }
        q = subTreeRoot;
        p = p->nextSibling_;
    }
    return r;
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::Create(ElemType *datas, int *parents, int n, int rootIndex)
{
    if (rootIndex >= 0 && rootIndex < n)
    {
        ChildSiblingTreeNode<ElemType> *r = new ChildSiblingTreeNode<ElemType>(datas[rootIndex]);
        ChildSiblingTreeNode<ElemType> *subRoot;
        ChildSiblingTreeNode<ElemType> *p = NULL;
        for (int i = 0; i < n; i++)
        {
            if (parents[i] == rootIndex)
            {
                subRoot = Create(datas, parents, n, i);
                if (!r->firstChild_)
                {
                    r->firstChild_ = subRoot;
                }
                else
                {
                    p->nextSibling_ = subRoot;
                }
                p = subRoot;
            }
        }
        return r;
    }
    return NULL;
}
template <class ElemType>
void ChildSiblingTree<ElemType>::Clear(ChildSiblingTreeNode<ElemType> *&r)
{
    if (r)
    {
        Clear(r->firstChild_);
        Clear(r->nextSibling_);
        delete r;
        r = NULL;
    }
}
template <class ElemType>
void ChildSiblingTree<ElemType>::PreOrderTraverse(ChildSiblingTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
{
    if (r)
    {
        (*Visit)(r->elem_);
        ChildSiblingTreeNode<ElemType> *p = r->firstChild_;
        while (p)
        {
            PreOrderTraverse(p, Visit);
            p = p->nextSibling_;
        }
    }
}
template <class ElemType>
void ChildSiblingTree<ElemType>::PostOrderTraverse(ChildSiblingTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const
{
    if (r)
    {
        ChildSiblingTreeNode<ElemType> *p = r->firstChild_;
        while (p)
        {
            PostOrderTraverse(p, Visit);
            p = p->nextSibling_;
        }
        (*Visit)(r->data);
    }
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetParent(ChildSiblingTreeNode<ElemType> *r, ChildSiblingTreeNode<ElemType> *CSTN) const
{
    if (!r)
    {
        return NULL;
    }
    ChildSiblingTreeNode<ElemType> *p = r->firstChild_;
    while (p)
    {
        if (p == CSTN)
        {
            return r;
        }
        p = p->nextSibling_;
    }
    p = r->firstChild_;
    while (p)
    {
        ChildSiblingTreeNode<ElemType> *q = GetParent(p, CSTN);
        if (q)
        {
            return q;
        }
        p = p->nextSibling_;
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
    ChildSiblingTreeNode<ElemType> *p = r->firstChild_;
    int maxDegree = GetNodeDegree(r);
    while (p)
    {
        int degree = GetDegree(p);
        maxDegree = maxDegree > degree ? maxDegree : degree;
        p = p->nextSibling_;
    }
    return maxDegree;
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetHeight(ChildSiblingTreeNode<ElemType> *r) const
{
    if (!r)
    {
        return 0;
    }
    ChildSiblingTreeNode<ElemType> *p = r->firstChild_;
    int maxHeight = 0;
    while (p)
    {
        int height = GetHeight(p);
        maxHeight = maxHeight > height ? maxHeight : height;
        p = p->nextSibling_;
    }
    return maxHeight + 1;
}
template <class ElemType>
int ChildSiblingTree<ElemType>::GetNodeDegree(ChildSiblingTreeNode<ElemType> *r) const
{
    if (!r)
    {
        return 0;
    }
    ChildSiblingTreeNode<ElemType> *p = r->firstChild_;
    int count = 0;
    while (p)
    {
        count++;
        p = p->nextSibling_;
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
    return GetNodeNumber(r->firstChild_) + GetNodeNumber(r->nextSibling_) + 1;
}
template <class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree() : root_(NULL)
{
}
template <class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(const ElemType &e)
{
    root_ = new ChildSiblingTreeNode<ElemType>(e);
}
template <class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(ChildSiblingTreeNode<ElemType> *r) : root_(r)
{
}
template <class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(ElemType *datas, int *parents, int n)
{
    root_ = Create(datas, parents, n, 0);
}
template <class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(const ChildSiblingTree<ElemType> &CST)
{
    root_ = Copy(CST.GetRoot());
}
template <class ElemType>
ChildSiblingTree<ElemType>::~ChildSiblingTree()
{
    Clear(root_);
}
template <class ElemType>
bool ChildSiblingTree<ElemType>::IsEmpty() const
{
    return root_ == NULL;
}
template <class ElemType>
void ChildSiblingTree<ElemType>::PreOrderTraverse(void (*Visit)(const ElemType &)) const
{
    PreRootOrder(root_, Visit);
}
template <class ElemType>
void ChildSiblingTree<ElemType>::PostOrderTraverse(void (*Visit)(const ElemType &)) const
{
    PostOrderTraverse(root_, Visit);
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetFirstChild(ChildSiblingTreeNode<ElemType> *CSTN) const
{
    return CSTN ? CSTN->firstChild_ : NULL;
}
template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetNextSibling(ChildSiblingTreeNode<ElemType> *CSTN) const
{
    return CSTN ? CSTN->nextSibling_ : NULL;
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
Status ChildSiblingTree<ElemType>::InsertChild(ChildSiblingTreeNode<ElemType> *CSTN, int position, const ElemType &e)
{
    if (!CSTN)
    {
        return UNDER_FLOW;
    }
    if (position < 1 || position > GetNodeDegree(CSTN) + 1)
    {
        return RANGE_ERROR;
    }
    ChildSiblingTreeNode<ElemType> *q = new ChildSiblingTreeNode<ElemType>(e);
    if (position == 1)
    {
        q->nextSibling_ = CSTN->firstChild_;
        CSTN->firstChild_ = q;
    }
    else
    {
        ChildSiblingTreeNode<ElemType> *p = CSTN->firstChild_;
        for (int i = 1; i < position - 1; i++)
        {
            p = p->nextSibling_;
        }
        q->nextSibling_ = p->nextSibling_;
        p->nextSibling_ = q;
    }
    return SUCCESS;
}
template <class ElemType>
Status ChildSiblingTree<ElemType>::DeleteChild(ChildSiblingTreeNode<ElemType> *CSTN, int position, ElemType &e)
{
    if (!CSTN)
    {
        return UNDER_FLOW;
    }
    ChildSiblingTreeNode<ElemType> *p, *q;
    if (position < 0 || position > GetNodeDegree(CSTN))
    {
        return UNDER_FLOW;
    }
    if (position == 1)
    {
        q = CSTN->firstChild_;
        CSTN->firstChild_ = q->nextSibling_;
    }
    else
    {
        p = CSTN->firstChild_;
        for (int i = 1; i < i - 1; i++)
        {
            p = p->nextSibling_;
        }
        q = p->nextSibling_;
        p->nextSibling_ = q->nextSibling_;
    }
    e = q->elem_;
    Clear(q);
    return SUCCESS;
}
template <class ElemType>
Status ChildSiblingTree<ElemType>::SetElem(ChildSiblingTreeNode<ElemType> *CSTN, const ElemType &e)
{
    if (!CSTN)
    {
        return UNDER_FLOW;
    }
    CSTN->elem_ = e;
    return SUCCESS;
}
template <class ElemType>
Status ChildSiblingTree<ElemType>::GetElem(ChildSiblingTreeNode<ElemType> *CSTN, ElemType &e) const
{
    if (!CSTN)
    {
        return UNDER_FLOW;
    }
    e = CSTN->elem_;
    return SUCCESS;
}
template <class ElemType>
ChildSiblingTree<ElemType> &ChildSiblingTree<ElemType>::operator=(const ChildSiblingTree<ElemType> &CST)
{
    if (&CST != this)
    {
        Clear(root_);
        root_ = Copy(CST.GetRoot());
    }
    return *this;
}
#endif