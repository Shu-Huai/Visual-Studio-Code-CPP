#include <iostream>
using namespace std;
template <class ElemType>
void Merge(ElemType *elems, int low, int middle, int high)
{
    ElemType *result = new ElemType[high + 1];
    int i = low;
    int j = middle + 1;
    int k = low;
    while (i <= middle && j <= high)
    {
        if (elems[i] <= elems[j])
        {
            result[k] = elems[i];
            i++;
        }
        else
        {
            result[k] = elems[j];
            j++;
        }
        k++;
    }
    while (i <= middle)
    {
        result[k] = elems[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        result[k] = elems[j];
        k++;
        j++;
    }
    for (k = low; k <= high; k++)
    {
        elems[k] = result[k];
    }
    delete[] result;
}
template <class ElemType>
void MergePass(ElemType *x, ElemType *y, int size, int number)
{
    int i = 0;
    while (i <= number - 2 * size)
    {
        Merge(x, i, i + size - 1, i + 2 * size - 1);
        i = i + 2 * size;
    }
    if (i + size < number)
    {
        Merge(x, i, i + size - 1, number - 1);
    }
    else
    {
        for (int j = i; j <= number - 1; j++)
        {
            y[j] = x[j];
        }
    }
}
template <class ElemType>
void MergeSort(ElemType *elems, int number)
{
    ElemType *temp = new ElemType[number];
    int size = 1;
    while (size < number)
    {
        MergePass(elems, temp, size, number);
        size += size;
        MergePass(temp, elems, size, number);
        size += size;
    }
}
int main()
{
    int count = 0;
    int n = 0;
    while (cin >> n)
    {
        if (n <= 0)
        {
            break;
        }
        int *elems = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> elems[i];
        }
        MergeSort(elems, n);
        cout << "Case " << ++count << endl;
        for (int i = 0; i < n; i++)
        {
            cout << elems[i] << " ";
        }
        cout << endl;
    }
    return 0;
}