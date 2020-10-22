#include <iostream>
using namespace std;
void QuickSort(int *a, int length)
{
    static long long nComp = 0;
    static long long nAssign = 0;
    int pivot, temp;
    int left = 0, right = length - 1;
    if (length <= 1)
    {
        return;
    }
    pivot = a[right];
    do
    {
        while (left < right && a[left] <= pivot)
        {
            left++;
            nComp++;
        }
        while (left < right && a[right] >= pivot)
        {
            right--;
            nComp++;
        }
        if (left < right)
        {
            temp = a[left];
            a[left] = a[right];
            a[right] = temp;
            nAssign += 3;
        }
    } while (left < right);
    a[length - 1] = a[left];
    a[left] = pivot;
    nAssign += 2;
    QuickSort(a, left);
    QuickSort(a + left + 1, length - left - 1);
}
int main()
{
    cout << "Please input an array:";
    int a[1000] = {0};
    int i = 0;
    do
    {
        cin >> a[i];
        i++;
    } while (getchar() != '\n');
    QuickSort(a, i);
    cout << "The result is: ";
    for (int j = 0; j < i; j++)
    {
        cout << a[j];
        if (j != i - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
    return 0;
}