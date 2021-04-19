#pragma once
#ifndef __KRUSKAL_EDGE_H__
#define __KRUSKAL_EDGE_H__
#include "AdjacencyMatrixUndirectedGraph.h"
template <class ElemType, class WeightType>
class KruskalEdge
{
protected:
    ElemType vertexA_;
    ElemType vertexB_;
    WeightType weight_;

public:
    KruskalEdge();
    KruskalEdge(ElemType v1, ElemType v2, WeightType weight);
    ElemType GetVertexA() const;
    ElemType GetVertexB() const;
    WeightType GetWeight() const;
    KruskalEdge<ElemType, WeightType> &operator=(const KruskalEdge<ElemType, WeightType> &KE);
    bool operator<=(const KruskalEdge<ElemType, WeightType> &KE);
    bool operator>(const KruskalEdge<ElemType, WeightType> &KE);
};
template <class ElemType, class WeightType>
KruskalEdge<ElemType, WeightType>::KruskalEdge()
{
}
template <class ElemType, class WeightType>
KruskalEdge<ElemType, WeightType>::KruskalEdge(ElemType v1, ElemType v2, WeightType weight) : vertexA_(v1), vertexB_(v2), weight_(weight)
{
}
template <class ElemType, class WeightType>
ElemType KruskalEdge<ElemType, WeightType>::GetVertexA() const
{
    return vertexA_;
}
template <class ElemType, class WeightType>
ElemType KruskalEdge<ElemType, WeightType>::GetVertexB() const
{
    return vertexB_;
}
template <class ElemType, class WeightType>
WeightType KruskalEdge<ElemType, WeightType>::GetWeight() const
{
    return weight_;
}
template <class ElemType, class WeightType>
KruskalEdge<ElemType, WeightType> &KruskalEdge<ElemType, WeightType>::operator=(const KruskalEdge<ElemType, WeightType> &KE)
{
    if (&KE != this)
    {
        vertexA_ = KE.vertexA_;
        vertexB_ = KE.vertexB_;
        weight_ = KE.weight_;
    }
    return *this;
}
template <class ElemType, class WeightType>
bool KruskalEdge<ElemType, WeightType>::operator<=(const KruskalEdge<ElemType, WeightType> &KE)
{
    return (weight_ <= KE.weight_);
}

template <class ElemType, class WeightType>
bool KruskalEdge<ElemType, WeightType>::operator>(const KruskalEdge<ElemType, WeightType> &KE)
{
    return (weight_ > KE.weight_);
}
#endif