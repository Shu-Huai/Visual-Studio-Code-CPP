#include <iostream>
using namespace std;
// IsPrime函数，用于判断一个数是否为素数
// 函数类似于你的帮手，你调用这个函数就是你让这个帮手帮你做一件事情
bool IsPrime(int number)
{
    // 对输入的数进行判断，异常处理
    if (number < 2)
    {
        throw(string) "范围错误。";
    }
    // 从i从2开始一直加，如果这个数能够被i整除，则不是素数
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    // 否则就是素数
    return true;
}
int main()
{
    // 输入提示
    cout << "请输入一个数：";
    // 定义输入的那个数
    int number = 0;
    // 对这个数进行输入操作
    cin >> number;
    try
    {
        // 调用IsPrime函数判断是否是素数
        cout << number << (IsPrime(number) ? "是" : "不是") << "素数。" << endl;
    }
    catch (string &error)
    {
        // 如果出现异常，则输出错误信息
        cout << error << endl;
    }
    // 返回0
    system("pause");
    return 0;
}