#include "SeqList.h"
int main()
{
    char c = 0;
    SeqList<int> SL;
    int e = 0;
    int i = 0;
    Status S=SUCCESS;
    double low = 0;
    double high = 0;
    while (c != '0')
    {
        cout << endl
             << "1. 生成顺序表。";
        cout << endl
             << "2. 显示顺序表。";
        cout << endl
             << "3. 取指定元素。";
        cout << endl
             << "4. 设置元素值。";
        cout << endl
             << "5. 删除元素。";
        cout << endl
             << "6. 插入元素。";
        cout << endl
             << "7. 元素定位。";
        cout << endl
             << "8. 求顺序表长度。";
        cout << endl
             << "9. 删除重复。";
        cout << endl
             << "a. 原地逆置。";
        cout << endl
             << "b. 删除处在指定范围内的元素。";
        cout << endl
             << "c. 排序。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能(0~c)：";
        cin >> c;
        switch (c)
        {
        case '1':
            SL.Clear();
            cout << endl
                 << "输入e(e = 0时退出)：";
            cin >> e;
            while (e != 0 && S != OVER_FLOW)
            {
                S = SL.AppendElem(e);
                if (S == OVER_FLOW)
                {
                    cout << "顺序表已满。" << endl;
                }
                else
                {
                    cin >> e;
                }
            }
            break;
        case '2':
            SL.Traverse(Write<int>);
            break;
        case '3':
            cout << endl
                 << "输入元素位置：";
            cin >> i;
            if (SL.GetElem(i, e) == NOT_PRESENT)
            {
                cout << "元素不存储。" << endl;
            }
            else
            {
                cout << "元素：" << e << endl;
            }
            break;
        case '4':
            cout << endl
                 << "输入位置：";
            cin >> i;
            cout << endl
                 << "输入元素值：";
            cin >> e;
            if (SL.SetElem(i, e) == RANGE_ERROR)
            {
                cout << "位置范围错。" << endl;
            }
            else
            {
                cout << "设置成功。" << endl;
            }
            break;
        case '5':
            cout << endl
                 << "输入位置：";
            cin >> i;
            if (SL.DeleteElem(i, e) == RANGE_ERROR)
            {
                cout << "位置范围错。" << endl;
            }
            else
            {
                cout << "被删除元素值：" << e << endl;
            }
            break;
        case '6':
            cout << endl
                 << "输入位置：";
            cin >> i;
            cout << endl
                 << "输入元素值：";
            cin >> e;
            S = SL.InsertElem(i, e);
            if (S == RANGE_ERROR)
            {
                cout << "位置范围错。" << endl;
            }
            else if (S == OVER_FLOW)
            {
                cout << "顺序表已满。" << endl;
            }
            else
            {
                cout << "插入成功。" << endl;
            }
            break;
        case '7':
            cout << endl
                 << "输入元素值：";
            cin >> e;
            i = SL.LocateElem(e);
            if (i != 0)
            {
                cout << "元素" << e << "的序号为：" << i << endl;
            }
            else
            {
                cout << "元素" << e << "不存在。" << endl;
            }
            break;
        case '8':
            cout << endl
                 << "顺序表的长度为：" << SL.GetLength() << endl;
            break;
        case '9':
            SL.DeleteRepeat();
            cout << endl
                 << "已将顺序表删除重复。" << endl;
            break;
        case 'a':
            SL.Reverse();
            cout << endl
                 << "已将顺序表逆置。" << endl;
            break;
        case 'b':
            cout << endl
                 << "输入删除范围的最小值：";
            cin >> low;
            cout << "输入删除范围的最大值：";
            cin >> high;
            S = SL.DeleteBetween(low, high);
            if (S == SUCCESS)
            {
                cout << "已删除" << low << " < " << e << " < " << high << "的结点。" << endl;
            }
            else if (S == UNDER_FLOW)
            {
                cout << "顺序表为空。" << endl;
            }
            else
            {
                cout << "范围错。" << endl;
            }
            break;
        case 'c':
            cout << endl;
            SL.Sort();
            cout << "已将顺序表排序。" << endl;
            break;
        }
    }
    return 0;
}