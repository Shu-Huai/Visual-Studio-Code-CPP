#include <iomanip>
#include <iostream>
using namespace std;
class Time
{
public: // 公开的（访问属性）
    Time(int hour = 0, int minute = 0, int second = 0)
    {
        h = hour;
        m = minute;
        s = second;
    }
    void SetTime(int hour, int minute, int second)
    {
        h = hour;
        m = minute;
        s = second;
    }
    int GetHour() { return h; }
    int GetMinute() { return m; }
    int GetSecond() { return s; }
    void Show()
    {
        cout << setfill('0') << setw(2) << h
             << ":" << setw(2) << m
             << ":" << setw(2) << s
             << setfill(' ') << endl;
    }

private: // 私有的（访问属性）
    int h, m, s;
};
int main()
{
    Time clock = (1);
    Time t = 30;
    return 0;
}