#include <iostream>
using namespace std;
void LongestCommonSequence(int m, int n, char *x, char *y, int **maxLength, int **subCase)
{
    int i, j;
    for (i = 1; i <= m; i++)
    {
        maxLength[i][0] = 0;
    }
    for (i = 1; i <= n; i++)
    {
        maxLength[0][i] = 0;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                maxLength[i][j] = maxLength[i - 1][j - 1] + 1;
                subCase[i][j] = 1;
            }
            else if (maxLength[i - 1][j] > maxLength[i][j - 1])
            {
                maxLength[i][j] = maxLength[i - 1][j];
                subCase[i][j] = 2;
            }
            else if ((maxLength[i - 1][j] < maxLength[i][j - 1]))
            {
                maxLength[i][j] = maxLength[i][j - 1];
                subCase[i][j] = 3;
            }
            else
            {
                maxLength[i][j] = maxLength[i][j - 1];
                subCase[i][j] = 4;
            }
        }
    }
}
void ShowResult(int i, int j, int **subCase, char *stringA, string result)
{
    while (i > 0 && j > 0)
    {
        if (subCase[i][j] == 1)
        {
            result = stringA[i - 1] + (string)" " + result;
            i--;
            j--;
        }
        else if (subCase[i][j] == 2)
        {
            i--;
        }
        else if (subCase[i][j] == 3)
        {
            j--;
        }
        else
        {
            ShowResult(i - 1, j, subCase, stringA, result);
            ShowResult(i, j - 1, subCase, stringA, result);
            return;
        }
    }
    cout << result << endl;
}
int main()
{
    int count = 0;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int lengthA = 0;
        int lengthB = 0;
        cin >> lengthA >> lengthB;
        char *stringA = new char[lengthA]{0};
        for (int i = 0; i < lengthA; i++)
        {
            cin >> stringA[i];
        }
        char *stringB = new char[lengthB]{0};
        for (int i = 0; i < lengthB; i++)
        {
            cin >> stringB[i];
        }
        int **maxLength = new int *[lengthA + 1];
        for (int i = 0; i <= lengthA; i++)
        {
            maxLength[i] = new int[lengthB + 1]{0};
        }
        int **subCase = new int *[lengthA + 1];
        for (int i = 0; i <= lengthA; i++)
        {
            subCase[i] = new int[lengthB + 1]{0};
        }
        LongestCommonSequence(lengthA, lengthB, stringA, stringB, maxLength, subCase);
        cout << "Case " << i + 1 << endl
             << "最长公共子序列的长度:" << maxLength[lengthA][lengthB] << endl
             << "LCS(X,Y):" << endl;
        string result = "";
        ShowResult(lengthA, lengthB, subCase, stringA, result);
        cout << endl;
        for (int i = 0; i <= lengthA; i++)
        {
            for (int j = 0; j <= lengthB; j++)
            {
                cout << maxLength[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i <= lengthA; i++)
        {
            for (int j = 0; j <= lengthB; j++)
            {
                cout << subCase[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        delete[] stringA;
        delete[] stringB;
        for (int i = 0; i <= lengthA; i++)
        {
            delete[] maxLength[i];
            delete[] subCase[i];
        }
        delete[] maxLength;
        delete[] subCase;
    }
    return 0;
}