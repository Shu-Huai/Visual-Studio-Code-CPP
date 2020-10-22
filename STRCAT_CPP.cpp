#include <conio.h>
#include <cstring>
#include <iostream>
using namespace std;
void STRCAT_CPP(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != 0)
    {
        i++;
    }
    str1[i] = '&';
    int j = 0;
    while (str2[j] != 0)
    {
        j++;
    }
    int k = 0;

    for (k = 0; k < j; k++)
    {
        str1[i + k + 1] = str2[k];
    }
    str1[k + 1 + i] = '\0';
}
int main()
{
    char *str1, *str2;
    str1 = new char[4];
    str2 = new char[6];
    strcpy(str1, "Tom");
    strcpy(str2, "Jerry");
    STRCAT_CPP(str1, str2);
    cout << str1 << endl;
    str1 = new char[4];
    delete[] str1;
    delete[] str2;
    system("pause");
    return 0;
}