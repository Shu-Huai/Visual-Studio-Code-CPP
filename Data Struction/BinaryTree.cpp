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
    test0.LevelOrder(Write<int>);
    cout << endl
         << endl;
    test0.DeleteLeftChild(testnode0);
    test0.PreOrder(Write<int>);
    cout << endl;
    cout << test0.GetHeight() << endl;
    cout << test0.GetNLeafNumber() << endl;
    BinaryTree<int> test1(test0);
    BinaryTree<int> test2(testnode0);
    BinaryTree<string> test3;
    LinkQueue<string> LQ;
    string S[15] = {"0", "2", "6", "#", "#", "8", "#", "#", "4", "10", "#", "#", "12", "#", "#"};
    for (int i = 0; i < 15; i++)
    {
        LQ.EnQueue(S[i]);
    }
    test3.InitByPre(LQ);
    BinaryTree<string> test4(test3);
    test4.PreOrder(Write<string>);
    test4.~BinaryTree();
    LinkQueue<string> LQ0;
    S[0] = "1001";
    for (int i = 0; i < 15; i++)
    {
        LQ0.EnQueue(S[i]);
    }
    test4.InitByPre(LQ0);
    test4.PreOrder(Write<string>);
    return 0;
}