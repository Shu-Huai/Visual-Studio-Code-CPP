// Main.cpp
#include "SortShow.h"
#include <conio.h>
#include <stdlib.h> // 或 <cstdlib>
#include <time.h>   // 或 <ctime>

int main()
{
    char text[100];
    const char *str[] = {"1 ---- 重新生成原始数据(D)",
                         "2 ---- 冒泡排序........(B)",
                         "3 ---- 选择排序........(S)",
                         "4 ---- 归并排序........(M)",
                         "5 ---- 快速排序........(Q)",
                         "6 ---- 优化的冒泡排序..(C)",
                         "7 ---- 优化的选择排序..(T)",
                         "0 ---- 退出..........(ESC)",
                         "请选择: "};
    int choice, n = sizeof(str) / sizeof(*str);

    srand(time(NULL));

    Init();

    while (true)
    {
        SetConsoleTitle("SortShow排序秀 - 排序过程可视化");
        system("cls");
        for (int i = 0; i < n; i++)
            ShowText(20, i + 2, 0, 7, str[i]); // 显示菜单
        choice = getch();
        if (choice == 27 || choice == '0')
            break;

        switch (choice)
        {
        case '1':
        case 'd':
        case 'D':
            ShowText(2, 10, 0, 7, "1.正序; 2.倒序; 3.随机 : ");
            SetData(getch() - '0');
            system("cls");
            ShowData();
            break;
        case '2':
        case 'b':
        case 'B':
            col1 = 30;
            SetConsoleTitle("冒泡排序（Bubble Sorting）");
            Start();
            Bubble_Sort(array, N);
            Finish();
            break;
        case '3':
        case 's':
        case 'S':
            col1 = 30;
            SetConsoleTitle("选择排序（Selection Sorting）");
            Start();
            Select_Sort(array, N);
            Finish();
            break;
        case '4':
        case 'm':
        case 'M':
            col1 = 5;
            col2 = col1 + 40;
            SetConsoleTitle("归并排序（Merge Sorting）");
            Start();
            Merge_Sort(array, N);
            Finish();
            break;
        case '5':
        case 'q':
        case 'Q':
            col1 = 40;
            SetConsoleTitle("快速排序（Quick Sorting）");
            Start();
            Quick_Sort(array, N);
            Finish();
            break;
        case '6':
        case 'c':
        case 'C':
            col1 = 30;
            SetConsoleTitle("优化的冒泡排序（Optimized Bubble Sorting）");
            Start();
            Optimized_Bubble_Sort(array, N);
            Finish();
            break;
        case '7':
        case 't':
        case 'T':
            col1 = 30;
            SetConsoleTitle("优化的选择排序（Optimized Selection Sorting）");
            Start();
            Optimized_Select_Sort(array, N);
            Finish();
            break;
        }
        sprintf(text, "按回车键继续...");
        ShowText(79 - strlen(text), top + N + 6, 0, 7, text);
        while (getch() != '\r')
            ;
    }
    Quit();
    return 0;
}
