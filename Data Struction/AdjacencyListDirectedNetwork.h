#ifndef __ADJACENCY_LIST_DIRECTED_NETWORK_H__
#define __ADJACENCY_LIST_DIRECTED_NETWORK_H__
#include "AdjacencyListNetworkSide.h"
#include "AdjacencyListNetworkVertex.h"
template <class ElemType, class WeightType>
class AdjacencyListDirectedNetwork
{
protected:
    int vertexNum_;
    int maxVertexNum_;
    int sideNum_;
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
    Status InsertSide(int v1, int v2, WeightType weigtht);
    Status DeleteVertex(ElemType &e);
    Status DeleteSide(int v1, int v2);
    Status SetElem(int v, const ElemType &e);
    Status SetTag(int v, bool tag) const;
    Status SetWeight(int v1, int v2, WeightType w);
    int GetVertexNum() const;
    int GetSideNum() const;
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
    : vertexNum_(0), maxVertexNum_(maxVertexNum), sideNum_(0), infinity_(infinity)
{
    vertexs_ = new AdjacencyListNetWorkVertex<ElemType, WeightType>[maxVertexNum_];
    tags_ = new bool[maxVertexNum_];
}
template <class ElemType, class WeightType>
AdjacencyListDirectedNetwork<ElemType, WeightType>::AdjacencyListDirectedNetwork(ElemType *v, int vertexNum, int maxVertexNum, WeightType infinity)
    : vertexNum_(vertexNum), maxVertexNum_(maxVertexNum), sideNum_(0), infinity_(infinity)
{
    vertexs_ = new AdjacencyListNetWorkVertex<ElemType, WeightType>[maxVertexNum_];
    tags_ = new bool[maxVertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        vertexs_[i].data_ = v[i];
        vertexs_[i].firstSide_ = NULL;
        tags_[i] = 0;
    }
}
template <class ElemType, class WeightType>
AdjacencyListDirectedNetwork<ElemType, WeightType>::AdjacencyListDirectedNetwork(const AdjacencyListDirectedNetwork<ElemType, WeightType> &ALDN)
    : vertexNum_(ALDN.vertexNum_), maxVertexNum_(ALDN.maxVertexNum_), sideNum_(ALDN.sideNum_), infinity_(ALDN.infinity_)
{
    vertexs_ = new AdjacencyListNetWorkVertex<ElemType, WeightType>[maxVertexNum_];
    tags_ = new int[maxVertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        vertexs_[i].data_ = ALDN.vertexs_[i].data_;
        vertexs_[i].firstSide_ = NULL;
        AdjacencyListNetworkSide<WeightType> *p = ALDN.vertexs_[i].firstSide_;
        AdjacencyListNetworkSide<WeightType> *q;
        while (p)
        {
            if (!vertexs_[i].firstSide_)
            {
                vertexs_[i].firstSide_ = new AdjacencyListNetworkSide<WeightType>(p->vertex_, p->weight_);
                q = vertexs_[i].firstSide_;
                p = p->nextSide_;
            }
            else
            {
                q->nextSide_ = new AdjacencyListNetworkSide<WeightType>(p->vertex_, p->weight_);
                q = q->nextSide_;
                p = p->nextSide_;
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
    AdjacencyListNetworkSide<WeightType> *p;
    for (int v = 0; v < vertexNum_; v++)
    {
        p = vertexs_[v].firstSide_;
        while (p != NULL)
        {
            vertexs_[v].firstSide_ = p->nextSide_;
            delete p;
            p = vertexs_[v].firstSide_;
        }
    }
    vertexNum_ = 0;
    sideNum_ = 0;
}
template <class ElemType, class WeightType>
bool AdjacencyListDirectedNetwork<ElemType, WeightType>::IsEmpty()
{
    return vertexNum_ == 0;
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::Display()
{
    AdjacencyListNetworkSide<WeightType> *p;
    cout << "有向网共有" << vertexNum_ << "个顶点，" << sideNum_ << "条边。" << endl;
    for (int i = 0; i < vertexNum_; i++)
    {
        cout << i << ":\t" << vertexs_[i].data_;
        p = vertexs_[i].firstSide_;
        while (p)
        {
            cout << "-->(" << p->vertex_ << "," << p->weight_ << ")";
            p = p->nextSide_;
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
    vertexs_[vertexNum_].firstSide_ = NULL;
    tags_[vertexNum_] = 0;
    vertexNum_++;
    return SUCCESS;
}
template <class ElemType, class WeightType>
Status AdjacencyListDirectedNetwork<ElemType, WeightType>::InsertSide(int v1, int v2, WeightType weight)
{
    if (v1 < 0 || v1 >= vertexNum_ || v2 < 0 || v2 >= vertexNum_ || v1 == v2)
    {
        return RANGE_ERROR;
    }
    AdjacencyListNetworkSide<WeightType> *p, *q;
    p = vertexs_[v1].firstSide_;
    vertexs_[v1].firstSide_ = new AdjacencyListNetworkSide<WeightType>(v2, weight, p);
    sideNum_++;
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
            DeleteSide(i, v);
        }
    }
    AdjacencyListNetworkSide<WeightType> *p = vertexs_[v].firstSide_, *q;
    while (p)
    {
        vertexs_[v].firstSide_ = p->nextSide_;
        delete p;
        p = vertexs_[v].firstSide_;
        sideNum_--;
    }
    vertexs_[v].data_ = vertexs_[vertexNum_].data_;
    vertexs_[v].firstSide_ = vertexs_[vertexNum_].firstSide_;
    vertexs_[vertexNum_].firstSide_ = NULL;
    tags_[v] = tags_[vertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        if (i != v)
        {
            p = vertexs_[i].firstSide_;
            while (p != NULL)
            {
                if (p->vertex_ == vertexNum_)
                {
                    p->vertex_ = v;
                }
                p = p->nextSide_;
            }
        }
    }
    vertexNum_--;
    return SUCCESS;
}
template <class ElemType, class WeightType>
Status AdjacencyListDirectedNetwork<ElemType, WeightType>::DeleteSide(int v1, int v2)
{
    if (v1 < 0 || v1 >= vertexNum_ || v2 < 0 || v2 >= vertexNum_ || v1 == v2)
    {
        return RANGE_ERROR;
    }
    AdjacencyListNetworkSide<WeightType> *p = vertexs_[v1].firstSide_;
    AdjacencyListNetworkSide<WeightType> *q;
    while (p && p->vertex_ != v2)
    {
        q = p;
        p = p->nextSide_;
    }
    if (p)
    {
        if (vertexs_[v1].firstSide_ == p)
        {
            vertexs_[v1].firstSide_ = p->nextSide_;
        }
        else
        {
            q->nextSide_ = p->nextSide_;
        }
        delete p;
        sideNum_--;
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
    AdjacencyListNetworkSide<WeightType> *p = vertexs_[v1].firstSide_;
    while (p && p->vertex_ != v2)
    {
        p = p->nextSide_;
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
int AdjacencyListDirectedNetwork<ElemType, WeightType>::GetSideNum() const
{
    return sideNum_;
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
    if (!vertexs_[v].firstSide_)
    {
        return -1;
    }
    return vertexs_[v].firstSide_->vertex_;
}
template <class ElemType, class WeightType>
int AdjacencyListDirectedNetwork<ElemType, WeightType>::GetNextAdjacencyVertex(int v1, int v2) const
{
    AdjacencyListNetworkSide<WeightType> *p = vertexs_[v1].firstSide_;
    while (p && p->vertex_ != v2)
    {
        p = p->nextSide_;
    }
    if (!p || !p->nextSide_)
    {
        return -1;
    }
    return p->nextSide_->vertex_;
}
template <class ElemType, class WeightType>
WeightType AdjacencyListDirectedNetwork<ElemType, WeightType>::GetInfinity() const
{
    return infinity_;
}
template <class ElemType, class WeightType>
WeightType AdjacencyListDirectedNetwork<ElemType, WeightType>::GetWeight(int v1, int v2) const
{
    AdjacencyListNetworkSide<WeightType> *p = vertexs_[v1].firstSide_;
    while (p && p->vertex_ != v2)
    {
        p = p->nextSide_;
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
        sideNum_ = ALDN.sideNum_;
        infinity_ = ALDN.infinity_;
        vertexs_ = new AdjacencyListNetWorkVertex<ElemType, WeightType>[maxVertexNum_];
        tags_ = new bool[maxVertexNum_];
        for (int i = 0; i < vertexNum_; i++)
        {
            vertexs_[i].data = ALDN.vertexs_[i].data;
            vertexs_[i].firstSide_ = NULL;
            AdjacencyListNetworkSide<WeightType> *p = ALDN.vertexs_[i].firstSide_;
            AdjacencyListNetworkSide<WeightType> *q;
            while (p)
            {
                if (!vertexs_[i].firstSide_)
                {
                    vertexs_[i].firstSide_ = new AdjacencyListNetworkSide<WeightType>(p->vertex_, p->weight_);
                    q = vertexs_[i].firstSide_;
                    p = p->nextSide_;
                }
                else
                {
                    q->nextSide_ = new AdjacencyListNetworkSide<WeightType>(p->vertex_, p->weight_);
                    q = q->nextSide_;
                    p = p->nextSide_;
                }
            }
            tags_[i] = ALDN.tags_[i];
        }
    }
    return *this;
}
#endif