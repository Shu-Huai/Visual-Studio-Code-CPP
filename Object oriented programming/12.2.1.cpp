#include <iomanip>
#include <iostream>
using namespace std;
class Time
{
private:
    int hour, minute, second;

public:
    Time(int Hour = 0, int Minute = 0, int Second = 0);
    void SetTime(int Hour = 0, int Minute = 0, int Second = 0);
    void operator+(int seconds);
    Time operator+(const Time &time0);
    friend istream &operator>>(istream &in, const Time &time);
    friend ostream &operator<<(ostream &out, const Time &time);
    Time &operator++();
    Time &operator--();
    Time operator++(int);
    Time operator--(int);
};
Time::Time(int Hour, int Minute, int Second)
{
    hour = Hour;
    minute = Minute;
    second = Second;
}
void Time::SetTime(int Hour, int Minute, int Second)
{
    hour = Hour;
    minute = Minute;
    second = Second;
}
void Time::operator+(int seconds)
{
    int Seconds = seconds % 60;
    int Minutes = seconds / 60;
    int Hours = Minutes / 60;
    Minutes %= 60;
    hour += Hours;
    minute += Minutes;
    second += Seconds;
}
Time Time::operator+(const Time &time0)
{
    Time sum;
    sum.second = second + time0.second;
    sum.minute = minute + time0.minute + sum.second / 60;
    sum.second %= 60;
    sum.hour = hour + time0.hour + sum.minute / 60;
    sum.minute %= 60;
    return sum;
}
istream &operator>>(istream &in, Time &time)
{
    int hour, minute, second;
    char str[100];
    in.getline(str, 100, ':');
    hour = atoi(str);
    in.getline(str, 100, ':');
    minute = atoi(str);
    in.getline(str, 100);
    second = atoi(str);
    time.SetTime(hour, minute, second);
    return in;
}
ostream &operator<<(ostream &out, const Time &time)
{
    out << setfill('0') << setw(2) << time.hour << ":" << time.minute << ":" << time.second << endl;
    return out;
}
Time &Time::operator++()
{
    second++;
    if (second == 60)
    {
        second = 0;
        minute++;
    }
    if (minute == 60)
    {
        minute = 0;
        hour++;
    }
    return *this;
}
Time &Time::operator--()
{
    second--;
    if (second == -1)
    {
        second = 59;
        minute--;
    }
    if (minute == -1)
    {
        minute = 59;
        hour--;
    }
    return *this;
}
Time Time::operator++(int)
{
    Time temp(*this);
    ++(*this);
    return temp;
}
Time Time::operator--(int)
{
    Time temp(*this);
    --(*this);
    return temp;
}

int main()
{
    Time test0(8, 10, 32);
    Time test1(0, 10, 10);
    test0 + 10;
    Time test2 = test0 + test1;
    cin >> test0;
    cout << test0;
    ++test0;
    --test0;
    test0++;
    test0--;
    return 0;
}