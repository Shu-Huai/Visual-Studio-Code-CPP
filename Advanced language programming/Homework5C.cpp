#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int num, n, count = 0;
    while (cin >> num)
    {
        cin.get();
        for (n = 0; n < num; n++)
        {
            count++;
            string str1;
            getline(cin, str1);
            int length = str1.length();
            if (length % 2 == 0)
            {
                cout << "Case " << count << ": "
                     << "\"" << str1;
                reverse(str1.begin(), str1.end());
                cout << str1 << "\"" << endl;
            }
            else
            {
                cout << "Case " << count << ": "
                     << "\"" << str1.substr(0, length - 1);
                reverse(str1.begin(), str1.end());
                cout << str1 << "\"" << endl;
            }
        }
    }
    return 0;
}