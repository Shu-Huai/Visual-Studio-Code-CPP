#include "Binary Tree.h"
int main()
{
    char functionSelect = 0;
    BinaryTree<int> tree;
    BinaryTreeNode<int> node;
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
             << "6. 获取父元素。";
        cout << endl
             << "7. 获取左孩子。";
        cout << endl
             << "8. 获取右孩子。";
        cout << endl
             << "9. 获取左兄弟。";
        cout << endl
             << "a. 获取右兄弟。";
        cout << endl
             << "b. 获取高度。";
        cout << endl
             << "c. 获取宽度。";
        cout << endl
             << "d. 获取节点个数。";
        cout << endl
             << "e. 获取镜像树。";
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
            elem = -1;
            tree.CreateByPreOrder(elems, index, elem);
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
        case '6':
            cout << "输入元素：";
            cin >> elem;
            cout << "父元素：" << tree.GetElem(tree.GetParent(tree.GetNode(elem))) << "。" << endl;
            break;
        case '7':
            cout << "输入元素：";
            cin >> elem;
            try
            {
                cout << "左孩子元素：" << tree.GetElem(tree.GetLeftChild(tree.GetNode(elem))) << "。" << endl;
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            break;
        case '8':
            cout << "输入元素：";
            cin >> elem;
            try
            {
                cout << "右孩子元素：" << tree.GetElem(tree.GetRightChild(tree.GetNode(elem))) << "。" << endl;
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            break;
        case '9':
            cout << "输入元素：";
            cin >> elem;
            try
            {
                cout << "左兄弟元素：" << tree.GetElem(tree.GetLeftSibling(tree.GetNode(elem))) << "。" << endl;
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            break;
        case 'a':
            cout << "输入元素：";
            cin >> elem;
            try
            {
                cout << "右兄弟元素：" << tree.GetElem(tree.GetRightSibling(tree.GetNode(elem))) << "。" << endl;
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            break;
        case 'b':
            cout << "高度：" << tree.GetHeight() << "。" << endl;
            break;
        case 'c':
            cout << "宽度：" << tree.GetWidth() << "。" << endl;
            break;
        case 'd':
            cout << "节点个数：" << tree.GetNodeNumber() << "。" << endl;
            break;
        case 'e':
            tree.GetMirror();
            cout << "成功。" << endl;
            break;
        }
    }
    return 0;
}