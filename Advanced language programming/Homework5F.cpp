#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int case_ = 0;
    string str1;
    string str2;
    while (getline(cin, str1))
    {
        int index = 0;
        int n = 0;
        case_++;
        cout << "Case " << case_ << ": ";
        getline(cin, str2);
        for (int i = 0; i < str2.length(); i++)
        {
            if (str1[0] == str2[i])
            {
                index = i;
                n++;
                while (str1[n] == str2[i + n] and n < str1.length())
                {
                    n++;
                }
                if (n != str1.length())
                {
                    n = 0;
                }
                else
                {
                    break;
                }
            }
        }
        if (n == str1.length())
        {
            cout << index << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}