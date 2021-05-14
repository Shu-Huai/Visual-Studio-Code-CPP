#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int case_ = 0;
    int count = 0;
    while (cin >> case_)
    {
        cin.get();
        for (int i = 0; i < case_; i++)
        {
            count++;
            string input;
            getline(cin, input);
            reverse(input.begin(), input.end());
            cout << "Case " << count << ": " << input << endl;
        }
    }
    return 0;
}