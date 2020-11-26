#include <iostream>
using namespace std;
template <typename T>
T test(T *n)
{
    (*n)++;
    return *n;
}
int main()
{
    int n = 114514;
    test(&n);
    double o = 114.514;
    test(&o);
    char c = '1';
    test(&c);
    char *d = &c;
    test(&*d);
    return 0;
}