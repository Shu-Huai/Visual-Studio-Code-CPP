#include "Sort.h"
#include <iostream>
using namespace std;
int main()
{
    int resource[10] = {-10, 16, 2, -11, 0, 1, 5, 8, 43, 81};
    int length = 10;
    SequenceList<int> sequenceList;
    for (int i = 0; i < length; i++)
    {
        sequenceList.AppendElem(0);
        sequenceList[i] = resource[i];
    }
    cout << "The list is:" << endl;
    sequenceList.Traverse();
    Sort<int>::BubbleSort(sequenceList);
    cout << endl
         << "The list after bubble sort is:" << endl;
    sequenceList.Traverse();
    for (int i = 0; i < length; i++)
    {
        sequenceList[i] = resource[i];
    }
    cout << endl
         << "The list is:" << endl;
    sequenceList.Traverse();
    Sort<int>::QuickSort(sequenceList);
    cout << endl
         << "The list after qucik sort is:" << endl;
    sequenceList.Traverse();
    for (int i = 0; i < length; i++)
    {
        sequenceList[i] = resource[i];
    }
    cout << endl
         << "The list is:" << endl;
    sequenceList.Traverse();
    Sort<int>::StraightInsertSort(sequenceList);
    cout << endl
         << "The list after straight insert sort is:" << endl;
    sequenceList.Traverse();
    for (int i = 0; i < length; i++)
    {
        sequenceList[i] = resource[i];
    }
    cout << endl
         << "The list is:" << endl;
    sequenceList.Traverse();
    Sort<int>::BinaryInsertSort(sequenceList);
    cout << endl
         << "The list after binary insert sort is:" << endl;
    sequenceList.Traverse();
    for (int i = 0; i < length; i++)
    {
        sequenceList[i] = resource[i];
    }
    cout << endl
         << "The list is:" << endl;
    sequenceList.Traverse();
    Sort<int>::ShellSort(sequenceList);
    cout << endl
         << "The list after shell sort is:" << endl;
    sequenceList.Traverse();
    for (int i = 0; i < length; i++)
    {
        sequenceList[i] = resource[i];
    }
    cout << endl
         << "The list is:" << endl;
    sequenceList.Traverse();
    Sort<int>::MergeSort(sequenceList);
    cout << endl
         << "The list after merge sort is:" << endl;
    sequenceList.Traverse();
    for (int i = 0; i < length; i++)
    {
        sequenceList[i] = resource[i];
    }
    cout << endl
         << "The list is:" << endl;
    sequenceList.Traverse();
    Sort<int>::MergeSortWithRecursion(sequenceList);
    cout << endl
         << "The list after merge sort with recursion is:" << endl;
    sequenceList.Traverse();
    for (int i = 0; i < length; i++)
    {
        sequenceList[i] = resource[i];
    }
    cout << endl
         << "The list is:" << endl;
    sequenceList.Traverse();
    Sort<int>::MonkeySort(sequenceList);
    cout << endl
         << "The list after monkey sort is:" << endl;
    sequenceList.Traverse();
    DoubleLinkList<int> doubleLinkList;
    for (int i = 0; i < length; i++)
    {
        doubleLinkList.AppendElem(resource[i]);
    }
    cout << endl
         << "The list is:" << endl;
    doubleLinkList.Traverse();
    Sort<int>::BubbleSort(doubleLinkList);
    cout << endl
         << "The list after bubble sort is:" << endl;
    doubleLinkList.Traverse();
    for (int i = 0; i < length; i++)
    {
        sequenceList[i] = resource[i];
    }
    cout << endl
         << "The list is:" << endl;
    sequenceList.Traverse();
    Sort<int>::CountSort(sequenceList);
    cout << endl
         << "The list after count sort is:" << endl;
    sequenceList.Traverse();
    for (int i = 0; i < length; i++)
    {
        sequenceList[i] = resource[i];
    }
    cout << endl
         << "The list is:" << endl;
    sequenceList.Traverse();
    Sort<int>::QuickSortWithoutRecursion(sequenceList);
    cout << endl
         << "The list after qucik sort is:" << endl;
    sequenceList.Traverse();
    for (int i = 0; i < length; i++)
    {
        sequenceList[i] = resource[i];
    }
    cout << endl
         << "The list is:" << endl;
    sequenceList.Traverse();
    Sort<int>::TwoWayInsertSort(sequenceList);
    cout << endl
         << "The list after two way insert sort is:" << endl;
    sequenceList.Traverse();
    return 0;
}