#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int inputNumber = 0;
    cin >> inputNumber;
    for (int i = 0; i < inputNumber; i++)
    {
        for (int j = 0; j < inputNumber; j++)
        {
            cout << setw(2) << setfill('0') << i * inputNumber + j + 1;
        }
        cout << endl;
    }
    cout << endl;
    int outputNumber = 1;
    for (int i = 0; i < inputNumber; i++)
    {
        for (int j = 0; j < inputNumber - i - 1; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << setw(2) << setfill('0') << outputNumber;
            outputNumber++;
        }
        cout << endl;
    }
    return 0;
}