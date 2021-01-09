#include "Assistant.h"
template <class ElemType>
int BinarySearch(ElemType *array, int length, ElemType x)
{
    int low = 0;
    int high = length - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == x)
        {
            return mid;
        }
        if (array[mid] < x)
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
    int array[N] = {0};
    InitRand(array, N);
    Sort(array, N);
    cout << "The resource is: " << endl;
    ShowData(array, N);
    ShowVision(array, N);
    int x = 0;
    cout << "Please input the number: ";
    cin >> x;
    cout << "The result is: " << BinarySearch(array, N, x) << endl;
    return 0;
}