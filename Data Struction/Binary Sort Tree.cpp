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
    int key = 0;
    while (functionSelect != '0')
    {
        cout << endl
             << "1. 插入元素。";
        cout << endl
             << "2. 查找元素。";
        cout << endl
             << "3. 删除元素。";
        cout << endl
             << "4. 先序遍历。";
        cout << endl
             << "5. 中序遍历。";
        cout << endl
             << "6. 后序遍历。";
        cout << endl
             << "7. 判断二叉树是否为二叉排序树。";
        cout << endl
             << "8. 输出不小于关键字的元素。";
        cout << endl
             << "9. 查找并插入。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能(0~8)：";
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
        case '7':
            cout << endl
                 << "这棵树" << (BST.IsBinarySortTree() ? "是" : "不是") << "二叉排序树。";
            break;
        case '8':
            cout << endl
                 << "请输入关键字：";
            cin >> key;
            BST.GetElemsAbove(key);
            break;
        case '9':
            cout << endl
                 << "请输入数据：";
            cin >> elem;
            BST.Insert_NoRecurve(elem);
            break;
        }
    }
    return 0;
}