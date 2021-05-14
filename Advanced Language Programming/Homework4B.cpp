#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int a[1000] = {0};
    int i = 1;
    int case_ = 1;
    while (cin >> a[i])
    {
        char c = 'e';
        while (c != '\n')
        {
            i++;
            cin >> a[i];
            c = getchar();
        }
        for (int p = 1; p < i; p++)
        {
            for (int q = p + 1; q <= i; q++)
            {
                if (a[p] < a[q])
                {
                    int temp;
                    temp = a[p];
                    a[p] = a[q];
                    a[q] = temp;
                }
            }
        }
        cout << "Case " << case_ << ": ";
        if (i <= 10)
        {
            int j = 1;
            for (j = 1; j <= i; j++)
            {
                cout << a[j];
                if (j < i)
                {
                    cout << ", ";
                }
            }
        }
        else
        {
            int j = 1;
            for (j = 1; j <= 10; j++)
            {
                cout << a[j];
                if (j < 10)
                {
                    cout << ", ";
                }
            }
            i = 11;
        }
        cout << endl;
        case_++;
    }
    return 0;
}