#pragma once
#ifndef __DOUBLE_LINK_LIST_NODE_H__
#define __DOUBLE_LINK_LIST_NODE_H__
#include "Assistance.h"
template <class ElemType>
struct DoubleLinkListNode
{
	ElemType data_;
	DoubleLinkListNode<ElemType> *prior_;
	DoubleLinkListNode<ElemType> *next_;
	DoubleLinkListNode();
	DoubleLinkListNode(ElemType e, DoubleLinkListNode<ElemType> *prior = NULL, DoubleLinkListNode<ElemType> *next = NULL);
};
template <class ElemType>
DoubleLinkListNode<ElemType>::DoubleLinkListNode() : prior_(NULL), next_(NULL)
{
}
template <class ElemType>
DoubleLinkListNode<ElemType>::DoubleLinkListNode(ElemType e, DoubleLinkListNode<ElemType> *prior, DoubleLinkListNode<ElemType> *next) : data_(e), prior_(prior), next_(next)
{
}
#endif
