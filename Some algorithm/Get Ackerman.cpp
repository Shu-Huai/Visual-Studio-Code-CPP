#include <iostream>
int GetAckerman(int n, int m)
{
    if (!n)
    {
        return 1;
    }
    if (n == 1 && !m)
    {
        return 2;
    }
    if (n >= 2 && !m)
    {
        return n + 2;
    }
    return GetAckerman(GetAckerman(n - 1, m), m - 1);
}
int main()
{
    std::cout << "请输入两个数：";
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    std::cout << "Ackerman(" << n << ", " << m << ") = " << GetAckerman(n, m) << std::endl;
    return 0;
}