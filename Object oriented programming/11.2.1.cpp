#include <iostream>
using namespace std;
class Date
{
private:
    int year, month, day;
    static int days[12];

public:
    Date(int Year = 0, int Month = 0, int Day = 0);
    int Getnumber();
};
Date::Date(int Year, int Month, int Day)
{
    year = Year;
    month = Month;
    day = Day;
    if (year % 4 == 0 and year % 100 != 0 or year % 400 == 0)
    {
        days[1] = 29;
    }
}
int Date::Getnumber()
{
    int number = 0;
    for (int i = 1; i < month; i++)
    {
        for (int j = 1; j <= days[i - 1]; j++)
        {
            number++;
        }
    }
    number += day;
    return number;
}
int Date::days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    Date test(2020, 10, 13);
    int number = test.Getnumber();
    return 0;
}