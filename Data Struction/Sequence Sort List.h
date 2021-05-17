#pragma once
#ifndef __SEQUENCE_SORT_LIST_H__
#define __SEQUENCE_SORT_LIST_H__
#include "Sequence List.h"
template <class ElemType>
class SequenceSortList : public SequenceList<ElemType>
{
public:
    SequenceSortList(int maxLength = DEFAULT_SIZE);
    SequenceSortList(ElemType *elems, int length, int maxLength = DEFAULT_SIZE);
    void Swap(int indexA, int indexB);
    void BubbleSort(bool isReverse = false);
    void QuickSort(int low, int high)
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
    ElemType temp;
    temp = this->elems_[indexA];
    this->elems_[indexA] = this->elems_[indexB];
    this->elems_[indexB] = temp;
}
template <class ElemType>
void SequenceSortList<ElemType>::BubbleSort(bool isReverse)
{
    for (int i = 0; i < this->length_; i++)
    {
        for (int j = 0; j < this->length_ - 1; j++)
        {
            if ((this->elems_[j] > this->elems_[j + 1] && !isReverse) || (this->elems_[j] < this->elems_[j + 1] && isReverse))
            {
                Swap(i, j);
            }
        }
    }
}

#endif