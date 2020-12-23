#include "String.h"
void GetFreq(String S, int times[])
{
    for (int i = 0; i < S.GetLength(); i++)
    {
        if (S[i] >= 'a' and S[i] <= 'z')
        {
            times[S[i] - 97]++;
        }
        else if (S[i] >= 'A' and S[i] <= 'Z')
        {
            times[S[i] - 65]++;
        }
    }
}
int main()
{
    char input[DEFAULT_SIZE] = {'\0'};
    int i = 0;
    cin >> input;
    String S(input);
    int times[26] = {0};
    GetFreq(S, times);
    for (int i = 0; i < 26; i++)
    {
        cout << char(i + 65) << " / " << char(i + 97) << ": " << times[i];
        if (!((i + 1) % 5))
        {
            cout << endl;
        }
        else
        {
            cout << "\t";
        }
    }
    return 0;
}