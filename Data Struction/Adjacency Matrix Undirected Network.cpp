#include "Adjacency Matrix Undirected Network.h"
int main()
{
    char vertexes[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    AdjacencyMatrixUndirectedNetwork<char, int> ALDN(vertexes, 6);
    ALDN.InsertEdge(0, 1, 34);
    ALDN.InsertEdge(0, 2, 46);
    ALDN.InsertEdge(0, 5, 19);
    ALDN.InsertEdge(1, 4, 12);
    ALDN.InsertEdge(2, 3, 17);
    ALDN.InsertEdge(2, 5, 25);
    ALDN.InsertEdge(3, 4, 38);
    ALDN.InsertEdge(3, 5, 25);
    ALDN.InsertEdge(4, 5, 26);
    cout << "The adjacency matrix is:" << endl;
    ALDN.Display();
    cout << endl;
    cout << "The Kruskal Minimum Spanning Tree is:" << endl;
    ALDN.KruskalMinimumSpanningTree();
    cout << endl;
    cout << "The Prim Minimum Spanning Tree is:" << endl;
    ALDN.PrimMinimumSpanningTree();
    cout << endl;
    return 0;
}