/*
// 算术平均值和几何平均值
#include <iostream>
using namespace std;
int main()
{
    char a[3] = {0};
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cout << a[2 - i];
    }
    return 0;
}
// 算术平均值和几何平均值
#include <cmath>
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    double input[5] = {0};
    double sum = 0;
    double chengji = 1;
    for (int i = 0; i < 5; i++)
    {
        cin >> input[i];
        sum += input[i];
        chengji *= input[i];
    }
    printf("%.1lf, %.1lf\n", sum / 5, pow(chengji, 0.2));
    return 0;
}
*/
// 小写字母转换成大写字母
#include <iostream>
using namespace std;
int main()
{
    char input;
    cin >> input;
    cout << char(input - 32) << endl;
    return 0;
}