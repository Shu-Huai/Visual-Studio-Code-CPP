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
    int rows_, cols_, nums_;

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
TriSparseMatrix<ElemType>::TriSparseMatrix(int rows, int cols, int maxsize) : rows_(rows), cols_(cols), maxsize_(maxsize)
{
    elems_ = new Tripple<ElemType>[maxsize_];
    assert(elems_);
}

#endif