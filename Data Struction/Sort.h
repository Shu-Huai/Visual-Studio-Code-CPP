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
    static void Merge(ElemType *elems, int low, int middle, int high);

public:
    Sort();
    static void BubbleSort(ElemType *elems, int length);
    static void BubbleSort(DoubleLinkList<ElemType> &doubleLinkList);
    static void QuickSort(ElemType *elems, int length);
    static void QuickSort(ElemType *elems, int length, int low, int high);
    static void QuickSortWithoutRecursion(SequenceList<ElemType> &sequenceList);
    static void StraightInsertSort(ElemType *elems, int length);
    static void BinaryInsertSort(ElemType *elems, int length);
    static void TwoWayInsertSort(SequenceList<ElemType> &SequenceList);
    static void ShellSort(ElemType *elems, int length);
    static void MergeSort(ElemType *elems, int length);
    static void MergeSortWithRecursion(ElemType *elems, int length);
    static void MergeSortWithRecursion(ElemType *elems, int length, int low, int high);
    static void MonkeySort(ElemType *elems, int length);
    static void CountSort(SequenceList<ElemType> &sequenceList);
};
template <class ElemType>
void Sort<ElemType>::Merge(ElemType *elems, int low, int middle, int high)
{
    ElemType *result = new ElemType[high + 1];
    int i = low;
    int j = middle + 1;
    int k = low;
    while (i <= middle && j <= high)
    {
        if (elems[i] <= elems[j])
        {
            result[k] = elems[i];
            i++;
        }
        else
        {
            result[k] = elems[j];
            j++;
        }
        k++;
    }
    while (i <= middle)
    {
        result[k] = elems[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        result[k] = elems[j];
        k++;
        j++;
    }
    for (k = low; k <= high; k++)
    {
        elems[k] = result[k];
    }
    delete[] result;
}
template <class ElemType>
Sort<ElemType>::Sort()
{
}
template <class ElemType>
void Sort<ElemType>::BubbleSort(ElemType *elems, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
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
void Sort<ElemType>::BubbleSort(DoubleLinkList<ElemType> &doubleLinkList)
{
    for (int i = 0; i < doubleLinkList.GetLength() - 1; i++)
    {
        for (int j = 0; j < doubleLinkList.GetLength() - 1 - i; j++)
        {
            if (doubleLinkList.GetElem(j) > doubleLinkList.GetElem(j + 1))
            {
                ElemType temp = doubleLinkList.GetElem(j);
                doubleLinkList.SetElem(j, doubleLinkList.GetElem(j + 1));
                doubleLinkList.SetElem(j + 1, temp);
            }
        }
    }
}
template <class ElemType>
void Sort<ElemType>::QuickSort(ElemType *elems, int length)
{
    QuickSort(elems, length, 0, length - 1);
}
template <class ElemType>
void Sort<ElemType>::QuickSort(ElemType *elems, int length, int low, int high)
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
void Sort<ElemType>::QuickSortWithoutRecursion(SequenceList<ElemType> &sequenceList)
{
    int low = 0;
    int high = sequenceList.GetLength() - 1;
    int i, j, l, h, count = 1;
    int compare, all = 0, move = 0, allc = 0;
    stack<int> s;
    queue<int> q;
    ElemType temp;
    bool still = true;
    s.push(low);
    s.push(high);
    while (still)
    {
        while (!s.empty())
        {
            j = s.top();
            s.pop();
            h = j;
            i = s.top();
            s.pop();
            l = i;
            temp = sequenceList.GetElem(i);
            compare = 0;
            while (i < j)
            {
                while (i < j && temp <= sequenceList.GetElem(j))
                {
                    j--;
                    compare++;
                }
                if (i < j)
                {
                    sequenceList.SetElem(i, sequenceList.GetElem(j));
                    i++;
                    move++;
                    compare++;
                }
                while (i < j && temp > sequenceList.GetElem(i))
                {
                    i++;
                    compare++;
                }
                if (i < j)
                {
                    sequenceList.SetElem(j, sequenceList.GetElem(i));
                    j--;
                    move++;
                    compare++;
                }
            }
            sequenceList.SetElem(i, temp);
            all += move;
            allc += compare;
            move = 0;
            if (l < i - 1)
            {
                q.push(l);
                q.push(i - 1);
            }
            if (i + 1 < h)
            {
                q.push(i + 1);
                q.push(h);
            }
        }
        still = false;
        count++;
        while (!q.empty())
        {
            s.push(q.front());
            q.pop();
            still = true;
        }
    }
}
template <class ElemType>
void Sort<ElemType>::StraightInsertSort(ElemType *elems, int length)
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
void Sort<ElemType>::BinaryInsertSort(ElemType *elems, int length)
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
void Sort<ElemType>::TwoWayInsertSort(SequenceList<ElemType> &sequenceList)
{
    ElemType *result = new int[sequenceList.GetLength()];
    int head = 0;
    int tail = 0;
    result[0] = sequenceList.GetElem(0);
    for (int i = 1; i < sequenceList.GetLength(); i++)
    {
        ElemType temp = sequenceList.GetElem(i);
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
        sequenceList.SetElem(count, result[i]);
    }
    sequenceList.SetElem(0, result[head]);
    delete[] result;
}
template <class ElemType>
void Sort<ElemType>::ShellSort(ElemType *elems, int length)
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
void Sort<ElemType>::MergeSort(ElemType *elems, int length)
{
    int intervalLength = 1;
    while (intervalLength < length)
    {
        int index = 0;
        while (index + 2 * intervalLength <= length)
        {
            Merge(elems, index, index + intervalLength - 1, index + 2 * intervalLength - 1);
            index += 2 * intervalLength;
        }
        if (index + intervalLength < length)
        {
            Merge(elems, index, index + intervalLength - 1, length - 1);
        }
        intervalLength *= 2;
    }
}
template <class ElemType>
void Sort<ElemType>::MergeSortWithRecursion(ElemType *elems, int length)
{
    MergeSortWithRecursion(elems, length, 0, length - 1);
}
template <class ElemType>
void Sort<ElemType>::MergeSortWithRecursion(ElemType *elems, int length, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int middle = (low + high) / 2;
    MergeSortWithRecursion(elems, length, low, middle);
    MergeSortWithRecursion(elems, length, middle + 1, high);
    Merge(elems, low, middle, high);
}
template <class ElemType>
void Sort<ElemType>::MonkeySort(ElemType *elems, int length)
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
template <class ElemType>
void Sort<ElemType>::CountSort(SequenceList<ElemType> &sequenceList)
{
    int *indexes = new int[sequenceList.GetLength()]{0};
    for (int i = 0; i < sequenceList.GetLength(); i++)
    {
        for (int j = 0; j < sequenceList.GetLength(); j++)
        {
            if (sequenceList.GetElem(j) < sequenceList.GetElem(i))
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
        result.SetElem(indexes[i], sequenceList.GetElem(i));
    }
    sequenceList = result;
    delete[] indexes;
}
#endif