
#pragma once
#ifndef __ADJACENCY_LIST_NETWORK_VERTEX_H__
#define __ADJACENCY_LIST_NETWORK_VERTEX_H__
#include "AdjacencyListNetworkSide.h"
template <class ElemType, class WeightType>
class AdjacencyListNetWorkVertex
{
public:
    ElemType data_;
    AdjacencyListNetworkSide<WeightType> *firstSide_;
    AdjacencyListNetWorkVertex();
    AdjacencyListNetWorkVertex(ElemType e, AdjacencyListNetworkSide<WeightType> *sides = NULL);
};
template <class ElemType, class WeightType>
AdjacencyListNetWorkVertex<ElemType, WeightType>::AdjacencyListNetWorkVertex() : firstSide_(NULL)
{
}
template <class ElemType, class WeightType>
AdjacencyListNetWorkVertex<ElemType, WeightType>::AdjacencyListNetWorkVertex(ElemType e, AdjacencyListNetworkSide<WeightType> *sides)
    : data_(e), firstSide_(sides)
{
}
#endif