#include "AVL Tree.h"
using namespace std;
int main()
{
    AVLTree<int> t1(-1);
    int data[] = {39, 11, 8, -1, -1, 23, -1, -1, 68, 46, -1, -1, 75, 71, -1, -1, -1};
    t1.CreateTreeByPreOrder(data, 17);
    int n = 5;
    AVLTreeNode<int> *p = t1.LocateNode(n);
    t1.InOrderTraverse(Write<int>);
    if (p)
    {
        cout << "第" << n << "小的结点是: " << p->data_ << endl;
    }
    else
    {
        cout << "找不到结点!" << endl;
    }
    return 0;
}