#include <iostream>
#include <string>
using namespace std;
int main()
{
    int p = 0;
    string s;
    while (getline(cin, s))
    {
        p++;
        cout << "Case " << p << ": ";
        s += " ";
        int i = s.length();
        if (s.length() == 0)
        {
            break;
        }
        int n = 0, sum = 0;
        for (int k = 0; k < s.length(); ++k)
        {
            if (s[k] >= 48 and s[k] <= 57)
            {
                if (s[k - 1] < 48 or s[k - 1] > 57)
                {
                    sum++;
                }
                if (s[k + 1] < 48 or s[k + 1] > 57)
                {
                    sum++;
                }
            }
        }
        cout << "(" << sum / 2 << ")";
        for (int k = 0; k < s.length(); ++k)
        {
            if (s[k] < 48 or s[k] > 57)
            {
                for (int f = k - n; f <= k - 1; ++f)
                {
                    if (s[f - 1] < 48 or s[f - 1] > 57)
                    {
                        cout << " ";
                    }
                    cout << s[f];
                }
                n = 0;
            }
            if (s[k] >= 48 and s[k] <= 57)
            {
                n++;
            }
        }
        int k = 0;
        cout << endl;
        s = "";
    }
    return 0;
}