#include "String.h"
void GetFreq(String S, int times[])
{
    for (int i = 0; i < S.GetLength(); i++)
    {
        times[int(S[i])]++;
    }
}
int main()
{
    char input[DEFAULT_SIZE] = {'\0'};
    int i = 0;
    cin >> input;
    String S(input);
    int times[128] = {0};
    GetFreq(S, times);
    bool judge = 0;
    for (int i = 32, format = 0; i < 127; i++)
    {
        if (times[i])
        {
            cout << char(i) << ": " << times[i];
            if (!((format++ + 1) % 5) && i != 126)
            {
                cout << endl;
                judge = 1;
            }
            else
            {
                cout << "\t";
                judge = 0;
            }
        }
    }
    if (!judge)
    {
        cout << endl;
    }
    return 0;
}