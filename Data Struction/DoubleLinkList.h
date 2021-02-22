#pragma once
#ifndef __DOUBLE_LINK_LIST_H__
#define __DOUBLE_LINK_LIST_H__
#include "DoubleLinkListNode.h"
template <class ElemType>
class DoubleLinkList
{
protected:
	DoubleLinkListNode<ElemType> *head_;
	int length_;

public:
	DoubleLinkList();
	DoubleLinkList(ElemType v[], int n);
	virtual ~DoubleLinkList();
	int GetLength() const;
	bool IsEmpty() const;
	void Clear();
	void Traverse(void (*Visit)(const ElemType &)) const;
	int LocateElem(const ElemType &e) const;
	Status GetElem(int position, ElemType &e) const;
	Status SetElem(int position, const ElemType &e);
	Status DeleteElem(int position, ElemType &e);
	Status InsertElem(int position, const ElemType &e);
	Status InsertElem(const ElemType &e);
	DoubleLinkList(const DoubleLinkList<ElemType> &DLL);
	DoubleLinkList<ElemType> &operator=(const DoubleLinkList<ElemType> &DLL);
};
template <class ElemType>
DoubleLinkList<ElemType>::DoubleLinkList() : length_(0)
{
	head_ = new DoubleLinkListNode<ElemType>;
	assert(head_);
	head_->prior_ = head_;
	head_->next_ = head_;
}
template <class ElemType>
DoubleLinkList<ElemType>::DoubleLinkList(ElemType v[], int n) : length_(n)
{
	head_ = new DoubleLinkListNode<ElemType>;
	DoubleLinkListNode<ElemType> *p = head_;
	assert(head_);
	for (int i = 0; i < n; i++)
	{
		p->next_ = new DoubleLinkListNode<ElemType>(v[i], p, NULL);
		assert(p->next_);
		p = p->next_;
	}
	head_->prior_ = p;
	p->next_ = head_;
}
template <class ElemType>
DoubleLinkList<ElemType>::~DoubleLinkList()
{
	Clear();
	delete head_;
}
template <class ElemType>
int DoubleLinkList<ElemType>::GetLength() const
{
	return length_;
}
template <class ElemType>
bool DoubleLinkList<ElemType>::IsEmpty() const
{
	return head_->next_ == head_;
}
template <class ElemType>
void DoubleLinkList<ElemType>::Clear()
{
	DoubleLinkListNode<ElemType> *p = head_->next_;
	while (p != head_)
	{
		head_->next_ = p->next_;
		delete p;
		p = head_->next_;
	}
	length_ = 0;
}
template <class ElemType>
void DoubleLinkList<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
	DoubleLinkListNode<ElemType> *p = head_->next_;
	while (p != head_)
	{
		(*Visit)(p->data_);
		p = p->next_;
	}
}
template <class ElemType>
int DoubleLinkList<ElemType>::LocateElem(const ElemType &e) const
{
	DoubleLinkListNode<ElemType> *p = head_->next_;
	int count = 1;
	while (p != head_ and p->data_ != e)
	{
		count++;
		p = p->next_;
	}
	return (p != head_) ? count : 0;
}
template <class ElemType>
Status DoubleLinkList<ElemType>::GetElem(int position, ElemType &e) const
{
	if (position < 1 or position > length_)
	{
		return RANGE_ERROR;
	}
	DoubleLinkListNode<ElemType> *p = head_;
	for (int i = 0; i < position; i++)
	{
		p = p->next_;
	}
	e = p->data_;
	return ENTRY_FOUND;
}
template <class ElemType>
Status DoubleLinkList<ElemType>::SetElem(int position, const ElemType &e)
{
	if (position < 1 or position > length_)
	{
		return RANGE_ERROR;
	}
	DoubleLinkListNode<ElemType> *p = head_;
	for (int i = 0; i < position; i++)
	{
		p = p->next_;
	}
	p->data_ = e;
	return SUCCESS;
}
template <class ElemType>
Status DoubleLinkList<ElemType>::DeleteElem(int position, ElemType &e)
{
	if (position < 1 or position > length_)
	{
		return RANGE_ERROR;
	}
	DoubleLinkListNode<ElemType> *p = head_;
	for (int i = 0; i < position; i++)
	{
		p = p->next_;
	}
	p->prior_->next_ = p->next_;
	p->next_->prior_ = p->prior_;
	e = p->data_;
	delete p;
	length_--;
	return SUCCESS;
}
template <class ElemType>
Status DoubleLinkList<ElemType>::InsertElem(int position, const ElemType &e)
{
	if (position < 1 or position > length_ + 1)
	{
		return RANGE_ERROR;
	}
	DoubleLinkListNode<ElemType> *p = head_;
	for (int i = 0; i < position - 1; i++)
	{
		p = p->next_;
	}
	DoubleLinkListNode<ElemType> *q = new DoubleLinkListNode<ElemType>(e, p, p->next_);
	p->next_ = q;
	length_++;
	return SUCCESS;
}
template <class ElemType>
Status DoubleLinkList<ElemType>::InsertElem(const ElemType &e)
{
	DoubleLinkListNode<ElemType> *p = new DoubleLinkListNode<ElemType>(e, head_->prior_, head_);
	assert(p);
	head_->prior_->next_ = p;
	head_->prior_ = p;
	length_++;
	return SUCCESS;
}
template <class ElemType>
DoubleLinkList<ElemType>::DoubleLinkList(const DoubleLinkList<ElemType> &DLL) : length_(DLL.length_)
{
	head_ = new DoubleLinkListNode<ElemType>;
	assert(head_);
	*this = DLL;
}
template <class ElemType>
DoubleLinkList<ElemType> &DoubleLinkList<ElemType>::operator=(const DoubleLinkList<ElemType> &DLL)
{
	if (&DLL != this)
	{
		int length = DLL.length_;
		ElemType e;
		Clear();
		for (int i = 0; i < length; i++)
		{
			DLL.GetElem(i + 1, e);
			InsertElem(e);
		}
	}
	return *this;
}
#endif