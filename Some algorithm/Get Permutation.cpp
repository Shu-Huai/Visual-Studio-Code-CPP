#include <iostream>
template <class ElemType>
void GetPermutation(ElemType *list, int k, int m)
{
    if (k == m)
    {
        for (int i = 0; i <= m; i++)
        {
            std::cout << list[i] << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        for (int i = k; i <= m; i++)
        {
            std::swap(list[k], list[i]);
            GetPermutation(list, k + 1, m);
            std::swap(list[k], list[i]);
        }
    }
}
int main()
{
    int numbers[] = {1, 2, 3};
    std::cout << "1 2 3的全排列是：" << std::endl;
    GetPermutation(numbers, 0, sizeof(numbers) / sizeof(int) - 1);
    return 0;
}