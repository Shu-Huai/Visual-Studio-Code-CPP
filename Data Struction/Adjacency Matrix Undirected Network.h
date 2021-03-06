#pragma once
#ifndef __ADJACENCY_MATRIX_UNDIRECRED_NETWORK_H__
#define __ADJACENCY_MATRIX_UNDIRECRED_NETWORK_H__
#include "Adjacency Matrix Network Edge.h"
#include "Assistance.h"
#include "Kruskal Edge.h"
#include "Maximum Heap.h"
#include "Minimum Heap.h"
#include "Prim Edge.h"
#include "Union-Find Sets.h"
template <class ElemType, class WeightType>
class AdjacencyMatrixUndirectedNetwork
{
protected:
    int vertexNum_;
    int maxVertexNum_;
    int edgeNum_;
    ElemType *vertexes_;
    bool *isVisited_;
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
    Status SetVisited(int v, bool val);
    int GetVertexNum() const;
    int GetEdgeNum() const;
    int GetIndex(ElemType &e) const;
    int GetElem(int v) const;
    bool IsVisited(int v) const;
    WeightType GetWeight(int v1, int v2) const;
    WeightType GetInfinity() const;
    int GetFirstAdjacencyVertex(int v) const;
    int GetNextAdjacencyVertex(int v1, int v2) const;
    void KruskalMinimumSpanningTree();
    void PrimMinimumSpanningTree(int firstVertex = 0);
    bool IsConnected();
    void TearCycleMinimumSpanningTree();
    AdjacencyMatrixUndirectedNetwork<ElemType, WeightType> &operator=(const AdjacencyMatrixUndirectedNetwork<ElemType, WeightType> &AMUN);
};
template <class ElemType, class WeightType>
void AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::DepthFirstSearch(int v, void (*Visit)(const ElemType &))
{
    ElemType e;
    isVisited_[v] = 1;
    Visit(vertexes_[v]);
    for (int i = GetFirstAdjacencyVertex(v); i != -1; i = GetNextAdjacencyVertex(v, i))
    {
        if (!isVisited_[i])
        {
            DepthFirstSearch(i, Visit);
        }
    }
}
template <class ElemType, class WeigthType>
void AdjacencyMatrixUndirectedNetwork<ElemType, WeigthType>::BreadthFirstSearch(int v, void (*Visit)(const ElemType &))
{
    isVisited_[v] = 1;
    Visit(vertexes_[v]);
    queue<int> Q;
    Q.push(v);
    while (!Q.empty())
    {
        int e = Q.front();
        Q.pop();
        for (int i = GetFirstAdjacencyVertex(e); i != -1; i = GetNextAdjacencyVertex(e, i))
        {
            if (!isVisited_[i])
            {
                isVisited_[i] = 1;
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
    assert(vertexes_);
    isVisited_ = new bool[maxVertexNum_];
    assert(isVisited_);
    adjacencyMatrix_ = (int **)new int *[maxVertexNum_];
    assert(adjacencyMatrix_);
    for (int i = 0; i < maxVertexNum_; i++)
    {
        adjacencyMatrix_[i] = new int[maxVertexNum_];
        assert(adjacencyMatrix_[i]);
    }
}
template <class ElemType, class WeightType>
AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::AdjacencyMatrixUndirectedNetwork(ElemType *v, int vertexNum, int maxVertexNum, WeightType infinity)
    : vertexNum_(vertexNum), maxVertexNum_(maxVertexNum), edgeNum_(0), infinity_(infinity)
{
    vertexes_ = new ElemType[maxVertexNum_];
    assert(vertexes_);
    isVisited_ = new bool[maxVertexNum_];
    assert(isVisited_);
    for (int i = 0; i < vertexNum_; i++)
    {
        vertexes_[i] = v[i];
        isVisited_[i] = 0;
    }
    adjacencyMatrix_ = (int **)new int *[maxVertexNum_];
    assert(adjacencyMatrix_);
    for (int i = 0; i < maxVertexNum_; i++)
    {
        adjacencyMatrix_[i] = new int[maxVertexNum_];
        assert(adjacencyMatrix_[i]);
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
    assert(vertexes_);
    isVisited_ = new bool[maxVertexNum_];
    assert(isVisited_);
    for (int i = 0; i < vertexNum_; i++)
    {
        vertexes_[i] = AMUN.vertexes_[i];
        isVisited_[i] = AMUN.isVisited_[i];
    }
    adjacencyMatrix_ = (int **)new int *[maxVertexNum_];
    assert(adjacencyMatrix_);
    for (int i = 0; i < maxVertexNum_; i++)
    {
        adjacencyMatrix_[i] = new int[maxVertexNum_];
        assert(adjacencyMatrix_[i]);
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
    delete[] isVisited_;
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
        isVisited_[i] = 0;
    }
    for (int i = 0; i < vertexNum_; i++)
    {
        if (!isVisited_[i])
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
        isVisited_[i] = 0;
    }
    for (int i = 0; i < vertexNum_; i++)
    {
        if (!isVisited_[i])
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
    isVisited_[vertexNum_] = 0;
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
        isVisited_[v] = isVisited_[vertexNum_];
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
Status AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::SetVisited(int v, bool val)
{
    if (v < 0 || v >= vertexNum_)
    {
        return RANGE_ERROR;
    }
    isVisited_[v] = val;
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
bool AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::IsVisited(int v) const
{
    return isVisited_[v];
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
            cout << "Edge: (" << v1 << ", " << v2 << ") Weight: " << KE.GetWeight() << "." << endl;
            UFS.UnionByNodeNumber(v1, v2);
            count++;
        }
    }
    UFS.Display();
}
template <class ElemType, class WeightType>
void AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::PrimMinimumSpanningTree(int firstVertex)
{
    PrimEdge<ElemType, WeightType> *minimunWeightEdge = new PrimEdge<ElemType, WeightType>[vertexNum_];
    assert(minimunWeightEdge);
    for (int i = 0; i < vertexNum_; i++)
    {
        if (i == firstVertex)
        {
            minimunWeightEdge[i].minimunWeight_ = 0;
            minimunWeightEdge[i].adjacencyVertex_ = -1;
        }
        else
        {
            minimunWeightEdge[i].minimunWeight_ = adjacencyMatrix_[firstVertex][i];
            minimunWeightEdge[i].adjacencyVertex_ = firstVertex;
        }
    }
    for (int i = 1; i < vertexNum_; i++)
    {
        WeightType minimunWeight = infinity_;
        int vertex = firstVertex;
        for (int j = 0; j < vertexNum_; j++)
        {
            if (minimunWeightEdge[j].minimunWeight_ != 0 && minimunWeightEdge[j].minimunWeight_ < minimunWeight)
            {
                vertex = j;
                minimunWeight = minimunWeightEdge[j].minimunWeight_;
            }
        }
        if (vertex != firstVertex)
        {
            cout << "Edge: (" << vertexes_[minimunWeightEdge[vertex].adjacencyVertex_] << ", " << vertexes_[vertex] << ") Weight: " << minimunWeight << endl;
            minimunWeightEdge[vertex].minimunWeight_ = 0;
            for (int j = GetFirstAdjacencyVertex(vertex); j != -1; j = GetNextAdjacencyVertex(vertex, j))
            {
                if (minimunWeightEdge[j].minimunWeight_ != 0 && adjacencyMatrix_[vertex][j] < minimunWeightEdge[j].minimunWeight_)
                {
                    minimunWeightEdge[j].adjacencyVertex_ = vertex;
                    minimunWeightEdge[j].minimunWeight_ = adjacencyMatrix_[vertex][j];
                }
            }
        }
    }
    delete[] minimunWeightEdge;
}
template <class ElemType, class WeightType>
bool AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::IsConnected()
{

    for (int i = 0; i < vertexNum_; i++)
    {
        isVisited_[i] = 0;
    }
    DepthFirstSearch(0, Write<ElemType>);
    for (int i = 0; i < vertexNum_; i++)
    {
        if (!isVisited_[i])
        {
            return 0;
        }
    }
    return 1;
}
template <class ElemType, class WeightType>
void AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::TearCycleMinimumSpanningTree()
{
    MaximumHeap<AdjacencyMatrixNetworkEdge<ElemType, WeightType>> MH(edgeNum_);
    AdjacencyMatrixNetworkEdge<ElemType, WeightType> AMNE;
    ElemType v1, v2;
    for (int row = 0; row < vertexNum_; row++)
    {
        for (int col = 0; col < vertexNum_; col++)
        {
            if (row > col && adjacencyMatrix_[row][col] != infinity_)
            {
                v1 = GetElem(row);
                v2 = GetElem(col);
                AMNE.SetElem(v1, v2, adjacencyMatrix_[row][col]);
                MH.InsertElem(AMNE);
            }
        }
    }
    int count = 0;
    while (edgeNum_ > vertexNum_ - 1)
    {
        MH.DeleteTop(AMNE);
        DeleteEdge(GetIndex(AMNE.vertexA_), GetIndex(AMNE.vertexB_));
        if (IsConnected())
        {
            cout << "Deleted <" << AMNE.vertexA_ << ", " << AMNE.vertexB_ << "> , Weight: " << AMNE.weight_ << endl;
        }
        else
        {
            InsertEdge(GetIndex(AMNE.vertexA_), GetIndex(AMNE.vertexB_), AMNE.weight_);
        }
    }
}
template <class ElemType, class WeightType>
AdjacencyMatrixUndirectedNetwork<ElemType, WeightType> &AdjacencyMatrixUndirectedNetwork<ElemType, WeightType>::operator=(
    const AdjacencyMatrixUndirectedNetwork<ElemType, WeightType> &AMUN)
{
    if (&AMUN != this)
    {
        delete[] vertexes_;
        delete[] isVisited_;
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
        assert(vertexes_);
        isVisited_ = new bool[maxVertexNum_];
        assert(isVisited_);
        for (int i = 0; i < vertexNum_; i++)
        {
            vertexes_[i] = AMUN.vertexes_[i];
            isVisited_[i] = AMUN.isVisited_[i];
        }
        adjacencyMatrix_ = (int **)new int *[maxVertexNum_];
        assert(adjacencyMatrix_);
        for (int i = 0; i < maxVertexNum_; i++)
        {
            adjacencyMatrix_[i] = new int[maxVertexNum_];
            assert(adjacencyMatrix_[i]);
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
#endif