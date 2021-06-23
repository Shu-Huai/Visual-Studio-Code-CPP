#pragma once
#ifndef __STACK_SIMULATE_QUQUQ_H__
#define __STACK_SIMULATE_QUQUQ_H__
#include <iostream>
#include <stack>
using namespace std;
template <class ElemType>
class StackSimulateQueue
{
protected:
    stack<ElemType> firstStack_;
    stack<ElemType> secondStack_;

public:
    StackSimulateQueue();
    StackSimulateQueue(const StackSimulateQueue<ElemType> &queue);
    virtual ~StackSimulateQueue();
    void Clear();
    bool IsEmpty() const;
    void Dispay();
    void Traverse();
    void Push(const ElemType elem);
    void Pop();
    int GetLength() const;
    ElemType GetFront();
    StackSimulateQueue<ElemType> &operator=(const StackSimulateQueue<ElemType> &queue);
};
template <class ElemType>
StackSimulateQueue<ElemType>::StackSimulateQueue() : firstStack_(), secondStack_()
{
}
template <class ElemType>
StackSimulateQueue<ElemType>::StackSimulateQueue(const StackSimulateQueue<ElemType> &queue) : firstStack_(queue.firstStack_), secondStack_(queue.secondStack_)
{
}
template <class ElemType>
StackSimulateQueue<ElemType>::~StackSimulateQueue()
{
    Clear();
}
template <class ElemType>
void StackSimulateQueue<ElemType>::Clear()
{
    while (!firstStack_.empty())
    {
        firstStack_.pop();
    }
    while (!secondStack_.empty())
    {
        secondStack_.pop();
    }
}
template <class ElemType>
bool StackSimulateQueue<ElemType>::IsEmpty() const
{
    return firstStack_.empty();
}
template <class ElemType>
void StackSimulateQueue<ElemType>::Dispay()
{
    int length = firstStack_.size();
    if (!length)
    {
        cout << endl;
        return;
    }
    for (int i = 0; i < length; i++)
    {
        secondStack_.push(firstStack_.top());
        firstStack_.pop();
    }
    for (int i = 0; i < length; i++)
    {
        cout << secondStack_.top();
        if (!i)
        {
            cout << " <- 头";
        }
        cout << endl;
        firstStack_.push(secondStack_.top());
        secondStack_.pop();
    }
    cout << "长度是：" << length << endl;
}
template <class ElemType>
void StackSimulateQueue<ElemType>::Traverse()
{
    int length = firstStack_.size();
    if (!length)
    {
        cout << endl;
        return;
    }
    for (int i = 0; i < length; i++)
    {
        secondStack_.push(firstStack_.top());
        firstStack_.pop();
    }
    for (int i = 0; i < length; i++)
    {
        cout << secondStack_.top() << " ";
        firstStack_.push(secondStack_.top());
        secondStack_.pop();
    }
    cout << endl;
}
template <class ElemType>
void StackSimulateQueue<ElemType>::Push(const ElemType elem)
{
    firstStack_.push(elem);
}
template <class ElemType>
void StackSimulateQueue<ElemType>::Pop()
{
    int length = firstStack_.size();
    if (!length)
    {
        throw string("队空。");
    }
    for (int i = 0; i < length; i++)
    {
        secondStack_.push(firstStack_.top());
        firstStack_.pop();
    }
    secondStack_.pop();
    for (int i = 0; i < length - 1; i++)
    {
        firstStack_.push(secondStack_.top());
        secondStack_.pop();
    }
}
template <class ElemType>
int StackSimulateQueue<ElemType>::GetLength() const
{
    return firstStack_.size();
}
template <class ElemType>
ElemType StackSimulateQueue<ElemType>::GetFront()
{
    int length = firstStack_.size();
    if (!length)
    {
        throw string("队空。");
    }
    for (int i = 0; i < length; i++)
    {
        secondStack_.push(firstStack_.top());
        firstStack_.pop();
    }
    ElemType elem = secondStack_.top();
    for (int i = 0; i < length; i++)
    {
        firstStack_.push(secondStack_.top());
        secondStack_.pop();
    }
    return elem;
}
template <class ElemType>
StackSimulateQueue<ElemType> &StackSimulateQueue<ElemType>::operator=(const StackSimulateQueue<ElemType> &queue)
{
    if (this != queue)
    {
        Clear();
        firstStack_ = queue.firstStack_;
        secondStack_ = queue.secondStack_;
    }
    return *this;
}
#endif