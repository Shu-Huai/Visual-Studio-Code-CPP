#include "Assistance.h"
template <class ElemType>
int BinarySearch(ElemType *elems, ElemType key, int length)
{
    int low = 0;
    int high = length - 1;
    int middle = 0;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (elems[middle] == key)
        {
            return middle;
        }
        if (elems[middle] < key)
        {
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }
    return -1;
}
template <class ElemType>
int BinarySearch(ElemType *elems, ElemType key, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    int middle = (low + high) / 2;
    if (elems[middle] < key)
    {
        middle = BinarySearch(elems, key, middle + 1, high);
    }
    else if (elems[middle] > key)
    {
        middle = BinarySearch(elems, key, low, middle - 1);
    }
    return middle;
}
int main()
{
    int elems[9] = {-2, 4, 7, 10, 15, 18, 25, 36, 43};
    cout << "The resource is: " << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << elems[i] << " ";
    }
    cout << endl
         << "Please input the number: ";
    int input = 0;
    cin >> input;
    cout << "The result is: " << BinarySearch(elems, input, 9) << endl;
    cout << "The result is: " << BinarySearch(elems, input, 0, 8) << endl;
    return 0;
}