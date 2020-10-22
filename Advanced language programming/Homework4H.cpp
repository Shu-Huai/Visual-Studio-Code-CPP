#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int n = 1;
    int case_ = 1;
    while (cin >> n)
    {
        cout << "Case " << case_ << ":" << endl;
        case_++;
        int a[52][52] = {0};
        int b = 1;
        int i = 1;
        if (n % 2 == 0)
        {
            b = n / 2;
            int j = 1;
            int k = 1;
            for (i = 1; i <= b; i++)
            {
                for (j = i; j <= n - i + 1; j++)
                {
                    for (k = i; k <= n - i + 1; k++)
                    {
                        a[j][k] = i;
                    }
                }
            }
        }
        else
        {
            b = n / 2 + 1;
            int j = 1;
            int k = 1;
            for (i = 1; i <= b; i++)
            {
                for (j = i; j <= n - i + 1; j++)
                {
                    for (k = i; k <= n - i + 1; k++)
                    {
                        a[j][k] = i;
                    }
                }
            }
        }
        int l = 1;
        int m = 1;
        for (l = 1; l <= n; l++)
        {
            for (m = 1; m < n; m++)
            {
                cout << a[l][m] << " ";
            }
            cout << a[l][n];
            cout << endl;
        }
    }
    return 0;
}