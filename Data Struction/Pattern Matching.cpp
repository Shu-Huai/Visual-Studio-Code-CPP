#include <cstring>
#include <iostream>
using namespace std;
int BFPatternMatching(string &ob, string &pat)
{
    int i = 0;
    int j = 0;
    while (j < int(pat.length()) && i < int(ob.length()) && int(pat.length()) - j <= int(ob.length()) - i)
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
    if (j >= int(pat.length()))
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
    while (j < int(pat.length()) - 1)
    {
        if (k == -1 || pat[j] == pat[k])
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
int KMPPatternMatching(string &ob, string &pat)
{
    int *f = new int[pat.length()];
    GetFailure(pat, f);
    int i = 0;
    int j = 0;
    while (j < int(pat.length()) && i < int(ob.length()) && int(pat.length()) - j <= int(ob.length()) - i)
    {
        if (j == -1 || ob[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            j = f[j];
        }
    }
    if (j >= int(pat.length()))
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
    cout << BFPatternMatching(ob, pat) << endl;
    cout << KMPPatternMatching(ob, pat) << endl;
    return 0;
}