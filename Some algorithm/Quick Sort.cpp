#include <iostream>
#include <time.h>
unsigned long long nComp = 0;
unsigned long long nAssign = 0;
using namespace std;

double gettime(int restart = 0)
{
    const double c = 1.0 / CLOCKS_PER_SEC;
    static long t = clock();
    if (restart)
        t = clock();
    return c * (clock() - t);
}
void basicquicksort(double *a, int size, int judge)
{
    double pivot, temp;
    int left = 0, right = size - 1;

    if (size <= 1)
        return;

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
    a[size - 1] = a[left];
    a[left] = pivot;
    nAssign += 2;
    basicquicksort(a, left, 0);
    basicquicksort(a + left + 1, size - left - 1, 0);
    if (judge == 1)
    {
        cout << "比较次数为：" << nComp << "次，赋值次数为：" << nAssign << "次。" << '\n';
    }
}

int main()
{
    double arr[500];
    int i = 0;
    while (cin.peek() != '\n')
    {
        cin >> arr[i++];
    }
    double t;
    gettime(1);
    basicquicksort(arr, i, 1);
    t = gettime(0);
    for (int k = 0; k < i; k++)
    {
        cout << arr[k] << " ";
    }
    cout << '\n';
    cout << "排序用时：" << t << "s" << '\n';
    return 0;
}