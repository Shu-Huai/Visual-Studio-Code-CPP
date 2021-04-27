#include "Adjacency Matrix Undirected Network.h"
int main()
{
    // char vertexes[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    // AdjacencyMatrixUndirectedNetwork<char, int> ALDN(vertexes, 6);
    // ALDN.InsertEdge(0, 1, 34);
    // ALDN.InsertEdge(0, 2, 46);
    // ALDN.InsertEdge(0, 5, 19);
    // ALDN.InsertEdge(1, 4, 12);
    // ALDN.InsertEdge(2, 3, 17);
    // ALDN.InsertEdge(2, 5, 25);
    // ALDN.InsertEdge(3, 4, 38);
    // ALDN.InsertEdge(3, 5, 25);
    // ALDN.InsertEdge(4, 5, 26);
    // cout << "The adjacency matrix is:" << endl;
    // ALDN.Display();
    // cout << endl;
    // cout << "The Kruskal Minimum Spanning Tree is:" << endl;
    // ALDN.KruskalMinimumSpanningTree();
    // cout << endl;
    // cout << "The Prim Minimum Spanning Tree is:" << endl;
    // ALDN.PrimMinimumSpanningTree();
    // cout << endl;
    cout << endl
         << "T10 破圈法" << endl;
    char es4[6] = {'0', '1', '2', '3', '4', '5'};
    int arc3[6][6] = {
        {0, 6, 3, 5, 0, 0},
        {6, 0, 0, 1, 5, 0},
        {3, 0, 0, 6, 0, 6},
        {5, 1, 6, 0, 5, 4},
        {0, 5, 0, 5, 0, 2},
        {0, 0, 6, 4, 2, 0}};
    AdjacencyMatrixUndirectedNetwork<char, int> ALDN(es4, 6, 6);
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
    ALDN.Display();
    cout << "破圈法" << endl;
    ALDN.TearCycleMinimumSpanTree();
    return 0;
}