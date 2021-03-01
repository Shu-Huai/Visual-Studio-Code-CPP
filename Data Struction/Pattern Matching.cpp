#include <cstring>
#include <iostream>
using namespace std;
int BF(string &ob, string &pat)
{
    int i = 0;
    int j = 0;
    while (j < pat.length() and i < ob.length() and pat.length() - j <= ob.length() - i)
    {
        if (ob[i] == pat[j])
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
    if (j == pat.length())
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}
int main()
{
    string ob = "ZWWZWZ";
    string pat = "ZWZ";
    cout << BF(ob, pat);
    return 0;
}