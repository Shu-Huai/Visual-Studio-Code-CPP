#pragma once
#ifndef __ADJACENCY_LIST_DIRECTED_NETWORK_H__
#define __ADJACENCY_LIST_DIRECTED_NETWORK_H__
#include "Adjacency List Network Edge.h"
#include "Adjacency List Network Vertex.h"
#include <queue>
#include <stack>
using namespace std;
template <class ElemType, class WeightType>
class AdjacencyListDirectedNetwork
{
protected:
    int vertexNum_;
    int maxVertexNum_;
    int edgeNum_;
    AdjacencyListNetWorkVertex<ElemType, WeightType> *vertexes_;
    bool *isVisited_;
    WeightType infinity_;
    void DepthFirstSearch(int vertex);
    void BreadthFirstSearch(int vertex);

public:
    AdjacencyListDirectedNetwork(int maxVertexNum = 1000, WeightType infinity = (WeightType)1000000);
    AdjacencyListDirectedNetwork(ElemType *vertexes, int vertexNum, int maxVertexNum = 1000, WeightType infinity = (WeightType)1000000);
    AdjacencyListDirectedNetwork(const AdjacencyListDirectedNetwork<ElemType, WeightType> &network);
    virtual ~AdjacencyListDirectedNetwork();
    void Clear();
    bool IsEmpty();
    void Show();
    void DepthFirstTraverse();
    void BreadthFirstTraverse();
    void AppendVertex(const ElemType &data);
    void InsertEdge(int tailvertex, int headvertex, WeightType weigtht);
    void DeleteVertex(ElemType &data);
    void DeleteEdge(int tailvertex, int headvertex);
    void SetElem(int vertex, const ElemType &data);
    void SetVisited(int vertex, bool isVisited) const;
    void SetWeight(int tailvertex, int headvertex, WeightType w);
    int GetVertexNum() const;
    int GetEdgeNum() const;
    int GetIndex(ElemType &data) const;
    ElemType GetElem(int vertex) const;
    bool IsVisited(int vertex) const;
    int GetFirstAdjacencyVertex(int vertex) const;
    int GetNextAdjacencyVertex(int tailvertex, int headvertex) const;
    WeightType GetInfinity() const;
    WeightType GetWeight(int tailvertex, int headvertex) const;
    void DijkstraShortestPath(int sourceVertex) const;
    int GetInDegree(int vertex) const;
    void TopologicalSort() const;
    void CriticalPath() const;
    AdjacencyListDirectedNetwork<ElemType, WeightType> &operator=(const AdjacencyListDirectedNetwork<ElemType, WeightType> &network);
    template <class Elem, class Weight>
    friend ostream &operator<<(ostream &out, const AdjacencyListDirectedNetwork<Elem, Weight> &network);
};
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::DepthFirstSearch(int vertex)
{
    cout << vertexes_[vertex].elem_ << " ";
    isVisited_[vertex] = true;
    for (int i = GetFirstAdjacencyVertex(vertex); i != -1; i = GetNextAdjacencyVertex(vertex, i))
    {
        if (!isVisited_[i])
        {
            DepthFirstSearch(i);
        }
    }
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::BreadthFirstSearch(int vertex)
{
    cout << vertexes_[vertex].elem_ << " ";
    isVisited_[vertex] = true;
    queue<int> q;
    q.push(vertex);
    while (!q.empty())
    {
        vertex = q.front();
        q.pop();
        for (int i = GetFirstAdjacencyVertex(vertex); i != -1; i = GetNextAdjacencyVertex(vertex, i))
        {
            if (!isVisited_[i])
            {
                cout << vertexes_[i].elem_ << " ";
                isVisited_[i] = true;
                q.push(i);
            }
        }
    }
}
template <class ElemType, class WeightType>
AdjacencyListDirectedNetwork<ElemType, WeightType>::AdjacencyListDirectedNetwork(int maxVertexNum, WeightType infinity)
    : vertexNum_(0), maxVertexNum_(maxVertexNum), edgeNum_(0), infinity_(infinity)
{
    vertexes_ = new AdjacencyListNetWorkVertex<ElemType, WeightType>[maxVertexNum_];
    isVisited_ = new bool[maxVertexNum_];
}
template <class ElemType, class WeightType>
AdjacencyListDirectedNetwork<ElemType, WeightType>::AdjacencyListDirectedNetwork(ElemType *vertexes, int vertexNum, int maxVertexNum, WeightType infinity)
    : vertexNum_(vertexNum), maxVertexNum_(maxVertexNum), edgeNum_(0), infinity_(infinity)
{
    vertexes_ = new AdjacencyListNetWorkVertex<ElemType, WeightType>[maxVertexNum_];
    isVisited_ = new bool[maxVertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        vertexes_[i].elem_ = vertexes[i];
        vertexes_[i].firstEdge_ = NULL;
        isVisited_[i] = false;
    }
}
template <class ElemType, class WeightType>
AdjacencyListDirectedNetwork<ElemType, WeightType>::AdjacencyListDirectedNetwork(const AdjacencyListDirectedNetwork<ElemType, WeightType> &network)
    : vertexNum_(network.vertexNum_), maxVertexNum_(network.maxVertexNum_), edgeNum_(network.edgeNum_), infinity_(network.infinity_)
{
    vertexes_ = new AdjacencyListNetWorkVertex<ElemType, WeightType>[maxVertexNum_];
    isVisited_ = new int[maxVertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        vertexes_[i].elem_ = network.vertexes_[i].elem_;
        vertexes_[i].firstEdge_ = NULL;
        AdjacencyListNetworkEdge<WeightType> *p = network.vertexes_[i].firstEdge_;
        AdjacencyListNetworkEdge<WeightType> *q;
        while (p)
        {
            if (!vertexes_[i].firstEdge_)
            {
                vertexes_[i].firstEdge_ = new AdjacencyListNetworkEdge<WeightType>(p->vertex_, p->weight_);
                q = vertexes_[i].firstEdge_;
                p = p->nextEdge_;
            }
            else
            {
                q->nextEdge_ = new AdjacencyListNetworkEdge<WeightType>(p->vertex_, p->weight_);
                q = q->nextEdge_;
                p = p->nextEdge_;
            }
        }
        isVisited_[i] = network.isVisited_[i];
    }
}
template <class ElemType, class WeightType>
AdjacencyListDirectedNetwork<ElemType, WeightType>::~AdjacencyListDirectedNetwork()
{
    Clear();
    delete[] vertexes_;
    delete[] isVisited_;
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::Clear()
{
    AdjacencyListNetworkEdge<WeightType> *p;
    for (int i = 0; i < vertexNum_; i++)
    {
        p = vertexes_[i].firstEdge_;
        while (p != NULL)
        {
            vertexes_[i].firstEdge_ = p->nextEdge_;
            delete p;
            p = vertexes_[i].firstEdge_;
        }
    }
    vertexNum_ = 0;
    edgeNum_ = 0;
}
template <class ElemType, class WeightType>
bool AdjacencyListDirectedNetwork<ElemType, WeightType>::IsEmpty()
{
    return vertexNum_ == 0;
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::Show()
{
    AdjacencyListNetworkEdge<WeightType> *p;
    cout << "Vertex number is: " << vertexNum_ << ", "
         << "edge number is: " << edgeNum_ << "." << endl;
    for (int i = 0; i < vertexNum_; i++)
    {
        cout << i << ":\t" << vertexes_[i].elem_;
        p = vertexes_[i].firstEdge_;
        while (p)
        {
            cout << " ->( " << p->vertex_ << ", " << p->weight_ << " )";
            p = p->nextEdge_;
        }
        cout << endl;
    }
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::DepthFirstTraverse()
{
    for (int i = 0; i < vertexNum_; i++)
    {
        isVisited_[i] = false;
    }
    for (int i = 0; i < vertexNum_; i++)
    {
        if (!isVisited_[i])
        {
            DepthFirstSearch(i);
        }
    }
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::AppendVertex(const ElemType &data)
{
    if (vertexNum_ == maxVertexNum_)
    {
        throw(string) "Over flow.";
    }
    vertexes_[vertexNum_].elem_ = data;
    vertexes_[vertexNum_].firstEdge_ = NULL;
    isVisited_[vertexNum_] = false;
    vertexNum_++;
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::InsertEdge(int tailvertex, int headvertex, WeightType weight)
{
    if (tailvertex < 0 || tailvertex >= vertexNum_ || headvertex < 0 || headvertex >= vertexNum_)
    {
        throw(string) "Range error.";
    }
    if (tailvertex == headvertex)
    {
        throw(string) "Vertexes equal.";
    }
    AdjacencyListNetworkEdge<WeightType> *p = vertexes_[tailvertex].firstEdge_;
    vertexes_[tailvertex].firstEdge_ = new AdjacencyListNetworkEdge<WeightType>(headvertex, weight, p);
    edgeNum_++;
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::DeleteVertex(ElemType &data)
{
    int vertex = GetIndex(data);
    if (vertex == -1)
    {
        throw(string) "vertex does not exist.";
    }
    for (int i = 0; i < vertexNum_; i++)
    {
        if (i != vertex)
        {
            DeleteEdge(i, vertex);
        }
    }
    AdjacencyListNetworkEdge<WeightType> *p = vertexes_[vertex].firstEdge_;
    while (p)
    {
        vertexes_[vertex].firstEdge_ = p->nextEdge_;
        delete p;
        p = vertexes_[vertex].firstEdge_;
        edgeNum_--;
    }
    vertexes_[vertex].elem_ = vertexes_[vertexNum_].elem_;
    vertexes_[vertex].firstEdge_ = vertexes_[vertexNum_].firstEdge_;
    vertexes_[vertexNum_].firstEdge_ = NULL;
    isVisited_[vertex] = isVisited_[vertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        if (i != vertex)
        {
            p = vertexes_[i].firstEdge_;
            while (p != NULL)
            {
                if (p->vertex_ == vertexNum_)
                {
                    p->vertex_ = vertex;
                }
                p = p->nextEdge_;
            }
        }
    }
    vertexNum_--;
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::DeleteEdge(int tailvertex, int headvertex)
{
    if (tailvertex < 0 || tailvertex >= vertexNum_ || headvertex < 0 || headvertex >= vertexNum_)
    {
        throw(string) "Range error.";
    }
    if (tailvertex == headvertex)
    {
        throw(string) "Vertexes equal.";
    }
    AdjacencyListNetworkEdge<WeightType> *p = vertexes_[tailvertex].firstEdge_;
    AdjacencyListNetworkEdge<WeightType> *q;
    while (p && p->vertex_ != headvertex)
    {
        q = p;
        p = p->nextEdge_;
    }
    if (p)
    {
        if (vertexes_[tailvertex].firstEdge_ == p)
        {
            vertexes_[tailvertex].firstEdge_ = p->nextEdge_;
        }
        else
        {
            q->nextEdge_ = p->nextEdge_;
        }
        delete p;
        edgeNum_--;
    }
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::SetElem(int vertex, const ElemType &data)
{
    if (vertex < 0 || vertex >= vertexNum_)
    {
        throw(string) "Range error.";
    }
    vertexes_[vertex].elem_ = data;
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::SetVisited(int vertex, bool isVisited) const
{
    if (vertex < 0 || vertex >= vertexNum_)
    {
        throw(string) "Range error.";
    }
    isVisited_[vertex] = isVisited;
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::SetWeight(int tailvertex, int headvertex, WeightType weight)
{
    if (tailvertex < 0 || tailvertex >= vertexNum_ || headvertex < 0 || headvertex >= vertexNum_)
    {
        throw(string) "Range error.";
    }
    if (tailvertex == headvertex)
    {
        throw(string) "Vertexes equal.";
    }
    AdjacencyListNetworkEdge<WeightType> *p = vertexes_[tailvertex].firstEdge_;
    while (p && p->vertex_ != headvertex)
    {
        p = p->nextEdge_;
    }
    if (p)
    {
        p->weight_ = weight;
    }
}
template <class ElemType, class WeightType>
int AdjacencyListDirectedNetwork<ElemType, WeightType>::GetVertexNum() const
{
    return vertexNum_;
}
template <class ElemType, class WeightType>
int AdjacencyListDirectedNetwork<ElemType, WeightType>::GetEdgeNum() const
{
    return edgeNum_;
}
template <class ElemType, class WeightType>
int AdjacencyListDirectedNetwork<ElemType, WeightType>::GetIndex(ElemType &data) const
{
    for (int i = 0; i < vertexNum_; i++)
    {
        if (vertexes_[i].elem_ == data)
        {
            return i;
        }
    }
    return -1;
}
template <class ElemType, class WeightType>
ElemType AdjacencyListDirectedNetwork<ElemType, WeightType>::GetElem(int vertex) const
{
    if (vertex < 0 || vertex >= vertexNum_)
    {
        throw(string) "Range error.";
    }
    return vertexes_[vertex].elem_;
}
template <class ElemType, class WeightType>
bool AdjacencyListDirectedNetwork<ElemType, WeightType>::IsVisited(int vertex) const
{
    return isVisited_[vertex];
}
template <class ElemType, class WeightType>
int AdjacencyListDirectedNetwork<ElemType, WeightType>::GetFirstAdjacencyVertex(int vertex) const
{
    if (!vertexes_[vertex].firstEdge_)
    {
        return -1;
    }
    return vertexes_[vertex].firstEdge_->vertex_;
}
template <class ElemType, class WeightType>
int AdjacencyListDirectedNetwork<ElemType, WeightType>::GetNextAdjacencyVertex(int tailvertex, int headvertex) const
{
    AdjacencyListNetworkEdge<WeightType> *p = vertexes_[tailvertex].firstEdge_;
    while (p && p->vertex_ != headvertex)
    {
        p = p->nextEdge_;
    }
    if (!p || !p->nextEdge_)
    {
        return -1;
    }
    return p->nextEdge_->vertex_;
}
template <class ElemType, class WeightType>
WeightType AdjacencyListDirectedNetwork<ElemType, WeightType>::GetInfinity() const
{
    return infinity_;
}
template <class ElemType, class WeightType>
WeightType AdjacencyListDirectedNetwork<ElemType, WeightType>::GetWeight(int tailvertex, int headvertex) const
{
    AdjacencyListNetworkEdge<WeightType> *p = vertexes_[tailvertex].firstEdge_;
    while (p && p->vertex_ != headvertex)
    {
        p = p->nextEdge_;
    }
    if (p)
    {
        return p->weight_;
    }
    return infinity_;
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::DijkstraShortestPath(int sourceVertex) const
{
    int *path = new int[vertexNum_];
    WeightType *distance = new WeightType[vertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        distance[i] = GetWeight(sourceVertex, i);
        if (distance[i] == infinity_)
        {
            path[i] = -1;
        }
        else
        {
            path[i] = sourceVertex;
        }
        isVisited_[i] = false;
    }
    isVisited_[sourceVertex] = true;
    for (int i = 0; i < vertexNum_ - 1; i++)
    {
        WeightType minimumWeight = infinity_;
        int vertex = sourceVertex;
        for (int j = 0; j < vertexNum_; j++)
        {
            if (!isVisited_[j] && distance[j] < minimumWeight)
            {
                vertex = j;
                minimumWeight = distance[j];
            }
        }
        isVisited_[vertex] = true;
        for (int j = GetFirstAdjacencyVertex(vertex); j != -1; j = GetNextAdjacencyVertex(vertex, j))
        {
            if (!isVisited_[j] && minimumWeight + GetWeight(vertex, j) < distance[j])
            {
                distance[j] = minimumWeight + GetWeight(vertex, j);
                path[j] = vertex;
            }
        }
    }
    cout << "Path: ";
    for (int i = 0; i < vertexNum_; i++)
    {
        cout << path[i] << " ";
    }
    cout << endl
         << "Distance: ";
    for (int i = 0; i < vertexNum_; i++)
    {
        cout << distance[i] << " ";
    }
    delete[] path;
    delete[] distance;
}
template <class ElemType, class WeightType>
int AdjacencyListDirectedNetwork<ElemType, WeightType>::GetInDegree(int vertex) const
{
    int inDegree = 0;
    for (int i = 0; i < vertexNum_; i++)
    {
        AdjacencyListNetworkEdge<WeightType> *p = vertexes_[i].firstEdge_;
        while (p)
        {
            if (p->vertex_ == vertex)
            {
                inDegree++;
            }
            p = p->nextEdge_;
        }
    }
    return inDegree;
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::TopologicalSort() const
{
    int *inDegrees = new int[vertexNum_];
    stack<int> s;
    for (int i = 0; i < vertexNum_; i++)
    {
        inDegrees[i] = GetInDegree(i);
        if (!inDegrees[i])
        {
            s.push(i);
        }
    }
    int count = 0;
    while (!s.empty())
    {
        int vertex = s.top();
        s.pop();
        cout << vertexes_[vertex].elem_ << " ";
        count++;
        for (int i = GetFirstAdjacencyVertex(vertex); i != -1; i = GetNextAdjacencyVertex(vertex, i))
        {
            inDegrees[i]--;
            if (!inDegrees[i])
            {
                s.push(i);
            }
        }
    }
    cout << endl;
    delete[] inDegrees;
    if (count < vertexNum_)
    {
        throw(string) "The network has circle.";
    }
}
template <class ElemType, class WeightType>
void AdjacencyListDirectedNetwork<ElemType, WeightType>::CriticalPath() const
{
    int *inDegrees = new int[vertexNum_];
    stack<int> s;
    queue<int> q;
    WeightType *vertexEarly = new WeightType[vertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        inDegrees[i] = GetInDegree(i);
        if (!inDegrees[i])
        {
            q.push(i);
        }
        vertexEarly[i] = 0;
    }
    int count = 0;
    int vertex = 0;
    while (!q.empty())
    {
        vertex = q.front();
        q.pop();
        s.push(vertex);
        count++;
        for (int i = GetFirstAdjacencyVertex(vertex); i != -1; i = GetNextAdjacencyVertex(vertex, i))
        {
            inDegrees[i]--;
            if (!inDegrees[i])
            {
                q.push(i);
            }
            if (vertexEarly[vertex] + GetWeight(vertex, i) > vertexEarly[i])
            {
                vertexEarly[i] = vertexEarly[vertex] + GetWeight(vertex, i);
            }
        }
    }
    delete[] inDegrees;
    if (count < vertexNum_)
    {
        delete[] vertexEarly;
        throw(string) "The network has circle.";
    }
    vertex = s.top();
    s.pop();
    WeightType *vertexLate = new WeightType[vertexNum_];
    for (int i = 0; i < vertexNum_; i++)
    {
        vertexLate[i] = vertexEarly[vertex];
    }
    while (!s.empty())
    {
        vertex = s.top();
        s.pop();
        for (int i = GetFirstAdjacencyVertex(vertex); i != -1; i = GetNextAdjacencyVertex(vertex, i))
        {
            if (vertexLate[i] - GetWeight(vertex, i) < vertexLate[vertex])
            {
                vertexLate[vertex] = vertexLate[i] - GetWeight(vertex, i);
            }
        }
    }
    vector<WeightType> early;
    vector<WeightType> late;
    for (vertex = 0; vertex < vertexNum_; vertex++)
    {
        for (int i = GetFirstAdjacencyVertex(vertex); i != -1; i = GetNextAdjacencyVertex(vertex, i))
        {
            WeightType ee = vertexEarly[vertex];
            WeightType el = vertexLate[i] - GetWeight(vertex, i);
            early.push_back(ee);
            late.push_back(el);
            if (ee == el)
            {
                cout << "<" << vertexes_[vertex].elem_ << ", " << vertexes_[i].elem_ << "> ";
            }
        }
    }
    cout << endl
         << "ve: ";
    for (int i = 0; i < vertexNum_; i++)
    {
        cout << vertexEarly[i] << " ";
    }
    cout << endl
         << "vl: ";
    for (int i = 0; i < vertexNum_; i++)
    {
        cout << vertexLate[i] << " ";
    }
    cout << endl
         << "data: ";
    for (int i = 0; i < edgeNum_; i++)
    {
        cout << early[i] << " ";
    }
    cout << endl
         << "l: ";
    for (int i = 0; i < edgeNum_; i++)
    {
        cout << late[i] << " ";
    }
    delete[] vertexEarly;
    delete[] vertexLate;
}
template <class ElemType, class WeightType>
AdjacencyListDirectedNetwork<ElemType, WeightType> &AdjacencyListDirectedNetwork<ElemType, WeightType>::operator=(const AdjacencyListDirectedNetwork<ElemType, WeightType> &network)
{
    if (&network != this)
    {
        Clear();
        delete[] vertexes_;
        delete[] isVisited_;
        vertexNum_ = network.vertexNum_;
        maxVertexNum_ = network.maxVertexNum_;
        edgeNum_ = network.edgeNum_;
        infinity_ = network.infinity_;
        vertexes_ = new AdjacencyListNetWorkVertex<ElemType, WeightType>[maxVertexNum_];
        isVisited_ = new bool[maxVertexNum_];
        for (int i = 0; i < vertexNum_; i++)
        {
            vertexes_[i].data = network.vertexes_[i].data;
            vertexes_[i].firstEdge_ = NULL;
            AdjacencyListNetworkEdge<WeightType> *p = network.vertexes_[i].firstEdge_;
            AdjacencyListNetworkEdge<WeightType> *q;
            while (p)
            {
                if (!vertexes_[i].firstEdge_)
                {
                    vertexes_[i].firstEdge_ = new AdjacencyListNetworkEdge<WeightType>(p->vertex_, p->weight_);
                    q = vertexes_[i].firstEdge_;
                    p = p->nextEdge_;
                }
                else
                {
                    q->nextEdge_ = new AdjacencyListNetworkEdge<WeightType>(p->vertex_, p->weight_);
                    q = q->nextEdge_;
                    p = p->nextEdge_;
                }
            }
            isVisited_[i] = network.isVisited_[i];
        }
    }
    return *this;
}
template <class ElemType, class WeightType>
ostream operator<<(ostream &out, const AdjacencyListDirectedNetwork<ElemType, WeightType> &network)
{
    AdjacencyListNetworkEdge<WeightType> *p;
    out << "Vertex number is: " << network.vertexNum_ << ", "
        << "edge number is: " << network.edgeNum_ << "." << endl;
    for (int i = 0; i < network.vertexNum_; i++)
    {
        out << i << ":\t" << network.vertexes_[i].elem_;
        p = network.vertexes_[i].firstEdge_;
        while (p)
        {
            out << " ->( " << p->vertex_ << ", " << p->weight_ << " )";
            p = p->nextEdge_;
        }
        out << endl;
    }
    return out;
}
#endif