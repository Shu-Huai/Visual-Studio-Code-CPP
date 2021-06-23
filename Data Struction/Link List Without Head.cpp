#include "Link List Without Head.h"
int main()
{
    char functionSelect = 0;
    LinkListWithoutHead<int> list;
    LinkListWithoutHead<int> subList;
    int elem;
    int index;
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
             << "8. 取链表长度。";
        cout << endl
             << "9. 逆置。";
        cout << endl
             << "a. 将两个链表合并为一个。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能（0~a）：";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            list.Clear();
            cout << "输入元素（输入0时退出）：";
            cin >> elem;
            while (elem)
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
            if (index == -1)
            {
                cout << "元素不存在。" << endl;
            }
            else
            {
                cout << "下标是：" << index << endl;
            }
            break;
        case '8':
            cout << "长度是：" << list.GetLength() << endl;
            break;
        case '9':
            list.Reverse();
            cout << "成功。" << endl;
            break;
        case 'a':
            subList.Clear();
            cout << "输入元素（输入0时停止）：";
            cin >> elem;
            while (elem)
            {
                subList.AppendElem(elem);
                cin >> elem;
            }
            list.Merge(subList);
            break;
        }
    }
    return 0;
}
