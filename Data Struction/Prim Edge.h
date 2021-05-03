#pragma once
#ifndef __PRIM_EDGE_H__
#define __PRIM_EDGE_H__
template <class ElemType, class WeightType>
class PrimEdge
{
public:
    WeightType minimunWeight_;
    int adjacencyVertex_;
};
#endif