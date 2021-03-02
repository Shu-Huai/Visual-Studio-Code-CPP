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
    MinHeap(ElemType a[], int n, int maxsize = DEFAULT_SIZE);
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