#include "LinkStack.h"
int main()
{
    char c = 0;
    LinkStack<int> LS;
    int x;
    while (c != '0')
    {
        cout << endl
             << "1. 生成栈.";
        cout << endl
             << "2. 显示栈.";
        cout << endl
             << "3. 入栈.";
        cout << endl
             << "4. 出栈.";
        cout << endl
             << "5. 取栈顶.";
        cout << endl
             << "0. 退出";
        cout << endl
             << "选择功能(0~5):";
        cin >> c;
        switch (c)
        {
        case '1':
            LS.Clear();
            cout << "输入e(e = 0时退出)" << endl;
            cin >> x;
            while (x != 0)
            {
                LS.Push(x);
                cin >> x;
            }
            break;
        case '2':
            cout << endl;
            LS.Traverse(Write<int>);
            break;
        case '3':
            cout << endl
                 << "输入元素值:";
            cin >> x;
            LS.Push(x);
            break;
        case '4':
            if (LS.Pop(x) == SUCCESS)
            {
                cout << endl
                     << "栈顶元素值为：" << x << "." << endl;
            }
            else
            {
                cout << endl
                     << "栈为空." << endl;
            }
            break;
        case '5':
            if (LS.Top(x) == SUCCESS)
            {
                cout << endl
                     << "栈顶元素值为：" << x << "." << endl;
            }
            else
            {
                cout << endl
                     << "栈为空." << endl;
            }
            break;
        }
    }
    system("PAUSE");
    return 0;
}