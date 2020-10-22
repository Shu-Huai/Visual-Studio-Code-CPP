#include <iomanip>
#include <iostream>
using namespace std;
long double digui(long double n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0 or n == 1)
    {
        return 1;
    }
    return n * digui(n - 1);
}
int main()
{
    int i = 0;
    cout << "Please input a number: ";
    cin >> i;
    long double result = digui(i);
    for (int j = i; j > 0; j--)
    {
        cout << j << " * ";
    }
    cout << "\b\b\b"
         << " = " << fixed << setprecision(0) << result << endl;
    return 0;
}