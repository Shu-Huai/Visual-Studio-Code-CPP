#include <iomanip>
#include <iostream>
using namespace std;
class date
{
public:
    date(int year = 0, int month = 0, int day = 0)
    {
        y = year;
        m = month;
        d = day;
    }
    int returnyear()
    {
        return y;
    }
    int returnmonth()
    {
        return m;
    }
    int returnday()
    {
        return d;
    }
    void outputdate()
    {
        cout << "The date is: " << y << "-" << setfill('0') << setw(2) << m << "-" << setw(2) << d << endl;
    }
    void nextday(int year, int month, int day)
    {
        if ((year % 4 == 0 and year % 100 != 0) or year % 400 == 0)
        {
            if (month == 2)
            {
                if (day == 29)
                {
                    day = 1;
                    month = 3;
                }
                else
                {
                    day++;
                }
            }
            else if (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10)
            {
                if (day == 31)
                {
                    day = 1;
                    month++;
                }
                else
                {
                    day++;
                }
            }
            else if (month == 4 or month == 6 or month == 9 or month == 11)
            {
                if (day == 30)
                {
                    day = 1;
                    month++;
                }
                else
                {
                    day++;
                }
            }
            else if (month == 12)
            {
                if (day == 31)
                {
                    day = 1;
                    month = 1;
                    year++;
                }
                else
                {
                    day++;
                }
            }
        }
        else
        {
            if (month == 2)
            {
                if (day == 28)
                {
                    day = 1;
                    month = 3;
                }
                else
                {
                    day++;
                }
            }
            else if (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10)
            {
                if (day == 31)
                {
                    day = 1;
                    month++;
                }
                else
                {
                    day++;
                }
            }
            else if (month == 4 or month == 6 or month == 9 or month == 11)
            {
                if (day == 30)
                {
                    day = 1;
                    month++;
                }
                else
                {
                    day++;
                }
            }
            else if (month == 12)
            {
                if (day == 31)
                {
                    day = 1;
                    month = 1;
                    year++;
                }
                else
                {
                    day++;
                }
            }
        }
        cout << "The next date is: " << year << "-" << setfill('0') << setw(2) << month << "-" << setw(2) << day << endl;
    }

private:
    int y, m, d;
};
int main()
{
    cout << "Please input a date: ";
    int year = 0;
    int month = 0;
    int day = 0;
    char temp = '\0';
    cin >> year >> temp >> month >> temp >> day;
    date date(year, month, day);
    cout << "The year is: " << date.returnyear() << endl;
    cout << "The month is: " << date.returnmonth() << endl;
    cout << "The day is: " << date.returnday() << endl;
    date.outputdate();
    date.nextday(year, month, day);
    return 0;
}