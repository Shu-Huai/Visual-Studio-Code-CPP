#include "Sequence Sort.h"
#include <iostream>
using namespace std;
int main()
{
    int resource[10] = {-10, 16, 2, -11, 0, 1, 5, 8, 43, 81};
    int elems[10] = {-10, 16, 2, -11, 0, 1, 5, 8, 43, 81};
    int length = 10;
    cout << "The list is:" << endl;
    for (int i = 0; i < length; i++)
    {
        elems[i] = resource[i];
        cout << elems[i] << " ";
    }
    SequenceSort<int>::BubbleSort(elems, length);
    cout << endl
         << "The list after bubble sort is:" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << elems[i] << " ";
    }
    cout << endl
         << "The list is:" << endl;
    for (int i = 0; i < length; i++)
    {
        elems[i] = resource[i];
        cout << elems[i] << " ";
    }
    SequenceSort<int>::QuickSort(elems, length);
    cout << endl
         << "The list after qucik sort is:" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << elems[i] << " ";
    }
    cout << endl
         << "The list is:" << endl;
    for (int i = 0; i < length; i++)
    {
        elems[i] = resource[i];
        cout << elems[i] << " ";
    }
    SequenceSort<int>::StraightInsertSort(elems, length);
    cout << endl
         << "The list after straight insert sort is:" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << elems[i] << " ";
    }
    cout << endl
         << "The list is:" << endl;
    for (int i = 0; i < length; i++)
    {
        elems[i] = resource[i];
        cout << elems[i] << " ";
    }
    SequenceSort<int>::BinaryInsertSort(elems, length);
    cout << endl
         << "The list after binary insert sort is:" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << elems[i] << " ";
    }
    cout << endl
         << "The list is:" << endl;
    for (int i = 0; i < length; i++)
    {
        elems[i] = resource[i];
        cout << elems[i] << " ";
    }
    SequenceSort<int>::ShellSort(elems, length);
    cout << endl
         << "The list after shell sort is:" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << elems[i] << " ";
    }
    cout << endl
         << "The list is:" << endl;
    int *temp = new int[10]{6, 23, 31, 58, 65, 79, 18, 27, 31, 43};
    for (int i = 0; i < length; i++)
    {
        elems[i] = temp[i];
        cout << elems[i] << " ";
    }
    delete[] temp;
    SequenceSort<int>::MergeSort(elems, length, 5);
    cout << endl
         << "The list after merge sort is:" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << elems[i] << " ";
    }
    cout << endl
         << "The list is:" << endl;
    for (int i = 0; i < length; i++)
    {
        elems[i] = resource[i];
        cout << elems[i] << " ";
    }
    SequenceSort<int>::MonkeySort(elems, length);
    cout << endl
         << "The list after monkey sort is:" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << elems[i] << " ";
    }
    return 0;
}