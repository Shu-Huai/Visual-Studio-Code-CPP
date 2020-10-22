#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int a[100] = {0};
    int max = 0;
    int min = 1000;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < min)
        {
            min = a[i];
        }
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    cout << max - min << endl;
    return 0;
}