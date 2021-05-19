#pragma once
#ifndef __SEQUENCE_SORT_H__
#define __SEQUENCE_SORT_H__
#include <stdlib.h>
template <class ElemType>
class SequenceSort
{
public:
    SequenceSort();
    static void BubbleSort(ElemType *elems, int length);
    static void QuickSort(ElemType *elems, int length);
    static void QuickSort(ElemType *elems, int length, int low, int high);
    static void StraightInsertSort(ElemType *elems, int length);
    static void BinaryInsertSort(ElemType *elems, int length);
    static void ShellSort(ElemType *elems, int length);
    static void MonkeySort(ElemType *elems, int length);
};
template <class ElemType>
SequenceSort<ElemType>::SequenceSort()
{
}
template <class ElemType>
void SequenceSort<ElemType>::BubbleSort(ElemType *elems, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (elems[j] > elems[j + 1])
            {
                ElemType temp = elems[j];
                elems[j] = elems[j + 1];
                elems[j + 1] = temp;
            }
        }
    }
}
template <class ElemType>
void SequenceSort<ElemType>::QuickSort(ElemType *elems, int length)
{
    QuickSort(elems, length, 0, length - 1);
}
template <class ElemType>
void SequenceSort<ElemType>::QuickSort(ElemType *elems, int length, int low, int high)
{
    if (low < high)
    {
        ElemType referenceValue = elems[low];
        int i = low;
        int j = high;
        while (i < j)
        {
            while (i < j && elems[j] >= referenceValue)
            {
                j--;
            }
            if (i < j)
            {
                elems[i] = elems[j];
                i++;
            }
            while (i < j && elems[i] <= referenceValue)
            {
                i++;
            }
            if (i < j)
            {
                elems[j] = elems[i];
                j--;
            }
        }
        elems[i] = referenceValue;
        QuickSort(elems, length, low, i - 1);
        QuickSort(elems, length, i + 1, high);
    }
}
template <class ElemType>
void SequenceSort<ElemType>::StraightInsertSort(ElemType *elems, int length)
{
    for (int i = 1; i < length; i++)
    {
        int j = i - 1;
        ElemType temp = elems[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (elems[j] <= temp)
            {
                break;
            }
            elems[j + 1] = elems[j];
        }
        elems[j + 1] = temp;
    }
}
template <class ElemType>
void SequenceSort<ElemType>::BinaryInsertSort(ElemType *elems, int length)
{
    for (int i = 1; i < length; i++)
    {
        int low = 0;
        int high = i - 1;
        int middle = 0;
        ElemType key = elems[i];
        while (low <= high)
        {
            middle = (low + high) / 2;
            if (key < elems[middle])
            {
                high = middle - 1;
            }
            else if (key > elems[middle])
            {
                low = middle + 1;
            }
        }
        for (int j = i - 1; j >= low; j--)
        {
            elems[j + 1] = elems[j];
        }
        elems[low] = key;
    }
}
template <class ElemType>
void SequenceSort<ElemType>::ShellSort(ElemType *elems, int length)
{
    int distance = length / 2;
    while (distance > 0)
    {
        for (int i = distance; i < length; i++)
        {
            int j = i - distance;
            ElemType temp = elems[i];
            for (j = i - distance; j >= 0; j -= distance)
            {
                if (elems[j] <= temp)
                {
                    break;
                }
                elems[j + distance] = elems[j];
            }
            elems[j + distance] = temp;
        }
        distance /= 2;
    }
}
template <class ElemType>
void SequenceSort<ElemType>::MonkeySort(ElemType *elems, int length)
{
    bool isSorted = false;
    ElemType *result = new ElemType[length]{0};
    while (!isSorted)
    {
        bool *needIndex = new bool[length];
        for (int i = 0; i < length; i++)
        {
            needIndex[i] = true;
        }
        for (int i = 0; i < length; i++)
        {
            int index = rand() % length;
            if (needIndex[index])
            {
                result[i] = elems[index];
                needIndex[index] = false;
            }
            else
            {
                i--;
            }
        }
        delete[] needIndex;
        isSorted = true;
        for (int i = 0; i < length - 1; i++)
        {
            if (result[i] > result[i + 1])
            {
                isSorted = 0;
            }
        }
    }
    for (int i = 0; i < length; i++)
    {
        elems[i] = result[i];
    }
    delete[] result;
}
#endif