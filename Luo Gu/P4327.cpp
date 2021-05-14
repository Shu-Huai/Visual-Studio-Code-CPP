#include <iostream>
using namespace std;
void OutputFirstAndFifthLine(int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "..";
        if ((i + 1) % 3)
        {
            cout << "#";
        }
        else
        {
            cout << "*";
        }
        cout << ".";
    }
    cout << "." << endl;
}
void OutputSecondAndFourthLine(int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << ".";
            if ((i + 1) % 3)
            {
                cout << "#";
            }
            else
            {
                cout << "*";
            }
        }
    }
    cout << "." << endl;
}
void OutputThirdLine(int length, string inputString)
{
    for (int i = 0; i < length; i++)
    {
        if ((i + 1) % 3 && i % 3 || !i)
        {
            cout << "#";
        }
        else
        {
            cout << "*";
        }
        cout << "." << inputString[i] << ".";
    }
    if (length % 3)
    {
        cout << "#" << endl;
    }
    else
    {
        cout << "*" << endl;
    }
}
int main()
{
    string inputString;
    cin >> inputString;
    int length = inputString.length();
    OutputFirstAndFifthLine(length);
    OutputSecondAndFourthLine(length);
    OutputThirdLine(length, inputString);
    OutputSecondAndFourthLine(length);
    OutputFirstAndFifthLine(length);
    return 0;
}