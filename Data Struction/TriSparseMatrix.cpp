#include "TriSparseMatrix.h"
using namespace std;
int main()
{
    char c = 0;
    TriSparseMatrix<int> TSM0;
    TriSparseMatrix<int> TSM1;
    int e, i;
    int rows, cols;
    Status sta;
    while (c != '0')
    {
        cout << endl
             << "1. 生成矩阵.";
        cout << endl
             << "2. 显示矩阵.";
        cout << endl
             << "3. 取矩阵元素.";
        cout << endl
             << "4. 更改矩阵元素.";
        cout << endl
             << "5. 求矩阵行列.";
        cout << endl
             << "6. 求矩阵转置.";
        cout << endl
             << "7. 求矩阵相加.";
        cout << endl
             << "0. 退出.";
        cout << endl
             << "选择功能(0~7): ";
        cin >> c;
        switch (c)
        {
        case '1':
            sta = SUCCESS;
            cout << endl
                 << "输入rows: ";
            cin >> rows;
            cout << "输入cols: ";
            cin >> cols;
            TSM0 = TriSparseMatrix<int>(rows, cols, rows * cols);
            cout << "输入e:" << endl;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cin >> e;
                    if (e)
                    {
                        sta = TSM0.SetElem(i, j, e);
                        if (sta == OVER_FLOW)
                        {
                            cout << "矩阵已满." << endl;
                        }
                    }
                }
            }
            break;
        case '2':
            cout << endl
                 << TSM0;
            break;
        case '3':
            cout << endl
                 << "输入rows: ";
            cin >> rows;
            cout << "输入cols: ";
            cin >> cols;
            if (TSM0.GetElem(rows, cols, e) == RANGE_ERROR)
            {
                cout << "范围错误." << endl;
            }
            else
            {
                cout << "元素: " << e << endl;
            }
            break;
        case '4':
            cout << endl
                 << "输入rows: ";
            cin >> rows;
            cout << "输入cols: ";
            cin >> cols;
            cout << "输入e: ";
            cin >> e;
            sta = TSM0.SetElem(rows, cols, e);
            if (sta == OVERFLOW)
            {
                cout << "矩阵已满." << endl;
            }
            else if (sta == RANGE_ERROR)
            {
                cout << "范围错误." << endl;
            }
            else
            {
                cout << "已设置." << endl;
            }
            break;
        case '5':
            cout << endl
                 << "矩阵的行列为: " << TSM0.GetRows() << ", " << TSM0.GetCols() << endl;
            break;
        case '6':
            cout << endl
                 << "矩阵的转置为: " << endl;
            TSM0.SimpleTranspose(TSM1);
            TSM0 = TSM1;
            cout << TSM0;
            break;
        case '7':
            cout << endl
                 << "输入rows: ";
            cin >> rows;
            cout << "输入cols: ";
            cin >> cols;
            if (rows != TSM0.GetRows() or cols != TSM0.GetCols())
            {
                cout << "cols或rows不同." << endl;
                break;
            }
            TSM1 = TriSparseMatrix<int>(rows, cols, rows * cols);
            cout << "输入e:" << endl;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cin >> e;
                    if (e)
                    {
                        sta = TSM1.SetElem(i, j, e);
                        if (sta == OVER_FLOW)
                        {
                            cout << "矩阵已满." << endl;
                        }
                    }
                }
            }
            TSM0 = TSM0 + TSM1;
            cout << "已将矩阵相加." << endl;
            break;
        }
    }
    return 0;
}