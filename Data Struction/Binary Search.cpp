#include "Assistance.h"
template <class ElemType>
int BinarySearch(ElemType *elems, int length, ElemType key)
{
    int low = 0;
    int high = length - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (elems[mid] == key)
        {
            return mid;
        }
        if (elems[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
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
    cout << "The result is: " << BinarySearch(elems, 9, input) << endl;
    return 0;
}