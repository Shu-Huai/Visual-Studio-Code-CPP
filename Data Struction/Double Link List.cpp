#include "Double Link List.h"
int main()
{
    char functionSelect = 0;
    DoubleLinkList<double> list;
    double elem = 0;
    int index = 0;
    while (functionSelect != '0')
    {
        cout << "1. 生成链表。";
        cout << endl
             << "2. 遍历链表。";
        cout << endl
             << "3. 取元素。";
        cout << endl
             << "4. 设元素。";
        cout << endl
             << "5. 删除元素。";
        cout << endl
             << "6. 插入元素。";
        cout << endl
             << "7. 取元素下标。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能（0~7）：";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            list.Clear();
            cout << "输入元素（输入0时退出）：";
            cin >> elem;
            while (elem != 0)
            {
                list.AppendElem(elem);
                cin >> elem;
            }
            break;
        case '2':
            list.Traverse();
            break;
        case '3':
            cout << "输入元素下标：";
            cin >> index;
            try
            {
                elem = list.GetElem(index);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "元素：" << elem << endl;
            break;
        case '4':
            cout << "输入元素下标：";
            cin >> index;
            cout << "输入元素：";
            cin >> elem;
            try
            {
                list.SetElem(index, elem);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "成功。" << endl;
            break;
        case '5':
            cout << "输入元素下标：";
            cin >> index;
            try
            {
                list.DeleteElem(index);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "成功。" << endl;
            break;
        case '6':
            cout << "输入元素下标：";
            cin >> index;
            cout << "输入元素：";
            cin >> elem;
            try
            {
                list.InsertElem(index, elem);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "成功。" << endl;
            break;
        case '7':
            cout << "输入元素：";
            cin >> elem;
            index = list.GetIndex(elem);
            if (index == 0)
                cout << "元素不存在。" << endl;
            else
                cout << "下标是：" << index << endl;
            break;
        }
    }
    return 0;
}
