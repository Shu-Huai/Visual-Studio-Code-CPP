#include <iostream>
#include <stack>
using namespace std;
int AkmWithRecursion(int m, int n)
{
    if (!m)
    {
        return n + 1;
    }
    if (!n)
    {
        return AkmWithRecursion(m - 1, 1);
    }
    return AkmWithRecursion(m - 1, AkmWithRecursion(m, n - 1));
}
int Akm(int m, int n)
{
    stack<int> s;
    s.push(m);
    s.push(n);
    int tempM = 0;
    int tempN = 0;
    while (!s.empty())
    {
        tempN = s.top();
        s.pop();
        if (s.empty())
        {
            break;
        }
        tempM = s.top();
        s.pop();
        if (!tempM)
        {
            s.push(tempN + 1);
        }
        else if (!tempN)
        {
            s.push(tempM - 1);
            s.push(1);
        }
        else
        {
            s.push(tempM - 1);
            s.push(tempM);
            s.push(tempN - 1);
        }
    }
    return tempN;
}
int main()
{
    cout << "Please input m and n: ";
    int m = 0;
    int n = 0;
    while (cin >> m >> n)
    {
        if (m == -1 && n == -1)
        {
            cout << "Exit." << endl;
            break;
        }
        cout << "Akm with recusion is: " << AkmWithRecursion(m, n) << endl
             << "Akm without recursion is: " << Akm(m, n) << endl
             << "Please input m and n: ";
    }
    return 0;
}