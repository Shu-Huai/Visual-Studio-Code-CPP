#include "MinHeap.h"
int main()
{
    int a[10] = {12, 70, 33, 65, 24, 56, 48, 92, 86, 33};
    MinHeap<int> MH(a, 10, 10);
    MH.Traverse(Write<int>);
    return 0;
}