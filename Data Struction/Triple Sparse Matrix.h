#pragma once
#ifndef __TRIPLE_SPARSE_MATRTIX_H__
#define __TRIPLE_SPARSE_MATRTIX_H__
#include "Triple.h"
template <class ElemType>
class TripleSparseMatrix
{
protected:
    Triple<ElemType> *elems_;
    int rowNum_;
    int colNum_;
    int elemNum_;
    int maxSize_;

public:
    TripleSparseMatrix(int rowsNum = 1000, int colsNum = 1000, int maxSize = 1000000);
    TripleSparseMatrix(const TripleSparseMatrix<ElemType> &matrix);
    ~TripleSparseMatrix();
    void Display() const;
    void SetElem(int rowIndex, int colIndex, const ElemType &elem);
    int GetRowNum() const;
    int GetColNum() const;
    int GetElemNum() const;
    ElemType GetElem(int rowIndex, int colIndex) const;
    void SimpleTranspose();
    void FastTranspose();
    TripleSparseMatrix<ElemType> &operator=(const TripleSparseMatrix<ElemType> &matrix);
    TripleSparseMatrix<ElemType> operator+(const TripleSparseMatrix<ElemType> &matrix);
    template <class SubElemType>
    friend ostream &operator<<(ostream &out, TripleSparseMatrix<SubElemType> &matrix);
};
template <class ElemType>
TripleSparseMatrix<ElemType>::TripleSparseMatrix(int rowsNum, int colsNum, int maxSize) : rowNum_(rowsNum), colNum_(colsNum), elemNum_(0), maxSize_(maxSize)
{
    elems_ = new Triple<ElemType>[maxSize_];
}
template <class ElemType>
TripleSparseMatrix<ElemType>::TripleSparseMatrix(const TripleSparseMatrix<ElemType> &matrix)
    : rowNum_(matrix.rowNum_), colNum_(matrix.colNum_), elemNum_(matrix.elemNum_), maxSize_(matrix.maxSize_)
{
    elems_ = new Triple<ElemType>[maxSize_];
    for (int i = 0; i < elemNum_; i++)
    {
        elems_[i] = matrix.elems_[i];
    }
}
template <class ElemType>
TripleSparseMatrix<ElemType>::~TripleSparseMatrix()
{
    delete[] elems_;
}
template <class ElemType>
void TripleSparseMatrix<ElemType>::Display() const
{
    int count = 0;
    for (int i = 0; i < rowNum_; i++)
    {
        for (int j = 0; j < colNum_; j++)
        {
            if (elems_[count].rowIndex_ == i && elems_[count].colIndex_ == j)
            {
                cout << elems_[count].elem_;
                count++;
            }
            else
            {
                cout << "0";
            }
            if (j == colNum_ - 1)
            {
                cout << endl;
            }
            else
            {
                cout << " ";
            }
        }
    }
}
template <class ElemType>
void TripleSparseMatrix<ElemType>::SetElem(int rowIndex, int colIndex, const ElemType &elem)
{
    if (elemNum_ == maxSize_)
    {
        throw string("存储空间已满。");
    }
    if (rowIndex > rowNum_ || rowIndex < 0 || colIndex > colNum_ || colIndex < 0)
    {
        throw string("范围错误。");
    }
    if (elem)
    {
        for (int i = 0; i < elemNum_; i++)
        {
            if (elems_[i].rowIndex_ == rowIndex && elems_[i].colIndex_ == colIndex)
            {
                elems_[i].elem_ = elem;
                return;
            }
        }
        elems_[elemNum_] = Triple<ElemType>(rowIndex, colIndex, elem);
        elemNum_++;
    }
    else
    {
        for (int i = 0; i < elemNum_; i++)
        {
            if (elems_[i].rowIndex_ == rowIndex && elems_[i].colIndex_ == colIndex)
            {
                for (int j = i; j < elemNum_ - 1; j++)
                {
                    elems_[j] = elems_[j + 1];
                }
                elemNum_--;
                return;
            }
        }
        throw string("元素不存在。");
    }
}
template <class ElemType>
int TripleSparseMatrix<ElemType>::GetRowNum() const
{
    return rowNum_;
}
template <class ElemType>
int TripleSparseMatrix<ElemType>::GetColNum() const
{
    return colNum_;
}
template <class ElemType>
int TripleSparseMatrix<ElemType>::GetElemNum() const
{
    return elemNum_;
}
template <class ElemType>
ElemType TripleSparseMatrix<ElemType>::GetElem(int rowIndex, int colIndex) const
{
    if (rowIndex > rowNum_ || rowIndex < 0 || colIndex > colNum_ || colIndex < 0)
    {
        throw string("范围错误。");
    }
    for (int i = 0; i < elemNum_; i++)
    {
        if (elems_[i].rowIndex_ == rowIndex && elems_[i].colIndex_ == colIndex)
        {
            return elems_[i].elem_;
        }
    }
    return ElemType(0);
}
template <class ElemType>
void TripleSparseMatrix<ElemType>::SimpleTranspose()
{
    int temp = colNum_;
    colNum_ = rowNum_;
    rowNum_ = temp;
    Triple<ElemType> *tempTriple = new Triple<ElemType>[elemNum_];
    for (int i = 0; i < elemNum_; i++)
    {
        tempTriple[i] = elems_[i];
    }
    delete[] elems_;
    elems_ = new Triple<ElemType>[maxSize_];
    int count = 0;
    for (int i = 0; i < colNum_; i++)
    {
        for (int j = 0; j < elemNum_; j++)
        {
            if (tempTriple[j].colIndex_ == i)
            {
                elems_[count] = Triple<ElemType>(tempTriple[j].colIndex_, tempTriple[j].rowIndex_, tempTriple[j].elem_);
                count++;
            }
        }
    }
    delete[] tempTriple;
}
template <class ElemType>
void TripleSparseMatrix<ElemType>::FastTranspose()
{
    int temp = colNum_;
    colNum_ = rowNum_;
    rowNum_ = temp;
    Triple<ElemType> *tempTriple = new Triple<ElemType>[elemNum_];
    for (int i = 0; i < elemNum_; i++)
    {
        tempTriple[i] = elems_[i];
    }
    delete[] elems_;
    elems_ = new Triple<ElemType>[maxSize_];
    int *colElemNum = new int[colNum_]{0};
    int *colElemIndex = new int[colNum_]{0};
    for (int i = 0; i < elemNum_; i++)
    {
        colElemNum[tempTriple[i].colIndex_]++;
    }
    for (int i = 1; i < colNum_; i++)
    {
        colElemIndex[i] = colElemIndex[i - 1] + colElemNum[i - 1];
    }
    for (int i = 0; i < elemNum_; i++)
    {
        elems_[colElemIndex[tempTriple[i].colIndex_]] = Triple<ElemType>(tempTriple[i].colIndex_, tempTriple[i].rowIndex_, tempTriple[i].elem_);
        colElemIndex[tempTriple[i].colIndex_]++;
    }
    delete[] colElemNum;
    delete[] colElemIndex;
    delete[] tempTriple;
}
template <class ElemType>
TripleSparseMatrix<ElemType> &TripleSparseMatrix<ElemType>::operator=(const TripleSparseMatrix<ElemType> &matrix)
{
    if (&matrix != this)
    {
        delete[] elems_;
        rowNum_ = matrix.rowNum_;
        colNum_ = matrix.colNum_;
        elemNum_ = matrix.elemNum_;
        maxSize_ = matrix.maxSize_;
        elems_ = new Triple<ElemType>[maxSize_];
        for (int i = 0; i < elemNum_; i++)
        {
            elems_[i] = matrix.elems_[i];
        }
    }
    return *this;
}
template <class ElemType>
TripleSparseMatrix<ElemType> TripleSparseMatrix<ElemType>::operator+(const TripleSparseMatrix<ElemType> &matrix)
{
    if (rowNum_ != matrix.rowNum_ || colNum_ != matrix.colNum_)
    {
        throw string("行列数不相等。");
    }
    int flag = 0;
    for (int i = 0; i < matrix.elemNum_; i++)
    {
        for (int j = flag; j < elemNum_; j++)
        {
            if (elems_[j].rowIndex_ == matrix.elems_[i].rowIndex_ && elems_[j].colIndex_ == matrix.elems_[i].colIndex_)
            {
                elems_[j].elem_ += matrix.elems_[i].elem_;
                if (elems_[j].elem_ == 0)
                {
                    for (int k = j; k < elemNum_ - 1; k++)
                    {
                        elems_[k] = elems_[k + 1];
                    }
                    elems_[elemNum_ - 1] = Triple<ElemType>(0, 0, 0);
                    elemNum_--;
                }
                flag = j;
                break;
            }
            else if (elems_[j].rowIndex_ == matrix.elems_[i].rowIndex_ && elems_[j].colIndex_ < matrix.elems_[i].colIndex_ &&
                     (elems_[j + 1].colIndex_ > matrix.elems_[i].colIndex_ || elems_[j + 1].rowIndex_ > matrix.elems_[i].rowIndex_))
            {
                for (int k = elemNum_; k > j; k--)
                {
                    elems_[k] = elems_[k - 1];
                }
                elems_[j + 1] = Triple<ElemType>(matrix.elems_[i].rowIndex_, matrix.elems_[i].colIndex_, matrix.elems_[i].elem_);
                elemNum_++;
                flag = j + 1;
                break;
            }
            else if (elems_[j].rowIndex_ < matrix.elems_[i].rowIndex_ && elems_[j + 1].colIndex_ > matrix.elems_[i].colIndex_)
            {
                for (int k = elemNum_; k > j; k--)
                {
                    elems_[k] = elems_[k - 1];
                }
                elems_[j + 1] = Triple<ElemType>(matrix.elems_[i].rowIndex_, matrix.elems_[i].colIndex_, matrix.elems_[i].elem_);
                elemNum_++;
                flag = j + 1;
                break;
            }
        }
    }
    return *this;
}
template <class SubElemType>
ostream &operator<<(ostream &out, TripleSparseMatrix<SubElemType> &matrix)
{
    for (int i = 0; i < matrix.elemNum_; i++)
    {
        out << matrix.elems_[i];
        if (i != matrix.elemNum_ - 1)
        {
            cout << endl;
        }
    }
    return out;
}
#endif