#include "Sequence List.h"
int main()
{
    char functionSelect = 0;
    SequenceList<int> list;
    int elem = 0;
    int index = 0;
    int minElem = 0;
    int maxElem = 0;
    while (functionSelect != '0')
    {
        cout << "1. 生成顺序表。";
        cout << endl
             << "2. 遍历顺序表。";
        cout << endl
             << "3. 取元素值。";
        cout << endl
             << "4. 设置元素值。";
        cout << endl
             << "5. 删除元素。";
        cout << endl
             << "6. 插入元素。";
        cout << endl
             << "7. 取元素下标。";
        cout << endl
             << "8. 取顺序表长度。";
        cout << endl
             << "9. 删除重复元素。";
        cout << endl
             << "a. 逆置。";
        cout << endl
             << "b. 删除范围内的元素。";
        cout << endl
             << "c. 排序。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能：（0~c）：";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            list.Clear();
            cout << "输入元素（输入0时停止）：";
            cin >> elem;
            while (elem)
            {
                try
                {
                    list.AppendElem(elem);
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
            if (index != 0)
            {
                cout << "下标是：" << index << "。" << endl;
            }
            else
            {
                cout << "元素不存在。" << endl;
            }
            break;
        case '8':
            cout << "长度是：" << list.GetLength() << endl;
            break;
        case '9':
            list.DeleteRepeat();
            cout << "成功。" << endl;
            break;
        case 'a':
            list.Reverse();
            cout << "成功。" << endl;
            break;
        case 'b':
            cout << "输入最小元素：";
            cin >> minElem;
            cout << "输入最大元素：";
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
            cout << "删除" << minElem << "和" << maxElem << "之间的元素。" << endl;
            break;
        case 'c':
            list.Sort();
            cout << "成功。" << endl;
            break;
        }
    }
    return 0;
}