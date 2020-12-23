#include <Windows.h>
#include <ctime>
#include <cxxabi.h>
#include <iostream>
#include <thread>
using namespace std;
double UniformRand(double a, double b)
{
    return a + rand() * (b - a) / RAND_MAX;
}
template <class ElemType>
void InitData(ElemType *elems, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        elems[i] = (ElemType)UniformRand(54, 90);
    }
}
template <class ElemType>
ElemType &BubbleSort(ElemType *elems, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (elems[j] > elems[j + 1])
            {
                int temp = elems[j];
                elems[j] = elems[j + 1];
                elems[j + 1] = temp;
            }
        }
    }
    return *elems;
}
template <typename ElemType>
bool Check(const ElemType *elems, int length)
{
    for (int i = 1; i < length; i++)
    {
        if (elems[i - 1] > elems[i])
        {
            return false;
        }
    }
    return true;
}
template <class ElemType>
void TestSingleThread(int i, double &Time, bool &IsRight)
{
    clock_t StartTime;
    clock_t EndTime;
    ElemType *a = new ElemType[i];
    ElemType *b = new ElemType[i];
    ElemType *c = new ElemType[i];
    InitData(a, i);
    InitData(b, i);
    InitData(c, i);
    StartTime = clock();
    BubbleSort(a, i);
    BubbleSort(b, i);
    BubbleSort(c, i);
    EndTime = clock();
    Time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;
    IsRight = Check(a, i) and Check(b, i) and Check(c, i);
    delete[] a;
    delete[] b;
}
template <class ElemType>
void TestDoubleThreads(int i, double &Time, bool &IsRight)
{
    clock_t StartTime;
    clock_t EndTime;
    ElemType *a = new ElemType[i];
    ElemType *b = new ElemType[i];
    ElemType *c = new ElemType[i];
    InitData(a, i);
    InitData(b, i);
    InitData(c, i);
    StartTime = clock();
    thread T0(BubbleSort<ElemType>, a, i);
    thread T1(BubbleSort<ElemType>, b, i);
    T0.join();
    T1.join();
    BubbleSort<ElemType>(c, i);
    EndTime = clock();
    Time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;
    IsRight = Check(a, i) and Check(b, i) and Check(c, i);
    delete[] a;
    delete[] b;
    delete[] c;
}
template <class ElemType>
void TestTrippleThreads(int i, double &Time, bool &IsRight)
{
    clock_t StartTime;
    clock_t EndTime;
    ElemType *a = new ElemType[i];
    ElemType *b = new ElemType[i];
    ElemType *c = new ElemType[i];
    InitData(a, i);
    InitData(b, i);
    InitData(c, i);
    StartTime = clock();
    thread T0(BubbleSort<ElemType>, a, i);
    thread T1(BubbleSort<ElemType>, b, i);
    thread T2(BubbleSort<ElemType>, c, i);
    T0.join();
    T1.join();
    T2.join();
    EndTime = clock();
    Time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;
    IsRight = Check(a, i) and Check(b, i) and Check(c, i);
    delete[] a;
    delete[] b;
    delete[] c;
}
template <class ElemType>
void TestMutiThreads()
{
    for (int i = 1; i <= 65536; i *= 2)
    {
        double Time = 0;
        bool IsRight = 0;
        for (int j = 0; j < 3; j++)
        {
            cout << "The runtime when using ";
            if (!j)
            {
                cout << "single";
                TestSingleThread<ElemType>(i, Time, IsRight);
            }
            else if (j == 1)
            {
                cout << "double";
                TestDoubleThreads<ElemType>(i, Time, IsRight);
            }
            else
            {
                cout << "tripple";
                TestTrippleThreads<ElemType>(i, Time, IsRight);
            }
            cout << " thread to handle three of " << i << " " << abi::__cxa_demangle(typeid(ElemType).name(), 0, 0, 0) << " data is " << Time << "s." << endl
                 << "The result is " << (IsRight ? "true." : "false.") << endl;
        }
        cout << endl;
    }
}
int main()
{
    TestMutiThreads<short>();
    TestMutiThreads<int>();
    TestMutiThreads<float>();
    TestMutiThreads<double>();
    return 0;
}