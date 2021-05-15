#include "Binary Sort Tree.h"
#include "Assistance.h"
int main()
{
    BinarySortTree<int> BST;
    int elems[] = {39, 68, 11, 23, 46, 34, 75, 86, 8, 71};
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        BST.InsertElem(elems[i]);
    }
    char functionSelect = 0;
    int elem = 0;
    while (functionSelect != '0')
    {
        cout << endl
             << "1. 插入元素。";
        cout << endl
             << "2. 查找元素。";
        cout << endl
             << "3. 删除元素方法一。";
        cout << endl
             << "4. 先序遍历。";
        cout << endl
             << "5. 中序遍历。";
        cout << endl
             << "6. 后序遍历。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能(0~7)：";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            cout << endl
                 << "输入插入元素的值：";
            cin >> elem;
            BST.InsertElem(elem);
            break;
        case '2':
            cout << endl
                 << "输入查找元素的值：";
            cin >> elem;
            if (!BST.Find(elem))
            {
                cout << endl
                     << "元素不存在。";
            }
            else
            {
                cout << endl
                     << "元素存在。";
            }
            break;
        case '3':
            cout << endl
                 << "输入删除元素的值：";
            cin >> elem;
            BST.DeleteElem(elem);
            break;
        case '4':
            cout << endl;
            BST.PreOrderTraverse(Write<int>);
            break;
        case '5':
            cout << endl;
            BST.InOrderTraverse(Write<int>);
            break;
        case '6':
            cout << endl;
            BST.PostOrderTraverse(Write<int>);
            break;
        }
    }
    return 0;
}