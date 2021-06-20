
#pragma once
#ifndef __ADJACENCY_LIST_NETWORK_VERTEX_H__
#define __ADJACENCY_LIST_NETWORK_VERTEX_H__
#include "Adjacency List Network Edge.h"
template <class ElemType, class WeightType>
class AdjacencyListNetWorkVertex
{
public:
    ElemType elem_;
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
    : elem_(e), firstEdge_(sides)
{
}
#endif