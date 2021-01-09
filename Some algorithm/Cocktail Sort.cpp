#include "Assistant.h"
template <class ElemType>
void CocktailSort(ElemType *array, int length)
{
    int left = 0;
    int right = length - 1;
    int temppostion = 0;
    for (int i = 0; i < length - 1; i++)
    {
        int flag = 1;
        temppostion = 0;
        for (int j = left; j < right; j++)
        {
            if (array[j] > array[j + 1])
            {
                ElemType temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 0;
                temppostion = j;
            }
        }
        if (flag == 1)
        {
            break;
        }
        right = temppostion;
        for (int j = right; j > left; j--)
        {
            if (array[j] < array[j - 1])
            {
                ElemType temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                flag = 0;
                temppostion = j;
            }
        }
        left++;
        if (flag == 1)
        {
            break;
        }
    }
}
int main()
{
    int array[N] = {0};
    Begin(array, N);
    CocktailSort(array, N);
    End(array, N);
    return 0;
}