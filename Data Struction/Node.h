#pragma once
#ifndef __NODE_H__
#define __NODE_H__
template <class ElemType>
struct Node
{
	ElemType data_;
	Node<ElemType> *next_;
	Node();
	Node(ElemType e, Node<ElemType> *next = NULL);
};
template <class ElemType>
Node<ElemType>::Node() : data_(0), next_(NULL)
{
}
template <class ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType> *next) : data_(e), next_(next)
{
}
#endif
