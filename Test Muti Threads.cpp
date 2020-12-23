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
        elems[i] = (ElemType)UniformRand(32, 126);
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
                ElemType temp = elems[j];
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
void SingleThread(int i, double &Time, bool &IsRight)
{
    clock_t StartTime;
    clock_t EndTime;
    ElemType *a = new ElemType[i];
    ElemType *b = new ElemType[i];
    ElemType *c = new ElemType[i];
    ElemType *d = new ElemType[i];
    InitData(a, i);
    InitData(b, i);
    InitData(c, i);
    InitData(d, i);
    StartTime = clock();
    BubbleSort(a, i);
    BubbleSort(b, i);
    BubbleSort(c, i);
    BubbleSort(d, i);
    EndTime = clock();
    Time = (float)(EndTime - StartTime) / CLOCKS_PER_SEC;
    IsRight = Check(a, i) and Check(b, i) and Check(c, i) and Check(d, i);
    delete[] a;
    delete[] b;
    delete[] c;
    delete[] d;
}
template <class ElemType>
void DoubleThreads(int i, double &Time, bool &IsRight)
{
    clock_t StartTime;
    clock_t EndTime;
    ElemType *a = new ElemType[i];
    ElemType *b = new ElemType[i];
    ElemType *c = new ElemType[i];
    ElemType *d = new ElemType[i];
    InitData(a, i);
    InitData(b, i);
    InitData(c, i);
    InitData(d, i);
    StartTime = clock();
    thread T0(BubbleSort<ElemType>, a, i);
    thread T1(BubbleSort<ElemType>, b, i);
    T0.join();
    T1.join();
    T0 = thread(BubbleSort<ElemType>, c, i);
    T1 = thread(BubbleSort<ElemType>, d, i);
    T0.join();
    T1.join();
    EndTime = clock();
    Time = (float)(EndTime - StartTime) / CLOCKS_PER_SEC;
    IsRight = Check(a, i) and Check(b, i) and Check(c, i) and Check(d, i);
    delete[] a;
    delete[] b;
    delete[] c;
    delete[] d;
}
template <class ElemType>
void QuadrupleThreads(int i, double &Time, bool &IsRight)
{
    clock_t StartTime;
    clock_t EndTime;
    ElemType *a = new ElemType[i];
    ElemType *b = new ElemType[i];
    ElemType *c = new ElemType[i];
    ElemType *d = new ElemType[i];
    InitData(a, i);
    InitData(b, i);
    InitData(c, i);
    InitData(d, i);
    StartTime = clock();
    thread T0(BubbleSort<ElemType>, a, i);
    thread T1(BubbleSort<ElemType>, b, i);
    thread T2(BubbleSort<ElemType>, c, i);
    thread T3(BubbleSort<ElemType>, d, i);
    T0.join();
    T1.join();
    T2.join();
    T3.join();
    EndTime = clock();
    Time = (float)(EndTime - StartTime) / CLOCKS_PER_SEC;
    IsRight = Check(a, i) and Check(b, i) and Check(c, i) and Check(d, i);
    delete[] a;
    delete[] b;
    delete[] c;
    delete[] d;
}
template <class ElemType>
void TestMultiThreads()
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
                SingleThread<ElemType>(i, Time, IsRight);
            }
            else if (j == 1)
            {
                cout << "double";
                DoubleThreads<ElemType>(i, Time, IsRight);
            }
            else
            {
                cout << "quadruple";
                QuadrupleThreads<ElemType>(i, Time, IsRight);
            }
            cout << " thread to handle four " << i << " " << abi::__cxa_demangle(typeid(ElemType).name(), 0, 0, 0) << " data is " << Time << "s." << (IsRight ? "√" : "×") << endl;
        }
    }
}
template <class ElemType>
void SingleSort(int i, double &Time, bool &IsRight)
{
    clock_t StartTime;
    clock_t EndTime;
    ElemType *a = new ElemType[i];
    InitData(a, i);
    StartTime = clock();
    BubbleSort<ElemType>(a, i);
    EndTime = clock();
    Time = (float)(EndTime - StartTime) / CLOCKS_PER_SEC;
    IsRight = Check(a, i);
    delete[] a;
}
template <class ElemType>
void MultiSort(int i, double &Time, bool &IsRight)
{
    clock_t StartTime;
    clock_t EndTime;
    ElemType *a = new ElemType[i];
    InitData(a, i);
    ElemType *b = new ElemType[i];
    ElemType *c = new ElemType[i];
    StartTime = clock();
    int bindex = 0;
    int cindex = 0;
    for (int j = 0; j < i; j++)
    {
        if (a[j] <= a[0])
        {
            b[bindex] = a[j];
            bindex++;
        }
        else
        {
            c[cindex] = a[j];
            cindex++;
        }
    }
    thread T0(BubbleSort<ElemType>, b, bindex);
    thread T1(BubbleSort<ElemType>, c, cindex);
    T0.join();
    T1.join();
    for (int j = 0; j < bindex; j++)
    {
        a[j] = b[j];
    }
    for (int j = 0; j < cindex; j++)
    {
        a[j + bindex] = c[j];
    }
    EndTime = clock();
    Time = (float)(EndTime - StartTime) / CLOCKS_PER_SEC;
    IsRight = Check(a, i);
    delete[] a;
    delete[] b;
    delete[] c;
}
template <class ElemType>
void TestMultiSort()
{
    for (int i = 1; i <= 65536; i *= 2)
    {
        double Time = 0;
        bool IsRight = 0;
        for (int j = 0; j < 2; j++)
        {
            cout << "The runtime when using ";
            if (!j)
            {
                cout << "single";
                SingleSort<ElemType>(i, Time, IsRight);
            }
            else
            {
                cout << "double";
                MultiSort<ElemType>(i, Time, IsRight);
            }
            cout << " thread to handle " << i << " " << abi::__cxa_demangle(typeid(ElemType).name(), 0, 0, 0) << " data is " << Time << "s." << (IsRight ? "√" : "×") << endl;
        }
    }
}
int main()
{
    freopen("Test Muti Threads.txt", "w", stdout);
    TestMultiThreads<short int>();
    TestMultiThreads<int>();
    TestMultiThreads<long int>();
    TestMultiThreads<long long int>();
    TestMultiThreads<float>();
    TestMultiThreads<double>();
    TestMultiThreads<long double>();
    TestMultiThreads<char>();
    TestMultiSort<short int>();
    TestMultiSort<int>();
    TestMultiSort<long int>();
    TestMultiSort<long long int>();
    TestMultiSort<float>();
    TestMultiSort<double>();
    TestMultiSort<long double>();
    TestMultiSort<char>();
    return 0;
}