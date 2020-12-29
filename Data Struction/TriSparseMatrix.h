#pragma once
#ifndef __TRI_SPARSE_MATRTIX_H__
#define __TRI_SPARSE_MATRTIX_H__
#include "Assistance.h"
template <class ElemType>
struct Tripple
{
    int row_, col_;
    ElemType value_;
    Tripple();
    Tripple(int r, int c, ElemType e);
};
template <class ElemType>
Tripple<ElemType>::Tripple()
{
}
template <class ElemType>
Tripple<ElemType>::Tripple(int r, int c, ElemType e) : row_(r), col_(c), value_(e)
{
}
template <class ElemType>
class TriSparseMatrix
{
protected:
    Tripple<ElemType> *elems_;
    int maxsize_;
    int rows_, cols_;
    int num_;

public:
    TriSparseMatrix(int rows = DEFAULT_SIZE, int cols = DEFAULT_SIZE, int maxsize = DEFAULT_SIZE);
    ~TriSparseMatrix();
    int GetRows() const;
    int GetCols() const;
    int GetNum() const;
    Status SetElem(int r, int c, const ElemType &e);
    Status GetElem(int r, int c, ElemType &e);
    TriSparseMatrix(const TriSparseMatrix<ElemType> &TSM);
    TriSparseMatrix<ElemType> &operator=(const TriSparseMatrix<ElemType> &TSM);
    void SimpleTranspose(const TriSparseMatrix<ElemType> &source, TriSparseMatrix<ElemType> &TSM);
    void FastTranspose(const TriSparseMatrix<ElemType> &source, TriSparseMatrix<ElemType> &TSM);
};
template <class ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix(int rows, int cols, int maxsize) : maxsize_(maxsize), rows_(rows), cols_(cols), num_(0)
{
    elems_ = new Tripple<ElemType>[maxsize_];
    assert(elems_);
}
template <class ElemType>
TriSparseMatrix<ElemType>::~TriSparseMatrix()
{
    delete[] elems_;
}
template <class ElemType>
int TriSparseMatrix<ElemType>::GetRows() const
{
    return rows_;
}
template <class ElemType>
int TriSparseMatrix<ElemType>::GetCols() const
{
    return cols_;
}
template <class ElemType>
int TriSparseMatrix<ElemType>::GetNum() const
{
    return num_;
}
template <class ElemType>
Status TriSparseMatrix<ElemType>::SetElem(int r, int c, const ElemType &e)
{
    if (num_ >= maxsize_)
    {
        return OVER_FLOW;
    }
    if (r > rows_ or r < 0 or c > cols_ or c < 0)
    {
        return RANGE_ERROR;
    }
    Tripple<ElemType> temp(r, c, e);
    elems_[num_++] = temp;
    return SUCCESS;
}
template <class ElemType>
Status TriSparseMatrix<ElemType>::GetElem(int r, int c, ElemType &e)
{
    if (r > rows_ or r < 0 or c > cols_ or c < 0)
    {
        return RANGE_ERROR;
    }
    for (int i = 0; i < num_; i++)
    {
        if (elems_[i].row_ == r and elems_[i].col_ == c)
        {
            e = elems_[i].value_;
            return SUCCESS;
        }
    }
    return RANGE_ERROR;
}
template <class ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix(const TriSparseMatrix<ElemType> &TSM) : maxsize_(TSM.maxsize_), rows_(TSM.rows_), cols_(TSM.cols_), num_(TSM.num_)
{
    elems_ = new ElemType[maxsize_];
    assert(elems_);
    for (int i = 0; i < num_; i++)
    {
        elems_[i] = TSM.elems_[i];
    }
}
template <class ElemType>
TriSparseMatrix<ElemType> &TriSparseMatrix<ElemType>::operator=(const TriSparseMatrix<ElemType> &TSM)
{
    if (&TSM == this)
    {
        return *this;
    }
    delete[] elems_;
    maxsize_ = TSM.maxsize_;
    rows_ = TSM.rows_;
    cols_ = TSM.cols_;
    num_ = TSM.num_;
    elems_ = new ElemType[maxsize_];
    assert(elems_);
    for (int i = 0; i < num_; i++)
    {
        elems_[i] = TSM.elems_[i];
    }
    return *this;
}
template <class ElemType>
void TriSparseMatrix<ElemType>::SimpleTranspose(const TriSparseMatrix<ElemType> &source, TriSparseMatrix<ElemType> &TSM)
{
}
template <class ElemType>
void TriSparseMatrix<ElemType>::FastTranspose(const TriSparseMatrix<ElemType> &source, TriSparseMatrix<ElemType> &TSM)
{
}
#endif