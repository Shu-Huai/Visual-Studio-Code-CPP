#include "Minimum Heap.h"
int main()
{
    char c = 0;
    int e = 0;
    MinimumHeap<int> MH;
    Status S;
    while (c != '0')
    {
        cout << endl
             << "1. 生成最小堆。";
        cout << endl
             << "2. 显示最小堆。";
        cout << endl
             << "3. 取堆顶元素。";
        cout << endl
             << "4. 删除堆顶元素。";
        cout << endl
             << "5. 插入元素。";
        cout << endl
             << "6. 求最小堆大小。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能(0~6)：";
        cin >> c;
        switch (c)
        {
        case '1':
            MH.Clear();
            S = SUCCESS;
            cout << endl
                 << "输入e(e = 0时退出)：";
            cin >> e;
            while (e != 0 && S != OVER_FLOW)
            {
                S = MH.InsertElem(e);
                if (S == OVER_FLOW)
                {
                    cout << "最小堆已满。" << endl;
                }
                else
                {
                    cin >> e;
                }
            }
            break;
        case '2':
            MH.Traverse(Write<int>);
            break;
        case '3':
            cout << endl;
            if (MH.GetTop(e) == UNDER_FLOW)
            {
                cout << "最小堆为空。" << endl;
            }
            else
            {
                cout << "元素：" << e << endl;
            }
            break;
        case '4':
            cout << endl;
            if (MH.DeleteTop(e) == UNDER_FLOW)
            {
                cout << "最小堆为空。" << endl;
            }
            else
            {
                cout << "被删除元素值：" << e << endl;
            }
            break;
        case '5':
            cout << endl
                 << "输入元素值：";
            cin >> e;
            S = MH.InsertElem(e);
            if (S == OVER_FLOW)
            {
                cout << "最小堆已满。" << endl;
            }
            else
            {
                cout << "插入成功。" << endl;
            }
            break;
        case '6':
            cout << endl
                 << "最小堆的大小为。" << MH.GetSize() << endl;
            break;
        }
    }
    return 0;
}