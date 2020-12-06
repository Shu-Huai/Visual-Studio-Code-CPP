#include <iostream>
using namespace std;
struct test
{
    int a;
    double b;
    char c;
};
int main()
{
    test test0[10];
    for (int i = 0; i < 10; i++)
    {
        test0[i].a = i;
        test0[i].b = i + 0.1;
        test0[i].c = 'a' + i;
        cout << "Struct " << i << ": " << test0[i].a << ", " << test0[i].b << ", " << test0[i].c << endl;
    }
    return 0;
}