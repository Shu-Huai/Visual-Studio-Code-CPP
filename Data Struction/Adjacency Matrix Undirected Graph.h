#pragma once
#ifndef __ADJACENCY_MATRIX_UNDIRECTED_GRAPH_H__
#define __ADJACENCY_MATRIX_UNDIRECTED_GRAPH_H__
#include "Assistance.h"
template <class ElemType>
class AdjacencyMatrixUndirectedGraph
{
protected:
    int vertexNum_;
    int maxVertexNum_;
    int edgeNum_;
    ElemType *vertexes_;
    bool *visited_;
    int **adjacencyMatrix_;
    void DepthFirstSearch(int v, void (*Visit)(const ElemType &));
    void BreadthFirstSearch(int v, void (*Visit)(const ElemType &));

public:
    AdjacencyMatrixUndirectedGraph(int maxVertexNum = DEFAULT_SIZE);
    AdjacencyMatrixUndirectedGraph(ElemType *v, int vertexNum, int maxVertexNum = DEFAULT_SIZE);
    AdjacencyMatrixUndirectedGraph(const AdjacencyMatrixUndirectedGraph<ElemType> &AMUG);
    ~AdjacencyMatrixUndirectedGraph();
    void Clear();
    bool IsEmpty();
    void Display();
    void DepthFirstTraverse(void (*Visit)(const ElemType &));
    void BreadthFirstTraverse(void (*Visit)(const ElemType &));
    Status AppendVertex(const ElemType &e);
    Status InsertEdge(int v1, int v2);
    Status DeleteVertex(ElemType &e);
    Status DeleteEdge(int v1, int v2);
    Status SetElem(int v, const ElemType &e);
    Status SetTag(int v, bool val);
    int GetVertexNum() const;
    int GetEdgeNum() const;
    int GetIndex(ElemType &e) const;
    int GetElem(int v) const;
    bool GetTag(int v) const;
    int GetFirstAdjacencyVertex(int v) const;
    int GetNextAdjacencyVertex(int v1, int v2) const;
    AdjacencyMatrixUndirectedGraph<ElemType> &operator=(const AdjacencyMatrixUndirectedGraph<ElemType> &AMUG);
};
template <class ElemType>
void AdjacencyMatrixUndirectedGraph<ElemType>::DepthFirstSearch(int v, void (*Visit)(const ElemType &))
{
    visited_[v] = 1;
    Visit(vertexes_[v]);
    for (int i = GetFirstAdjacencyVertex(v); i != -1; i = GetNextAdjacencyVertex(v, i))
    {
        if (!visited_[i])
        {
            DepthFirstSearch(i, Visit);
        }
    }
}
template <class ElemType>
void AdjacencyMatrixUndirectedGraph<ElemType>::BreadthFirstSearch(int v, void (*Visit)(const ElemType &))
{
    visited_[v] = 1;
    Visit(vertexes_[v]);
    queue<int> Q;
    Q.push(v);
    while (!Q.empty())
    {
        int e = Q.front();
        Q.pop();
        for (int i = GetFirstAdjacencyVertex(e); i != -1; i = GetNextAdjacencyVertex(e, i))
        {
            if (!visited_[i])
            {
                visited_[i] = 1;
                Visit(vertexes_[i]);
                Q.push(i);
            }
        }
    }
}
template <class ElemType>
AdjacencyMatrixUndirectedGraph<ElemType>::AdjacencyMatrixUndirectedGraph(int maxVertexNum) : vertexNum_(0), maxVertexNum_(maxVertexNum), edgeNum_(0)
{
    vertexes_ = new ElemType[maxVertexNum_];
    visited_ = new bool[maxVertexNum_];
    adjacencyMatrix_ = (int **)new int *[maxVertexNum_];
    for (int i = 0; i < maxVertexNum_; i++)
    {
        adjacencyMatrix_[i] = new int[maxVertexNum_];
    }
}
template <class ElemType>
AdjacencyMatrixUndirectedGraph<ElemType>::AdjacencyMatrixUndirectedGraph(ElemType *v, int vertexNum, int maxVertexNum)
    : vertexNum_(vertexNum), maxVertexNum_(maxVertexNum), edgeNum_(0)
{
    vertexes_ = new ElemType[maxVertexNum_];
    visited_ = new bool[maxVertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        vertexes_[i] = v[i];
        visited_[i] = 0;
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
            adjacencyMatrix_[i][j] = 0;
        }
    }
}
template <class ElemType>
AdjacencyMatrixUndirectedGraph<ElemType>::AdjacencyMatrixUndirectedGraph(const AdjacencyMatrixUndirectedGraph<ElemType> &AMUG)
    : vertexNum_(AMUG.vertexNum_), maxVertexNum_(AMUG.maxVertexNum_), edgeNum_(AMUG.edgeNum_)
{
    vertexes_ = new ElemType[maxVertexNum_];
    visited_ = new bool[maxVertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        vertexes_[i] = AMUG.vertexes_[i];
        visited_[i] = AMUG.visited_[i];
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
            adjacencyMatrix_[i][j] = AMUG.adjacencyMatrix_[i][j];
        }
    }
}
template <class ElemType>
AdjacencyMatrixUndirectedGraph<ElemType>::~AdjacencyMatrixUndirectedGraph()
{
    delete[] vertexes_;
    delete[] visited_;
    for (int i = 0; i < maxVertexNum_; i++)
    {
        delete[] adjacencyMatrix_[i];
    }
    delete[] adjacencyMatrix_;
}
template <class ElemType>
void AdjacencyMatrixUndirectedGraph<ElemType>::Clear()
{
    vertexNum_ = 0;
    edgeNum_ = 0;
}
template <class ElemType>
bool AdjacencyMatrixUndirectedGraph<ElemType>::IsEmpty()
{
    return vertexNum_ == 0;
}
template <class ElemType>
void AdjacencyMatrixUndirectedGraph<ElemType>::Display()
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
template <class ElemType>
void AdjacencyMatrixUndirectedGraph<ElemType>::DepthFirstTraverse(void (*Visit)(const ElemType &))
{
    for (int i = 0; i < vertexNum_; i++)
    {
        visited_[i] = 0;
    }
    for (int i = 0; i < vertexNum_; i++)
    {
        if (!visited_[i])
        {
            DepthFirstSearch(i, Visit);
        }
    }
}
template <class ElemType>
void AdjacencyMatrixUndirectedGraph<ElemType>::BreadthFirstTraverse(void (*Visit)(const ElemType &))
{
    for (int i = 0; i < vertexNum_; i++)
    {
        visited_[i] = 0;
    }
    for (int i = 0; i < vertexNum_; i++)
    {
        if (!visited_[i])
        {
            BreadthFirstSearch(i, Visit);
        }
    }
}
template <class ElemType>
Status AdjacencyMatrixUndirectedGraph<ElemType>::AppendVertex(const ElemType &e)
{
    if (vertexNum_ == maxVertexNum_)
    {
        return OVER_FLOW;
    }
    vertexes_[vertexNum_] = e;
    visited_[vertexNum_] = 0;
    for (int i = 0; i <= vertexNum_; i++)
    {
        adjacencyMatrix_[vertexNum_][i] = 0;
        adjacencyMatrix_[i][vertexNum_] = 0;
    }
    vertexNum_++;
    return SUCCESS;
}
template <class ElemType>
Status AdjacencyMatrixUndirectedGraph<ElemType>::InsertEdge(int v1, int v2)
{
    if (v1 < 0 || v1 >= vertexNum_ || v2 < 0 || v2 >= vertexNum_ || v1 == v2)
    {
        return RANGE_ERROR;
    }
    if (!adjacencyMatrix_[v1][v2])
    {
        adjacencyMatrix_[v1][v2] = 1;
        adjacencyMatrix_[v2][v1] = 1;
        edgeNum_++;
    }
    return SUCCESS;
}
template <class ElemType>
Status AdjacencyMatrixUndirectedGraph<ElemType>::DeleteVertex(ElemType &e)
{
    int v = GetIndex(e);
    if (v == -1)
    {
        return UNDER_FLOW;
    }
    for (int i = 0; i < vertexNum_; i++)
    {
        if (adjacencyMatrix_[v][i] == 1)
        {
            adjacencyMatrix_[v][i] = 0;
            adjacencyMatrix_[i][v] = 0;
            edgeNum_--;
        }
    }
    vertexNum_--;
    if (v < vertexNum_)
    {
        vertexes_[v] = vertexes_[vertexNum_];
        visited_[v] = visited_[vertexNum_];
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
template <class ElemType>
Status AdjacencyMatrixUndirectedGraph<ElemType>::DeleteEdge(int v1, int v2)
{
    if (v1 < 0 || v1 >= vertexNum_ || v2 < 0 || v2 >= vertexNum_ || v1 == v2)
    {
        return RANGE_ERROR;
    }
    if (adjacencyMatrix_[v1][v2])
    {
        adjacencyMatrix_[v1][v2] = 0;
        adjacencyMatrix_[v2][v1] = 0;
        edgeNum_--;
    }
    return SUCCESS;
}
template <class ElemType>
Status AdjacencyMatrixUndirectedGraph<ElemType>::SetElem(int v, const ElemType &e)
{
    if (v < 0 || v >= vertexNum_)
    {
        return RANGE_ERROR;
    }
    vertexes_[v] = e;
    return SUCCESS;
}
template <class ElemType>
Status AdjacencyMatrixUndirectedGraph<ElemType>::SetTag(int v, bool val)
{
    if (v < 0 || v >= vertexNum_)
    {
        return RANGE_ERROR;
    }
    visited_[v] = val;
    return SUCCESS;
}
template <class ElemType>
int AdjacencyMatrixUndirectedGraph<ElemType>::GetVertexNum() const
{
    return vertexNum_;
}
template <class ElemType>
int AdjacencyMatrixUndirectedGraph<ElemType>::GetEdgeNum() const
{
    return edgeNum_;
}
template <class ElemType>
int AdjacencyMatrixUndirectedGraph<ElemType>::GetIndex(ElemType &e) const
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
template <class ElemType>
int AdjacencyMatrixUndirectedGraph<ElemType>::GetElem(int v) const
{
    return vertexes_[v];
}
template <class ElemType>
bool AdjacencyMatrixUndirectedGraph<ElemType>::GetTag(int v) const
{
    return visited_[v];
}
template <class ElemType>
int AdjacencyMatrixUndirectedGraph<ElemType>::GetFirstAdjacencyVertex(int v) const
{
    for (int i = 0; i < vertexNum_; i++)
    {
        if (adjacencyMatrix_[v][i])
        {
            return i;
        }
    }
    return -1;
}
template <class ElemType>
int AdjacencyMatrixUndirectedGraph<ElemType>::GetNextAdjacencyVertex(int v1, int v2) const
{
    for (int i = v2 + 1; i < vertexNum_; i++)
    {
        if (adjacencyMatrix_[v1][i])
        {
            return i;
        }
    }
    return -1;
}
template <class ElemType>
AdjacencyMatrixUndirectedGraph<ElemType> &AdjacencyMatrixUndirectedGraph<ElemType>::operator=(const AdjacencyMatrixUndirectedGraph<ElemType> &AMUG)
{
    if (&AMUG != this)
    {
        delete[] vertexes_;
        delete[] visited_;
        for (int i = 0; i < maxVertexNum_; i++)
        {
            delete[] adjacencyMatrix_[i];
        }
        delete[] adjacencyMatrix_;
        vertexNum_ = AMUG.vertexNum_;
        maxVertexNum_ = AMUG.maxVertexNum_;
        edgeNum_ = AMUG.edgeNum_;
        vertexes_ = new ElemType[maxVertexNum_];
        visited_ = new bool[maxVertexNum_];
        for (int i = 0; i < vertexNum_; i++)
        {
            vertexes_[i] = AMUG.vertexes_[i];
            visited_[i] = AMUG.visited_[i];
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
                adjacencyMatrix_[i][j] = AMUG.adjacencyMatrix_[i][j];
            }
        }
    }
    return *this;
}
#endif