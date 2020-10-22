#include <iomanip>
#include <iostream>
using namespace std;
class Date
{
private:
    int year, month, day;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
    Date(int Year = 0, int Month = 0, int Day = 0);
    int Getnumber();
    friend ostream &operator<<(ostream &out, const Date &d);
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
ostream &operator<<(ostream &out, const Date &d)
{
    out << setfill('0') << setw(2) << d.month << "/" << setw(2) << d.day << "/" << setw(4) << d.year;
    return out;
}
int main()
{
    int year = 0;
    int month = 0;
    int day = 0;
    static int case_ = 0;
    while (cin >> year >> month >> day)
    {
        case_++;
        Date d(year, month, day);
        cout << "Case " << case_ << ": " << d << ", " << d.Getnumber() << endl;
    }
    return 0;
}