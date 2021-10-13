#include <iostream>
using namespace std;
void GetMatrixMultiplicationOrder(int *rowColNumber, int matrixNumber, int **minTimes, int **cutPosition)
{
    for (int i = 1; i <= matrixNumber; i++)
    {
        minTimes[i][i] = 0;
    }
    for (int r = 2; r <= matrixNumber; r++)
    {
        for (int i = 1; i <= matrixNumber - r + 1; i++)
        {
            int j = i + r - 1;
            minTimes[i][j] = minTimes[i + 1][j] + rowColNumber[i - 1] * rowColNumber[i] * rowColNumber[j];
            cutPosition[i][j] = i;
            for (int k = i + 1; k < j; k++)
            {
                int temp = minTimes[i][k] + minTimes[k + 1][j] + rowColNumber[i - 1] * rowColNumber[k] * rowColNumber[j];
                if (temp < minTimes[i][j])
                {
                    minTimes[i][j] = temp;
                    cutPosition[i][j] = k;
                }
            }
        }
    }
}
void ShowResult(int i, int j, int **cutPosition, int matrixNumber)
{
    if (i == j)
    {
        cout << "A" << i << "";
        return;
    }
    if (i != 1 || j != matrixNumber)
    {
        cout << "(";
    }
    ShowResult(i, cutPosition[i][j], cutPosition, matrixNumber);
    ShowResult(cutPosition[i][j] + 1, j, cutPosition, matrixNumber);
    if (i != 1 || j != matrixNumber)
    {
        cout << ")";
    }
}
int main()
{
    int matrixNumber = 0;
    int count = 0;
    while (cin >> matrixNumber)
    {
        int *rowColNumber = new int[matrixNumber]{0};
        for (int i = 0; i <= matrixNumber; i++)
        {
            cin >> rowColNumber[i];
        }
        int **minTimes = new int *[matrixNumber + 1];
        for (int i = 0; i < 5; i++)
        {
            minTimes[i] = new int[matrixNumber + 1]{0};
        }
        int **cutPosition = new int *[matrixNumber + 1];
        for (int i = 0; i < 5; i++)
        {
            cutPosition[i] = new int[matrixNumber + 1]{0};
        }
        GetMatrixMultiplicationOrder(rowColNumber, matrixNumber, minTimes, cutPosition);
        cout << "Case " << ++count << endl
             << minTimes[1][matrixNumber] << " ";
        ShowResult(1, matrixNumber, cutPosition, matrixNumber);
        cout << endl;
    }
    return 0;
}