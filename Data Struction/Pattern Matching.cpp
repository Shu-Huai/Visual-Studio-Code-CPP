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
    if (j >= pat.length())
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}
void GetFailure(string &pat, int f[])
{
    int j = 0;
    int k = -1;
    f[0] = -1;
    while (j < pat.length() - 1)
    {
        if (k == -1 or pat[j] == pat[k])
        {
            j++;
            k++;
            f[j] = k;
        }
        else
        {
            k = f[k];
        }
    }
}
int KMP(string &ob, string &pat)
{
    int *f = new int[pat.length()];
    GetFailure(pat, f);
    int i = 0;
    int j = 0;
    while (j < pat.length() and i < ob.length() and pat.length() - j <= ob.length() - i)
    {
        if (j == -1 or ob[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            j = f[j];
        }
    }
    if (j >= pat.length())
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
    string pat = "ABCABCAAA";
    cout << BF(ob, pat) << endl;
    cout << KMP(ob, pat) << endl;
    return 0;
}