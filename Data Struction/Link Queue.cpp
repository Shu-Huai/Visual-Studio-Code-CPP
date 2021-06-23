#include "Link Queue.h"
int main()
{
    char functionSelect = 0;
    LinkQueue<int> queue;
    int elem;
    while (functionSelect != '0')
    {
        cout << "1. 生成队列。";
        cout << endl
             << "2. 显示队列。";
        cout << endl
             << "3. 入队列。";
        cout << endl
             << "4. 出队列。";
        cout << endl
             << "5. 取队列头。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能（0~5）：";
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
            try
            {
                elem = queue.GetFront();
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "队头元素值为 " << elem << "。" << endl;
            break;
        }
    }
    return 0;
}
