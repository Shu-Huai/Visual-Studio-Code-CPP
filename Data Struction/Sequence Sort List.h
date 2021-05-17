#pragma once
#ifndef __SEQUENCE_SORT_LIST_H__
#define __SEQUENCE_SORT_LIST_H__
#include "Sequence List.h"
template <class ElemType>
class SequenceSortList : public SequenceList<ElemType>
{
public:
    SequenceSortList(int maxLength = 1000);
    SequenceSortList(ElemType *elems, int length, int maxLength = 1000);
    void Swap(int indexA, int indexB);
    void BubbleSort();
    void QuickSort(int low, int high);
    void StraightInsertSort();
    void BinaryInsertSort();
};
template <class ElemType>
SequenceSortList<ElemType>::SequenceSortList(int maxLength) : SequenceList<ElemType>(maxLength)
{
}
template <class ElemType>
SequenceSortList<ElemType>::SequenceSortList(ElemType *elems, int length, int maxLength) : SequenceList<ElemType>(elems, length, maxLength)
{
}
template <class ElemType>
void SequenceSortList<ElemType>::Swap(int indexA, int indexB)
{
    ElemType temp = this->elems_[indexA];
    this->elems_[indexA] = this->elems_[indexB];
    this->elems_[indexB] = temp;
}
template <class ElemType>
void SequenceSortList<ElemType>::BubbleSort()
{
    for (int i = 0; i < this->length_; i++)
    {
        for (int j = 0; j < this->length_ - 1; j++)
        {
            if (this->elems_[j] > this->elems_[j + 1])
            {
                Swap(j, j + 1);
            }
        }
    }
}
template <class ElemType>
void SequenceSortList<ElemType>::QuickSort(int low, int high)
{
    if (low < high)
    {
        ElemType referenceValue = this->elems_[low];
        int i = low;
        int j = high;
        while (i < j)
        {
            while (i < j && this->elems_[j] >= referenceValue)
            {
                j--;
            }
            if (i < j)
            {
                this->elems_[i] = this->elems_[j];
                i++;
            }
            while (i < j && this->elems_[i] <= referenceValue)
            {
                i++;
            }
            if (i < j)
            {
                this->elems_[j] = this->elems_[i];
                j--;
            }
        }
        this->elems_[i] = referenceValue;
        QuickSort(low, i - 1);
        QuickSort(i + 1, high);
    }
}
template <class ElemType>
void SequenceSortList<ElemType>::StraightInsertSort()
{
    for (int i = 1; i < this->length_; i++)
    {
        int j = i - 1;
        ElemType temp = this->elems_[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (this->elems_[j] <= temp)
            {
                break;
            }
            this->elems_[j + 1] = this->elems_[j];
        }
        this->elems_[j + 1] = temp;
    }
}
template <class ElemType>
void SequenceSortList<ElemType>::BinaryInsertSort()
{
    for (int i = 1; i < this->length_; i++)
    {
        int low = 0;
        int high = i - 1;
        int middle = 0;
        ElemType key = this->elems_[i];
        while (low <= high)
        {
            middle = (low + high) / 2;
            if (key < this->elems_[middle])
            {
                high = middle - 1;
            }
            else if (key > this->elems_[middle])
            {
                low = middle + 1;
            }
        }
        for (int j = i - 1; j >= low; j--)
        {
            this->elems_[j + 1] = this->elems_[j];
        }
        this->elems_[low] = key;
    }
}
#endif