#include <iostream>
using namespace std;
int GetCheck(string &str)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < 12; i++)
    {
        if (str[i] == '-')
        {
            continue;
        }
        else
        {
            sum += (str[i] - 48) * (count + 1);
            count++;
        }
    }
    return sum % 11;
}
int main()
{
    string input;
    while (getline(cin, input))
    {
        int check = GetCheck(input);
        if (check == 10)
        {
            if (input[12] == 'X')
            {
                cout << "Right" << endl;
            }
            else
            {
                input[12] = 'X';
                cout << input << endl;
            }
        }
        else if (check == (input[12] - 48))
        {
            cout << "Right" << endl;
        }
        else
        {
            input[12] = check + 48;
            cout << input << endl;
        }
    }
    return 0;
}