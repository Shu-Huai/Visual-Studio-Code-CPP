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
void MergeSort(ElemType *elems, int low, int high)
{
    if (low < high)
    {
        int middle = (low + high) / 2;
        MergeSort(elems, low, middle);
        MergeSort(elems, middle + 1, high);
        Merge(elems, low, middle, high);
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
        MergeSort(elems, 0, n - 1);
        cout << "Case " << ++count << endl;
        for (int i = 0; i < n; i++)
        {
            cout << elems[i] << " ";
        }
        cout << endl;
    }
    return 0;
}