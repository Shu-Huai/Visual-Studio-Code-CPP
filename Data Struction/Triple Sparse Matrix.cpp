#include "Triple Sparse Matrix.h"
using namespace std;
int main()
{
    char functionSelect = 0;
    TripleSparseMatrix<int> matrix;
    TripleSparseMatrix<int> subMatrix;
    int elem = 0;
    int rowNum = 0;
    int colNum = 0;
    int rowIndex = 0;
    int colIndex = 0;
    while (functionSelect != '0')
    {
        cout << "1. 生成矩阵。";
        cout << endl
             << "2. 显示矩阵。";
        cout << endl
             << "3. 取矩阵元素。";
        cout << endl
             << "4. 更改矩阵元素。";
        cout << endl
             << "5. 求矩阵行列。";
        cout << endl
             << "6. 求矩阵转置。";
        cout << endl
             << "7. 求矩阵相加。";
        cout << endl
             << "0. 退出。";
        cout << endl
             << "选择功能（0~7）：";
        cin >> functionSelect;
        switch (functionSelect)
        {
        case '1':
            cout << "输入行数：";
            cin >> rowNum;
            cout << "输入列数：";
            cin >> colNum;
            matrix = TripleSparseMatrix<int>(rowNum, colNum, rowNum * colNum);
            cout << "输入元素：" << endl;
            for (int i = 0; i < rowNum; i++)
            {
                for (int j = 0; j < colNum; j++)
                {
                    cin >> elem;
                    if (elem)
                    {
                        try
                        {
                            matrix.SetElem(i, j, elem);
                        }
                        catch (string &error)
                        {
                            cout << error << endl;
                            break;
                        }
                    }
                }
            }
            break;
        case '2':
            cout << matrix << endl;
            break;
        case '3':
            cout << "输入行下标：";
            cin >> rowIndex;
            cout << "输入列下标：";
            cin >> colIndex;
            try
            {
                elem = matrix.GetElem(rowIndex, colIndex);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "元素：" << elem << "。" << endl;
            break;
        case '4':
            cout << "输入行下标：";
            cin >> rowIndex;
            cout << "输入列下标：";
            cin >> colIndex;
            cout << "输入元素：";
            cin >> elem;
            try
            {
                matrix.SetElem(rowIndex, colIndex, elem);
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "成功。" << endl;
            break;
        case '5':
            cout << "矩阵的行数为：" << matrix.GetRowNum() << "，矩阵的列数为：" << matrix.GetColNum() << "。" << endl;
            break;
        case '6':
            matrix.FastTranspose();
            cout << "成功。" << endl;
            break;
        case '7':
            cout << "输入行数：";
            cin >> rowNum;
            cout << "输入列数：";
            cin >> colNum;
            subMatrix = TripleSparseMatrix<int>(rowNum, colNum, rowNum * colNum);
            cout << "输入元素：" << endl;
            for (int i = 0; i < rowNum; i++)
            {
                for (int j = 0; j < colNum; j++)
                {
                    cin >> elem;
                    if (elem)
                    {
                        try
                        {
                            subMatrix.SetElem(i, j, elem);
                        }
                        catch (string &error)
                        {
                            cout << error << endl;
                            break;
                        }
                    }
                }
            }
            try
            {
                matrix = matrix + subMatrix;
            }
            catch (string &error)
            {
                cout << error << endl;
                break;
            }
            cout << "成功。" << endl;
            break;
        }
    }
    return 0;
}