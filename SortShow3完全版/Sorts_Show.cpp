// Sorts_Show.cpp	具体的排序算法成员函数定义（相应的函数声明在文件SortShow.h中）
#include "SortShow.h"
#include <conio.h>

void Bubble_Sort(int *array, int length)
{
    ShowText(col1 - 4, top - 1, 0, 15, "︻");
    ShowText(col1 - 4, top + length, 0, 15, "︼");
    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < length - i; j++)
        {
            if (array[j] > array[j + 1]) // 有元素需要交换时
                SWAP(array, j, j + 1);
            else // 无元素需要交换时，展示曾比较过
                ShowBars(col1, top + j, array[j], col1, top + j + 1, array[j + 1]);
        }
        ShowText(col1 - 4, top + length - i + 1, 0, 15, "  ");
        ShowText(col1 - 4, top + length - i, 0, 15, "︼");
    }
    ShowText(col1 - 4, top + 1, 0, 15, "  ");
    ShowText(col1 - 4, top - 1, 0, 15, "  ");
}

void Optimized_Bubble_Sort(int *array, int length) // 优化的冒泡排序
{
    ShowText(col1 - 4, top - 1, 0, 15, "︻"); //显示初始的前后范围
    ShowText(col1 - 4, top + length, 0, 15, "︼");
    int left = 0; // 同时找最大值的最小需要两个下标遍历
    int right = length - 1;
    int tempPostion = 0;                 // 开始比较的下标
    for (int i = 0; i < length - 1; i++) // 共进行 length-1 轮比较和交换
    {
        int flag = 1; // 初始未交换过
        tempPostion = 0;
        for (int j = left; j < right; j++) // 正向寻找最大值
        {
            if (array[j] > array[j + 1]) // 相邻元素之间比较，必要时
            {
                SWAP(array, j, j + 1); // 交换 array[j] 与 array[j+1]
                flag = 0;              // 记录已经交换过
                tempPostion = j;
            }
            else // 无元素需要交换时，展示曾比较过
                ShowBars(col1, top + j, array[j], col1, top + j + 1, array[j + 1]);
        }
        if (flag == 1) // 判断如果没有交换过跳出循环
        {
            break;
        }
        ShowText(col1 - 4, top + length - i, 0, 15, "  "); // 显示变更后排序的范围
        ShowText(col1 - 4, top + length - i - 1, 0, 15, "︼");
        right = tempPostion;
        for (int j = right; j > left; j--) // 反向寻找最小值
        {
            if (array[j] < array[j - 1]) // 相邻元素之间比较，必要时
            {
                SWAP(array, j - 1, j); // 交换 array[j] 与 array[j+1]
                flag = 0;              // 记录已经交换过
                tempPostion = j;
            }
        }
        left++;
        if (flag == 1) //如果没有交换过元素，则已经有序,直接结束
        {
            break;
        }
        ShowText(col1 - 4, top + i, 0, 15, "︻"); // 显示变更后排序的范围
        ShowText(col1 - 4, top + i - 1, 0, 15, "  ");
    }
    ShowText(col1 - 4, top + 1, 0, 15, "  "); // 排序完成后删除显示范围
    ShowText(col1 - 4, top - 1, 0, 15, "  ");
    for (int i = 0; i < 15; i++) // 排序完成后删除显示范围
    {
        ShowText(col1 - 4, top + i - 1, 0, 15, "  ");
    }
}

void Select_Sort(int *array, int length) // 选择排序
{
    int k;

    ShowText(col1 - 4, top + length, 0, 15, "︼ ");
    for (int i = 0; i < length - 1; i++)
    {
        k = i;
        ShowText(col1 - 4, top + i - 1, 0, 15, "︻");
        ShowText(col1 - 4, top + i, 0, 15, "min");
        for (int j = i + 1; j < length; j++)
        {
            ShowBars(col1, top + j, array[j], col1, top + k, array[k]);
            if (array[j] < array[k])
            {
                ShowText(col1 - 4, top + k, 0, 15, "   ");
                k = j;
                ShowText(col1 - 4, top + k, 0, 15, "min");
            }
        }
        if (k != i)
            SWAP(array, k, i);
        ShowText(col1 - 4, top + k, 0, 15, "   ");
        ShowText(col1 - 4, top + i - 1, 0, 15, "   ");
    }
    ShowText(col1 - 4, top + length, 0, 15, "   ");
}

void Optimized_Select_Sort(int *array, int length) // 优化的选择排序
{
    int i;
    int left = 0, right = length - 1;
    int min = left, max = left;
    while (left < right) // 到达中间位置即停止
    {
        min = left;
        max = left;
        ShowText(col1 - 4, top + left - 1, 0, 15, "︻"); //显示初始的前后范围
        ShowText(col1 - 4, top + right + 1, 0, 15, "︼ ");
        ShowText(col1 - 4, top + left, 0, 15, "min"); // 显示初始的最大最小值
        ShowText(col1 - 8, top + left, 0, 15, "max");
        for (i = left; i <= right; i++) // 设定寻找最大最小值的范围
        {
            ShowBars(col1, top + i, array[i], col1, top + max, array[max]);
            if (array[i] > array[max]) // 寻找最大值
            {
                ShowText(col1 - 8, top + max, 0, 15, "   ");
                max = i;
                ShowText(col1 - 8, top + max, 0, 15, "max"); // 显示最大值
            }
            ShowBars(col1, top + i, array[i], col1, top + min, array[min]);
            if (array[i] < array[min]) // 寻找最小值
            {
                ShowText(col1 - 4, top + min, 0, 15, "   ");
                min = i;
                ShowText(col1 - 4, top + min, 0, 15, "min"); // 显示最小值
            }
        }
        if (max != right) // 如果最大值不在最后位
        {
            SWAP(array, max, right); // 交换 array[max] 与 array[right]
        }
        ShowText(col1 - 8, top + max, 0, 15, "   ");
        if (min == right) // 防止最小值在最大值要插入的位置
        {
            min = max;
        }
        if (min != left) // 如果最小值不在最首位
        {
            SWAP(array, min, left); // 交换 array[min] 与 array[left]
        }
        ShowText(col1 - 4, top + min, 0, 15, "   ");
        ShowText(col1 - 4, top + left - 1, 0, 15, "   ");
        ShowText(col1 - 4, top + right + 1, 0, 15, "   ");
        left++;
        right--;
    }
    ShowText(col1 - 4, top + length, 0, 15, "   ");
    for (int i = 0; i < 15; i++) // 排序完成后删除显示范围
    {
        ShowText(col1 - 4, top + i - 1, 0, 15, "   ");
        ShowText(col1 - 8, top + i - 1, 0, 15, "   ");
    }
}

void Merge_Sort(int *a, int size)
{
    int r = 2;
    if (size <= 1)
        return;
    if (size == 2)
    {
        if (a[0] > a[1])
            SWAP(a, 0, 1);
        else
            ShowBars(col1, top + a - array, a[0], col1, top + a - array + 1, a[1]);
        return;
    }
    int i = 0, j = 0, k = 0, len1 = size / 2, len2 = size - size / 2;
    int *b = a + len1;
    Merge_Sort(a, len1);
    Merge_Sort(b, len2);

    ShowText(col1 - 3, top + a - array, 0, 15, "︻");
    ShowText(col1 - 3, top + b - array, 0, 15, "—");
    ShowText(col1 - 3, top + b - array + len2, 0, 15, "︼");

    for (i = 0; i < len1; i++)
    {
        MoveBar(col1, a - array + i + top, r * a[i], col2, i + top);
        temp[i] = a[i];
    }
    getch();

    i = j = k = 0;
    for (i = j = 0; i < len1 && j < len2; k++)
    {
        if (temp[i] <= b[j])
        {
            MoveBar(col2, i + top, r * temp[i], col1, a - array + k + top);
            a[k] = temp[i++];
        }
        else
        {
            MoveBar(col1, b - array + j + top, r * b[j], col1, a - array + k + top);
            a[k] = b[j++];
        }
        getch();
    }
    while (i < len1)
    {
        MoveBar(col2, i + top, r * temp[i], col1, a - array + k + top);
        a[k++] = temp[i++];
    }
    while (j < len2)
    {
        MoveBar(col1, b - array + j + top, r * b[j], col1, a - array + k + top);
        a[k++] = b[j++];
    }
    ShowText(col1 - 3, top + a - array, 0, 15, "  ");
    ShowText(col1 - 3, top + b - array, 0, 15, "  ");
    ShowText(col1 - 3, top + b - array + len2, 0, 15, "  ");
}

void Quick_Sort(int *a, int size)
{
    char lStr[] = "{[(<abcdefghijkl", rStr[] = "}])>ABCDEFGHIJKL"; // 展示递归过程中的"层次"
    int left = 0, right = size - 1;
    int pivot = a[right];  // 以右端的值为轴（值）
    static int layer = -1; // 局部静态变量，记录递归的层数

    layer++;
    if (size <= 1)
    {
        layer--;
        return;
    }
    ShowChar(col1 - 6 - 2 * layer, top + a - array, 0, 15, lStr[layer]);
    ShowChar(col1 - 6 - 2 * layer, top + a - array + size - 1, 0, 15, rStr[layer]);
    ShowText(col1 - 2, top + a - array + size - 1, 0, 15, "*");
    if (size == 2)
    {
        if (a[0] > a[1])
        {
            SWAP(a, 0, 1);
        }
        ShowText(col1 - 2, top + a - array + size - 1, 0, 15, " ");
        layer--;
        return;
    }
    do
    {
        ShowText(col1 - 4, top + a - array + left, 0, 15, "L");
        ShowText(col1 - 3, top + a - array + right, 0, 15, "R");
        while (left < right && (a[left] <= pivot))
        {
            ShowBars(col1, top + a - array + left, a[left], col1, top + a - array + size - 1, pivot);
            left++; // 找到左侧严格大于轴值的元素（下标）
            ShowText(col1 - 4, top + a - array + left - 1, 0, 15, " ");
            ShowText(col1 - 4, top + a - array + left, 0, 15, "L");
        }
        while (left < right && (pivot <= a[right]))
        {
            ShowBars(col1, top + a - array + right, a[right], col1, top + a - array + size - 1, pivot);
            right--; // 找到右侧严格小于轴值的元素（下标）
            ShowText(col1 - 3, top + a - array + right + 1, 0, 15, " ");
            ShowText(col1 - 3, top + a - array + right, 0, 15, "R");
        }
        if (left < right)
        {
            SWAP(a, left, right);
        }
    } while (left < right);
    SWAP(a, left, size - 1); // 至此，left以左全不超过轴值，left到位，left以右全部小于轴值
    ShowText(col1 - 1, top + a - array + left, 0, 15, "-");
    ShowText(col1 - 4, top + a - array + left, 0, 15, " ");
    ShowText(col1 - 3, top + a - array + right, 0, 15, " ");

    ShowText(col1 - 2, top + a - array + size - 1, 0, 15, " ");

    Quick_Sort(a, left); // 递归处理a[0],...,a[left-1]（长度left）
    ShowText(col1 - 1, top + a - array + left, 0, 15, " ");
    Quick_Sort(a + left + 1, size - left - 1); // 递归处理a[left+1],...,a[size-1]（长度size-left-1）
    layer--;
}
