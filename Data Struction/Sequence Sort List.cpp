#include "Sequence Sort List.h"
int main()
{
    int elems[10] = {-10, 16, 2, -11, 0, 1, 5, 8, 43, 81};
    SequenceSortList<int> SSL;
    SSL = SequenceSortList<int>(elems, 10);
    cout << "The list is: ";
    SSL.Traverse(Write<int>);
    SSL.BubbleSort();
    cout << endl
         << "The list after bubble sort is: ";
    SSL.Traverse(Write<int>);
    SSL = SequenceSortList<int>(elems, 10);
    cout << endl
         << "The list is: ";
    SSL.Traverse(Write<int>);
    SSL.QuickSort(0, 9);
    cout << endl
         << "The list after qucik sort is: ";
    SSL.Traverse(Write<int>);
    SSL = SequenceSortList<int>(elems, 10);
    cout << endl
         << "The list is: ";
    SSL.Traverse(Write<int>);
    SSL.StraightInsertSort();
    cout << endl
         << "The list after straight insert sort is: ";
    SSL.Traverse(Write<int>);
    return 0;
}