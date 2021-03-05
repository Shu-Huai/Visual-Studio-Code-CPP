#ifndef __CROSS_LIST_H__
#define __CROSS_LIST_H__
#include "CrossNode.h"
template <class ElemType>
class CrossList
{
protected:
    CrossNode<ElemType> **rowhead_;
    CrossNode<ElemType> **colhead_;
    int rows_;
    int cols_;
    int num_;

public:
    CrossList(int rows = DEFAULT_SIZE, int cols = DEFAULT_SIZE);
    ~CrossList();
    void Clear();
    int GetRows() const;
    int GetCols() const;
    int GetNum() const;
    Status SetElem(int r, int c, const ElemType &v);
    Status GetElem(int r, int c, ElemType &v);
    CrossList(const CrossList<ElemType> &CL);
    CrossList<ElemType> &operator=(const CrossList<ElemType> &CL);
    CrossList<ElemType> operator+(const CrossList<ElemType> &CL);
};
template <class ElemType>
CrossList<ElemType>::CrossList(int rows, int cols) : rows_(rows), cols_(cols), num_(0)
{
    if (rows > 0 and cols > 0)
    {
        rowhead_ = new CrossNode<ElemType> *[rows_];
        colhead_ = new CrossNode<ElemType> *[cols_];
        for (int i = 0; i < rows_; i++)
        {
            rowhead_[i] = NULL;
        }
        for (int i = 0; i < cols_; i++)
        {
            colhead_[i] = NULL;
        }
    }
}
template <class ElemType>
CrossList<ElemType>::~CrossList()
{
    Clear();
    delete[] rowhead_;
    delete[] colhead_;
}
template <class ElemType>
void CrossList<ElemType>::Clear()
{
    CrossNode<ElemType> *p;
    for (int i = 0; i < rows_; i++)
    {
        while (rowhead_[i] != NULL)
        {
            p = rowhead_[i];
            rowhead_[i] = p->right_;
            delete p;
        }
    }
    for (int j = 0; j < cols_; j++)
    {
        colhead_[j] = NULL;
    }
    num_ = 0;
}
template <class ElemType>
int CrossList<ElemType>::GetRows() const
{
    return rows_;
}
template <class ElemType>
int CrossList<ElemType>::GetCols() const
{
    return cols_;
}
template <class ElemType>
int CrossList<ElemType>::GetNum() const
{
    return num_;
}
template <class ElemType>
Status CrossList<ElemType>::SetElem(int r, int c, const ElemType &v)
{
    if (r >= rows_ or r < 0 or c >= cols_ or c < 0)
    {
        return RANGE_ERROR;
    }
    CrossNode<ElemType> *pre = NULL;
    CrossNode<ElemType> *p = rowhead_[r];
    while (p != NULL and p->elem_->col_ < c)
    {
        pre = p;
        p = p->right_;
    }
    if (v == 0)
    {
        if (p != NULL and p->elem_->col_ == c)
        {
            if (rowhead_[r] == p)
            {
                rowhead_[r] = p->right_;
            }
            else
            {
                pre->right_ = p->right_;
            }
            if (colhead_[c] == p)
            {
                colhead_[c] = p->right_;
            }
            else
            {
                pre = colhead_[c];
                while (pre->down_ != p)
                {
                    pre = pre->down_;
                }
                pre->down_ = p->down_;
            }
            delete p;
            num_--;
        }
    }
    else
    {
        if (p != NULL and p->elem_->col_ == c)
        {
            p->elem_->value_ = v;
        }
        else
        {
            Triple<ElemType> e(r, c, v);
            CrossNode<ElemType> *q = new CrossNode<ElemType>(e);
            if (rowhead_[r] == p)
            {
                rowhead_[r] = q;
            }
            else
            {
                pre->right_ = q;
            }
            q->right_ = p;
            pre = NULL;
            p = colhead_[c];
            while (p != NULL and p->elem_->row_ < r)
            {
                pre = p;
                p = p->down_;
            }
            if (colhead_[c] == p)
            {
                colhead_[c] = q;
            }
            else
            {
                pre->down_ = q;
            }
            q->down_ = p;
            num_++;
        }
    }
    return SUCCESS;
}
template <class ElemType>
Status CrossList<ElemType>::GetElem(int r, int c, ElemType &v)
{
    if (r < 0 or r >= rows_ or c < 0 or c >= cols_)
    {
        return RANGE_ERROR;
    }
    CrossNode<ElemType> *p = rowhead_[r];
    while (p != NULL and p->elem_->col_ < c)
    {
        p = p->right_;
    }
    if (p != NULL and p->elem_->col_ == c)
    {
        v = p->elem_->value_;
    }
    else
    {
        v = 0;
    }
    return SUCCESS;
}
template <class ElemType>
CrossList<ElemType>::CrossList(const CrossList<ElemType> &CL) : rows_(CL.rows_), cols_(CL.cols_), num_(0)
{
    CrossNode<ElemType> *p;
    rowhead_ = new CrossNode<ElemType> *[rows_];
    colhead_ = new CrossNode<ElemType> *[cols_];
    for (int i = 0; i < rows_; i++)
    {
        rowhead_[i] = NULL;
    }
    for (int i = 0; i < cols_; i++)
    {
        colhead_[i] = NULL;
    }
    for (int i = 0; i < rows_; i++)
    {
        for (p = CL.rowhead_[i]; p != NULL; p = p->right_)
        {
            SetElem(p->elem_->row_, p->elem_->col_, p->elem_->value_);
        }
    }
}
template <class ElemType>
CrossList<ElemType> &CrossList<ElemType>::operator=(const CrossList<ElemType> &CL)
{
    if (&CL != this)
    {
        CrossNode<ElemType> *p;
        Clear();
        num_ = CL.num_;
        for (int i = 0; i < rows_; i++)
        {
            for (p = CL.rowhead_[i]; p != NULL; p = p->right_)
            {
                SetElem(p->elem_->row_, p->elem_->col_, p->elem_->value_);
            }
        }
    }
    return *this;
}
template <class ElemType>
CrossList<ElemType> CrossList<ElemType>::operator+(const CrossList<ElemType> &CL)
{
    if (rows_ != CL.rows_ || cols_ != CL.cols_)
        throw Error("行数或列数不相等!");

    CrossList<ElemType> temp(CL.rows_, CL.cols_);
    ElemType v;
    CrossNode<ElemType> *p, *q;

    for (int i = 0; i < rows_; i++)
    {
        p = rowhead_[i];
        q = CL.rowhead_[i];
        while (p != NULL && q != NULL)
            if (p->elem_->col_ < q->elem_->col_)
            {
                temp.SetElem(p->elem_->row_, p->elem_->col_, p->elem_->value_);
                p = p->right_;
            }
            else if (p->elem_->col_ > q->elem_->col_)
            {
                temp.SetElem(q->elem_->row_, q->elem_->col_, q->elem_->value_);
                q = q->right_;
            }
            else
            {
                v = p->elem_->value_ + q->elem_->value_;
                if (v != 0)
                    temp.SetElem(q->elem_->row_, q->elem_->col_, v);
                p = p->right_;
                q = q->right_;
            }
        while (p != NULL)
        {
            temp.SetElem(p->elem_->row_, p->elem_->col_, p->elem_->value_);
            p = p->right_;
        }
        while (q != NULL)
        {
            temp.SetElem(q->elem_->row_, q->elem_->col_, q->elem_->value_);
            q = q->right_;
        }
    }
    return temp;
}
#endif