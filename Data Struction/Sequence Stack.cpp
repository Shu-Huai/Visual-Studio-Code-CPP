#include "Sequence Stack.h"
int main()
{
    char functionSelect = 0;
    SequenceStack<int> stack;
    int elem = 0;
    while (functionSelect != '0')
    {
        cout << "1. 生成栈。";
        cout << endl
             << "2. 遍历栈。";
        cout << endl
             << "3. 取栈顶元素。";
        cout << endl
             << "4. 入栈。";
        cout << endl
             << "5. 出栈。";
        cout << endl
             << "6. 取栈长度。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能（0~6）：";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            stack.Clear();
            cout << "输入元素（输入0时停止）：";
            cin >> elem;
            while (elem)
            {
                try
                {
                    stack.Push(elem);
                }
                catch (string &error)
                {
                    cout << error << endl;
                    break;
                }
            }
            break;
        case '2':
            stack.Traverse();
            break;
        case '3':
            try
            {
                elem = stack.GetTop();
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "元素是：" << elem << endl;
            break;
        case '4':
            cout << "输入元素：";
            cin >> elem;
            try
            {
                stack.Push(elem);
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
                stack.Pop();
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "成功。" << endl;
            break;
        case '6':
            cout << "栈的长度是：" << stack.GetLength() << endl;
            break;
        }
    }
    return 0;
}