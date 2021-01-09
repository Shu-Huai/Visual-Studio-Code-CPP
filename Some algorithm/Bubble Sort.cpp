#include "Assistant.h"
template <class ElemType>
void BubbleSort(ElemType *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                ElemType temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int array[N] = {0};
    Begin(array, N);
    BubbleSort(array, N);
    End(array, N);
    return 0;
}