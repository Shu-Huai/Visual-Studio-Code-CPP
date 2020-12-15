#include "SeqStack.h"
int main(void)
{
     char c = '*';
     SeqStack<int> la(6);
     int e, i;
     Status sta;
     double s = 0;
     double t = 0;
     while (c != '0')
     {
          cout << endl
               << "1. 生成顺序栈.";
          cout << endl
               << "2. 显示顺序栈.";
          cout << endl
               << "3. 取栈顶元素.";
          cout << endl
               << "4. 入栈.";
          cout << endl
               << "5. 出栈.";
          cout << endl
               << "6. 求顺序栈长度.";
          cout << endl
               << "选择功能(0~6):";
          cin >> c;
          switch (c)
          {
          case '1':
               la.Clear();
               sta = SUCCESS;
               cout << endl
                    << "输入e(e = 0时退出):";
               cin >> e;
               while (e != 0 && sta != OVER_FLOW)
               {
                    sta = la.Push(e);
                    if (sta == OVER_FLOW)
                    {
                         cout << "顺序栈已满." << endl;
                    }
                    else
                    {
                         cin >> e;
                    }
               }
               break;
          case '2':
               la.Traverse(Write<int>);
               break;
          case '3':
               if (la.Top(e) == UNDER_FLOW)
               {
                    cout << "顺序栈空." << endl;
               }
               else
               {
                    cout << "元素:" << e << endl;
               }
               break;
          case '4':
               cout << endl
                    << "输入e:";
               cin >> e;
               if (la.Push(e) == UNDER_FLOW)
               {
                    cout << "顺序栈空." << endl;
               }
               else
               {
                    cout << "已入栈." << endl;
               }
               break;
          case '5':
               if (la.Pop(e) == UNDER_FLOW)
               {
                    cout << "顺序栈空." << endl;
               }
               else
               {
                    cout << "已出栈." << endl
                         << "元素:" << e << endl;
               }
               break;
          case '6':
               cout << endl
                    << "顺序栈的长度为:" << la.GetLength() << endl;
               break;
          }
     }
     system("PAUSE");
     return 0;
}