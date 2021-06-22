#include "Link List.h"
int main()
{
    char functionSelect = 0;
    LinkList<int> list;
    LinkList<int> subList;
    int elem = 0;
    int i = 0;
    int minElem = 0;
    int maxElem = 0;
    while (functionSelect != '0')
    {
        cout << endl
             << "1. 生成链表。";
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
             << "a. 删除范围内的元素。";
        cout << endl
             << "b. 将两个链表合并为一个。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能（0~b）：";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            list.Clear();
            cout << endl
                 << "输入元素（输入0时退出）：";
            cin >> elem;
            while (elem)
            {
                list.AppendElem(elem);
                cin >> elem;
            }
            list.SwapElem(0, 5);
            break;
        case '2':
            list.Traverse();
            break;
        case '3':
            cout << endl
                 << "输入元素下标：";
            cin >> i;
            try
            {
                elem = list.GetElem(i);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "元素：" << elem << endl;
            break;
        case '4':
            cout << endl
                 << "输入元素下标：";
            cin >> i;
            cout << endl
                 << "输入元素：";
            cin >> elem;
            try
            {
                list.SetElem(i, elem);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "成功。" << endl;
            break;
        case '5':
            cout << endl
                 << "输入元素下标：";
            cin >> i;
            try
            {
                list.DeleteElem(i);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "成功。" << endl;
            break;
        case '6':
            cout << endl
                 << "输入元素下标：";
            cin >> i;
            cout << endl
                 << "输入元素：";
            cin >> elem;
            try
            {
                list.InsertElem(i, elem);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "成功。" << endl;
            break;
        case '7':
            cout << endl
                 << "输入元素：";
            cin >> elem;
            i = list.GetIndex(elem);
            if (i == -1)
            {
                cout << "元素不存在。" << endl;
            }
            else
            {
                cout << "下标是：" << i << endl;
            }
            break;
        case '8':
            cout << endl
                 << "长度是：" << list.GetLength() << endl;
            break;
        case '9':
            list.Reverse();
            break;
        case 'a':
            cout << endl
                 << "输入最小元素：";
            cin >> minElem;
            cout << "输入最大元素。、：";
            cin >> maxElem;
            try
            {
                list.DeleteBetween(minElem, maxElem);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "成功。" << endl;
            break;
        case 'b':
            subList.Clear();
            cout << endl
                 << "输入元素（输入0时退出）：";
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
