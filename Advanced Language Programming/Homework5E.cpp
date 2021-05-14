#include <iostream>
#include <string>
using namespace std;
int main()
{
    system("");
    int count = 1;
    string str[16] =
        {
            "□□□□", "□□□■", "□□■□", "□□■■",
            "□■□□", "□■□■", "□■■□", "□■■■",
            "■□□□", "■□□■", "■□■□", "■□■■",
            "■■□□", "■■□■", "■■■□", "■■■■"};
    string s;
    while (getline(cin, s))
    {
        cout << "Case " << count << ":" << endl;
        count++;
        int i = 1;
        int j = 0;
        for (i = 0; i < s.length(); i++)
        {
            if (j == 4)
            {
                cout << endl;
                j = 0;
            }
            switch (s[i])
            {
            case '0':
                cout << str[0];
                break;
            case '1':
                cout << str[1];
                break;
            case '2':
                cout << str[2];
                break;
            case '3':
                cout << str[3];
                break;
            case '4':
                cout << str[4];
                break;
            case '5':
                cout << str[5];
                break;
            case '6':
                cout << str[6];
                break;
            case '7':
                cout << str[7];
                break;
            case '8':
                cout << str[8];
                break;
            case '9':
                cout << str[9];
                break;
            case 'A':
                cout << str[10];
                break;
            case 'B':
                cout << str[11];
                break;
            case 'C':
                cout << str[12];
                break;
            case 'D':
                cout << str[13];
                break;
            case 'E':
                cout << str[14];
                break;
            case 'F':
                cout << str[15];
                break;
            default:
                j--;
                break;
            }
            j++;
        }
        cout << endl;
    }
    return 0;
}