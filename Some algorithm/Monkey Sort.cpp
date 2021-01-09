#define __USE_OWN_N__
#include "Assistant.h"
#define N 10
template <class ElemType>
void MonkeySort(ElemType *array, int length)
{
    bool judge = 0;
    ElemType *result = new ElemType[length]{0};
    while (!judge)
    {
        bool *flag = new bool[length]{1};
        for (int i = 0; i < length; i++)
        {
            flag[i] = 1;
        }
        for (int i = 0; i < length; i++)
        {
            int t = rand() % length;
            if (flag[t])
            {
                result[i] = array[t];
                flag[t] = 0;
            }
            else
            {
                i--;
            }
        }
        judge = 1;
        for (int i = 0; i < length - 1; i++)
        {
            if (result[i] > result[i + 1])
            {
                judge = 0;
            }
        }
        delete[] flag;
    }
    for (int i = 0; i < length; i++)
    {
        array[i] = result[i];
    }
    delete[] result;
}
int main()
{
    int array[N] = {0};
    Begin(array, N);
    MonkeySort(array, N);
    End(array, N);
    return 0;
}