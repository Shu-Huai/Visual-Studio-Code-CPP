#pragma once
#ifndef __TRI_SPARSE_MATRTIX_H__
#define __TRI_SPARSE_MATRTIX_H__
#include "Assistance.h"
#include "Triple.h"
template <class ElemType>
class TriSparseMatrix
{
protected:
    Triple<ElemType> *elems_;
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
    void SimpleTranspose(TriSparseMatrix<ElemType> &TSM);
    void FastTranspose(const TriSparseMatrix<ElemType> &TSMO, TriSparseMatrix<ElemType> &TSMR);
    TriSparseMatrix<ElemType> operator+(const TriSparseMatrix<ElemType> &TSM);
    template <class E>
    friend ostream &operator<<(ostream &out, TriSparseMatrix<E> &TSM);
};
template <class ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix(int rows, int cols, int maxsize) : maxsize_(maxsize), rows_(rows), cols_(cols), num_(0)
{
    elems_ = new Triple<ElemType>[maxsize_];
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
    if (e != 0)
    {
        for (int i = 0; i < num_; i++)
        {
            if (elems_[i].row_ == r and elems_[i].col_ == c)
            {
                elems_[i].value_ = e;
                return SUCCESS;
            }
        }
        elems_[num_].row_ = r;
        elems_[num_].col_ = c;
        elems_[num_++].value_ = e;
        return SUCCESS;
    }
    else
    {
        for (int i = 0; i < num_; i++)
        {
            if (elems_[i].row_ == r and elems_[i].col_ == c)
            {
                for (int j = i; j < num_ - 1; j++)
                {
                    elems_[j] = elems_[j + 1];
                }
                elems_[num_ - 1].value_ = 0;
                num_--;
                return SUCCESS;
            }
        }
    }
    return SUCCESS;
}
template <class ElemType>
Status TriSparseMatrix<ElemType>::GetElem(int r, int c, ElemType &e)
{
    if (r < rows_ and r > 0 or c < cols_ and c > 0)
    {
        for (int i = 0; i < num_; i++)
        {
            if (elems_[i].row_ == r and elems_[i].col_ == c)
            {
                e = elems_[i].value_;
                return SUCCESS;
            }
        }
        e = 0;
        return SUCCESS;
    }
    else
    {
        return RANGE_ERROR;
    }
    return RANGE_ERROR;
}
template <class ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix(const TriSparseMatrix<ElemType> &TSM) : maxsize_(TSM.maxsize_), rows_(TSM.rows_), cols_(TSM.cols_), num_(TSM.num_)
{
    elems_ = new Triple<ElemType>[maxsize_];
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
    elems_ = new Triple<ElemType>[maxsize_];
    assert(elems_);
    for (int i = 0; i < num_; i++)
    {
        elems_[i] = TSM.elems_[i];
    }
    return *this;
}
template <class ElemType>
void TriSparseMatrix<ElemType>::SimpleTranspose(TriSparseMatrix<ElemType> &TSM)
{
    TSM.maxsize_ = maxsize_;
    TSM.rows_ = cols_;
    TSM.cols_ = rows_;
    TSM.num_ = num_;
    TSM.elems_ = new Triple<ElemType>[TSM.maxsize_];
    int count = 0;
    for (int i = 0; i < cols_; i++)
    {
        for (int j = 0; j < num_; j++)
        {
            if (elems_[j].col_ == i)
            {
                TSM.elems_[count] = Triple<ElemType>(elems_[j].col_, elems_[j].row_, elems_[j].value_);
                count++;
            }
        }
    }
}
template <class ElemType>
void TriSparseMatrix<ElemType>::FastTranspose(const TriSparseMatrix<ElemType> &TSMO, TriSparseMatrix<ElemType> &TSMR)
{
}
template <class ElemType>
TriSparseMatrix<ElemType> TriSparseMatrix<ElemType>::operator+(const TriSparseMatrix<ElemType> &TSM)
{
    if (rows_ != TSM.rows_ or cols_ != TSM.cols_)
    {
        return *this;
    }
    for (int i = 0; i < TSM.num_; i++)
    {
        int length = num_;
        for (int j = 0; j < length; j++)
        {
            if (elems_[j].row_ == TSM.elems_[i].row_ and elems_[j].col_ == TSM.elems_[i].col_)
            {
                elems_[j].value_ += TSM.elems_[i].value_;
                i++;
            }
            else if (elems_[j].row_ == TSM.elems_[i].row_ and elems_[j].col_ < TSM.elems_[i].col_ and elems_[j + 1].col_ > TSM.elems_[i].col_)
            {
                for (int k = num_; k > i - 1; k--)
                {
                    elems_[k] = elems_[k - 1];
                }
                elems_[j] = Triple<ElemType>(TSM.elems_[i].row_, TSM.elems_[i].col_, TSM.elems_[i].value_);
                num_++;
                i++;
            }
            else if (elems_[j].row_ < TSM.elems_[i].row_ and elems_[j + 1].row_ > TSM.elems_[i].row_ or j == num_ - 1)
            {
                for (int k = num_; k > i - 1; k--)
                {
                    elems_[k] = elems_[k - 1];
                }
                elems_[j] = Triple<ElemType>(TSM.elems_[i].row_, TSM.elems_[i].col_, TSM.elems_[i].value_);
                num_++;
                i++;
            }
        }
    }
    return *this;
}
template <class ElemType>
ostream &operator<<(ostream &out, TriSparseMatrix<ElemType> &TSM)
{
    int count = 0;
    for (int i = 0; i < TSM.rows_; i++)
    {
        for (int j = 0; j < TSM.cols_; j++)
        {
            if (TSM.elems_[count].row_ == i and TSM.elems_[count].col_ == j)
            {
                out << TSM.elems_[count].value_;
                count++;
            }
            else
            {
                out << "0";
            }
            if (j == TSM.cols_ - 1)
            {
                out << endl;
            }
            else
            {
                out << " ";
            }
        }
    }
    return out;
}
#endif