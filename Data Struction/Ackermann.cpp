#include "SeqStack.h"
#include <future>
#include <thread>
int Akm(int m, int n)
{
    if (!m)
    {
        return n + 1;
    }
    if (!n)
    {
        return Akm(m - 1, 1);
    }
    return Akm(m - 1, Akm(m, n - 1));
}
int AKM(promise<int> &P, int m, int n)
{
    SeqStack<int> SS;
    SS.Push(m);
    SS.Push(n);
    int tempm = 0;
    int tempn = 0;
    while (SS.Pop(tempn) != UNDER_FLOW and SS.Pop(tempm) != UNDER_FLOW)
    {
        if (!tempm)
        {
            SS.Push(tempn + 1);
        }
        else if (!tempn)
        {
            SS.Push(tempm - 1);
            SS.Push(1);
        }
        else
        {
            SS.Push(tempm - 1);
            SS.Push(tempm);
            SS.Push(tempn - 1);
        }
    }
    P.set_value(tempn);
    return tempn;
}
int main()
{
    int m = 0;
    int n = 0;
    while (cin >> m >> n)
    {
        promise<int> P;
        future<int> F = P.get_future();
        thread T(AKM, ref(P), m, n);
        cout << Akm(m, n) << endl
             << F.get() << endl;
        T.join();
    }
    return 0;
}