#include "Link Stack.h"
int main()
{
    char functionSelect = 0;
    LinkStack<int> stack;
    int elem;
    while (functionSelect != '0')
    {
        cout << "1. 生成栈。";
        cout << endl
             << "2. 遍历栈。";
        cout << endl
             << "3. 入栈。";
        cout << endl
             << "4. 出栈。";
        cout << endl
             << "5. 取栈顶元素。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能（0~5）：";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            stack.Clear();
            cout << "输入元素（输入0时退出）：" << endl;
            cin >> elem;
            while (elem != 0)
            {
                stack.Push(elem);
                cin >> elem;
            }
            break;
        case '2':
            stack.Traverse();
            break;
        case '3':
            cout << "输入元素：";
            cin >> elem;
            stack.Push(elem);
            break;
        case '4':
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
        case '5':
            try
            {
                elem = stack.GetTop();
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "元素：" << elem << endl;
            break;
        }
    }
    return 0;
}