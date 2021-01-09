#include "Assistant.h"
template <class ElemType>
void QuickSort(ElemType *array, int length)
{
    static long long nComp = 0;
    static long long nAssign = 0;
    ElemType pivot, temp;
    int left = 0, right = length - 1;
    if (length <= 1)
    {
        return;
    }
    pivot = array[right];
    do
    {
        while (left < right && array[left] <= pivot)
        {
            left++;
            nComp++;
        }
        while (left < right && array[right] >= pivot)
        {
            right--;
            nComp++;
        }
        if (left < right)
        {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            nAssign += 3;
        }
    } while (left < right);
    array[length - 1] = array[left];
    array[left] = pivot;
    nAssign += 2;
    QuickSort(array, left);
    QuickSort(array + left + 1, length - left - 1);
}
int main()
{
    int array[N] = {0};
    Begin(array, N);
    QuickSort(array, N);
    End(array, N);
    return 0;
}