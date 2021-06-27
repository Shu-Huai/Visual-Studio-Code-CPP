#include "Binary Tree.h"
int main()
{
    char functionSelect = 0;
    BinaryTree<int> tree;
    int elems[1000];
    int elem = 0;
    int index = 0;
    while (functionSelect != '0')
    {
        cout << "1. 生成树。";
        cout << endl
             << "2. 前序遍历树。";
        cout << endl
             << "3. 中序遍历树。";
        cout << endl
             << "4. 后序遍历树。";
        cout << endl
             << "5. 层序遍历树。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能（0~7）：";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            tree.Clear();
            cout << "输入元素（输入0时退出）：";
            index = 0;
            cin >> elem;
            while (elem != 0)
            {
                elems[index++] = elem;
                cin >> elem;
            }
            tree.CreateByPreOrder(elems, index, -1);
            break;
        case '2':
            tree.PreOrderTraverse();
            break;
        case '3':
            tree.InOrderTraverse();
            break;
        case '4':
            tree.PostOrderTraverse();
            break;
        case '5':
            tree.LevelOrderTraverse();
            break;
        }
    }
    return 0;
}