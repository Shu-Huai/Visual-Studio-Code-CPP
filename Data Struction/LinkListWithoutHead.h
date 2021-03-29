#ifndef __LK_LIST_NO_HEAD_H__
#define __LK_LIST_NO_HEAD_H__
#include "Node.h"
template <class ElemType>
class LinkList
{
protected:
	Node<ElemType> *head_;
	int length_;

public:
	LinkList();
	LinkList(ElemType *v, int n);
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
	void Merge(LinkList<ElemType> &LL);
};
template <class ElemType>
LinkList<ElemType>::LinkList() : head_(NULL), length_(0)
{
}
template <class ElemType>
LinkList<ElemType>::LinkList(ElemType *v, int n) : length_(n)
{
	if (n)
	{
		head_ = new Node<ElemType>(v[0], NULL);
		assert(head_);
		Node<ElemType> *p = head_;
		for (int i = 1; i < n; i++)
		{
			Node<ElemType> *q = new Node<ElemType>(v[i], NULL);
			assert(q);
			p->next_ = q;
			p = p->next_;
		}
	}
}
template <class ElemType>
LinkList<ElemType>::~LinkList()
{
	Clear();
 	}
template <class ElemType>
int LinkList<ElemType>::GetLength() const
{
	return length_;
}
template <class ElemType>
bool LinkList<ElemType>::IsEmpty() const
{
	return head_ == NULL;
}
template <class ElemType>
void LinkList<ElemType>::Clear()
{
	Node<ElemType> *p;
	while (head_ != NULL)
	{
		p = head_;
		head_ = head_->next_;
		delete p;
	}
	length_ = 0;
}
template <class ElemType>
void LinkList<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
	Node<ElemType> *p = head_;
	while (p)
	{
		(*Visit)(p->data_);
		p = p->next_;
	}
}
template <class ElemType>
int LinkList<ElemType>::LocateElem(const ElemType &e) const
{
	Node<ElemType> *p = head_;
	int count = 1;
	while (p and p->data_ != e)
	{
		count++;
		p = p->next_;
	}
	return (p) ? count : 0;
}
template <class ElemType>
Status LinkList<ElemType>::GetElem(int position, ElemType &e) const
{
	if (position < 1 or position > length_)
	{
		return RANGE_ERROR;
	}
	Node<ElemType> *p = head_;
	for (int i = 1; i < position; i++)
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
	for (int i = 1; i < position; i++)
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
	if (position == 1)
	{
		Node<ElemType> *q = p->next_;
		head_ = q;
		e = p->data_;
		delete p;
	}
	else
	{
		for (int i = 1; i < position - 1; i++)
		{
			p = p->next_;
		}
		Node<ElemType> *q = p->next_;
		p->next_ = p->next_->next_;
		e = q->data_;
		delete q;
	}
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
	Node<ElemType> *q = new Node<ElemType>(e, NULL);
	assert(q);
	if (position == 1)
	{
		q->next_ = head_;
		head_ = q;
	}
	else
	{
		for (int i = 1; i < position - 1; i++)
		{
			p = p->next_;
		}
		q->next_ = p->next_;
		p->next_ = q;
	}
	length_++;
	return SUCCESS;
}
template <class ElemType>
Status LinkList<ElemType>::InsertElem(const ElemType &e)
{
	Node<ElemType> *q = new Node<ElemType>(e, NULL);
	assert(q);
	if (head_ == NULL)
	{
		head_ = q;
	}
	else
	{
		Node<ElemType> *p = head_;
		while (p->next_ != NULL)
		{
			p = p->next_;
		}
		p->next_ = q;
	}
	length_++;
	return SUCCESS;
}
template <class ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType> &LL) : length_(LL.length_)
{
	ElemType e;
	head_ = new Node<ElemType>;
	assert(head_);
	for (int i = 0; i < LL.length_; i++)
	{
		LL.GetElem(i, e);
		InsertElem(e);
	}
}
template <class ElemType>
LinkList<ElemType> &LinkList<ElemType>::operator=(const LinkList<ElemType> &LL)
{
	if (&LL != this)
	{
		ElemType e;
		Clear();
		for (int i = 0; i < LL.length_; i++)
		{
			LL.GetElem(i, e);
			InsertElem(e);
		}
	}
	return *this;
}
template <class ElemType>
void LinkList<ElemType>::Reverse()
{
	Node<ElemType> *temp = new Node<ElemType>;
	temp->next_ = head_;
	Node<ElemType> *p = temp->next_, *q;
	temp->next_ = NULL;
	while (p != NULL)
	{
		q = p->next_;
		p->next_ = temp->next_;
		temp->next_ = p;
		p = q;
	}
	head_ = temp->next_;
	delete temp;
}
template <class ElemType>
void LinkList<ElemType>::Merge(LinkList<ElemType> &LL)
{
	Node<ElemType> *q = new Node<ElemType>;
	q->next_ = head_;
	Node<ElemType> *p = new Node<ElemType>;
	p->next_ = head_;
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
		if (p->data_ >= temp and p == q->next_)
		{
			t->next_ = p;
			q->next_ = t;
			p = q;
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
	head_ = q->next_;
	Reverse();
	delete q;
}
#endif