#include <iostream>
using namespace std;
template <typename T>
void ShowBits(T x)
{
    unsigned char *p;
    int n, i, j;
    n = sizeof(T);
    p = (unsigned char *)(&x);
    for (i = 0; i < n; i++)
    {
        for (j = 7; j >= 0; j--)
        {
            cout << (*p >> j & 1);
        }
        cout << ' ';
        p++;
    }
    cout << endl;
}
int main()
{
    ShowBits(char(-1));
    ShowBits(short(-1));
    ShowBits(long(100));
    ShowBits(char(100));
    ShowBits(short(100));
    ShowBits(long(100));
    ShowBits(3.1415926f);
    ShowBits(3.1415926);
    return 0;
}