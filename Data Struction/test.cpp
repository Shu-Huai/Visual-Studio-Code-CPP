#include "SeqStack.h"
void test(int &sum)
{
    int x;
    scanf("%d", &x);
    if (x == 0)
    {
        sum = 0;
    }
    else
    {
        test(sum);
        sum += x;
    }
    printf("%d", sum);
}
void TEST(int &SUM)
{
    SeqStack<int> SS;
    int elem = 0;
    do
    {
        scanf("%d", &elem);
        SS.Push(elem);
    } while (elem);
    while (SS.Pop(elem) == SUCCESS)
    {
        SUM += elem;
        printf("%d", SUM);
    }
}
int main()
{
    int sum = 0;
    test(sum);
    int SUM = 0;
    TEST(SUM);
    return 0;
}