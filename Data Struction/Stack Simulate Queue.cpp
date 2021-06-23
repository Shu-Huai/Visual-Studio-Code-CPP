#include "Stack Simulate Queue.h"
int main()
{
    char functionSelect = 0;
    StackSimulateQueue<int> queue;
    int elem = 0;
    while (functionSelect != '0')
    {
        cout << "1. 生成队列。";
        cout << endl
             << "2. 显示队列。";
        cout << endl
             << "3. 入队。";
        cout << endl
             << "4. 出队。";
        cout << endl
             << "5. 求队列长度。";
        cout << endl
             << "6. 判断列空。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能（0~6）：";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            queue.Clear();
            cout << "输入元素（输入0时退出）：";
            cin >> elem;
            while (elem)
            {
                queue.Push(elem);
                cin >> elem;
            }
            break;
        case '2':
            queue.Traverse();
            break;
        case '3':
            cout << "输入元素：";
            cin >> elem;
            queue.Push(elem);
            cout << "成功。" << endl;
            break;
        case '4':
            try
            {
                queue.Pop();
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "成功。" << endl;
            break;
        case '5':
            cout << "长度为：" << queue.GetLength() << "。" << endl;
            break;
        case '6':
            if (queue.IsEmpty())
            {
                cout << "列空。" << endl;
            }
            else
            {
                cout << "列非空。" << endl;
            }
            break;
        }
    }
    return 0;
}