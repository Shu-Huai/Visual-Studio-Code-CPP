#ifndef __CROSS_LIST_MATRIX_H__
#define __CROSS_LIST_MATRIX_H__
#include "Cross List Matrix Node.h"
template <class ElemType>
class CrossListMatrix
{
protected:
    CrossListMatrixNode<ElemType> **rowHeads_;
    CrossListMatrixNode<ElemType> **colHeads_;
    int rowNum_;
    int colNum_;
    int elemNum_;

public:
    CrossListMatrix(int rowNum = 1000, int colNum = 1000);
    CrossListMatrix(const CrossListMatrix<ElemType> &matrix);
    ~CrossListMatrix();
    void Clear();
    void Display() const;
    void SetElem(int rowIndex, int colIndex, const ElemType elem);
    int GetRowNum() const;
    int GetColNum() const;
    int GetElemNum() const;
    ElemType GetElem(int rowIndex, int colIndex) const;
    CrossListMatrix<ElemType> &operator=(const CrossListMatrix<ElemType> &matrix);
    CrossListMatrix<ElemType> operator+(const CrossListMatrix<ElemType> &matrix);
};
template <class ElemType>
CrossListMatrix<ElemType>::CrossListMatrix(int rowNum, int colNum)
{
    if (rowNum <= 0)
    {
        throw string("函数小于等于零。");
    }
    if (colNum <= 0)
    {
        throw string("列数小于等于零。");
    }
    rowNum_ = rowNum;
    colNum_ = colNum;
    elemNum_ = 0;
    rowHeads_ = new CrossListMatrixNode<ElemType> *[rowNum_];
    colHeads_ = new CrossListMatrixNode<ElemType> *[colNum_];
    for (int i = 0; i < rowNum_; i++)
    {
        rowHeads_[i] = NULL;
    }
    for (int i = 0; i < colNum_; i++)
    {
        colHeads_[i] = NULL;
    }
}
template <class ElemType>
CrossListMatrix<ElemType>::CrossListMatrix(const CrossListMatrix<ElemType> &matrix) : rowNum_(matrix.rowNum_), colNum_(matrix.colNum_), elemNum_(0)
{
    rowHeads_ = new CrossListMatrixNode<ElemType> *[rowNum_];
    colHeads_ = new CrossListMatrixNode<ElemType> *[colNum_];
    for (int i = 0; i < rowNum_; i++)
    {
        rowHeads_[i] = NULL;
    }
    for (int i = 0; i < colNum_; i++)
    {
        colHeads_[i] = NULL;
    }
    for (int i = 0; i < rowNum_; i++)
    {
        for (CrossListMatrixNode<ElemType> *p = matrix.rowHeads_[i]; p; p = p->right_)
        {
            SetElem(p->elem_->rowIndex_, p->elem_->colIndex_, p->elem_->elem_);
        }
    }
}
template <class ElemType>
CrossListMatrix<ElemType>::~CrossListMatrix()
{
    Clear();
    delete[] rowHeads_;
    delete[] colHeads_;
}
template <class ElemType>
void CrossListMatrix<ElemType>::Clear()
{
    for (int i = 0; i < rowNum_; i++)
    {
        while (rowHeads_[i])
        {
            CrossListMatrixNode<ElemType> *p = rowHeads_[i];
            rowHeads_[i] = p->right_;
            delete p;
        }
    }
    for (int j = 0; j < colNum_; j++)
    {
        colHeads_[j] = NULL;
    }
    elemNum_ = 0;
}
template <class ElemType>
void CrossListMatrix<ElemType>::Display() const
{
    for (int i = 0; i < rowNum_; i++)
    {
        CrossListMatrixNode<ElemType> *p = rowHeads_[i];
        for (int j = 0; j < colNum_; j++)
        {
            if (p && j == p->elem_->colIndex_)
            {
                cout << p->elem_->elem_;
                p = p->right_;
            }
            else
            {
                cout << ElemType(0);
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << "行数是：" << rowNum_ << "，列数是：" << colNum_ << "，元素数是：" << elemNum_ << "。" << endl;
}
template <class ElemType>
void CrossListMatrix<ElemType>::SetElem(int rowIndex, int colIndex, const ElemType elem)
{
    if (rowIndex >= rowNum_ || rowIndex < 0 || colIndex >= colNum_ || colIndex < 0)
    {
        throw string("范围错误。");
    }
    CrossListMatrixNode<ElemType> *pre = NULL;
    CrossListMatrixNode<ElemType> *p = rowHeads_[rowIndex];
    while (p && p->elem_->colIndex_ < colIndex)
    {
        pre = p;
        p = p->right_;
    }
    if (!elem)
    {
        if (p && p->elem_->colIndex_ == colIndex)
        {
            if (rowHeads_[rowIndex] == p)
            {
                rowHeads_[rowIndex] = p->right_;
            }
            else
            {
                pre->right_ = p->right_;
            }
            if (colHeads_[colIndex] == p)
            {
                colHeads_[colIndex] = p->right_;
            }
            else
            {
                pre = colHeads_[colIndex];
                while (pre->down_ != p)
                {
                    pre = pre->down_;
                }
                pre->down_ = p->down_;
            }
            delete p;
            elemNum_--;
        }
    }
    else
    {
        if (p && p->elem_->colIndex_ == colIndex)
        {
            p->elem_->elem_ = elem;
        }
        else
        {
            Triple<ElemType> triple(rowIndex, colIndex, elem);
            CrossListMatrixNode<ElemType> *q = new CrossListMatrixNode<ElemType>(triple);
            if (rowHeads_[rowIndex] == p)
            {
                rowHeads_[rowIndex] = q;
            }
            else
            {
                pre->right_ = q;
            }
            q->right_ = p;
            pre = NULL;
            p = colHeads_[colIndex];
            while (p && p->elem_->rowIndex_ < rowIndex)
            {
                pre = p;
                p = p->down_;
            }
            if (colHeads_[colIndex] == p)
            {
                colHeads_[colIndex] = q;
            }
            else
            {
                pre->down_ = q;
            }
            q->down_ = p;
            elemNum_++;
        }
    }
}
template <class ElemType>
int CrossListMatrix<ElemType>::GetRowNum() const
{
    return rowNum_;
}
template <class ElemType>
int CrossListMatrix<ElemType>::GetColNum() const
{
    return colNum_;
}
template <class ElemType>
int CrossListMatrix<ElemType>::GetElemNum() const
{
    return elemNum_;
}
template <class ElemType>
ElemType CrossListMatrix<ElemType>::GetElem(int rowIndex, int colIndex) const
{
    if (rowIndex < 0 || rowIndex >= rowNum_ || colIndex < 0 || colIndex >= colNum_)
    {
        throw string("范围错误。");
    }
    CrossListMatrixNode<ElemType> *p = rowHeads_[rowIndex];
    while (p && p->elem_->colIndex_ < colIndex)
    {
        p = p->right_;
    }
    if (p && p->elem_->colIndex_ == colIndex)
    {
        return p->elem_->elem_;
    }
    return 0;
}
template <class ElemType>
CrossListMatrix<ElemType> &CrossListMatrix<ElemType>::operator=(const CrossListMatrix<ElemType> &matrix)
{
    if (&matrix != this)
    {
        Clear();
        rowNum_ = matrix.rowNum_;
        colNum_ = matrix.colNum_;
        elemNum_ = matrix.elemNum_;
        for (int i = 0; i < rowNum_; i++)
        {
            for (CrossListMatrixNode<ElemType> *p = matrix.rowHeads_[i]; p; p = p->right_)
            {
                SetElem(p->elem_->rowIndex_, p->elem_->colIndex_, p->elem_->elem_);
            }
        }
    }
    return *this;
}
template <class ElemType>
CrossListMatrix<ElemType> CrossListMatrix<ElemType>::operator+(const CrossListMatrix<ElemType> &matrix)
{
    if (rowNum_ != matrix.rowNum_ || colNum_ != matrix.colNum_)
    {
        throw string("行列数不相等。");
    }
    CrossListMatrix<ElemType> temp(matrix.rowNum_, matrix.colNum_);
    for (int i = 0; i < rowNum_; i++)
    {
        CrossListMatrixNode<ElemType> *p = rowHeads_[i];
        CrossListMatrixNode<ElemType> *q = matrix.rowHeads_[i];
        while (p && q)
        {
            if (p->elem_->colIndex_ < q->elem_->colIndex_)
            {
                temp.SetElem(p->elem_->rowIndex_, p->elem_->colIndex_, p->elem_->elem_);
                p = p->right_;
            }
            else if (p->elem_->colIndex_ > q->elem_->colIndex_)
            {
                temp.SetElem(q->elem_->rowIndex_, q->elem_->colIndex_, q->elem_->elem_);
                q = q->right_;
            }
            else
            {
                ElemType elem = p->elem_->elem_ + q->elem_->elem_;
                if (elem)
                {
                    temp.SetElem(q->elem_->rowIndex_, q->elem_->colIndex_, elem);
                }
                p = p->right_;
                q = q->right_;
            }
        }
        while (p)
        {
            temp.SetElem(p->elem_->rowIndex_, p->elem_->colIndex_, p->elem_->elem_);
            p = p->right_;
        }
        while (q)
        {
            temp.SetElem(q->elem_->rowIndex_, q->elem_->colIndex_, q->elem_->elem_);
            q = q->right_;
        }
    }
    return temp;
}
#endif