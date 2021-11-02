#include <iostream>
#include <stack>
using namespace std;
void DijkStraShortestPath(int sourceVertex, int vertexNumber, int **matrix, int *distance, int *path)
{
    int max = 1000;
    bool *isVisited = new bool[max]{false};
    for (int i = 0; i < vertexNumber; i++)
    {
        distance[i] = matrix[sourceVertex][i];
        if (distance[i] != max)
        {
            path[i] = sourceVertex + 1;
        }
        else
        {
            path[i] = 0;
        }
    }
    isVisited[sourceVertex] = true;
    distance[sourceVertex] = 0;
    for (int i = 0; i < vertexNumber - 1; i++)
    {
        int min = max;
        int k = sourceVertex;
        for (int j = 0; j < vertexNumber; j++)
        {
            if ((!isVisited[j]) && (distance[j] < min))
            {
                min = distance[j];
                k = j;
            }
        }
        isVisited[k] = true;
        for (int j = 0; j < vertexNumber; j++)
        {
            if ((!isVisited[j]) && (distance[j] > distance[k] + matrix[k][j]))
            {
                distance[j] = distance[k] + matrix[k][j];
                path[j] = k + 1;
            }
        }
    }
}
int main()
{
    int vertexNumber = 0;
    int count = 0;
    while (cin >> vertexNumber)
    {
        int **matrix = new int *[vertexNumber];
        for (int i = 0; i < vertexNumber; i++)
        {
            matrix[i] = new int[vertexNumber]{0};
        }
        for (int i = 0; i < vertexNumber; i++)
        {
            for (int j = 0; j < vertexNumber; j++)
            {
                int temp = 0;
                cin >> temp;
                matrix[i][j] = temp == -1 ? 1000 : temp;
            }
        }
        int sourceVertex = 0;
        int vertexNumber = 0;
        cin >> sourceVertex >> vertexNumber;
        int *distance = new int[vertexNumber]{0};
        int *path = new int[vertexNumber]{0};
        DijkStraShortestPath(sourceVertex - 1, vertexNumber, matrix, distance, path);
        for (int i = 0; i < vertexNumber; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        cout << "Case " << ++count << endl
             << "The least distance from " << sourceVertex << "->" << vertexNumber << " is " << distance[vertexNumber - 1] << endl
             << "the path is ";
        delete[] distance;
        int pre = path[vertexNumber - 1];
        stack<int> s;
        s.push(pre);
        while (pre)
        {
            pre = path[pre - 1];
            s.push(pre);
        }
        delete[] path;
        s.pop();
        while (!s.empty())
        {
            cout << s.top() << "->";
            s.pop();
        }
        cout << vertexNumber << endl;
    }
    return 0;
}