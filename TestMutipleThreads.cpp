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
    InitData(a, i);
    InitData(b, i);
    StartTime = clock();
    BubbleSort(a, i);
    BubbleSort(b, i);
    EndTime = clock();
    Time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;
    IsRight = Check(a, i) and Check(b, i);
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
    InitData(a, i);
    InitData(b, i);
    StartTime = clock();
    thread T0(BubbleSort<ElemType>, a, i);
    thread T1(BubbleSort<ElemType>, b, i);
    T0.join();
    T1.join();
    EndTime = clock();
    Time = (double)(EndTime - StartTime) / CLOCKS_PER_SEC;
    IsRight = Check(a, i) and Check(b, i);
    delete[] a;
    delete[] b;
}
template <class ElemType>
void Test()
{
    for (int i = 1; i <= 65536; i *= 2)
    {
        char ThreadNumber[][20] = {"single", "double"};
        for (int j = 0; j < 2; j++)
        {
            double Time = 0;
            bool IsRight = 0;
            if (!j)
            {
                TestSingleThread<ElemType>(i, Time, IsRight);
            }
            else
            {
                TestDoubleThreads<ElemType>(i, Time, IsRight);
            }
            cout << "The runtime when using " << ThreadNumber[j] << " thread to handle two of " << i << " ";
            cout << abi::__cxa_demangle(typeid(ElemType).name(), 0, 0, 0);
            cout << " data is " << Time << "s." << endl
                 << "The result is " << (IsRight ? "true." : "false.") << endl;
        }
        cout << endl;
    }
}
int main()
{
    Test<short>();
    Test<int>();
    Test<float>();
    Test<double>();
    return 0;
}