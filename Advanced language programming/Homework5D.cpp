#include <iostream>
using namespace std;
int main()
{
    string s;
    int case_ = 0;
    while (getline(cin, s))
    {
        case_++;
        cout << "Case " << case_ << ": "
             << "\"";
        int i = s.length() - 1;
        while (i >= 0)
        {
            if ((s[i] < 0 or s[i] > 127) and (s[i - 1] < 0 or s[i - 1] > 127))
            {
                cout << s[i - 1] << s[i];
                i -= 2;
            }
            else
            {
                cout << s[i];
                i--;
            }
        }
        cout << "\"" << endl;
        for (int i = 0; i < s.length(); i++)
        {
            s[i] = 0;
        }
    }
    return 0;
}