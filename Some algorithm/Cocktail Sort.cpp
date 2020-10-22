#include <iostream>
using namespace std;
int &CocktailSort(int (&a)[1000], int length)
{
    int left = 0;
    int right = length - 1;
    int tempPostion = 0;
    for (int i = 0; i < length - 1; i++)
    {
        int flag = 1;
        tempPostion = 0;
        for (int j = left; j < right; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 0;
                tempPostion = j;
            }
        }
        if (flag == 1)
        {
            break;
        }
        right = tempPostion;
        for (int j = right; j > left; j--)
        {
            if (a[j] < a[j - 1])
            {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                flag = 0;
                tempPostion = j;
            }
        }
        left++;
        if (flag == 1)
        {
            break;
        }
    }
    return *a;
}
int main()
{
    cout << "Please input an array:";
    int a[1000] = {0};
    int i = 0;
    do
    {
        cin >> a[i];
        i++;
    } while (getchar() != '\n');
    CocktailSort(a, i);
    cout << "The result is: ";
    for (int j = 0; j < i; j++)
    {
        cout << a[j];
        if (j != i - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
    return 0;
}