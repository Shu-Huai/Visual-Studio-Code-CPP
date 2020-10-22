#include <iostream>
using namespace std;
bool yu(bool a, bool b)
{
    return a && b;
}
bool huo(bool a, bool b)
{
    return a || b;
}
bool fei(bool a)
{
    return !a;
}
bool yufei(bool a, bool b)
{
    return fei(yu(a, b));
}
bool huofei(bool a, bool b)
{
    return fei(huo(a, b));
}
bool yihuo(bool a, bool b)
{
    return huo(yu(fei(a), b), yu(a, fei(b)));
}
bool tonghuo(bool a, bool b)
{
    return fei(yihuo(a, b));
}
string banjiaqi(bool a, bool b)
{
    char result[2] = {char(yu(a, b) + 48), char(yihuo(a, b) + 48)};
    string temp(result, 2);
    return temp;
}
void show(bool a, bool b)
{
    cout << "a = " << a << ", b = " << b << endl
         << "与：" << yu(a, b) << endl
         << "或：" << huo(a, b) << endl
         << "非：" << fei(a) << endl
         << "与非：" << yufei(a, b) << endl
         << "或非：" << huofei(a, b) << endl
         << "异或：" << yihuo(a, b) << endl
         << "同或：" << tonghuo(a, b) << endl
         << "半加器：" << banjiaqi(a, b) << endl;
}
int main()
{
    system("");
    for (int i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            show(0, 0);
            break;
        case 1:
            show(0, 1);
            break;
        case 2:
            show(1, 0);
            break;
        case 3:
            show(1, 1);
            break;
        }
    }
    return 0;
}