#include <iostream>
using namespace std;
int main()
{
    static int case_ = 0;
    double temp = 0.0;
    while (cin >> temp)
    {
        case_++;
        cout << "Case " << case_ << ":" << endl;
        double n[1000] = {0.0};
        n[0] = temp;
        int i = 0;
        while (getchar() != '\n')
        {
            i++;
            cin >> n[i];
        }
        int length = i + 1;
        double min = n[0];
        for (i = 0; i < length; i++)
        {
            if (min > n[i])
            {
                min = n[i];
            }
        }
        int result[1000] = {0};
        int count = 0;
        temp = 0;
        for (i = 0; i < length; i++)
        {
            double max = n[0];
            int index = 0;
            for (int j = 0; j < length; j++)
            {
                if (max < n[j])
                {
                    max = n[j];
                    index = j;
                }
            }
            if (temp == max and i != 0)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            temp = n[index];
            result[index] = i - count + 1;
            n[index] = min - 1;
        }
        for (i = 0; i < length; i++)
        {
            cout << result[i];
            if (i != length - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
    return 0;
}