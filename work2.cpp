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