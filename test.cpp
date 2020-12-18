#include <stdio.h>
#define M 100
int promin(int a[])
{
    int min = a[0];
    for (int i = 1; i < M; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}
void input(int a[])
{
    printf("请输入%d个数组元素:\n", M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &a[i]);
    }
}
int main()
{
    int a[M] = {0};
    input(a);
    printf("10个数组元素中的最小值为:%d\n", promin(a));
    return 0;
}