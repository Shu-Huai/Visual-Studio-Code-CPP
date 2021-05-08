#include "Adjacency Matrix Undirected Network.h"
int main()
{
    char vertexes[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    AdjacencyMatrixUndirectedNetwork<char, int> AMUN(vertexes, 6);
    AMUN.InsertEdge(0, 1, 6);
    AMUN.InsertEdge(0, 2, 3);
    AMUN.InsertEdge(0, 3, 5);
    AMUN.InsertEdge(1, 3, 1);
    AMUN.InsertEdge(1, 4, 5);
    AMUN.InsertEdge(2, 3, 6);
    AMUN.InsertEdge(2, 5, 6);
    AMUN.InsertEdge(3, 4, 5);
    AMUN.InsertEdge(3, 5, 4);
    AMUN.InsertEdge(4, 5, 2);
    cout << "The adjacency matrix is:" << endl;
    AMUN.Display();
    cout << endl
         << "The Kruskal Minimum Spanning Tree is:" << endl;
    AMUN.KruskalMinimumSpanningTree();
    cout << endl
         << "The Prim Minimum Spanning Tree is:" << endl;
    AMUN.PrimMinimumSpanningTree();
    cout << endl
         << "The Tear Cycle Minimum Spanning Tree is:" << endl;
    AMUN.TearCycleMinimumSpanningTree();
    return 0;
}