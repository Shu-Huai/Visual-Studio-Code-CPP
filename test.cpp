#include <stdio.h>
#define M 3
#define N 4
int main()
{
    int a[M][N], i, j, maxi;
    printf("请输入%d个数组元素：\n", M * N);
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("矩阵元素为：\n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    maxi = 0;
    double max = 0;
    printf("每行元素平均值为：\n");
    for (i = 0; i < M; i++)
    {
        int sum = 0;
        for (j = 0; j < N; j++)
        {
            sum += a[i][j];
        }
        if (i == 0 or max < double(sum) / N)
        {
            max = double(sum) / N;
            maxi = i;
        }
        printf("%.2lf\n", double(sum) / N);
    }
    printf("平均值最大的行号为：%d", maxi + 1);
    return 0;
}
