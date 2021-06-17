#include "Adjacency List Directed Network.h"
int main()
{
    int infinity = 1000000;
    int elems[] = {0, 1, 2, 3, 4, 5};
    int m[6][6] = {
        {infinity, 45, 50, 15, infinity, infinity},
        {infinity, infinity, 5, infinity, 20, 15},
        {infinity, infinity, infinity, infinity, infinity, infinity},
        {10, 10, infinity, infinity, 79, infinity},
        {infinity, 30, infinity, infinity, infinity, infinity},
        {infinity, infinity, infinity, infinity, 20, infinity}};
    char functionSelect = 0;
    int e, e1, e2;
    int n = 6;
    int v, v1, v2, w;
    AdjacencyListDirectedNetwork<int, int> network(elems, n);
    for (int v = 0; v < n; v++)
    {
        for (int u = 0; u < n; u++)
        {
            if (m[v][u] != infinity)
            {
                network.InsertEdge(v, u, m[v][u]);
            }
        }
    }
    while (functionSelect != '0')
    {
        cout << endl
             << "1. Empty the directed net.";
        cout << endl
             << "2. Show directed net.";
        cout << endl
             << "3. Take the value of the specified vertex.";
        cout << endl
             << "4. Set the value of the specified vertex.";
        cout << endl
             << "5. Delete specified vertices.";
        cout << endl
             << "6. Insert vertex.";
        cout << endl
             << "7. Delete edge.";
        cout << endl
             << "8. Insert edge.";
        cout << endl
             << "9. Set the right of the specified edge.";
        cout << endl
             << "a. Find the shortest path with Dijkstra's method.";
        cout << endl
             << "b. Find the vertex in-degree.";
        cout << endl
             << "c. Topological sort.";
        cout << endl
             << "d. Find the critical path.";
        cout << endl
             << "0. Exit.";
        cout << endl
             << "Select funstion(0~d): ";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            network.Clear();
            break;
        case '2':
            if (network.IsEmpty())
                cout << "The directed net is empty." << endl;
            else
                network.Show();
            break;
        case '3':
            cout << endl
                 << "Enter the vertex number (the vertex number of the directed network starts from 0): ";
            cin >> v;
            e = network.GetElem(v);
            cout << "The vertex is: " << e;
            break;
        case '4':
            cout << endl
                 << "Enter the vertex number (the vertex number of the directed network starts from 0): ";
            cin >> v;
            cout << endl
                 << "Please input the value: ";
            cin >> e;
            network.SetElem(v, e);
            break;
        case '5':
            cout << endl
                 << "Enter the value of the deleted vertex: ";
            cin >> e;
            network.DeleteVertex(e);
            break;
        case '6':
            cout << endl
                 << "Enter the value of the inserted vertex: ";
            cin >> e;
            network.AppendVertex(e);
            break;
        case '7':
            cout << endl
                 << "Enter the two vertex values associated with the edge: ";
            cin >> e1 >> e2;
            v1 = network.GetIndex(e1);
            v2 = network.GetIndex(e2);
            network.DeleteEdge(v1, v2);
            break;
        case '8':
            cout << endl
                 << "Enter the two vertex values associated with the edge and the weight of the edge: ";
            cin >> e1 >> e2 >> w;
            v1 = network.GetIndex(e1);
            v2 = network.GetIndex(e2);
            network.InsertEdge(v1, v2, w);
            break;
        case '9':
            cout << endl
                 << "Enter the two vertex values associated with the edge and the weight of the edge: ";
            cin >> e1 >> e2 >> w;
            v1 = network.GetIndex(e1);
            v2 = network.GetIndex(e2);
            network.SetWeight(v1, v2, w);
            break;
        case 'a':
            cout << endl
                 << "Use Dijkstra's algorithm to find the shortest path." << endl;
            network.DijkstraShortestPath(0);
            break;
        case 'b':
            cout << endl
                 << "Enter the vertex: ";
            cin >> e;
            cout << "The indegree is: " << network.GetInDegree(network.GetIndex(e)) << endl;
            break;
        case 'c':
            cout << endl
                 << "Topological sort: " << endl;
            try
            {
                network.TopologicalSort();
            }
            catch (string &error)
            {
                cout << error << endl;
            }
            break;
        case 'd':
            cout << endl
                 << "Find the critical path." << endl;
            try
            {
                network.CriticalPath();
            }
            catch (string &error)
            {
                cout << error << endl;
            }
            break;
        }
    }
    return 0;
}