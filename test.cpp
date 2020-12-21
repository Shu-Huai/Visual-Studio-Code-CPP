#include <iostream>
using namespace std;
int Find(string &A, string &B)
{
    int i = 0;
    int j = 0;
    while (i < A.length() and j < B.length())
    {
        if (A[i] == B[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == B.length())
    {
        return i - j;
    }
    return -1;
}
int main()
{
    string A = "ZWWZWZ";
    string B = "ZWZ";
    cout << Find(A, B);
    return 0;
}