#include <iostream>
using namespace std;
int &BubbleSort(int (&a)[1000], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
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
    BubbleSort(a, i);
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