#include "SeqList.h" // 顺序表类

int main(void)
{
    char c = '*';
    SeqList<int> la(6);
    int e, i;
    Status sta;
    double s = 0;
    double t = 0;
    while (c != '0')
    {
        cout << endl
             << "1. 生成线性表.";
        cout << endl
             << "2. 显示线性表.";
        cout << endl
             << "3. 取指定元素.";
        cout << endl
             << "4. 设置元素值.";
        cout << endl
             << "5. 删除元素.";
        cout << endl
             << "6. 插入元素.";
        cout << endl
             << "7. 元素定位.";
        cout << endl
             << "8. 求线性表长度.";
        cout << endl
             << "9. 删除重复.";
        cout << endl
             << "a. 原地逆置.";
        cout << endl
             << "b. 删除s<e<t的结点.";
        cout << endl
             << "选择功能(0~8):";
        cin >> c;
        switch (c)
        {
        case '1':
            la.Clear();
            sta = SUCCESS;
            cout << endl
                 << "输入e(e = 0时退出):";
            cin >> e;
            while (e != 0 && sta != OVER_FLOW)
            {
                sta = la.InsertElem(e);
                if (sta == OVER_FLOW)
                    cout << "线性表已满." << endl;
                else
                    cin >> e;
            }
            break;
        case '2':
            la.Traverse(Write<int>);
            break;
        case '3':
            cout << endl
                 << "输入元素位置:";
            cin >> i;
            if (la.GetElem(i, e) == NOT_PRESENT)
                cout << "元素不存储." << endl;
            else
                cout << "元素:" << e << endl;
            break;
        case '4':
            cout << endl
                 << "输入位置:";
            cin >> i;
            cout << endl
                 << "输入元素值:";
            cin >> e;
            if (la.SetElem(i, e) == RANGE_ERROR)
                cout << "位置范围错." << endl;
            else
                cout << "设置成功." << endl;
            break;
        case '5':
            cout << endl
                 << "输入位置:";
            cin >> i;
            if (la.DeleteElem(i, e) == RANGE_ERROR)
                cout << "位置范围错." << endl;
            else
                cout << "被删除元素值:" << e << endl;
            break;
        case '6':
            cout << endl
                 << "输入位置:";
            cin >> i;
            cout << endl
                 << "输入元素值:";
            cin >> e;
            sta = la.InsertElem(i, e);

            if (sta == RANGE_ERROR)
                cout << "位置范围错." << endl;
            else if (sta == OVER_FLOW)
                cout << "线性表已满." << endl;
            else
                cout << "插入成功." << endl;
            break;
        case '7':
            cout << endl
                 << "输入元素值:";
            cin >> e;
            i = la.LocateElem(e);
            if (i != 0)
                cout << "元素" << e << "的序号为：" << i << endl;
            else
                cout << "元素" << e << "不存在。" << endl;
            break;
        case '8':
            cout << endl
                 << "线性表的长度为:" << la.GetLength() << endl;
            break;
        case '9':
            la.DeleteRepeat();
            cout << endl
                 << "已将线性表删除重复。" << endl;
            break;
        case 'a':
            la.Reverse();
            cout << endl
                 << "已将线性表逆置。" << endl;
            break;
            case 'b':
                cout << endl
                     << "输入s的值:";
                cin >> s;
                cout << "输入t的值:";
                cin >> t;
                if (la.DeleteBetween(s, t) == SUCCESS)
                {
                    cout << "已删除s<e<t的结点." << endl;
                }
                else
                {
                    cout << "错误." << endl;
                }
                break;
        }
    }

    system("PAUSE"); // 调用库函数system()，暂停程序运行
    return 0;        // 返回操作系统
}
