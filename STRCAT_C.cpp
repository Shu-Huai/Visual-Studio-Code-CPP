#include <conio.h>
#include <cstring>
#include <iostream>
using namespace std;
void STRCAT_C(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != 0)
    {
        i++;
    }
    int j = 0;
    while (str2[j] != 0)
    {
        j++;
    }
    char *str;
    str = new char[i + j + 1];
    int k = 0;
    for (k = 0; k < i; k++)
    {
        str[k] = str1[k];
    }
    str[k] = '&';
    for (k = 0; k < j; k++)
    {
        str[i + k + 1] = str2[k];
    }
    str[k + 1 + i] = '\0';
    delete[] str1;
    str1 = new char[i + j + 1];
    strcpy(str1, str);
    int oreo = 0;
}

int main()
{
    char *str1, *str2;
    str1 = new char[4];
    str2 = new char[6];
    strcpy(str1, "Tom");
    strcpy(str2, "Jerry");
    STRCAT_C(str1, str2);
    cout << str1 << endl;
    delete[] str1;
    delete[] str2;
    return 0;
}