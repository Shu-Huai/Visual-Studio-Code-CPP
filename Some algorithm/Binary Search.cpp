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
    InitSeq(array, N);
    cout << "The resource is: " << endl;
    ShowData(array, N);
    ShowVision(array, N);
    cout << "Please input the number: ";
    int x = 0;
    cin >> x;
    cout << "The result is: " << BinarySearch(array, N, x) << endl;
    return 0;
}