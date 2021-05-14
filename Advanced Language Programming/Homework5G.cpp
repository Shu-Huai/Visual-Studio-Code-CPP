#include <iostream>
using namespace std;
int main()
{
    string input;
    int case_ = 0;
    while (getline(cin, input))
    {
        case_++;
        cout << "Case " << case_ << ": ";
        int count = 0;
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i - 1] == ' ' and input[i] != ' ')
            {
                count++;
            }
        }
        count++;
        if (input[0] == ' ')
        {
            count = count - 1;
        }
        cout << count << endl;
    }
    return 0;
}