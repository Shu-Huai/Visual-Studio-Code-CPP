#include "Very Long Int.cpp"
int main()
{
    while (1)
    {
        string stringFirstNumber = "";
        string stringSecondNumber = "";
        cin >> stringFirstNumber >> stringSecondNumber;
        VeryLongInt firstNumber(stringFirstNumber.c_str());
        VeryLongInt secondNumber(stringSecondNumber.c_str());
        (firstNumber + secondNumber).Show();
        cout << endl;
    }
    return 0;
}