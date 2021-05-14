#include <iostream>
using namespace std;
int erfen(int (&a)[1000], int length, int key)
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
    static int case_ = 0;
    int x = 0;
    while (cin >> x)
    {
        case_++;
        int a[1000] = {0};
        int i = 0;
        getchar();
        do
        {
            cin >> a[i];
            i++;
        } while (getchar() != '\n');
        cout << "Case " << case_ << ": " << x << ", " << erfen(a, i, x) << endl;
    }
    return 0;
}