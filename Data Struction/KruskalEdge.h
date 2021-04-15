#pragma once
#ifndef __KRUSKAL_EDGE_H__
#define __KRUSKAL_EDGE_H__
#include "AdjacencyMatrixUndirectedGraph.h"
template <class ElemType, class WeightType>
class KruskalEdge
{
public:
    ElemType vertexA_;
    ElemType vertexB_;
    WeightType weight_;
    KruskalEdge(ElemType v1, ElemType v2, WeightType weight);
    KruskalEdge<ElemType, WeightType> &operator=(const KruskalEdge<ElemType, WeightType> &KE);
    bool operator<=(const KruskalEdge<ElemType, WeightType> &KE);
    bool operator>(const KruskalEdge<ElemType, WeightType> &KE);
};
template <class ElemType, class WeightType>
KruskalEdge<ElemType, WeightType>::KruskalEdge(ElemType v1, ElemType v2, WeightType weight) : vertexA_(v1), vertexB_(v2), weight_(weight)
{
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