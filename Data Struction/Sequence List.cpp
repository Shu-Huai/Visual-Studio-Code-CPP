#include "Sequence List.h"
int main()
{
    char functionSelect = 0;
    SequenceList<int> SL;
    int elem = 0;
    int i = 0;
    double minimumValue = 0;
    double maximumValue = 0;
    while (functionSelect != '0')
    {
        cout << endl
             << "1. 生成顺序表。";
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
            SL.Clear();
            cout << endl
                 << "输入元素（输入0时停止）：";
            cin >> elem;
            while (elem)
            {
                try
                {
                    SL.AppendElem(elem);
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
            SL.Traverse();
            break;
        case '3':
            cout << endl
                 << "输入元素下标：";
            cin >> i;
            try
            {
                elem = SL.GetElem(i);
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
                SL.SetElem(i, elem);
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
                SL.DeleteElem(i);
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
                SL.InsertElem(i, elem);
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
            i = SL.GetIndex(elem);
            if (i != 0)
            {
                cout << "下标是：" << i << "。" << endl;
            }
            else
            {
                cout << "元素不存在。" << endl;
            }
            break;
        case '8':
            cout << endl
                 << "长度是：" << SL.GetLength() << endl;
            break;
        case '9':
            SL.DeleteRepeat();
            cout << endl
                 << "成功。" << endl;
            break;
        case 'a':
            SL.Reverse();
            cout << endl
                 << "成功。" << endl;
            break;
        case 'b':
            cout << endl
                 << "输入最小元素：";
            cin >> minimumValue;
            cout << "输入最大元素：";
            cin >> maximumValue;
            try
            {
                SL.DeleteBetween(minimumValue, maximumValue);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "删除" << minimumValue << "和" << maximumValue << "之间的元素。" << endl;
            break;
        case 'c':
            cout << endl;
            SL.Sort();
            cout << "成功。" << endl;
            break;
        }
    }
    return 0;
}