#include "CrossList.h"
int main(void)
{
    const int rows = 6, cols = 7;
    CrossList<int> CL(rows, cols), d(rows, cols);
    int m[rows][cols] = {
        0, 0, 11, 0, 0, 13, 0,
        12, 0, 0, 0, 0, 0, 14,
        0, -4, 0, 0, 0, -8, 0,
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,
        0, -8, 0, 0, 0, 0, 0};
    int i, j, v;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            CL.SetElem(i, j, m[i][j]);
        }
    }
    cout << "显示矩阵CL:" << endl;
    for (i = 0; i < CL.GetRowNum(); i++)
    {
        for (j = 0; j < CL.GetColNum(); j++)
        {
            CL.GetElem(i, j, v);
            cout << v << "\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << "显示矩阵CL+CL:" << endl;
    CrossList<int> c(CL);
    c = CL + c;
    for (i = 0; i < c.GetRowNum(); i++)
    {
        for (j = 0; j < c.GetColNum(); j++)
        {
            c.GetElem(i, j, v);
            cout << v << "\t";
        }
        cout << endl;
    }
    return 0;
}