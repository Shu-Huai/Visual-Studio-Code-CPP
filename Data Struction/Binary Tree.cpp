#include "Binary Tree.h"
int main()
{
    BinaryTree<int> test0(0);
    BinaryTreeNode<int> *testnode0 = test0.GetRoot();
    test0.InsertLeftChild(testnode0, 1);
    test0.InsertRightChild(testnode0, 2);
    BinaryTreeNode<int> *testnode1 = testnode0->leftChild_;
    test0.InsertLeftChild(testnode1, 3);
    test0.InsertRightChild(testnode1, 4);
    testnode0 = testnode0->rightChild_;
    test0.InsertLeftChild(testnode0, 5);
    test0.InsertRightChild(testnode0, 6);
    cout << "PreOrder: ";
    test0.PreOrderTraverse();
    cout << endl;
    cout << "InOrder: ";
    test0.InOrderTraverse();
    cout << endl;
    cout << "PostOrder: ";
    test0.PostOrderTraverse();
    cout << endl;
    cout << "LevelOrder: ";
    test0.LevelOrder();
    cout << endl;
    cout << "Width: ";
    cout << test0.GetWidth() << endl;
    cout << "Delete 5." << endl;
    test0.DeleteLeftChild(testnode0);
    cout << "PreOrder: ";
    test0.PreOrderTraverse();
    cout << endl;
    test0.GetMirror(test0.GetRoot());
    test0.PreOrderTraverse();
    cout << endl;
    cout << "Width: " << test0.GetWidth() << endl;
    cout << "Height: " << test0.GetHeight() << endl;
    cout << "LeafNumber: " << test0.GetNodeNumber() << endl;
    cout << "Clone." << endl;
    BinaryTree<int> test1(test0);
    test1.PreOrderTraverse();
    cout << endl;
    return 0;
}