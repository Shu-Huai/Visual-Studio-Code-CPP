#include <iostream>
using namespace std;
int BinarySearch(int (&a)[1000], int length, int key)
{
    int low = 0;
    int high = length - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    cout << "Please input an array: ";
    int a[1000] = {0};
    int i = 0;
    while (getchar() != '\n')
    {
        cin >> a[i];
        i++;
    }
    int x = 0;
    cout << "Please input the number: ";
    cin >> x;
    cout << "The result is: " << BinarySearch(a, i, x) << endl;
    return 0;
}