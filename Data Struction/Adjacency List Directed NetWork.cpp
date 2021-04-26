#include "Adjacency List Directed Network.h"
int main()
{
     // int infinity = DEFAULT_INFINITY;
     // int vexs[] = {0, 1, 2, 3, 4, 5};
     // int m[6][6] = {
     //     {infinity, 45, 50, 15, infinity, infinity},
     //     {infinity, infinity, 5, infinity, 20, 15},
     //     {infinity, infinity, infinity, infinity, infinity, infinity},
     //     {10, 10, infinity, infinity, 79, infinity},
     //     {infinity, 30, infinity, infinity, infinity, infinity},
     //     {infinity, infinity, infinity, infinity, 20, infinity}};
     // char functionSelect = 0;
     // int e, e1, e2;
     // int n = 6, v, v1, v2, w;
     // int distance[6];
     // int path[6];
     // AdjacencyListDirectedNetwork<int, int> ALDN(vexs, n);
     // for (int v = 0; v < n; v++)
     // {
     //      for (int u = 0; u < n; u++)
     //      {
     //           if (m[v][u] != infinity)
     //           {
     //                ALDN.InsertEdge(v, u, m[v][u]);
     //           }
     //      }
     // }
     int infinity = DEFAULT_INFINITY;
     int vexs[] = {0, 1, 2, 3, 4, 5};
     int m[6][6] = {
         {infinity, infinity, 1, 1, infinity, infinity},
         {1, infinity, infinity, infinity, 1, infinity},
         {infinity, infinity, infinity, 1, infinity, infinity},
         {infinity, infinity, infinity, infinity, infinity, infinity},
         {1, infinity, infinity, infinity, infinity, infinity},
         {infinity, infinity, 1, 1, 1, infinity}};
     char functionSelect = 0;
     int e, e1, e2;
     int n = 6, v, v1, v2, w;
     int distance[6];
     int path[6];
     AdjacencyListDirectedNetwork<int, int> ALDN(vexs, n);
     for (int v = 0; v < n; v++)
     {
          for (int u = 0; u < n; u++)
          {
               if (m[v][u] != infinity)
               {
                    ALDN.InsertEdge(v, u, m[v][u]);
               }
          }
     }
     while (functionSelect != '0')
     {
          cout << endl
               << "1. 有向网清空。";
          cout << endl
               << "2. 显示有向网。";
          cout << endl
               << "3. 取指定顶点的值。";
          cout << endl
               << "4. 设置指定顶点的值。";
          cout << endl
               << "5. 删除顶点。";
          cout << endl
               << "6. 插入顶点。";
          cout << endl
               << "7. 删除边。";
          cout << endl
               << "8. 插入边。";
          cout << endl
               << "9. 设置指定边的权。";
          cout << endl
               << "a. 迪杰斯特拉法求最短路径。";
          cout << endl
               << "b. 求顶点入度。";
          cout << endl
               << "c. 拓扑排序。";
          cout << endl
               << "0. 退出。";
          cout << endl
               << "选择功能(0~b)：";
          cin >> functionSelect;
          switch (functionSelect)
          {
          case '1':
               ALDN.Clear();
               break;
          case '2':
               if (ALDN.IsEmpty())
                    cout << "该有向网为空。" << endl;
               else
                    ALDN.Display();
               break;
          case '3':
               cout << endl
                    << "输入顶点序号（有向网的顶点序号从0开始）：";
               cin >> v;
               ALDN.GetElem(v, e);
               cout << "序号为" << v << "的顶点为" << e;
               break;
          case '4':
               cout << endl
                    << "输入顶点序号（有向网的顶点序号从0开始）：";
               cin >> v;
               cout << endl
                    << "输入" << v << "号顶点的值：";
               cin >> e;
               ALDN.SetElem(v, e);
               break;
          case '5':
               cout << endl
                    << "输入被删除顶点的值：";
               cin >> e;
               ALDN.DeleteVertex(e);
               break;
          case '6':
               cout << endl
                    << "输入插入顶点的值：";
               cin >> e;
               ALDN.AppendVertex(e);
               break;
          case '7':
               cout << endl
                    << "输入与被删除边关联的两个顶点值：";
               cin >> e1 >> e2;
               v1 = ALDN.GetIndex(e1);
               v2 = ALDN.GetIndex(e2);
               ALDN.DeleteEdge(v1, v2);
               break;
          case '8':
               cout << endl
                    << "输入与插入边关联的两个顶点值和边的权值：";
               cin >> e1 >> e2 >> w;
               v1 = ALDN.GetIndex(e1);
               v2 = ALDN.GetIndex(e2);
               ALDN.InsertEdge(v1, v2, w);
               break;
          case '9':
               cout << endl
                    << "输入与插入边关联的两个顶点值和边的权值：";
               cin >> e1 >> e2 >> w;
               v1 = ALDN.GetIndex(e1);
               v2 = ALDN.GetIndex(e2);
               ALDN.SetWeight(v1, v2, w);
               break;
          case 'a':
               cout << endl
                    << "使用迪杰斯特拉算法求最短路径。" << endl;
               ALDN.DijkstraShortestPath(0, path, distance);
               cout << "前驱顶点：";
               Display(path, 6);
               cout << "Distance: ";
               Display(distance, 6);
               break;
          case 'b':
               cout << endl
                    << "输入顶点：";
               cin >> e;
               cout << "顶点入度：" << ALDN.GetInDegree(ALDN.GetIndex(e)) << endl;
               break;
          case 'c':
               cout << endl
                    << "拓扑排序：" << endl;
               ALDN.TopologicalSort();
               cout << endl;
          }
     }
     return 0;
}