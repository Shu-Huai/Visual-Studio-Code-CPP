#include <iostream>
using namespace std;
class Base1
{
public:
    Base1()
    {
        cout << "Base1 construct." << endl;
    }
};
class Base2
{
public:
    Base2(int x)
    {
        cout << "Base2 construct." << x << endl;
    }
};
class Base3
{
public:
    Base3(int y)
    {
        cout << "Base3 construct." << y << endl;
    }
};
class Child : public Base2, public Base1, public Base3
{
public:
    Child(int i, int j, int k, int m) : Base2(i), Base3(j), b2(k), b3(m)
    {
    }

private:
    Base1 b1;
    Base2 b2;
    Base3 b3;
};
int main()
{
    Child child(3, 4, 5, 6);
    return 0;
}