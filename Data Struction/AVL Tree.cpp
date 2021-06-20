#include "AVL Tree.h"
using namespace std;
int main()
{
    AVLTree<int> t1(-1);
    int data[] = {39, 11, 8, -1, -1, 23, -1, -1, 68, 46, -1, -1, 75, 71, -1, -1, -1};
    t1.InitializeByPreOrder(data, 17);
    int number = 0;
    t1.InOrderTraverse(Write<int>);
    cout << endl
         << "Please input the number: ";
    cin >> number;
    AVLTreeNode<int> *p = t1.LocateNode(number);
    if (p)
    {
        cout << "The element is: " << p->elem_ << endl;
    }
    else
    {
        cout << "The element does not exsit." << endl;
    }
    return 0;
}