#include <iostream>
using namespace std;
int main()
{
    int radix = 0;
    string number;
    cin >> radix >> number;
    for (int i = 0; i < number.length(); i++)
    {
        char thisDigit = number[i];
        if (thisDigit != '0')
        {
            if (i)
            {
                cout << "+";
            }
            cout << thisDigit << "*" << radix << "^" << number.length() - 1 - i;
        }
    }
    cout << endl;
    return 0;
}