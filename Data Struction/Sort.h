#pragma once
#ifndef __SORT_H__
#define __SORT_H__
#include "Double Link List.h"
#include "Sequence List.h"
#include <queue>
#include <stack>
#include <stdlib.h>
template <class ElemType>
class Sort
{
private:
    static void Merge(SequenceList<ElemType> &sequenceList, int low, int middle, int high);

public:
    Sort();
    static void BubbleSort(SequenceList<ElemType> &sequenceList);
    static void BubbleSort(DoubleLinkList<ElemType> &doubleLinkList);
    static void QuickSort(SequenceList<ElemType> &sequenceList);
    static void QuickSort(SequenceList<ElemType> &sequenceList, int low, int high);
    static void QuickSortWithoutRecursion(SequenceList<ElemType> &sequenceList);
    static void StraightInsertSort(SequenceList<ElemType> &sequenceList);
    static void BinaryInsertSort(SequenceList<ElemType> &sequenceList);
    static void TwoWayInsertSort(SequenceList<ElemType> &SequenceList);
    static void ShellSort(SequenceList<ElemType> &sequenceList);
    static void MergeSort(SequenceList<ElemType> &sequenceList);
    static void MergeSortWithRecursion(SequenceList<ElemType> &sequenceList);
    static void MergeSortWithRecursion(SequenceList<ElemType> &sequenceList, int low, int high);
    static void MonkeySort(SequenceList<ElemType> &sequenceList);
    static void CountSort(SequenceList<ElemType> &sequenceList);
};
template <class ElemType>
void Sort<ElemType>::Merge(SequenceList<ElemType> &sequenceList, int low, int middle, int high)
{
    ElemType *result = new ElemType[high + 1];
    int i = low;
    int j = middle + 1;
    int k = low;
    while (i <= middle && j <= high)
    {
        if (sequenceList[i] <= sequenceList[j])
        {
            result[k] = sequenceList[i];
            i++;
        }
        else
        {
            result[k] = sequenceList[j];
            j++;
        }
        k++;
    }
    while (i <= middle)
    {
        result[k] = sequenceList[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        result[k] = sequenceList[j];
        k++;
        j++;
    }
    for (k = low; k <= high; k++)
    {
        sequenceList[k] = result[k];
    }
    delete[] result;
}
template <class ElemType>
Sort<ElemType>::Sort()
{
}
template <class ElemType>
void Sort<ElemType>::BubbleSort(SequenceList<ElemType> &sequenceList)
{
    for (int i = 0; i < sequenceList.GetLength(); i++)
    {
        for (int j = 0; j < sequenceList.GetLength() - i - 1; j++)
        {
            if (sequenceList[j] > sequenceList[j + 1])
            {
                ElemType temp = sequenceList[j];
                sequenceList[j] = sequenceList[j + 1];
                sequenceList[j + 1] = temp;
            }
        }
    }
}
template <class ElemType>
void Sort<ElemType>::BubbleSort(DoubleLinkList<ElemType> &doubleLinkList)
{
    for (int i = 0; i < doubleLinkList.GetLength() - 1; i++)
    {
        for (int j = 0; j < doubleLinkList.GetLength() - i - 1; j++)
        {
            if (doubleLinkList[j] > doubleLinkList[j + 1])
            {
                ElemType temp = doubleLinkList[j];
                doubleLinkList[j] = doubleLinkList[j + 1];
                doubleLinkList[j + 1] = temp;
            }
        }
    }
}
template <class ElemType>
void Sort<ElemType>::QuickSort(SequenceList<ElemType> &sequenceList)
{
    QuickSort(sequenceList, 0, sequenceList.GetLength() - 1);
}
template <class ElemType>
void Sort<ElemType>::QuickSort(SequenceList<ElemType> &sequenceList, int low, int high)
{
    if (low < high)
    {
        ElemType referenceValue = sequenceList[low];
        int i = low;
        int j = high;
        while (i < j)
        {
            while (i < j && sequenceList[j] >= referenceValue)
            {
                j--;
            }
            if (i < j)
            {
                sequenceList[i] = sequenceList[j];
                i++;
            }
            while (i < j && sequenceList[i] <= referenceValue)
            {
                i++;
            }
            if (i < j)
            {
                sequenceList[j] = sequenceList[i];
                j--;
            }
        }
        sequenceList[i] = referenceValue;
        QuickSort(sequenceList, low, i - 1);
        QuickSort(sequenceList, i + 1, high);
    }
}
template <class ElemType>
void Sort<ElemType>::QuickSortWithoutRecursion(SequenceList<ElemType> &sequenceList)
{
    int head, tail, pivot;
    stack<ElemType> s;
    s.push(0);
    s.push(sequenceList.GetLength() - 1);
    while (!s.empty())
    {
        tail = s.top();
        s.pop();
        head = s.top();
        s.pop();
        while (tail - head >= 3)
        {
            int i = head;
            int j = tail;
            bool pivotLocation = true;
            while (i < j)
            {
                if (sequenceList[i] > sequenceList[j])
                {
                    ElemType temp = sequenceList[i];
                    sequenceList[i] = sequenceList[j];
                    sequenceList[j] = temp;
                    pivotLocation = !pivotLocation;
                }
                if (pivotLocation)
                {
                    j--;
                }
                else
                {
                    i++;
                }
            }
            pivot = i;
            if (pivot - head < tail - pivot)
            {
                s.push(pivot + 1);
                s.push(tail);
                tail = pivot - 1;
            }
            else
            {
                s.push(head);
                s.push(pivot - 1);
                head = pivot + 1;
            }
        }
        if (tail - head == 2)
        {
            if (sequenceList[head] > sequenceList[head + 1])
            {
                ElemType temp = sequenceList[head];
                sequenceList[head] = sequenceList[head + 1];
                sequenceList[head + 1] = temp;
            }
            if (sequenceList[head] > sequenceList[tail])
            {
                ElemType temp = sequenceList[head];
                sequenceList[head] = sequenceList[tail];
                sequenceList[tail] = temp;
            }
            if (sequenceList[head + 1] > sequenceList[tail])
            {
                ElemType temp = sequenceList[head + 1];
                sequenceList[head + 1] = sequenceList[tail];
                sequenceList[tail] = temp;
            }
        }
        else if (tail - head == 1)
        {
            if (sequenceList[head] > sequenceList[tail])
            {
                ElemType temp = sequenceList[head];
                sequenceList[head] = sequenceList[tail];
                sequenceList[tail] = temp;
            }
        }
    }
}
template <class ElemType>
void Sort<ElemType>::StraightInsertSort(SequenceList<ElemType> &sequenceList)
{
    for (int i = 1; i < sequenceList.GetLength(); i++)
    {
        int j = i - 1;
        ElemType temp = sequenceList[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (sequenceList[j] <= temp)
            {
                break;
            }
            sequenceList[j + 1] = sequenceList[j];
        }
        sequenceList[j + 1] = temp;
    }
}
template <class ElemType>
void Sort<ElemType>::BinaryInsertSort(SequenceList<ElemType> &sequenceList)
{
    for (int i = 1; i < sequenceList.GetLength(); i++)
    {
        int low = 0;
        int high = i - 1;
        int middle = 0;
        ElemType key = sequenceList[i];
        while (low <= high)
        {
            middle = (low + high) / 2;
            if (key < sequenceList[middle])
            {
                high = middle - 1;
            }
            else if (key > sequenceList[middle])
            {
                low = middle + 1;
            }
        }
        for (int j = i - 1; j >= low; j--)
        {
            sequenceList[j + 1] = sequenceList[j];
        }
        sequenceList[low] = key;
    }
}
template <class ElemType>
void Sort<ElemType>::TwoWayInsertSort(SequenceList<ElemType> &sequenceList)
{
    ElemType *result = new int[sequenceList.GetLength()];
    int head = 0;
    int tail = 0;
    result[0] = sequenceList[0];
    for (int i = 1; i < sequenceList.GetLength(); i++)
    {
        ElemType temp = sequenceList[i];
        if (temp > result[0])
        {
            int j = tail;
            for (j = tail; j > 0; j--)
            {
                if (result[j] <= temp)
                {
                    break;
                }
                result[j + 1] = result[j];
            }
            result[j + 1] = temp;
            tail++;
        }
        else
        {
            if (head == 0)
            {
                result[sequenceList.GetLength() - 1] = temp;
                head = sequenceList.GetLength() - 1;
            }
            else
            {
                int j = head;
                for (j = head; j < sequenceList.GetLength(); j++)
                {
                    if (result[j] >= temp)
                    {
                        break;
                    }
                    result[j - 1] = result[j];
                }
                result[j - 1] = temp;
                head--;
            }
        }
    }
    int count = 0;
    for (int i = head; i != tail; i = (i + 1) % sequenceList.GetLength())
    {
        sequenceList[count] = result[i];
        count++;
    }
    sequenceList[0] = result[head];
    delete[] result;
}
template <class ElemType>
void Sort<ElemType>::ShellSort(SequenceList<ElemType> &sequenceList)
{
    int distance = sequenceList.GetLength() / 2;
    while (distance > 0)
    {
        for (int i = distance; i < sequenceList.GetLength(); i++)
        {
            int j = i - distance;
            ElemType temp = sequenceList[i];
            for (j = i - distance; j >= 0; j -= distance)
            {
                if (sequenceList[j] <= temp)
                {
                    break;
                }
                sequenceList[j + distance] = sequenceList[j];
            }
            sequenceList[j + distance] = temp;
        }
        distance /= 2;
    }
}
template <class ElemType>
void Sort<ElemType>::MergeSort(SequenceList<ElemType> &sequenceList)
{
    int intervalLength = 1;
    while (intervalLength < sequenceList.GetLength())
    {
        int index = 0;
        while (index + 2 * intervalLength <= sequenceList.GetLength())
        {
            Merge(sequenceList, index, index + intervalLength - 1, index + 2 * intervalLength - 1);
            index += 2 * intervalLength;
        }
        if (index + intervalLength < sequenceList.GetLength())
        {
            Merge(sequenceList, index, index + intervalLength - 1, sequenceList.GetLength() - 1);
        }
        intervalLength *= 2;
    }
}
template <class ElemType>
void Sort<ElemType>::MergeSortWithRecursion(SequenceList<ElemType> &sequenceList)
{
    MergeSortWithRecursion(sequenceList, 0, sequenceList.GetLength() - 1);
}
template <class ElemType>
void Sort<ElemType>::MergeSortWithRecursion(SequenceList<ElemType> &sequenceList, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int middle = (low + high) / 2;
    MergeSortWithRecursion(sequenceList, low, middle);
    MergeSortWithRecursion(sequenceList, middle + 1, high);
    Merge(sequenceList, low, middle, high);
}
template <class ElemType>
void Sort<ElemType>::MonkeySort(SequenceList<ElemType> &sequenceList)
{
    bool isSorted = false;
    ElemType *result = new ElemType[sequenceList.GetLength()]{0};
    while (!isSorted)
    {
        bool *needIndex = new bool[sequenceList.GetLength()];
        for (int i = 0; i < sequenceList.GetLength(); i++)
        {
            needIndex[i] = true;
        }
        for (int i = 0; i < sequenceList.GetLength(); i++)
        {
            int index = rand() % sequenceList.GetLength();
            if (needIndex[index])
            {
                result[i] = sequenceList[index];
                needIndex[index] = false;
            }
            else
            {
                i--;
            }
        }
        delete[] needIndex;
        isSorted = true;
        for (int i = 0; i < sequenceList.GetLength() - 1; i++)
        {
            if (result[i] > result[i + 1])
            {
                isSorted = 0;
            }
        }
    }
    for (int i = 0; i < sequenceList.GetLength(); i++)
    {
        sequenceList[i] = result[i];
    }
    delete[] result;
}
template <class ElemType>
void Sort<ElemType>::CountSort(SequenceList<ElemType> &sequenceList)
{
    int *indexes = new int[sequenceList.GetLength()]{0};
    for (int i = 0; i < sequenceList.GetLength(); i++)
    {
        for (int j = 0; j < sequenceList.GetLength(); j++)
        {
            if (sequenceList[j] < sequenceList[i])
            {
                indexes[i]++;
            }
        }
    }
    SequenceList<ElemType> result;
    for (int i = 0; i < sequenceList.GetLength(); i++)
    {
        result.AppendElem(i);
    }
    for (int i = 0; i < sequenceList.GetLength(); i++)
    {
        result[indexes[i]] = sequenceList[i];
    }
    sequenceList = result;
    delete[] indexes;
}
#endif