#include "Share Space Sequence Stack.h"
int main()
{
    char functionSelect = 0;
    ShareSpaceSequenceStack<int> stacks;
    int elem = 0;
    int number = 0;
    while (functionSelect != '0')
    {
        cout << "1. 生成顺序栈。";
        cout << endl
             << "2. 显示顺序栈。";
        cout << endl
             << "3. 取栈顶元素。";
        cout << endl
             << "4. 入栈。";
        cout << endl
             << "5. 出栈。";
        cout << endl
             << "6. 求顺序栈长度。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能（0~6）：";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            cout << "输入栈号：";
            cin >> number;
            stacks.Clear(number);
            cout << "输入元素（输入0时退出）：";
            cin >> elem;
            while (elem)
            {
                try
                {
                    stacks.Push(elem, number);
                }
                catch (string &error)
                {
                    cout << error << endl;
                    break;
                }
                cin >> elem;
            }
            break;
        case '2':
            cout << "输入栈号：";
            cin >> number;
            stacks.Traverse(number);
            break;
        case '3':
            cout << "输入栈号：";
            cin >> number;
            try
            {
                elem = stacks.GetTop(number);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "元素：" << elem << endl;
            break;
        case '4':
            cout << "输入栈号：";
            cin >> number;
            cout << "输入elem：";
            cin >> elem;
            try
            {
                stacks.Push(number, elem);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "成功。" << endl;
            break;
        case '5':
            cout << "输入栈号：";
            cin >> number;
            try
            {
                stacks.Pop(number);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "成功。" << endl;
            break;
        case '6':
            cout << "输入栈号：";
            cin >> number;
            cout << "顺序栈的长度为：" << stacks.GetLength(number) << "。" << endl;
            break;
        }
    }
    return 0;
}