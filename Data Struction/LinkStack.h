#ifndef __LK_STACK_H__
#define __LK_STACK_H__
#include "Assistance.h"
#include "Node.h"
template <class ElemType>
class LinkStack
{
protected:
    Node<ElemType> *_elems;

public:
    LinkStack();
    virtual ~LinkStack();
    int GetLength() const;
    bool IsEmpty() const;
    void Clear();
    void Traverse(void (*Visit)(const ElemType &)) const;
    Status Push(const ElemType e);
    Status Top(ElemType &e) const;
    Status Pop(ElemType &e);
    LinkStack(const LinkStack<ElemType> &s);
    LinkStack<ElemType> &operator=(const LinkStack<ElemType> &s);
};
template <class ElemType>
LinkStack<ElemType>::LinkStack()
{
    _elems = NULL;
}
template <class ElemType>
LinkStack<ElemType>::~LinkStack()
{
    Node<ElemType> *p;
    while (_elems != NULL)
    {
        p = top;
        top = top->next;
        delete p;
    }
}
template <class ElemType>
int LinkStack<ElemType>::GetLength() const
{
    int count = 0;
    Node<ElemType> *p = _elems;
    while (p!=NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
template <class EElemType>
bool LinkStack<ElemType>::IsEmpyty() const
{
    return _elems == NULL;
}
template <class ElemType>
void LinkStack<ElemType>::Clear()
{
    Node<ElemType> *p;
    while (_elems != NULL)
    {
        p = top;
        top = top->next;
        delete p;
    }
}
template <class ElemType>
void LinkStack<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
    Node<ElemType> *p=top;
    while (p != NULL)
    {
        (*Visit)(p->data);
        p = p->next;
    }
}
template <class ElemType>
Status LinkStack<ElemType>::Push(const ElemType e)
// �����������Ԫ��e׷�ӵ�ջ��,��ɹ��򷵼�SUCCESS,�����綯̬�ڴ��Ѻľ�
//	������OVER_FLOW
{
    Node<ElemType> *p = new Node<ElemType>(e, top);
    if (p == NULL) // ϵͳ�ڴ�ľ�
        return OVER_FLOW;
    else
    { // �����ɹ�
        top = p;
        return SUCCESS;
    }
}

template <class ElemType>
Status LinkStack<ElemType>::Top(ElemType &e) const
// �����������ջ�ǿ�,��e����ջ��Ԫ��,��������SUCCESS,����������UNDER_FLOW
{
    if (IsEmpty()) // ջ��
        return UNDER_FLOW;
    else
    {                  // ջ�ǿ�,�����ɹ�
        e = top->data; // ��e����ջ��Ԫ��
        return SUCCESS;
    }
}

template <class ElemType>
Status LinkStack<ElemType>::Pop(ElemType &e)
{
    if (IsEmpty())
        return UNDER_FLOW;
    else
    {                            // �����ɹ�
        Node<ElemType> *p = top; // ����ԭջ��
        e = top->data;           // ��e����ջ��Ԫ��
        top = top->next;         // �޸�ջ��
        delete p;                // ɾ��ԭջ�����
        return SUCCESS;
    }
}
#endif