#include <cstring>
#include <iostream>
using namespace std;
void StrSwap(char *str1, char *str2)
{
    char temp[100] = {'\0'};
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}
int main()
{
    char str1[100] = "I'm a programmer.";
    char str2[100] = "Hello, World.";
    cout << str1 << '\n'
         << str2 << endl;
    StrSwap(str1, str2);
    cout << str1 << '\n'
         << str2 << endl;
    return 0;
}