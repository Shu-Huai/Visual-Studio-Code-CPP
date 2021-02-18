#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    srand((unsigned)time(NULL));
    int low = 1;
    int high = 10;
    char input = 0;
    int total = 0;
    int length = high - low + 1;
    int *number = new int[length]{0};
    double *probability = new double[length]{0};
    while (input != '\r')
    {
        number[rand() % (high - low + 1)]++;
        total++;
        for (int i = 0; i < length; i++)
        {
            probability[i] = double(number[i]) / total;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{short(0), short(i)});
            cout << i + low << ":\t" << fixed << probability[i] << ",\t" << number[i] << endl;
        }
        if (kbhit())
        {
            input = getch();
            if (input == '\40')
            {
                system("pause");
                system("cls");
            }
        }
    }
    return 0;
}