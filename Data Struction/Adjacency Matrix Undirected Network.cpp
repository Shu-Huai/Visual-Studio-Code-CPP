#include "Adjacency Matrix Undirected Network.h"
int main()
{
    char vertexes[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    AdjacencyMatrixUndirectedNetwork<char, int> ALDN(vertexes, 6);
    ALDN.InsertEdge(0, 1, 6);
    ALDN.InsertEdge(0, 2, 3);
    ALDN.InsertEdge(0, 3, 5);
    ALDN.InsertEdge(1, 3, 1);
    ALDN.InsertEdge(1, 4, 5);
    ALDN.InsertEdge(2, 3, 6);
    ALDN.InsertEdge(2, 5, 6);
    ALDN.InsertEdge(3, 4, 5);
    ALDN.InsertEdge(3, 5, 4);
    ALDN.InsertEdge(4, 5, 2);
    cout << "The adjacency matrix is:" << endl;
    ALDN.Display();
    cout << endl
         << "The Kruskal Minimum Spanning Tree is:" << endl;
    ALDN.KruskalMinimumSpanningTree();
    cout << endl
         << "The Prim Minimum Spanning Tree is:" << endl;
    ALDN.PrimMinimumSpanningTree();
    cout << endl
         << "The Tear Cycle Minimum Spanning Tree is:" << endl;
    ALDN.TearCycleMinimumSpanningTree();
    return 0;
}