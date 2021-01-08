#pragma once
#ifndef __LK_LIST_H__
#define __LK_LIST_H__
#include "Assistance.h"
#include "Node.h"
template <class ElemType>
class LinkList
{
protected:
	Node<ElemType> *head_;
	int length_;

public:
	LinkList();
	LinkList(ElemType v[], int n);
	virtual ~LinkList();
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
	LinkList(const LinkList<ElemType> &LL);
	LinkList<ElemType> &operator=(const LinkList<ElemType> &LL);
	void Reverse();
	Status DeleteBetween(ElemType low, ElemType high);
	void Merge(LinkList<ElemType> &LL);
};
template <class ElemType>
LinkList<ElemType>::LinkList() : length_(0)
{
	head_ = new Node<ElemType>;
	assert(head_);
}
template <class ElemType>
LinkList<ElemType>::LinkList(ElemType v[], int n) : length_(n)
{
	head_ = new Node<ElemType>;
	assert(head_ != 0);
	Node<ElemType> *p = head_;
	for (int i = 0; i < n; i++)
	{
		p->next_ = new Node<ElemType>(v[i], NULL);
		assert(p->next_);
		p = p->next_;
	}
}
template <class ElemType>
LinkList<ElemType>::~LinkList()
{
	Clear();
	delete head_;
}
template <class ElemType>
int LinkList<ElemType>::GetLength() const
{
	return length_;
}
template <class ElemType>
bool LinkList<ElemType>::IsEmpty() const
{
	return head_->next_ == NULL;
}
template <class ElemType>
void LinkList<ElemType>::Clear()
{
	Node<ElemType> *p = head_->next_;
	while (p != NULL)
	{
		head_->next_ = p->next_;
		delete p;
		p = head_->next_;
	}
	length_ = 0;
}
template <class ElemType>
void LinkList<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
	Node<ElemType> *p = head_->next_;
	while (p != NULL)
	{
		(*Visit)(p->data_);
		p = p->next_;
	}
}
template <class ElemType>
int LinkList<ElemType>::LocateElem(const ElemType &e) const
{
	Node<ElemType> *p = head_->next_;
	int count = 1;
	while (p != NULL and p->data_ != e)
	{
		count++;
		p = p->next_;
	}
	return (p != NULL) ? count : 0;
}

template <class ElemType>
Status LinkList<ElemType>::GetElem(int position, ElemType &e) const
{
	if (position < 1 or position > length_)
	{
		return RANGE_ERROR;
	}
	Node<ElemType> *p = head_;
	for (int j = 0; j < position; j++)
	{
		p = p->next_;
	}
	e = p->data_;
	return ENTRY_FOUND;
}
template <class ElemType>
Status LinkList<ElemType>::SetElem(int position, const ElemType &e)
{
	if (position < 1 or position > length_)
	{
		return RANGE_ERROR;
	}
	Node<ElemType> *p = head_;
	for (int j = 0; j < position; j++)
	{
		p = p->next_;
	}
	p->data_ = e;
	return SUCCESS;
}
template <class ElemType>
Status LinkList<ElemType>::DeleteElem(int position, ElemType &e)
{
	if (position < 1 or position > length_)
	{
		return RANGE_ERROR;
	}
	Node<ElemType> *p = head_;
	for (int j = 0; j < position - 1; j++)
	{
		p = p->next_;
	}
	Node<ElemType> *q = p->next_;
	p->next_ = p->next_->next_;
	e = q->data_;
	delete q;
	length_--;
	return SUCCESS;
}
template <class ElemType>
Status LinkList<ElemType>::InsertElem(int position, const ElemType &e)
{
	if (position < 1 or position > length_ + 1)
	{
		return RANGE_ERROR;
	}
	Node<ElemType> *p = head_;
	int count;
	for (int j = 0; j < position - 1; j++)
	{
		p = p->next_;
	}
	Node<ElemType> *q;
	q->data_ = e;
	q->next_ = p->next_;
	p->next_ = q;
	length_++;
	return SUCCESS;
}
template <class ElemType>
Status LinkList<ElemType>::InsertElem(const ElemType &e)
{
	Node<ElemType> *p = head_;
	while (p->next_ != NULL)
	{
		p = p->next_;
	}
	Node<ElemType> *q = new Node<ElemType>(e, NULL);
	p->next_ = q;
	length_++;
	return SUCCESS;
}
template <class ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType> &LL) : length_(0)
{
	head_ = new Node<ElemType>;
	assert(head_);
	*this = LL;
}
template <class ElemType>
LinkList<ElemType> &LinkList<ElemType>::operator=(const LinkList<ElemType> &LL)
{
	if (&LL != this)
	{
		int length = LL.GetLength();
		ElemType e;
		Clear();
		for (int i = 0; i < length; i++)
		{
			LL.GetElem(i + 1, e);
			InsertElem(e);
		}
	}
	return *this;
}
template <class ElemType>
void LinkList<ElemType>::Reverse()
{
	Node<ElemType> *p = head_->next_, *q;
	head_->next_ = NULL;
	while (p != NULL)
	{
		q = p->next_;
		p->next_ = head_->next_;
		head_->next_ = p;
		p = q;
	}
}
template <class ElemType>
Status LinkList<ElemType>::DeleteBetween(ElemType low, ElemType high)
{
	if (low >= high or head_->next_ == NULL)
	{
		return RANGE_ERROR;
	}
	Node<ElemType> *p = head_;
	while (p != NULL)
	{
		if (p->next_ != NULL)
		{
			if (p->next_->data_ > low and p->next_->data_ < high)
			{
				Node<ElemType> *q = p->next_;
				p->next_ = q->next_;
				length_--;
				delete q;
			}
			else
			{
				p = p->next_;
			}
		}
		else
		{
			p = p->next_;
		}
	}
	return SUCCESS;
}
template <class ElemType>
void LinkList<ElemType>::Merge(LinkList<ElemType> &LL)
{
	Node<ElemType> *p = head_;
	int i = 0;
	while (p != NULL)
	{
		if (i == LL.GetLength())
		{
			break;
		}
		ElemType temp;
		LL.GetElem(i + 1, temp);
		Node<ElemType> *t = new Node<ElemType>;
		t->data_ = temp;
		if (p->data_ >= temp and p == head_->next_)
		{
			t->next_ = p;
			head_->next_ = t;
			p = head_;
			i++;
			length_++;
		}
		else if (p->data_ < temp and p->next_ == NULL)
		{
			t->next_ = NULL;
			p->next_ = t;
			i++;
			length_++;
		}
		else if (p->data_ < temp and p->next_->data_ >= temp)
		{
			t->next_ = p->next_;
			p->next_ = t;
			i++;
			length_++;
		}
		p = p->next_;
	}
	Reverse();
}
#endif