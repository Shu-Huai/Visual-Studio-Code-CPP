#include "SeqQueue.h"
int main()
{
     char c = 0;
     SeqQueue<int> SQ(10);
     int e = 0;
     while (c != '0')
     {
          cout << endl
               << "1. 生成队列.";
          cout << endl
               << "2. 显示队列.";
          cout << endl
               << "3. 入队列.";
          cout << endl
               << "4. 出队列.";
          cout << endl
               << "5. 取队列头.";
          cout << endl
               << "0. 退出";
          cout << endl
               << "选择功能(0~5):";
          cin >> c;
          switch (c)
          {
          case '1':
               SQ.Clear();
               cout << endl
                    << "输入e(e = 0时退出)";
               cin >> e;
               while (e != 0)
               {
                    SQ.EnQueue(e);
                    cin >> e;
               }
               break;
          case '2':
               cout << endl;
               SQ.Traverse(Write<int>);
               break;
          case '3':
               cout << endl
                    << "输入元素值:";
               cin >> e;
               if (SQ.EnQueue(e) == OVER_FLOW)
               {
                    cout << endl
                         << "队列已满!";
               }
               else
               {
                    cout << endl
                         << "入队成功.";
               }
               break;
          case '4':
               SQ.DelQueue(e);
               cout << endl
                    << "队头元素值为 " << e << " ." << endl;
               break;
          case '5':
               SQ.GetHead(e);
               cout << endl
                    << "队头元素值为 " << e << " ." << endl;
               break;
          }
     }
     system("PAUSE");
     return 0;
}