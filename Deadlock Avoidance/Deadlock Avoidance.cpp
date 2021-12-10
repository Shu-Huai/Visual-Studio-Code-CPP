#include "Banker Algorithm.cpp"
int main()
{
    int processNumber = 5;
    int resourceNumber = 3;
    int available[3] = {3, 3, 2};
    int max[5][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int allocation[5][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int need[5][3] = {{7, 4, 3}, {1, 2, 2}, {6, 0, 0}, {0, 1, 1}, {4, 3, 1}};
    int **tempMax = new int *[processNumber];
    int **tempAllocation = new int *[processNumber];
    int **tempNeed = new int *[processNumber];
    for (int i = 0; i < 5; i++)
    {
        tempMax[i] = new int[resourceNumber];
        tempAllocation[i] = new int[resourceNumber];
        tempNeed[i] = new int[resourceNumber];
    }
    for (int i = 0; i < processNumber; i++)
    {
        for (int j = 0; j < resourceNumber; j++)
        {
            tempMax[i][j] = max[i][j];
            tempAllocation[i][j] = allocation[i][j];
            tempNeed[i][j] = need[i][j];
        }
    }
    BankerAlgorithm bankerAlgorithm(processNumber, resourceNumber, available, (int **)tempMax, (int **)tempAllocation, (int **)tempNeed);
    for (int i = 0; i < 5; i++)
    {
        delete[] tempMax[i];
        delete[] tempAllocation[i];
        delete[] tempNeed[i];
    }
    delete[] tempMax;
    delete[] tempAllocation;
    delete[] tempNeed;
    bankerAlgorithm.Begin();
    return 0;
}