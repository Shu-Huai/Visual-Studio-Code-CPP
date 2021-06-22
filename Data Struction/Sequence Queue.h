#pragma once
#ifndef __SQUENCE_QUEUE_H__
#define __SQUENCE_QUEUE_H__
#include <iostream>
using namespace std;
template <class ElemType>
class SequenceQueue
{
protected:
    int front_, rear_;
    int maxSize_;
    ElemType *elems_;

public:
    SequenceQueue(int maxSize = 1000);
    SequenceQueue(const SequenceQueue<ElemType> &queue);
    virtual ~SequenceQueue();
    void Clear();
    bool IsEmpty() const;
    void Display() const;
    void Traverse() const;
    void Push(const ElemType elem);
    void Pop();
    int GetLength() const;
    ElemType GetFront() const;
    SequenceQueue<ElemType> &operator=(const SequenceQueue<ElemType> &queue);
};
template <class ElemType>
SequenceQueue<ElemType>::SequenceQueue(int maxSize) : front_(0), rear_(0), maxSize_(maxSize)
{
    elems_ = new ElemType[maxSize_];
}
template <class ElemType>
SequenceQueue<ElemType>::SequenceQueue(const SequenceQueue<ElemType> &queue) : maxSize_(queue.maxSize_), front_(queue.front_), rear_(queue.rear_)
{
    elems_ = new ElemType[maxSize_];
    for (int i = front_; i <= rear_; i = (i + 1) % maxSize_)
    {
        elems_[i] = queue.elems_[i];
    }
}
template <class ElemType>
SequenceQueue<ElemType>::~SequenceQueue()
{
    delete[] elems_;
}
template <class ElemType>
void SequenceQueue<ElemType>::Clear()
{
    front_ = 0;
    rear_ = 0;
}
template <class ElemType>
bool SequenceQueue<ElemType>::IsEmpty() const
{
    return rear_ == front_;
}
template <class ElemType>
void SequenceQueue<ElemType>::Display() const
{
    for (int i = front_; i != rear_; i = (i + 1) % maxSize_)
    {
        cout << elems_[i];
        if (i == front_)
        {
            cout << " <- 头";
        }
        cout << endl;
    }
    cout << "长度是：" << GetLength() << endl;
}
template <class ElemType>
void SequenceQueue<ElemType>::Traverse() const
{
    for (int i = front_; i != rear_; i = (i + 1) % maxSize_)
    {
        cout << elems_[i] << " ";
    }
    cout << endl;
}
template <class ElemType>
void SequenceQueue<ElemType>::Push(const ElemType elem)
{
    if ((rear_ + 1) % maxSize_ == front_)
    {
        throw string("队满。");
    }
    elems_[rear_] = elem;
    rear_ = (rear_ + 1) % maxSize_;
}
template <class ElemType>
void SequenceQueue<ElemType>::Pop()
{
    if (rear_ == front_)
    {
        throw string("队空。");
    }
    front_ = (front_ + 1) % maxSize_;
}
template <class ElemType>
int SequenceQueue<ElemType>::GetLength() const
{
    return (rear_ - front_ + maxSize_) % maxSize_;
}
template <class ElemType>
ElemType SequenceQueue<ElemType>::GetFront() const
{
    if (rear_ == front_)
    {
        throw string("队空。");
    }
    return elems_[front_];
}
template <class ElemType>
SequenceQueue<ElemType> &SequenceQueue<ElemType>::operator=(const SequenceQueue<ElemType> &queue)
{
    if (&queue != this)
    {
        maxSize_ = queue.maxSize_;
        if (elems_)
        {
            delete[] elems_;
        }
        elems_ = new ElemType[maxSize_];
        front_ = queue.front_;
        rear_ = queue.rear_;
        for (int i = front_; i != rear_; i = (i + 1) % maxSize_)
        {
            elems_[i] = queue.elems_[i];
        }
    }
    return *this;
}
#endif