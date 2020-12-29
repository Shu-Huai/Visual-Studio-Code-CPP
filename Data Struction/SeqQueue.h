#pragma once
#ifndef __SQ_QUEUE_H__
#define __SQ_QUEUE_H__
#include "Assistance.h"
template <class ElemType>
class SeqQueue
{
protected:
    int _front, _rear;
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
    SeqQueue(const SeqQueue<ElemType> &q);
    SeqQueue<ElemType> &operator=(const SeqQueue<ElemType> &q);
};
template <class ElemType>
SeqQueue<ElemType>::SeqQueue(int size) : maxsize_(size), _front(0), _rear(0)
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
    return (_rear - _front + maxsize_) % maxsize_;
}
template <class ElemType>
bool SeqQueue<ElemType>::IsEmpty() const
{
    return _rear == _front;
}
template <class ElemType>
void SeqQueue<ElemType>::Clear()
{
    _front = 0;
    _rear = 0;
}
template <class ElemType>
void SeqQueue<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
    for (int i = _front; i != _rear; i = (i + 1) % maxsize_)
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
    e = elems_[_front];
    _front = (_front + 1) % maxsize_;
    return SUCCESS;
}
template <class ElemType>
Status SeqQueue<ElemType>::GetHead(ElemType &e) const
{
    if (IsEmpty())
    {
        return UNDER_FLOW;
    }
    e = elems_[_front];
    return SUCCESS;
}

template <class ElemType>
Status SeqQueue<ElemType>::EnQueue(const ElemType e)
{
    if ((_rear + 1) % maxsize_ == _front)
    {
        return OVER_FLOW;
    }
    elems_[_rear] = e;
    _rear = (_rear + 1) % maxsize_;
    return SUCCESS;
}
template <class ElemType>
SeqQueue<ElemType>::SeqQueue(const SeqQueue<ElemType> &SQ) : maxsize_(SQ.maxsize_), _front(SQ._front), _rear(SQ._rear)
{
    elems_ = new ElemType[maxsize_];
    for (int i = _front; i <= _rear; i = (i + 1) % maxsize_)
    {
        elems_[i] = SQ.elems_[i];
    }
}
template <class ElemType>
SeqQueue<ElemType> &SeqQueue<ElemType>::operator=(const SeqQueue<ElemType> &q)
{
    if (&q != this)
    {
        maxsize_ = q.maxsize_;
        if (elems_ != NULL)
            delete[] elems_;
        elems_ = new ElemType[maxsize_];
        _front = q._front;
        _rear = q._rear;
        for (int i = _front; i != _rear; i = (i + 1) % maxsize_)
            elems_[i] = q.elems_[i];
    }
    return *this;
}
#endif