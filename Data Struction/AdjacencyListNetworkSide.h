#pragma once
#ifndef __ADJ_LIST_NETWORK_SIDE__H__
#define __ADJ_LIST_NETWORK_SIDE_H__
#include "Assistance.h"
template <class WeightType>
class AdjacencyListNetworkSide
{
public:
    int vertex_;
    WeightType weight_;
    AdjacencyListNetworkSide<WeightType> *nextSide_;
    AdjacencyListNetworkSide();
    AdjacencyListNetworkSide(int vertex, WeightType weight, AdjacencyListNetworkSide<WeightType> *nextSide = NULL);
};
template <class WeightType>
AdjacencyListNetworkSide<WeightType>::AdjacencyListNetworkSide() : vertex_(-1)
{
}
template <class WeightType>
AdjacencyListNetworkSide<WeightType>::AdjacencyListNetworkSide(int vertex, WeightType weight, AdjacencyListNetworkSide<WeightType> *nextSide)
    : vertex_(vertex), weight_(weight), nextSide_(nextSide)
{
}
#endif