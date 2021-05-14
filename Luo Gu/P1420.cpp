#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int a[10000] = {0};
    int count = 1;
    int max = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] - a[i - 1] == 1)
        {
            count++;
        }
        else
        {
            count = 1;
        }
        if (count > max)
        {
            max = count;
        }
    }
    if (max > n)
    {
        max = n;
    }
    cout << max;
    return 0;
}