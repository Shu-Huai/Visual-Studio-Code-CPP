#pragma once
#ifndef __ADJACENCY_MATRIX_UNDIRECRED_NETWORK_H__
#define __ADJACENCY_MATRIX_UNDIRECRED_NETWORK_H__
#include "Assistance.h"
template <class ElemType, class WeightType>
class AdjacnecyMatrixUndirectedNetwork
{
protected:
    int vertexNum_;
    int maxVertexNum_;
    int edgeNum_;
    ElemType *vertexes_;
    bool *tags_;
    int **adjacencyMatrix_;
    WeightType infinity_;

public:
    AdjacnecyMatrixUndirectedNetwork(int maxVertexNum = DEFAULT_SIZE, WeightType infinity = WeightType(DEFAULT_INFINITY));
    AdjacnecyMatrixUndirectedNetwork(ElemType *v, int vertexNum, int maxVertexNum = DEFAULT_SIZE, WeightType infinity = WeightType(DEFAULT_INFINITY));
    AdjacnecyMatrixUndirectedNetwork(const AdjacnecyMatrixUndirectedNetwork<ElemType, WeightType> &AMUN);
    ~AdjacnecyMatrixUndirectedNetwork();
    void Clear();
    bool IsEmpty();
    void Display();
    Status AppendVertex(const ElemType &e);
    Status InsertEdge(int v1, int v2, WeightType weight);
    Status DeleteVertex(ElemType &e);
    Status DeleteEdge(int v1, int v2);
    Status SetElem(int v, const ElemType &e);
    Status SetTag(int v, bool val);
    int GetVertexNum() const;
    int GetEdgeNum() const;
    int GetIndex(ElemType &e) const;
    int GetElem(int v) const;
    bool GetTag(int v) const;
    WeightType GetWeight(int v1, int v2) const;
    WeightType GetInfinity() const;
    int GetFirstAdjacencyVertex(int v) const;
    int GetNextAdjacencyVertex(int v1, int v2) const;
    AdjacnecyMatrixUndirectedNetwork<ElemType> &operator=(const AdjacnecyMatrixUndirectedNetwork<ElemType, WeightType> &AMUN);
};
#endif
template <class ElemType, class WeightType>
void MiniSpanTreeKruskal(const AdjacnecyMatrixUndirectedNetwork<ElemType, WeightType> &g)
// 初始条件：存在网g
// 操作结果：用Kruskal算法构造网g的最小代价生成树
{
    int count, VexNum = g.GetVexNum();
    KruskalEdge<ElemType, WeightType> KEdge;
    MinHeap<KruskalEdge<ElemType, WeightType>> ha(g.GetEdgeNum());
    ElemType *kVex, v1, v2;
    kVex = new ElemType[VexNum]; // 定义顶点数组,存储顶点信息
    for (int i = 0; i < VexNum; i++)
        g.GetElem(i, kVex[i]);
    UFSets<ElemType> f(kVex, VexNum); // 根据顶点数组构造并查集
    for (int v = 0; v < g.GetVexNum(); v++)
        for (int u = g.FirstAdjVex(v); u >= 0; u = g.NextAdjVex(v, u))
            if (v < u)
            { // 将v < u的边插入到最小堆
                g.GetElem(v, v1);
                g.GetElem(u, v2);
                KEdge.vertexA_ = v1;
                KEdge.vertexB_ = v2;
                KEdge.weight_ = g.GetWeight(v, u);
                ha.Insert(KEdge);
            }
    count = 0; // 表示已经挑选的边数

    while (count < VexNum - 1)
    {
        ha.DeleteTop(KEdge); // 从堆顶取一条边
        v1 = KEdge.vertexA_;
        v2 = KEdge.vertexB_;
        if (f.Differ(v1, v2))
        {                                                                             // 边所依附的两顶点不在同一棵树上
            cout << "边:( " << v1 << ", " << v2 << " ) 权:" << KEdge.weight_ << endl; // 输出边及权值
            f.Union(v1, v2);                                                          // 将两个顶点所在的树合并成一棵树
            count++;
        }
    }
}