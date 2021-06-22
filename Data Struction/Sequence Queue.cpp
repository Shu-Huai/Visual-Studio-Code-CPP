#include "Sequence Queue.h"
int main()
{
    char functionSelect = 0;
    SequenceQueue<int> queue(10);
    int elem = 0;
    while (functionSelect != '0')
    {
        cout << endl
             << "1. 生成队列。";
        cout << endl
             << "2. 显示队列。";
        cout << endl
             << "3. 入队列。";
        cout << endl
             << "4. 出队列。";
        cout << endl
             << "5. 取队列头。";
        cout << endl
             << "0. 退出";
        cout << endl
             << "选择功能（0~5）：";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            queue.Clear();
            cout << endl
                 << "输入元素（输入0时退出）：";
            cin >> elem;
            while (elem)
            {
                queue.Push(elem);
                cin >> elem;
            }
            break;
        case '2':
            cout << endl;
            queue.Traverse();
            break;
        case '3':
            cout << endl
                 << "输入元素值：";
            cin >> elem;
            try
            {
                queue.Push(elem);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "成功。" << endl;
            break;
        case '4':
            queue.Pop();
            cout << endl
                 << "成功。" << endl;
            break;
        case '5':
            elem = queue.GetFront();
            cout << endl
                 << "队头元素值为 " << elem << " 。" << endl;
            break;
        }
    }
    return 0;
}