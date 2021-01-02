/*
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    int n = 0;
    scanf("%d", &n);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int number = 0;
        for (int j = 0; j <= i; j++)
        {
            number += (j + 1) * pow(10, i - j);
        }
        printf("%d", number);
        i == n - 1 ? printf("=") : printf("+");
        result += number;
    }
    printf("%d\n", result);
    return 0;
}
*/
#include <stdio.h>
void fun(float score[2][3])
{
    int i = 0;
    int j = 0;
    float StuAve[2] = {0};
    float CouAve[3] = {0};
    float CouMax = 0;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%f", &score[i][j]);
            StuAve[i] += score[i][j];
            CouAve[j] += score[i][j];
            if (i)
            {
                CouAve[j] /= 2;
            }
            if ((!i && !j) || CouMax < score[i][j])
            {
                CouMax = score[i][j];
            }
        }
        StuAve[i] /= 3;
    }
    return;
}
int main()
{
    float score[2][3];
    fun(score);
    return 0;
}