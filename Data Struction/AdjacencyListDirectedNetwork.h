#pragma once
#ifndef __ADJACENCY_LIST_DIRECTED_NETWORK_H__
#define __ADJACENCY_LIST_DIRECTED_NETWORK_H__
#include "AdjacencyListNetworkEdge.h"
#include "AdjacencyListNetworkVertex.h"
template <class ElemType, class WeightType>
class AdjacencyListDirectedNetwork
{
protected:
    int vertexNum_;
    int maxVertexNum_;
    int edgeNum_;
    AdjacencyListNetWorkVertex<ElemType, WeightType> *vertexs_;
    bool *tags_;
    WeightType infinity_;

public:
    AdjacencyListDirectedNetwork(int maxVertexNum = DEFAULT_SIZE, WeightType infinity = (WeightType)DEFAULT_INFINITY);
    AdjacencyListDirectedNetwork(ElemType *v, int vertexNum, int maxVertexNum = DEFAULT_SIZE, WeightType infinity = (WeightType)DEFAULT_INFINITY);
    AdjacencyListDirectedNetwork(const AdjacencyListDirectedNetwork<ElemType, WeightType> &ALDN);
    ~AdjacencyListDirectedNetwork();
    void Clear();
    bool IsEmpty();
    void Display();
    Status AppendVertex(const ElemType &e);
    Status InsertEdge(int v1, int v2, WeightType weigtht);
    Status DeleteVertex(ElemType &e);
    Status DeleteEdge(int v1, int v2);
    Status SetElem(int v, const ElemType &e);
    Status SetTag(int v, bool tag) const;
    Status SetWeight(int v1, int v2, WeightType w);
    int GetVertexNum() const;
    int GetEdgeNum() const;
    int GetIndex(ElemType &e) const;
    Status GetElem(int v, ElemType &e) const;
    bool GetTag(int v) const;
    int GetFirstAdjacencyVertex(int v) const;
    int GetNextAdjacencyVertex(int v1, int v2) const;
    WeightType GetInfinity() const;
    WeightType GetWeight(int v1, int v2) const;
    AdjacencyListDirectedNetwork<ElemType, WeightType> &operator=(const AdjacencyListDirectedNetwork<ElemType, WeightType> &ALDN);
};
template <class ElemType, class WeightType>
AdjacencyListDirectedNetwork<ElemType, WeightType>::AdjacencyListDirectedNetwork(int maxVertexNum, WeightType infinity)
    : vertexNum_(0), maxVertexNum_(maxVertexNum), edgeNum_(0), infinity_(infinity)
{
    vertexs_ = new AdjacencyListNetWorkVertex<ElemType, WeightType>[maxVertexNum_];
    tags_ = new bool[maxVertexNum_];
}
template <class ElemType, class WeightType>
AdjacencyListDirectedNetwork<ElemType, WeightType>::AdjacencyListDirectedNetwork(ElemType *v, int vertexNum, int maxVertexNum, WeightType infinity)
    : vertexNum_(vertexNum), maxVertexNum_(maxVertexNum), edgeNum_(0), infinity_(infinity)
{
    vertexs_ = new AdjacencyListNetWorkVertex<ElemType, WeightType>[maxVertexNum_];
    tags_ = new bool[maxVertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        vertexs_[i].data_ = v[i];
        vertexs_[i].firstEdge_ = NULL;
        tags_[i] = 0;
    }
}
template <class ElemType, class WeightType>
AdjacencyListDirectedNetwork<ElemType, WeightType>::AdjacencyListDirectedNetwork(const AdjacencyListDirectedNetwork<ElemType, WeightType> &ALDN)
    : vertexNum_(ALDN.vertexNum_), maxVertexNum_(ALDN.maxVertexNum_), edgeNum_(ALDN.edgeNum_), infinity_(ALDN.infinity_)
{
    vertexs_ = new AdjacencyListNetWorkVertex<ElemType, WeightType>[maxVertexNum_];
    tags_ = new int[maxVertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        vertexs_[i].data_ = ALDN.vertexs_[i].data_;
        vertexs_[i].firstEdge_ = NULL;
        AdjacencyListNetworkEdge<WeightType> *p = ALDN.vertexs_[i].firstEdge_;
        AdjacencyListNetworkEdge<WeightType> *q;
        while (p)
        {
            if (!vertexs_[i].firstEdge_)
            {
                vertexs_[i].firstEdge_ = new AdjacencyListNetworkEdge<WeightType>(p->vertex_, p->weight_);
                q = vertexs_[i].firstEdge_;
                p = p->nextEdge_;
            }
            else
            {
                q->nextEdge_ = new AdjacencyListNetworkEdge<WeightType>(p->vertex_, p->weight_);
                q = q->nextEdge_;
                p = p->nextEdge_;
            }
        }
        tags_[i] = ALDN.tags_[i];
    }
}
template <class ElemType, class WeightType>
AdjacencyListDirectedNetwork<ElemType, WeightType>::~AdjacencyListDirectedNetwork()
{
    Clear();
    delete[] vertexs_;
    delete[] tags_;
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::Clear()
{
    AdjacencyListNetworkEdge<WeightType> *p;
    for (int v = 0; v < vertexNum_; v++)
    {
        p = vertexs_[v].firstEdge_;
        while (p != NULL)
        {
            vertexs_[v].firstEdge_ = p->nextEdge_;
            delete p;
            p = vertexs_[v].firstEdge_;
        }
    }
    vertexNum_ = 0;
    edgeNum_ = 0;
}
template <class ElemType, class WeightType>
bool AdjacencyListDirectedNetwork<ElemType, WeightType>::IsEmpty()
{
    return vertexNum_ == 0;
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::Display()
{
    AdjacencyListNetworkEdge<WeightType> *p;
    cout << "有向网共有" << vertexNum_ << "个顶点，" << edgeNum_ << "条边。" << endl;
    for (int i = 0; i < vertexNum_; i++)
    {
        cout << i << ":\t" << vertexs_[i].data_;
        p = vertexs_[i].firstEdge_;
        while (p)
        {
            cout << "-->(" << p->vertex_ << "," << p->weight_ << ")";
            p = p->nextEdge_;
        }
        cout << endl;
    }
}
template <class ElemType, class WeightType>
Status AdjacencyListDirectedNetwork<ElemType, WeightType>::AppendVertex(const ElemType &e)
{
    if (vertexNum_ == maxVertexNum_)
    {
        return OVER_FLOW;
    }
    vertexs_[vertexNum_].data_ = e;
    vertexs_[vertexNum_].firstEdge_ = NULL;
    tags_[vertexNum_] = 0;
    vertexNum_++;
    return SUCCESS;
}
template <class ElemType, class WeightType>
Status AdjacencyListDirectedNetwork<ElemType, WeightType>::InsertEdge(int v1, int v2, WeightType weight)
{
    if (v1 < 0 || v1 >= vertexNum_ || v2 < 0 || v2 >= vertexNum_ || v1 == v2)
    {
        return RANGE_ERROR;
    }
    AdjacencyListNetworkEdge<WeightType> *p, *q;
    p = vertexs_[v1].firstEdge_;
    vertexs_[v1].firstEdge_ = new AdjacencyListNetworkEdge<WeightType>(v2, weight, p);
    edgeNum_++;
    return SUCCESS;
}
template <class ElemType, class WeightType>
Status AdjacencyListDirectedNetwork<ElemType, WeightType>::DeleteVertex(ElemType &e)
{
    int v = GetIndex(e);
    if (v == -1)
    {
        return UNDER_FLOW;
    }
    for (int i = 0; i < vertexNum_; i++)
    {
        if (i != v)
        {
            DeleteEdge(i, v);
        }
    }
    AdjacencyListNetworkEdge<WeightType> *p = vertexs_[v].firstEdge_, *q;
    while (p)
    {
        vertexs_[v].firstEdge_ = p->nextEdge_;
        delete p;
        p = vertexs_[v].firstEdge_;
        edgeNum_--;
    }
    vertexs_[v].data_ = vertexs_[vertexNum_].data_;
    vertexs_[v].firstEdge_ = vertexs_[vertexNum_].firstEdge_;
    vertexs_[vertexNum_].firstEdge_ = NULL;
    tags_[v] = tags_[vertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        if (i != v)
        {
            p = vertexs_[i].firstEdge_;
            while (p != NULL)
            {
                if (p->vertex_ == vertexNum_)
                {
                    p->vertex_ = v;
                }
                p = p->nextEdge_;
            }
        }
    }
    vertexNum_--;
    return SUCCESS;
}
template <class ElemType, class WeightType>
Status AdjacencyListDirectedNetwork<ElemType, WeightType>::DeleteEdge(int v1, int v2)
{
    if (v1 < 0 || v1 >= vertexNum_ || v2 < 0 || v2 >= vertexNum_ || v1 == v2)
    {
        return RANGE_ERROR;
    }
    AdjacencyListNetworkEdge<WeightType> *p = vertexs_[v1].firstEdge_;
    AdjacencyListNetworkEdge<WeightType> *q;
    while (p && p->vertex_ != v2)
    {
        q = p;
        p = p->nextEdge_;
    }
    if (p)
    {
        if (vertexs_[v1].firstEdge_ == p)
        {
            vertexs_[v1].firstEdge_ = p->nextEdge_;
        }
        else
        {
            q->nextEdge_ = p->nextEdge_;
        }
        delete p;
        edgeNum_--;
    }
    return SUCCESS;
}
template <class ElemType, class WeightType>
Status AdjacencyListDirectedNetwork<ElemType, WeightType>::SetElem(int v, const ElemType &e)
{
    if (v < 0 || v >= vertexNum_)
    {
        return RANGE_ERROR;
    }
    vertexs_[v].data_ = e;
    return SUCCESS;
}
template <class ElemType, class WeightType>
Status AdjacencyListDirectedNetwork<ElemType, WeightType>::SetTag(int v, bool val) const
{
    if (v < 0 || v >= vertexNum_)
    {
        return RANGE_ERROR;
    }
    tags_[v] = val;
    return SUCCESS;
}
template <class ElemType, class WeightType>
Status AdjacencyListDirectedNetwork<ElemType, WeightType>::SetWeight(int v1, int v2, WeightType weight)
{
    if (v1 < 0 || v1 >= vertexNum_ || v2 < 0 || v2 >= vertexNum_ || v1 == v2)
    {
        return RANGE_ERROR;
    }
    AdjacencyListNetworkEdge<WeightType> *p = vertexs_[v1].firstEdge_;
    while (p && p->vertex_ != v2)
    {
        p = p->nextEdge_;
    }
    if (p)
    {
        p->weight_ = weight;
    }
    return SUCCESS;
}
template <class ElemType, class WeightType>
int AdjacencyListDirectedNetwork<ElemType, WeightType>::GetVertexNum() const
{
    return vertexNum_;
}
template <class ElemType, class WeightType>
int AdjacencyListDirectedNetwork<ElemType, WeightType>::GetEdgeNum() const
{
    return edgeNum_;
}
template <class ElemType, class WeightType>
int AdjacencyListDirectedNetwork<ElemType, WeightType>::GetIndex(ElemType &e) const
{
    for (int i = 0; i < vertexNum_; i++)
    {
        if (vertexs_[i].data_ == e)
        {
            return i;
        }
    }
    return -1;
}
template <class ElemType, class WeightType>
Status AdjacencyListDirectedNetwork<ElemType, WeightType>::GetElem(int v, ElemType &e) const
{
    if (v < 0 || v >= vertexNum_)
    {
        return RANGE_ERROR;
    }
    e = vertexs_[v].data_;
    return SUCCESS;
}
template <class ElemType, class WeightType>
bool AdjacencyListDirectedNetwork<ElemType, WeightType>::GetTag(int v) const
{
    return tags_[v];
}
template <class ElemType, class WeightType>
int AdjacencyListDirectedNetwork<ElemType, WeightType>::GetFirstAdjacencyVertex(int v) const
{
    if (!vertexs_[v].firstEdge_)
    {
        return -1;
    }
    return vertexs_[v].firstEdge_->vertex_;
}
template <class ElemType, class WeightType>
int AdjacencyListDirectedNetwork<ElemType, WeightType>::GetNextAdjacencyVertex(int v1, int v2) const
{
    AdjacencyListNetworkEdge<WeightType> *p = vertexs_[v1].firstEdge_;
    while (p && p->vertex_ != v2)
    {
        p = p->nextEdge_;
    }
    if (!p || !p->nextEdge_)
    {
        return -1;
    }
    return p->nextEdge_->vertex_;
}
template <class ElemType, class WeightType>
WeightType AdjacencyListDirectedNetwork<ElemType, WeightType>::GetInfinity() const
{
    return infinity_;
}
template <class ElemType, class WeightType>
WeightType AdjacencyListDirectedNetwork<ElemType, WeightType>::GetWeight(int v1, int v2) const
{
    AdjacencyListNetworkEdge<WeightType> *p = vertexs_[v1].firstEdge_;
    while (p && p->vertex_ != v2)
    {
        p = p->nextEdge_;
    }
    if (p)
    {
        return p->weight_;
    }
    return infinity_;
}
template <class ElemType, class WeightType>
AdjacencyListDirectedNetwork<ElemType, WeightType> &AdjacencyListDirectedNetwork<ElemType, WeightType>::operator=(const AdjacencyListDirectedNetwork<ElemType, WeightType> &ALDN)
{
    if (&ALDN != this)
    {
        Clear();
        delete[] vertexs_;
        delete[] tags_;
        vertexNum_ = ALDN.vertexNum_;
        maxVertexNum_ = ALDN.maxVertexNum_;
        edgeNum_ = ALDN.edgeNum_;
        infinity_ = ALDN.infinity_;
        vertexs_ = new AdjacencyListNetWorkVertex<ElemType, WeightType>[maxVertexNum_];
        tags_ = new bool[maxVertexNum_];
        for (int i = 0; i < vertexNum_; i++)
        {
            vertexs_[i].data = ALDN.vertexs_[i].data;
            vertexs_[i].firstEdge_ = NULL;
            AdjacencyListNetworkEdge<WeightType> *p = ALDN.vertexs_[i].firstEdge_;
            AdjacencyListNetworkEdge<WeightType> *q;
            while (p)
            {
                if (!vertexs_[i].firstEdge_)
                {
                    vertexs_[i].firstEdge_ = new AdjacencyListNetworkEdge<WeightType>(p->vertex_, p->weight_);
                    q = vertexs_[i].firstEdge_;
                    p = p->nextEdge_;
                }
                else
                {
                    q->nextEdge_ = new AdjacencyListNetworkEdge<WeightType>(p->vertex_, p->weight_);
                    q = q->nextEdge_;
                    p = p->nextEdge_;
                }
            }
            tags_[i] = ALDN.tags_[i];
        }
    }
    return *this;
}
#endif