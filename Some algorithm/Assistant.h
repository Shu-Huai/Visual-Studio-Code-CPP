#pragma once
#ifndef __ASSISTANT_H__
#define __ASSISTANT_H__
#include <Windows.h>
#include <iomanip>
#include <iostream>
#ifndef __USE_OWN_N__
#define N 32
#endif
using namespace std;
double UniformRand(double a, double b)
{
    return a + rand() * (b - a) / RAND_MAX;
}
template <class ElemType>
void InitRand(ElemType *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = (ElemType)UniformRand(32, 126);
    }
}
template <class ElemType>
void Sort(ElemType *array, int length)
{
    static long long nComp = 0;
    static long long nAssign = 0;
    ElemType pivot, temp;
    int left = 0, right = length - 1;
    if (length <= 1)
    {
        return;
    }
    pivot = array[right];
    do
    {
        while (left < right && array[left] <= pivot)
        {
            left++;
            nComp++;
        }
        while (left < right && array[right] >= pivot)
        {
            right--;
            nComp++;
        }
        if (left < right)
        {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            nAssign += 3;
        }
    } while (left < right);
    array[length - 1] = array[left];
    array[left] = pivot;
    nAssign += 2;
    Sort(array, left);
    Sort(array + left + 1, length - left - 1);
}
template <class ElemType>
void ShowData(ElemType *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i];
        if (i != length - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}
template <class ElemType>
void ShowVision(ElemType *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << left << setw(4) << array[i];
        for (int j = 0; j < array[i] / 2; j++)
        {
            cout << "=";
        }
        cout << endl;
    }
}
template <typename ElemType>
bool Check(const ElemType *elems, int length)
{
    for (int i = 1; i < length; i++)
    {
        if (elems[i - 1] > elems[i])
        {
            return false;
        }
    }
    return true;
}
template <typename ElemType>
void Begin(ElemType *array, int length)
{
    InitRand(array, length);
    cout << "The resource is: " << endl;
    ShowData(array, length);
    ShowVision(array, length);
}
template <typename ElemType>
void End(ElemType *array, int length)
{
    cout << "The result is: " << endl;
    ShowData(array, length);
    ShowVision(array, length);
}
#endif