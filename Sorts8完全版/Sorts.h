// Sorts.h		三种（冒泡、选择、快速）基本排序算法（升序）
#ifndef SORTS_H
#define SORTS_H
#include <iomanip>
#include <iostream>
using namespace std;

double gettime(int restart = 0);

template <typename T>
void GetMemory(T *&data, T *&data0, int n) // 分配堆内存空间，通过参数"返回"首地址
{                                          // 隐含约定：指针非空就表示指针"拥有"堆空间资源
    if (data0 != NULL)
        delete[] data0; // 先释放原先所"拥有"的堆空间资源
    if (data != NULL)
        delete[] data;
    data0 = new T[n]; // 重新申请新的（容量符合要求的）堆空间资源
    data = new T[n];
}

template <typename T>
void FreeMemory(T *&data, T *&data0) // 释放指针所"拥有"的堆空间资源
{
    if (data0 != NULL)
        delete[] data0;
    if (data != NULL)
        delete[] data;
    data0 = data = NULL; // 这一条赋值语句非常重要！保持"隐含约定"
}

template <typename T>
void ReSet(T *data, const T *data0, int n) // 用于恢复"原始数据"，以保证不同的排序算法处理完全相同的数据
{
    for (int i = 0; i < n; i++)
        data[i] = data0[i];
}

template <typename T>
bool Check(const T *a, int size) // 检验数组元素是否已按升序排列
{
    for (int i = 1; i < size; i++)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

// 三种基本的（优化的）排序算法
template <typename T>
void Bubble(T *a, int size) // 冒泡排序
{
    long long fuzhicishu = 0; // 定义赋值次数和比较次数
    long long bijiaocishu = 0;
    T temp; // 定义一个局部变量，数据类型与形式数据类型相同
    int i, j;
    int left = 0; // 同时找最大值的最小需要两个下标遍历
    int right = size - 1;
    int tempPostion = 0;           // 开始比较的下标
    for (i = 0; i < size - 1; i++) // 共进行 size-1 轮比较和交换
    {
        int flag = 1; // 初始未交换过
        tempPostion = 0;
        for (j = left; j < right; j++) // 正向寻找最大值
        {
            bijiaocishu++;       // 比较次数+1
            if (a[j] > a[j + 1]) // 相邻元素之间比较，必要时
            {
                temp = a[j]; // 交换 a[j] 与 a[j+1]
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 0; // 记录已经交换过
                tempPostion = j;
                fuzhicishu += 3; // 赋值次数+3
            }
        }
        if (flag == 1) // 判断如果没有交换过跳出循环
        {
            break;
        }
        right = tempPostion;
        for (j = right; j > left; j--) // 反向寻找最小值
        {
            bijiaocishu++;       // 比较次数+1
            if (a[j] < a[j - 1]) // 相邻元素之间比较，必要时
            {
                temp = a[j]; // 交换 a[j] 与 a[j+1]
                a[j] = a[j - 1];
                a[j - 1] = temp;
                flag = 0; // 记录已经交换过
                tempPostion = j;
                fuzhicishu += 3; // 赋值次数+3
            }
        }
        left++;
        if (flag == 1) // 判断如果没有交换过跳出循环
        {
            break;
        }
    }
    cout << "冒比：" << setw(12) << bijiaocishu << "冒赋：" << setw(12) << fuzhicishu; // 输出比较次数和赋值次数
}

template <typename T>
void Select(T *a, int size) // 选择排序
{
    long long bijiaocishu = 0; // 定义赋值次数和比较次数
    long long fuzhicishu = 0;
    int i;
    int left = 0, right = size - 1;
    int min = left, max = left;
    while (left < right) // 到达中间位置即停止
    {
        min = left;
        max = left;
        for (i = left; i <= right; i++) // 设定寻找最大最小值的范围
        {
            bijiaocishu++;     // 比较次数+1
            if (a[i] > a[max]) // 寻找最大值
            {
                max = i;
            }
            bijiaocishu++;     // 比较次数+1
            if (a[i] < a[min]) // 寻找最小值
            {
                min = i;
            }
        }
        if (max != right) // 如果最大值不在最后位
        {
            swap(a[max], a[right]); // 交换 a[max] 与 a[right]
            fuzhicishu += 3;        // 赋值次数+3
        }
        if (min == right) // 防止最小值在最大值要插入的位置
        {
            min = max;
        }
        if (min != left) // 如果最小值不在最首位
        {
            swap(a[min], a[left]); // 交换 a[min] 与 a[left]
            fuzhicishu += 3;       // 赋值次数+3
        }
        left++;
        right--;
    }
    cout << "比比：" << setw(12) << bijiaocishu << "比赋：" << setw(12) << fuzhicishu; // 输出比较次数和赋值次数
}

template <typename T>
int gepivot(T *a, int size) // 三数取中
{
    if (size < 3)
        return 0;
    int b[3];
    b[0] = 0;
    b[1] = size / 2;
    b[2] = size - 1;
    int seq[6][3] = {{0, 1, 2},
                     {2, 1, 0},
                     {0, 2, 1},
                     {1, 2, 0},
                     {1, 0, 2},
                     {2, 0, 1}};
    for (int i = 0; i < 6; i++) // 判断次数
    {
        const int *s = seq[i];
        if (a[b[s[1]]] >= a[b[s[0]]] && a[b[s[2]]] >= a[b[s[1]]]) // 比较大小
            return b[s[1]];                                       // 返回中位数
    }
    return b[1];
}

template <typename T>
void Qsort(T *a, int size) // 快速排序
{
    T pivot, temp;                  // 定义局部变量，数据类型与形式数据类型相同
    int left = 0, right = size - 1; // 下标（整数）
    if (size <= 1)
        return;
    int TempTivot = gepivot(a, size); // 取分界值
    if (TempTivot != right)
        swap(a[TempTivot], a[right]);
    pivot = a[right];
    do
    {
        while (left < right && a[left] <= pivot)
        {
            left++;
        } // 此处 "<=" 是让与分界值相等的元素暂时留在原地
        while (left < right && a[right] >= pivot)
        {
            right--;
        } // 此处 ">=" 是让与分界值相等的元素暂时留在原地
        if (left < right)
        {
            temp = a[left];
            a[left] = a[right];
            a[right] = temp; // 交换a[eft] 与 a[right]
        }
    } while (left < right);
    a[size - 1] = a[left];
    a[left] = pivot;                        // 找到分界点 left
    Qsort(a, right);                        // 递归调用(左侧部分)
    Qsort(a + right + 1, size - right - 1); // 递归调用(右侧部分)
}

#endif
