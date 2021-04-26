#pragma once
#ifndef __ADJACENCY_MATRIX_NETWORK_EDGE_H__
#define __ADJACENCY_MATRIX_NETWORK_EDGE_H__
#include "Assistance.h"
template <class ElemType, class WeightType>
class AdjacencyMatrixNetworkEdge
{
public:
    ElemType vertexA_, vertexB_;
    WeightType weight_;
    AdjacencyMatrixNetworkEdge();
    AdjacencyMatrixNetworkEdge(ElemType vertexA, ElemType vertexB, WeightType weight);
    void SetElem(ElemType vertexA, ElemType vertexB, WeightType weight);
    bool operator<(const AdjacencyMatrixNetworkEdge<ElemType, WeightType> &AMNE);
    bool operator>=(const AdjacencyMatrixNetworkEdge<ElemType, WeightType> &AMNE);
};
template <class ElemType, class WeightType>
AdjacencyMatrixNetworkEdge<ElemType, WeightType>::AdjacencyMatrixNetworkEdge()
{
}
template <class ElemType, class WeightType>
AdjacencyMatrixNetworkEdge<ElemType, WeightType>::AdjacencyMatrixNetworkEdge(ElemType vertexA, ElemType vertexB, WeightType weight)
    : vertexA_(vertexA), vertexB_(vertexB), weight_(weight)
{
}
template <class ElemType, class WeightType>
void AdjacencyMatrixNetworkEdge<ElemType, WeightType>::SetElem(ElemType vertexA, ElemType vertexB, WeightType weight)
{
    vertexA_ = vertexA;
    vertexB_ = vertexB;
    weight_ = weight;
}
template <class ElemType, class WeightType>
bool AdjacencyMatrixNetworkEdge<ElemType, WeightType>::operator<(const AdjacencyMatrixNetworkEdge<ElemType, WeightType> &AMNE)
{
    return weight_ < AMNE.weight_ ? 1 : 0;
}
template <class ElemType, class WeightType>
bool AdjacencyMatrixNetworkEdge<ElemType, WeightType>::operator>=(const AdjacencyMatrixNetworkEdge<ElemType, WeightType> &AMNE)
{
    return weight_ >= AMNE.weight_ ? 1 : 0;
}
#endif