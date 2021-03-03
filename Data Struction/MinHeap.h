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
    int i = start;
    ElemType temp = elems_[i];
    int j = 2 * i + 1;
    while (j <= size_ - 1)
    {
        if (j < size_ - 1 and elems_[j] > elems_[j + 1])
        {
            j++;
        }
        if (temp <= elems_[j])
        {
            break;
        }
        else
        {
            elems_[i] = elems_[j];
            i = j;
            j = 2 * j + 1;
        }
    }
    elems_[i] = temp;
}
template <class ElemType>
void MinHeap<ElemType>::FilterUp(int end)
{
    int j = end;
    ElemType temp = elems_[j];
    int i = (j - 1) / 2;
    while (j > 0)
    {
        if (elems_[i] <= temp)
        {
            break;
        }
        else
        {
            elems_[j] = elems_[i];
            j = i;
            i = (j - 1) / 2;
        }
        elems_[j] = temp;
    }
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
        i--;
    }
}
template <class ElemType>
MinHeap<ElemType>::~MinHeap()
{
    delete[] elems_;
}
template <class ElemType>
Status MinHeap<ElemType>::Insert(const ElemType &e)
{
    if (IsFull())
    {
        return OVER_FLOW;
    }
    elems_[size_] = e;
    FilterUp(size_);
    size_++;
    return SUCCESS;
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
template <class ElemType>
void MinHeap<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
{
    for (int i = 0; i < size_; i++)
    {
        cout << elems_[i] << " ";
    }
    cout << endl;
}