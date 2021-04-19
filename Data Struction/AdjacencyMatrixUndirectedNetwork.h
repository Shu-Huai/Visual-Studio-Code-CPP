#pragma once
#ifndef __ADJACENCY_MATRIX_UNDIRECRED_NETWORK_H__
#define __ADJACENCY_MATRIX_UNDIRECRED_NETWORK_H__
#include "Assistance.h"
#include "KruskalEdge.h"
#include "MinimumHeap.h"
#include "UnionFindSets.h"
template <class ElemType, class WeightType>
class AdjacencyMatrixUndirectedNetwork
{
protected:
    int vertexNum_;
    int maxVertexNum_;
    int edgeNum_;
    ElemType *vertexes_;
    bool *tags_;
    int **adjacencyMatrix_;
    WeightType infinity_;
    void DepthFirstSearch(int v, void (*Visit)(const ElemType &));
    void BreadthFirstSearch(int v, void (*Visit)(const ElemType &));

public:
    AdjacencyMatrixUndirectedNetwork(int maxVertexNum = DEFAULT_SIZE, WeightType infinity = WeightType(DEFAULT_INFINITY));
    AdjacencyMatrixUndirectedNetwork(ElemType *v, int vertexNum, int maxVertexNum = DEFAULT_SIZE, WeightType infinity = WeightType(DEFAULT_INFINITY));
    AdjacencyMatrixUndirectedNetwork(const AdjacencyMatrixUndirectedNetwork<ElemType, WeightType> &AMUN);
    ~AdjacencyMatrixUndirectedNetwork();
    void Clear();
    bool IsEmpty();
    void Display();
    void DepthFirstTraverse(void (*Visit)(const ElemType &));
    void BreadthFirstTraverse(void (*Visit)(const ElemType &));
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
    AdjacencyMatrixUndirectedNetwork<ElemType, WeightType> &operator=(const AdjacencyMatrixUndirectedNetwork<ElemType, WeightType> &AMUN);
    void KruskalMinimumSpanningTree();
};
template <class ElemType, class WeightType>
void AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::DepthFirstSearch(int v, void (*Visit)(const ElemType &))
{
    ElemType e;
    tags_[v] = 1;
    Visit(vertexes_[v]);
    for (int i = GetFirstAdjacencyVertex(v); i != -1; i = GetNextAdjacencyVertex(v, i))
    {
        if (!tags_[i])
        {
            DepthFirstSearch(i, Visit);
        }
    }
}
template <class ElemType, class WeigthType>
void AdjacencyMatrixUndirectedNetwork<ElemType, WeigthType>::BreadthFirstSearch(int v, void (*Visit)(const ElemType &))
{
    tags_[v] = 1;
    Visit(vertexes_[v]);
    queue<int> Q;
    Q.push(v);
    while (!Q.empty())
    {
        int e = Q.front();
        Q.pop();
        for (int i = GetFirstAdjacencyVertex(e); i != -1; i = GetNextAdjacencyVertex(e, i))
        {
            if (!tags_[i])
            {
                tags_[i] = 1;
                Visit(vertexes_[i]);
                Q.push(i);
            }
        }
    }
}
template <class ElemType, class WeightType>
AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::AdjacencyMatrixUndirectedNetwork(int maxVertexNum, WeightType infinity)
    : vertexNum_(0), maxVertexNum_(maxVertexNum), edgeNum_(0), infinity_(infinity)
{
    vertexes_ = new ElemType[maxVertexNum_];
    tags_ = new bool[maxVertexNum_];
    adjacencyMatrix_ = (int **)new int *[maxVertexNum_];
    for (int i = 0; i < maxVertexNum_; i++)
    {
        adjacencyMatrix_[i] = new int[maxVertexNum_];
    }
}
template <class ElemType, class WeightType>
AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::AdjacencyMatrixUndirectedNetwork(ElemType *v, int vertexNum, int maxVertexNum, WeightType infinity)
    : vertexNum_(vertexNum), maxVertexNum_(maxVertexNum), edgeNum_(0), infinity_(infinity)
{
    vertexes_ = new ElemType[maxVertexNum_];
    tags_ = new bool[maxVertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        vertexes_[i] = v[i];
        tags_[i] = 0;
    }
    adjacencyMatrix_ = (int **)new int *[maxVertexNum_];
    for (int i = 0; i < maxVertexNum_; i++)
    {
        adjacencyMatrix_[i] = new int[maxVertexNum_];
    }
    for (int i = 0; i < vertexNum_; i++)
    {
        for (int j = 0; j < vertexNum_; j++)
        {
            adjacencyMatrix_[i][j] = infinity_;
        }
    }
}
template <class ElemType, class WeightType>
AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::AdjacencyMatrixUndirectedNetwork(const AdjacencyMatrixUndirectedNetwork<ElemType, WeightType> &AMUN)
    : vertexNum_(AMUN.vertexNum_), maxVertexNum_(AMUN.maxVertexNum_), edgeNum_(AMUN.edgeNum_), infinity_(AMUN.infinity_)
{
    vertexes_ = new ElemType[maxVertexNum_];
    tags_ = new bool[maxVertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        vertexes_[i] = AMUN.vertexes_[i];
        tags_[i] = AMUN.tags_[i];
    }
    adjacencyMatrix_ = (int **)new int *[maxVertexNum_];
    for (int i = 0; i < maxVertexNum_; i++)
    {
        adjacencyMatrix_[i] = new int[maxVertexNum_];
    }
    for (int i = 0; i < vertexNum_; i++)
    {
        for (int j = 0; j < vertexNum_; j++)
        {
            adjacencyMatrix_[i][j] = AMUN.adjacencyMatrix_[i][j];
        }
    }
}
template <class ElemType, class WeightType>
AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::~AdjacencyMatrixUndirectedNetwork()
{
    delete[] vertexes_;
    delete[] tags_;
    for (int i = 0; i < maxVertexNum_; i++)
    {
        delete[] adjacencyMatrix_[i];
    }
    delete[] adjacencyMatrix_;
}
template <class ElemType, class WeightType>
void AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::Clear()
{
    vertexNum_ = 0;
    edgeNum_ = 0;
}
template <class ElemType, class WeightType>
bool AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::IsEmpty()
{
    return vertexNum_ == 0;
}
template <class ElemType, class WeightType>
void AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::Display()
{
    for (int i = 0; i < vertexNum_; i++)
    {
        cout << "\t" << vertexes_[i];
    }
    cout << endl;
    for (int i = 0; i < vertexNum_; i++)
    {
        cout << vertexes_[i];
        for (int j = 0; j < vertexNum_; j++)
        {
            cout << "\t" << adjacencyMatrix_[i][j];
        }
        cout << endl;
    }
}
template <class ElemType, class WeightType>
void AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::DepthFirstTraverse(void (*Visit)(const ElemType &))
{
    for (int i = 0; i < vertexNum_; i++)
    {
        tags_[i] = 0;
    }
    for (int i = 0; i < vertexNum_; i++)
    {
        if (!tags_[i])
        {
            DepthFirstSearch(i, Visit);
        }
    }
}
template <class ElemType, class WeightType>
void AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::BreadthFirstTraverse(void (*Visit)(const ElemType &))
{
    for (int i = 0; i < vertexNum_; i++)
    {
        tags_[i] = 0;
    }
    for (int i = 0; i < vertexNum_; i++)
    {
        if (!tags_[i])
        {
            BreadthFirstSearch(i, Visit);
        }
    }
}
template <class ElemType, class WeightType>
Status AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::AppendVertex(const ElemType &e)
{
    if (vertexNum_ == maxVertexNum_)
    {
        return OVER_FLOW;
    }
    vertexes_[vertexNum_] = e;
    tags_[vertexNum_] = 0;
    for (int i = 0; i <= vertexNum_; i++)
    {
        adjacencyMatrix_[vertexNum_][i] = infinity_;
        adjacencyMatrix_[i][vertexNum_] = infinity_;
    }
    adjacencyMatrix_[vertexNum_][vertexNum_] = 0;
    vertexNum_++;
    return SUCCESS;
}
template <class ElemType, class WeightType>
Status AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::InsertEdge(int v1, int v2, WeightType weight)
{
    if (v1 < 0 || v1 >= vertexNum_ || v2 < 0 || v2 >= vertexNum_ || v1 == v2)
    {
        return RANGE_ERROR;
    }
    if (adjacencyMatrix_[v1][v2] == infinity_)
    {
        adjacencyMatrix_[v1][v2] = weight;
        adjacencyMatrix_[v2][v1] = weight;
        edgeNum_++;
    }
    return SUCCESS;
}
template <class ElemType, class WeightType>
Status AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::DeleteVertex(ElemType &e)
{
    int v = GetIndex(e);
    if (v == -1)
    {
        return UNDER_FLOW;
    }
    for (int i = 0; i < vertexNum_; i++)
    {
        if (adjacencyMatrix_[v][i] != infinity_ && v != i)
        {
            adjacencyMatrix_[v][i] = infinity_;
            adjacencyMatrix_[i][v] = infinity_;
            edgeNum_--;
        }
    }
    vertexNum_--;
    if (v < vertexNum_)
    {
        vertexes_[v] = vertexes_[vertexNum_];
        tags_[v] = tags_[vertexNum_];
        for (int i = 0; i <= vertexNum_; i++)
        {
            adjacencyMatrix_[v][i] = adjacencyMatrix_[vertexNum_][i];
        }
        for (int i = 0; i <= vertexNum_; i++)
        {
            adjacencyMatrix_[i][v] = adjacencyMatrix_[i][vertexNum_];
        }
    }
    return SUCCESS;
}
template <class ElemType, class WeightType>
Status AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::DeleteEdge(int v1, int v2)
{
    if (v1 < 0 || v1 >= vertexNum_ || v2 < 0 || v2 >= vertexNum_ || v1 == v2)
    {
        return RANGE_ERROR;
    }
    if (adjacencyMatrix_[v1][v2] != infinity_)
    {
        adjacencyMatrix_[v1][v2] = infinity_;
        adjacencyMatrix_[v2][v1] = infinity_;
        edgeNum_--;
    }
    return SUCCESS;
}
template <class ElemType, class WeightType>
Status AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::SetElem(int v, const ElemType &e)
{
    if (v < 0 || v >= vertexNum_)
    {
        return RANGE_ERROR;
    }
    vertexes_[v] = e;
    return SUCCESS;
}
template <class ElemType, class WeightType>
Status AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::SetTag(int v, bool val)
{
    if (v < 0 || v >= vertexNum_)
    {
        return RANGE_ERROR;
    }
    tags_[v] = val;
    return SUCCESS;
}
template <class ElemType, class WeightType>
int AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::GetVertexNum() const
{
    return vertexNum_;
}
template <class ElemType, class WeightType>
int AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::GetEdgeNum() const
{
    return edgeNum_;
}
template <class ElemType, class WeightType>
int AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::GetIndex(ElemType &e) const
{
    for (int i = 0; i < vertexNum_; i++)
    {
        if (vertexes_[i] == e)
        {
            return i;
        }
    }
    return -1;
}
template <class ElemType, class WeightType>
int AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::GetElem(int v) const
{
    return vertexes_[v];
}
template <class ElemType, class WeightType>
bool AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::GetTag(int v) const
{
    return tags_[v];
}
template <class ElemType, class WeightType>
WeightType AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::GetWeight(int v1, int v2) const
{
    return adjacencyMatrix_[v1][v2];
}
template <class ElemType, class WeightType>
WeightType AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::GetInfinity() const
{
    return infinity_;
}
template <class ElemType, class WeightType>
int AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::GetFirstAdjacencyVertex(int v) const
{
    for (int i = 0; i < vertexNum_; i++)
    {
        int test = adjacencyMatrix_[v][i];
        if (adjacencyMatrix_[v][i] && adjacencyMatrix_[v][i] != infinity_)
        {
            return i;
        }
    }
    return -1;
}
template <class ElemType, class WeightType>
int AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::GetNextAdjacencyVertex(int v1, int v2) const
{
    for (int i = v2 + 1; i < vertexNum_; i++)
    {
        if (adjacencyMatrix_[v1][i] && adjacencyMatrix_[v1][i] != infinity_)
        {
            return i;
        }
    }
    return -1;
}
template <class ElemType, class WeightType>
AdjacencyMatrixUndirectedNetwork<ElemType, WeightType> &AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::operator=(const AdjacencyMatrixUndirectedNetwork<ElemType, WeightType> &AMUN)
{
    if (&AMUN != this)
    {
        delete[] vertexes_;
        delete[] tags_;
        for (int i = 0; i < maxVertexNum_; i++)
        {
            delete[] adjacencyMatrix_[i];
        }
        delete[] adjacencyMatrix_;
        vertexNum_ = AMUN.vertexNum_;
        maxVertexNum_ = AMUN.maxVertexNum_;
        edgeNum_ = AMUN.edgeNum_;
        infinity_ = AMUN.infinity_;
        vertexes_ = new ElemType[maxVertexNum_];
        tags_ = new bool[maxVertexNum_];
        for (int i = 0; i < vertexNum_; i++)
        {
            vertexes_[i] = AMUN.vertexes_[i];
            tags_[i] = AMUN.tags_[i];
        }
        adjacencyMatrix_ = (int **)new int *[maxVertexNum_];
        for (int i = 0; i < maxVertexNum_; i++)
        {
            adjacencyMatrix_[i] = new int[maxVertexNum_];
        }
        for (int i = 0; i < vertexNum_; i++)
        {
            for (int j = 0; j < vertexNum_; j++)
            {
                adjacencyMatrix_[i][j] = AMUN.adjacencyMatrix_[i][j];
            }
        }
    }
    return *this;
}
template <class ElemType, class WeightType>
void AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::KruskalMinimumSpanningTree()
{
    MinimumHeap<KruskalEdge<ElemType, WeightType>> MH(edgeNum_);
    for (int i = 0; i < vertexNum_; i++)
    {
        for (int j = GetFirstAdjacencyVertex(i); j >= 0; j = GetNextAdjacencyVertex(i, j))
        {
            if (i < j)
            {
                KruskalEdge<ElemType, WeightType> KE(vertexes_[i], vertexes_[j], adjacencyMatrix_[i][j]);
                MH.InsertElem(KE);
            }
        }
    }
    int count = 0;
    UnionFindSets<ElemType> UFS(vertexes_, vertexNum_);
    while (count < vertexNum_ - 1)
    {
        KruskalEdge<ElemType, WeightType> KE;
        MH.DeleteTop(KE);
        ElemType v1 = KE.GetVertexA();
        ElemType v2 = KE.GetVertexB();
        if (UFS.Differ(v1, v2))
        {
            cout << "Edge: ( " << v1 << ", " << v2 << " ) Weight: " << KE.GetWeight() << "." << endl;
            UFS.UnionByNodeNumber(v1, v2);
            count++;
        }
    }
    UFS.Display();
}
#endif