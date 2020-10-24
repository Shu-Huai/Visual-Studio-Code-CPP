#include <iostream>
using namespace std;
bool judge(string &str)
{
    if (str[0] >= '0' and str[0] <= '9')
    {
        return 0;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (!(str[i] >= 'a' and str[i] <= 'z' or str[i] >= 'A' and str[i] <= 'Z' or str[i] >= '0' and str[i] <= '9' or str[i] == '_'))
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    string input;
    while (cin >> input)
    {
        if (input.length() != 0)
        {
            if (judge(input) == 1)
            {
                cout << "yes" << endl;
            }
            else if (judge(input) == 0)
            {
                cout << "no" << endl;
            }
        }
    }
    return 0;
}