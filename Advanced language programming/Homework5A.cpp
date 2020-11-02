#include <iostream>
using namespace std;
bool judge(string &s)
{
    for (int j = 0; j < s.length() / 2; j++)
    {
        if (s[j] != s[s.length() - 1 - j])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int case_ = 0;
    cin >> case_;
    for (int i = 0; i < case_; i++)
    {
        string input;
        if (i == 0)
        {
            getchar();
        }
        getline(cin, input);
        cout << "Case " << i + 1 << ": ";
        if (judge(input))
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
        cout << endl;
    }
    return 0;
}