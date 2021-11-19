#include <iostream>
using namespace std;
template <class ElemType>
void QuickSort(ElemType *elems, int low, int high)
{
    if (low < high)
    {
        ElemType referenceValue = elems[low];
        int i = low;
        int j = high;
        while (i < j)
        {
            while (i < j && elems[j] >= referenceValue)
            {
                j--;
            }
            if (i < j)
            {
                elems[i] = elems[j];
                i++;
            }
            while (i < j && elems[i] <= referenceValue)
            {
                i++;
            }
            if (i < j)
            {
                elems[j] = elems[i];
                j--;
            }
        }
        elems[i] = referenceValue;
        QuickSort(elems, low, i - 1);
        QuickSort(elems, i + 1, high);
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
        QuickSort(elems, 0, n - 1);
        cout << "Case " << ++count << endl;
        for (int i = 0; i < n; i++)
        {
            cout << elems[i] << " ";
        }
        cout << endl;
    }
    return 0;
}