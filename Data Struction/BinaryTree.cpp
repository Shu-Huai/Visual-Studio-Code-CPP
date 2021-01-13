#include "BinaryTree.h"
int main()
{
    BinaryTree<int> test0(0);
    BinaryTreeNode<int> *testnode0 = test0.GetRoot();
    test0.InsertLeftChild(testnode0, 1);
    test0.InsertRightChild(testnode0, 2);
    BinaryTreeNode<int> *testnode1 = testnode0->leftchild_;
    test0.InsertLeftChild(testnode1, 3);
    test0.InsertRightChild(testnode1, 4);
    testnode0 = testnode0->rightchild_;
    test0.InsertLeftChild(testnode0, 5);
    test0.InsertRightChild(testnode0, 6);
    test0.PreOrder(Write<int>);
    cout << endl;
    test0.InOrder(Write<int>);
    cout << endl;
    test0.PostOrder(Write<int>);
    cout << endl;
    return 0;
}