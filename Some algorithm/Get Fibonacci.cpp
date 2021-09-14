#include <iostream>
int GetFibonacci(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return GetFibonacci(n - 1) + GetFibonacci(n - 2);
}
int main()
{
    std::cout << "请输入一个数：";
    int n = 0;
    std::cin >> n;
    std::cout << "Fibonacci(" << n << ") = " << GetFibonacci(n) << std::endl;
    return 0;
}