#include <iomanip>
#include <iostream>
using namespace std;
long double GetFactorialByLoop(int number)
{
    if (number < 0)
    {
        return 0;
    }
    if (!number)
    {
        return 1;
    }
    int i = 0;
    long double result = 1;
    for (i = 0; i < number; i++)
    {
        result *= (i + 1);
    }
    return result;
}
long double GetFactorialByRecursion(long double number)
{
    if (number < 0)
    {
        return 0;
    }
    if (!number)
    {
        return 1;
    }
    return number * GetFactorialByRecursion(number - 1);
}
int main()
{
    int number = 0;
    cout << "请输入一个数：";
    cin >> number;
    cout << number << "!用循环求：";
    for (int i = number; i > 0; i--)
    {
        cout << i;
        if (i != 1)
        {
            cout << " * ";
        }
    }
    cout << " = " << fixed << setprecision(0) << GetFactorialByLoop(number) << endl;
    cout << number << "!用递归求：";
    for (int i = number; i > 0; i--)
    {
        cout << i;
        if (i != 1)
        {
            cout << " * ";
        }
    }
    cout << " = " << fixed << setprecision(0) << GetFactorialByRecursion(number) << endl;
    return 0;
}