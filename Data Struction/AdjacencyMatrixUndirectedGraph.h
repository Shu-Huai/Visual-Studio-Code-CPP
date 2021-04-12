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
    int sideNum_;
    ElemType *vertexes_;
    Status *tags_;
    int **adjacencyMatrix_;

public:
    AdjacencyMatrixUndirectedGraph(int maxVertexNum = DEFAULT_SIZE);
    AdjacencyMatrixUndirectedGraph(ElemType *v, int vertexNum, int maxVertexNum = DEFAULT_SIZE);
    AdjacencyMatrixUndirectedGraph(const AdjacencyMatrixUndirectedGraph<ElemType> &AMUG);
    ~AdjacencyMatrixUndirectedGraph();
    void Clear();
    bool IsEmpty();
    void Display();
    Status AppendVertex(const ElemType &e);
    Status InsertSide(int v1, int v2);
    Status DeleteVertex(const ElemType &e);
    Status DeleteSide(int v1, int v2);
    Status SetElem(int v, const ElemType &e);
    void SetTag(int v, Status val);
    int GetVertexNum() const;
    int GetSideNum() const;
    int GetIndex(ElemType &e) const;
    int GetElem(int v) const;
    int GetTag(int v) const;
    int GetFirstAdjacencyVertex(int v) const;
    int GetNextAdjacencyVertex(int v1, int v2) const;
    AdjacencyMatrixUndirectedGraph<ElemType> &operator=(const AdjacencyMatrixUndirectedGraph<ElemType> &AMUG);
};
template <class ElemType>
AdjacencyMatrixUndirectedGraph<ElemType>::AdjacencyMatrixUndirectedGraph(int maxVertexNum) : vertexNum_(0), maxVertexNum_(maxVertexNum), sideNum_(0)
{
    vertexes_ = new ElemType[maxVertexNum_];
    tags_ = new Status[maxVertexNum_];
    adjacencyMatrix_ = (int **)new int *[maxVertexNum_];
    for (int i = 0; i < maxVertexNum_; i++)
    {
        adjacencyMatrix_[i] = new int[maxVertexNum_];
    }
}
template <class ElemType>
AdjacencyMatrixUndirectedGraph<ElemType>::AdjacencyMatrixUndirectedGraph(ElemType *v, int vertexNum, int maxVertexNum)
    : vertexNum_(vertexNum), maxVertexNum_(maxVertexNum), sideNum_(0)
{
    vertexes_ = new ElemType[maxVertexNum_];
    tags_ = new Status[maxVertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        vertexes_[i] = v[i];
        tags_[i] = UNVISITED;
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
    : vertexNum_(AMUG.vertexNum_), maxVertexNum_(AMUG.maxVertexNum_), sideNum_(AMUG.sideNum_)
{
    vertexes_ = new ElemType[maxVertexNum_];
    tags_ = new Status[maxVertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        vertexes_[i] = AMUG.vertexes_[i];
        tags_[i] = AMUG.tags_[i];
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
    delete[] tags_;
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
    sideNum_ = 0;
}
template <class ElemType>
bool AdjacencyMatrixUndirectedGraph<ElemType>::IsEmpty()
{
    return vertexNum_ == 0;
}
template <class ElemType>
void AdjacencyMatrixUndirectedGraph<ElemType>::Display()
{

    for (int i = 0; i < vertexes_; i++)
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
Status AdjacencyMatrixUndirectedGraph<ElemType>::AppendVertex(const ElemType &e)
{
    if (vertexNum_ == maxVertexNum_)
    {
        return OVER_FLOW;
    }
    vertexes_[vertexNum_] = e;
    tags_[vertexNum_] = UNVISITED;
    for (int i = 0; i <= vertexNum_; i++)
    {
        adjacencyMatrix_[vertexNum_][i] = 0;
        adjacencyMatrix_[i][vertexNum_] = 0;
    }
    vertexNum_++;
    return SUCCESS;
}
template <class ElemType>
Status AdjacencyMatrixUndirectedGraph<ElemType>::InsertSide(int v1, int v2)
{
    if (v1 < 0 || v1 >= vertexNum_ || v2 < 0 || v2 >= vertexNum_ || v1 == v2)
    {
        return RANGE_ERROR;
    }
    if (!adjacencyMatrix_[v1][v2])
    {
        adjacencyMatrix_[v1][v2] = 1;
        adjacencyMatrix_[v2][v1] = 1;
        sideNum_++;
    }
    return SUCCESS;
}
template <class ElemType>
Status AdjacencyMatrixUndirectedGraph<ElemType>::DeleteVertex(const ElemType &e)
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
            sideNum_--;
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
template <class ElemType>
Status AdjacencyMatrixUndirectedGraph<ElemType>::DeleteSide(int v1, int v2)
{
    if (v1 < 0 || v1 >= vertexNum_ || v2 < 0 || v2 >= vertexNum_ || v1 == v2)
    {
        return RANGE_ERROR;
    }
    if (adjacencyMatrix_[v1][v2])
    {
        adjacencyMatrix_[v1][v2] = 0;
        adjacencyMatrix_[v2][v1] = 0;
        sideNum_--;
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
void AdjacencyMatrixUndirectedGraph<ElemType>::SetTag(int v, Status val)
{
    tags_[v] = val;
}
template <class ElemType>
int AdjacencyMatrixUndirectedGraph<ElemType>::GetVertexNum() const
{
    return vertexNum_;
}
template <class ElemType>
int AdjacencyMatrixUndirectedGraph<ElemType>::GetSideNum() const
{
    return sideNum_;
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
int AdjacencyMatrixUndirectedGraph<ElemType>::GetTag(int v) const
{
    return tags_[v];
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
        delete[] tags_;
        for (int i = 0; i < maxVertexNum_; i++)
        {
            delete[] adjacencyMatrix_[i];
        }
        delete[] adjacencyMatrix_;
        vertexNum_ = AMUG.vertexNum_;
        maxVertexNum_ = AMUG.maxVertexNum_;
        sideNum_ = AMUG.sideNum_;
        vertexes_ = new ElemType[maxVertexNum_];
        tags_ = new Status[maxVertexNum_];
        for (int i = 0; i < vertexNum_; i++)
        {
            vertexes_[i] = AMUG.vertexes_[i];
            tags_[i] = AMUG.tags_[i];
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