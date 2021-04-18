
#pragma once
#ifndef __ADJACENCY_LIST_NETWORK_VERTEX_H__
#define __ADJACENCY_LIST_NETWORK_VERTEX_H__
#include "AdjacencyListNetworkEdge.h"
template <class ElemType, class WeightType>
class AdjacencyListNetWorkVertex
{
public:
    ElemType data_;
    AdjacencyListNetworkEdge<WeightType> *firstEdge_;
    AdjacencyListNetWorkVertex();
    AdjacencyListNetWorkVertex(ElemType e, AdjacencyListNetworkEdge<WeightType> *sides = NULL);
};
template <class ElemType, class WeightType>
AdjacencyListNetWorkVertex<ElemType, WeightType>::AdjacencyListNetWorkVertex() : firstEdge_(NULL)
{
}
template <class ElemType, class WeightType>
AdjacencyListNetWorkVertex<ElemType, WeightType>::AdjacencyListNetWorkVertex(ElemType e, AdjacencyListNetworkEdge<WeightType> *sides)
    : data_(e), firstEdge_(sides)
{
}
#endif