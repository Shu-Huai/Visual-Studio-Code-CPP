#include <iostream>
using namespace std;
void SelectionSort(int (&a)[1000], int length)
{
    for (int i = 0; i < length; i++)
    {
        int min = a[i];
        int index = i;
        for (int j = i + 1; j < length; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                index = j;
            }
        }
        a[index] = a[i];
        a[i] = min;
    }
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
    SelectionSort(a, i);
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