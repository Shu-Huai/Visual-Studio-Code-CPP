#include <iostream>
using namespace std;
int main()
{
    string input;
    while (getline(cin, input))
    {
        int count = 0;
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] <= '9' and input[i] >= '0')
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}