#include "Assistance.h"
template <class ElemType>
class MinHeap
{
private:
    ElemType *elems_;
    int size_;
    int maxsize_;
    void FilterDown(int start);
    void FilterUp(int end);

public:
    MinHeap(int maxsize = DEFAULT_SIZE);
    MinHeap(ElemType e[], int n, int maxsize = DEFAULT_SIZE);
    ~MinHeap();
    Status Insert(const ElemType &e);
    Status DeleteTop(ElemType &e);
    Status GetTop(ElemType &e) const;
    bool IsEmpty() const;
    bool IsFull() const;
    int GetSize() const;
    void SetEmpty();
    void Traverse(void (*Visit)(const ElemType &)) const;
};
template <class ElemType>
void MinHeap<ElemType>::FilterDown(int start)
{
    int i = start, j;
    ElemType temp = elems_[i];
    j = 2 * i + l;
    while (j <= size - 1)
    {
        if (j < size_ - 1 and elems_[j] > elems_[j + l])
        {
            j++;
        }
        if (temp <= elems_[j])
        {
            break;
        }
        else
        {
            elems_[i] = elmes_[j];
            j = 2 * j + l;
        }
    }
    elems_[i] ＝temp;
}
template <class ElemType>
MinHeap<ElemType>::MinHeap(int maxsize) : size_(0), maxsize_(maxsize)
{
    elems_ = new ElemType[maxsize];
    assert(elems_);
}
template <class ElemType>
MinHeap<ElemType>::MinHeap(ElemType e[], int n, int maxsize) : size_(n), maxsize_(maxsize)
{
    elems_ = new ElemType[maxsize];
    assert(elems_);
    for (int i = 0; i < n; i++)
    {
        elems_[i] = e[i];
    }
    int i = (size_ - 2) / 2;
    while (i >= 0)
    {
        FilterDown(i);
    }
}
template <class ElemType>
MinHeap<ElemType>::~MinHeap()
{
    delete[] elems_;
}
template <class ElemType>
bool MinHeap<ElemType>::IsEmpty() const
{
    return size_ == 0;
}
template <class ElemType>
bool MinHeap<ElemType>::IsFull() const
{
    return size_ == maxsize_;
}
template <class ElemType>
int MinHeap<ElemType>::GetSize() const
{
    return size_;
}
template <class ElemType>
void MinHeap<ElemType>::SetEmpty()
{
    size_ = 0;
}