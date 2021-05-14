#include <iostream>
using namespace std;
int main()
{
    string input;
    while (getline(cin, input))
    {
        if (input.length() != 0)
        {
            if (input[0] % 2 == 0)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}