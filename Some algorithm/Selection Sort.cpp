#include "Assistant.h"
template <class ElemType>
void SelectionSort(ElemType *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        ElemType min = array[i];
        int index = i;
        for (int j = i + 1; j < length; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                index = j;
            }
        }
        array[index] = array[i];
        array[i] = min;
    }
}
int main()
{
    int array[N] = {0};
    Begin(array, N);
    SelectionSort(array, N);
    End(array, N);
    return 0;
}