#pragma once
#ifndef __SQ_QUEUE_H__
#define __SQ_QUEUE_H__
#include "Assistance.h"
template <class ElemType>
class SeqQueue
{
protected:
    int _front, _rear;
    int _maxsize;
    ElemType *_elems;

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
SeqQueue<ElemType>::SeqQueue(int size) : _maxsize(size), _front(0), _rear(0)
{
    _elems = new ElemType[_maxsize];
}
template <class ElemType>
SeqQueue<ElemType>::~SeqQueue()
{
    delete[] _elems;
}

template <class ElemType>
int SeqQueue<ElemType>::GetLength() const
{
    return (_rear - _front + _maxsize) % _maxsize;
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
    for (int i = _front; i != _rear; i = (i + 1) % _maxsize)
    {
        (*Visit)(_elems[i]);
    }
}
template <class ElemType>
Status SeqQueue<ElemType>::DelQueue(ElemType &e)
{
    if (IsEmpty())
    {
        return UNDER_FLOW;
    }
    e = _elems[_front];
    _front = (_front + 1) % _maxsize;
    return SUCCESS;
}
template <class ElemType>
Status SeqQueue<ElemType>::GetHead(ElemType &e) const
{
    if (IsEmpty())
    {
        return UNDER_FLOW;
    }
    e = _elems[_front];
    return SUCCESS;
}

template <class ElemType>
Status SeqQueue<ElemType>::EnQueue(const ElemType e)
{
    if ((_rear + 1) % _maxsize == _front)
    {
        return OVER_FLOW;
    }
    _elems[_rear] = e;
    _rear = (_rear + 1) % _maxsize;
    return SUCCESS;
}
template <class ElemType>
SeqQueue<ElemType>::SeqQueue(const SeqQueue<ElemType> &SQ) : _maxsize(SQ._maxsize), _front(SQ._front), _rear(SQ._rear)
{
    _elems = new ElemType[_maxsize];
    for (int i = _front; i <= _rear; i = (i + 1) % _maxsize)
    {
        _elems[i] = SQ._elems[i];
    }
}
template <class ElemType>
SeqQueue<ElemType> &SeqQueue<ElemType>::operator=(const SeqQueue<ElemType> &q)
{
    if (&q != this)
    {
        _maxsize = q._maxsize;
        if (_elems != NULL)
            delete[] _elems;
        _elems = new ElemType[_maxsize];
        _front = q._front;
        _rear = q._rear;
        for (int i = _front; i != _rear; i = (i + 1) % _maxsize)
            _elems[i] = q._elems[i];
    }
    return *this;
}
#endif