#include <iostream>
#include <time.h>
unsigned long long nComp = 0;   // 未使用引用型传递,因为做不来
unsigned long long nAssign = 0; // 非递归函数，可在此置0
using namespace std;

double gettime(int restart = 0) // 参数带默认值，非零表示重新设置计时起点
{
    const double c = 1.0 / CLOCKS_PER_SEC; // 毫秒转换至秒
    static long t = clock();               // 静态局部变量，第一次调用本函数时，确定计时起点
    if (restart)
        t = clock();          // 根据实参决定是否重新确定计时起点
    return c * (clock() - t); // 从上一计时点到现在所经历的时间差
}
void basicquicksort(double *a, int size, int judge) //基本快排
{
    double pivot, temp;
    int left = 0, right = size - 1; // 下标（整数）

    if (size <= 1)
        return;

    pivot = a[right]; // 选择最后一个值为分界值
    do
    {
        while (left < right && a[left] <= pivot)
        {
            left++; // 此处 "<=" 是让与分界值相等的元素暂时留在原地
            nComp++;
        }
        while (left < right && a[right] >= pivot)
        {
            right--; // 此处 ">=" 是让与分界值相等的元素暂时留在原地
            nComp++;
        }
        if (left < right)
        {
            temp = a[left];
            a[left] = a[right];
            a[right] = temp;
            nAssign += 3;
        }
    } while (left < right);
    a[size - 1] = a[left];
    a[left] = pivot;
    nAssign += 2;
    // 找到分界点 left
    basicquicksort(a, left, 0);                       // 递归调用(左侧部分)
    basicquicksort(a + left + 1, size - left - 1, 0); // 递归调用(右侧部分)
    if (judge == 1)
    {
        cout << "比较次数为：" << nComp << "次，赋值次数为：" << nAssign << "次。" << '\n';
    }
}

int main()
{
    double arr[500];
    int i = 0;
    while (cin.peek() != '\n')
    {
        cin >> arr[i++];
    }
    double t;
    gettime(1);
    basicquicksort(arr, i, 1);
    t = gettime(0);
    for (int k = 0; k < i; k++)
    {
        cout << arr[k] << " ";
    }
    cout << '\n';
    cout << "排序用时：" << t << "s" << '\n';
    return 0;
}