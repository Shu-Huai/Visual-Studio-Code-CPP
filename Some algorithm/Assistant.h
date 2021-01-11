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
template <class ElemType>
void InitSeq(ElemType *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = i+1;
    }
}
template <class ElemType>
void InitRand(ElemType *array, int length)
{
    InitSeq(array, length);
    ElemType *result = new ElemType[length]{0};
    for (int i = length - 1; i > 0; i--)
    {
        int pos = rand() % i;
        result[i] = array[pos];
        for (int j = pos; j < length - 1; j++)
        {
            array[j] = array[j + 1];
        }
    }
    for (int i = 1; i < length; i++)
    {
        array[i] = result[i];
    }
    delete[] result;
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
        for (int j = 0; j < array[i] * 2; j++)
        {
            cout << "=";
        }
        cout << endl;
    }
}
template <class ElemType>
void Show(ElemType *array, int length) 
{
    ShowData(array,length);
    ShowVision(array, length);
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
    Show(array, length);
}
template <typename ElemType>
void End(ElemType *array, int length)
{
    cout << "The result is: " << endl;
    Show(array, length);
}
#endif