#include <iostream>
using namespace std;
int Loading(int *weights, int room, int number, int *resultList)
{
    int *tempResult = new int[number + 2];
    int maxWeight = 0;
    int currentWeight = 0;
    int remainWeight = 0;
    for (int j = 0; j < number; j++)
    {
        remainWeight += weights[j];
    }
    int i = 0;
    bool begin = true;
    while (begin)
    {
        while (i < number && currentWeight + weights[i] <= room)
        {
            remainWeight -= weights[i];
            currentWeight += weights[i];
            tempResult[i] = 1;
            i++;
        }
        if (i >= number)
        {
            for (int j = 0; j < number; j++)
            {
                resultList[j] = tempResult[j];
            }
            maxWeight = currentWeight;
        }
        else
        {
            remainWeight -= weights[i];
            tempResult[i] = 0;
            i++;
        }
        while (currentWeight + remainWeight <= maxWeight)
        {
            i--;
            while (i >= 0 && !tempResult[i])
            {
                remainWeight += weights[i];
                i--;
            }
            if (i == -1)
            {
                delete[] tempResult;
                return maxWeight;
            }
            tempResult[i] = 0;
            currentWeight -= weights[i];
            i++;
        }
    }
    return 0;
}
int main()
{
    int number = 0;
    int count = 0;
    while (cin >> number)
    {
        int *weights = new int[number];
        for (int i = 0; i < number; i++)
        {
            cin >> weights[i];
        }
        int roomA = 0;
        int roomB = 0;
        cin >> roomA >> roomB;
        int *resultList = new int[number];
        int maxWeightA = Loading(weights, roomA, number, resultList);
        cout << "Case " << ++count << endl;
        int maxWeightB = 0;
        for (int j = 0; j < number; j++)
        {
            maxWeightB = maxWeightB + weights[j] * (1 - resultList[j]);
        }
        delete[] weights;
        if (maxWeightB > roomB)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << maxWeightA << " ";
            for (int i = 0; i < number; i++)
            {
                cout << resultList[i];
            }
            cout << endl;
        }
        delete[] resultList;
    }
    return 0;
}