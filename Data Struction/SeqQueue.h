#pragma once
#ifndef __SQ_QUEUE_H__
#define __SQ_QUEUE_H__
#include "Assistance.h"
template <class ElemType>
class SeqQueue
{
protected:
    int front_, rear_;
    int maxsize_;
    ElemType *elems_;

public:
    SeqQueue(int size = DEFAULT_SIZE);
    virtual ~SeqQueue();
    int GetLength() const;
    bool IsEmpty() const;
    void Clear();
    void Traverse(void (*Visit)(const ElemType &)) const;
    Status DelQueue(ElemType &e);
    Status GetHead(ElemType &e) const;
    Status EnQueue(const ElemType e);
    SeqQueue(const SeqQueue<ElemType> &SQ);
    SeqQueue<ElemType> &operator=(const SeqQueue<ElemType> &SQ);
};
template <class ElemType>
SeqQueue<ElemType>::SeqQueue(int size) : maxsize_(size), front_(0), rear_(0)
{
    elems_ = new ElemType[maxsize_];
}
template <class ElemType>
SeqQueue<ElemType>::~SeqQueue()
{
    delete[] elems_;
}

template <class ElemType>
int SeqQueue<ElemType>::GetLength() const
{
    return (rear_ - front_ + maxsize_) % maxsize_;
}
template <class ElemType>
bool SeqQueue<ElemType>::IsEmpty() const
{
    return rear_ == front_;
}
template <class ElemType>
void SeqQueue<ElemType>::Clear()
{
    front_ = 0;
    rear_ = 0;
}
template <class ElemType>
void SeqQueue<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
    for (int i = front_; i != rear_; i = (i + 1) % maxsize_)
    {
        (*Visit)(elems_[i]);
    }
}
template <class ElemType>
Status SeqQueue<ElemType>::DelQueue(ElemType &e)
{
    if (IsEmpty())
    {
        return UNDER_FLOW;
    }
    e = elems_[front_];
    front_ = (front_ + 1) % maxsize_;
    return SUCCESS;
}
template <class ElemType>
Status SeqQueue<ElemType>::GetHead(ElemType &e) const
{
    if (IsEmpty())
    {
        return UNDER_FLOW;
    }
    e = elems_[front_];
    return SUCCESS;
}

template <class ElemType>
Status SeqQueue<ElemType>::EnQueue(const ElemType e)
{
    if ((rear_ + 1) % maxsize_ == front_)
    {
        return OVER_FLOW;
    }
    elems_[rear_] = e;
    rear_ = (rear_ + 1) % maxsize_;
    return SUCCESS;
}
template <class ElemType>
SeqQueue<ElemType>::SeqQueue(const SeqQueue<ElemType> &SQ) : maxsize_(SQ.maxsize_), front_(SQ.front_), rear_(SQ.rear_)
{
    elems_ = new ElemType[maxsize_];
    for (int i = front_; i <= rear_; i = (i + 1) % maxsize_)
    {
        elems_[i] = SQ.elems_[i];
    }
}
template <class ElemType>
SeqQueue<ElemType> &SeqQueue<ElemType>::operator=(const SeqQueue<ElemType> &SQ)
{
    if (&SQ != this)
    {
        maxsize_ = SQ.maxsize_;
        if (elems_ != NULL)
            delete[] elems_;
        elems_ = new ElemType[maxsize_];
        front_ = SQ.front_;
        rear_ = SQ.rear_;
        for (int i = front_; i != rear_; i = (i + 1) % maxsize_)
            elems_[i] = SQ.elems_[i];
    }
    return *this;
}
#endif