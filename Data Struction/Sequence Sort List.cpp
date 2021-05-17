#include "Sequence Sort List.h"
int main()
{
    int elems[10] = {-10, 16, 2, -11, 0, 1, 5, 8, 43, 81};
    SequenceSortList<int> SSL;
    SSL = SequenceSortList<int>(elems, 10);
    cout << "The list is: ";
    SSL.Traverse();
    SSL.BubbleSort();
    cout << endl
         << "The list after bubble sort is: ";
    SSL.Traverse();
    SSL = SequenceSortList<int>(elems, 10);
    cout << endl
         << "The list is: ";
    SSL.Traverse();
    SSL.QuickSort(0, 9);
    cout << endl
         << "The list after qucik sort is: ";
    SSL.Traverse();
    SSL = SequenceSortList<int>(elems, 10);
    cout << endl
         << "The list is: ";
    SSL.Traverse();
    SSL.StraightInsertSort();
    cout << endl
         << "The list after straight insert sort is: ";
    SSL.Traverse();
    SSL = SequenceSortList<int>(elems, 10);
    cout << endl
         << "The list is: ";
    SSL.Traverse();
    SSL.BinaryInsertSort();
    cout << endl
         << "The list after binary insert sort is: ";
    SSL.Traverse();
    return 0;
}