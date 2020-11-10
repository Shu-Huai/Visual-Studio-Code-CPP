#include <stdio.h>
int main()
{
    int n, a, b, c, t = 0;
    for (n = 1; n < 1000; n++)
    {
        c = n % 10;
        b = (n / 10) % 100;
        a = n / 100;
        if ((n % 3 == 0) && ((a == 5) + (b == 5) + (c == 5)))
            if (++t % 7)
                printf("%6d", n);
            else
                printf("%6d\n", n);
    }
    printf("\n");
    return 0;
}