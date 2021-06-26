#include "Generalized List.h"
int main()
{
    char functionSelect = 0;
    GeneralizedList<char> list;
    GeneralizedList<char> subList;
    char elem;
    int index;
    while (functionSelect != '0')
    {
        cout << "1. 生成广义表。";
        cout << endl
             << "2. 显示广义表。";
        cout << endl
             << "3. 在表头插入原子元素。";
        cout << endl
             << "4. 在表头插入子表元素。";
        cout << endl
             << "5. 删除元素。";
        cout << endl
             << "6. 求广义表的深度。";
        cout << endl
             << "7. 求广义表的长度。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能（0~7）：";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            cout << "请输入广义表：";
            list.Create();
            cout << "成功。" << endl;
            break;
        case '2':
            list.Display();
            cout << endl;
            break;
        case '3':
            cout << "输入原子元素：";
            cin >> elem;
            list.Insert(elem);
            break;
        case '4':
            getchar();
            cout << "请输入子表：";
            subList.Create();
            list.Insert(subList);
            cout << "成功。" << endl;
            break;
        case '5':
            cout << "输入元素下标：";
            cin >> index;
            try
            {
                list.Delete(index);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "成功。" << endl;
            break;
        case '6':
            cout << "深度为：" << list.GetDepth() << "。" << endl;
            break;
        case '7':
            cout << "长度为：" << list.GetLength() << "。" << endl;
            break;
        }
    }
    return 0;
}