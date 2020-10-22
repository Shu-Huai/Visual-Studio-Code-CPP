#include <iostream>
using namespace std;
template <typename T>
void ShowTypeSize(const char *type, T x)
{
    int size = sizeof(x);
    cout << "The type size of \"" << type << "\" is " << size << " byte." << endl;
}
int main()
{
    ShowTypeSize("int", int(1));
    ShowTypeSize("unsigned int", (unsigned int)(1));
    ShowTypeSize("double", double(1));
    ShowTypeSize("long double", (long double)(1));
    ShowTypeSize("short", short(1));
    ShowTypeSize("unsigned short", (unsigned short)(1));
    ShowTypeSize("long", long(1));
    ShowTypeSize("unsigned long", (unsigned long)(1));
    ShowTypeSize("long long", (long long)(1));
    ShowTypeSize("unsigned long long", (unsigned long long)(1));
    ShowTypeSize("float", float(1));
    ShowTypeSize("char", char(1));
    ShowTypeSize("bool", bool(1));
    ShowTypeSize("int *", (int *)(1));
    return 0;
}