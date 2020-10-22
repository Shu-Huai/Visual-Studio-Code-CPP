#include <iostream>
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;
class Employee
{
public:
    Employee()
    {
        Name = "no name";
        Addr = "no addr";
        Zip = "no zip";
    }
    Employee(const char *name, const char *addr, const char *zip)
    {
        Name = name;
        Addr = addr;
        Zip = zip;
    }
    Employee(const char *name, const char *addr)
    {
        Name = name;
        Addr = addr;
        Zip = "no zip";
    }
    Employee(const char *name)
    {
        Name = name;
        Addr = "no addr";
        Zip = "no zip";
    }
    void ChangeName(const char *name)
    {
        Name = name;
    }
    void Display()
    {
        cout << "The name is: " << Name << endl
             << "The address is: " << Addr << endl
             << "The zip is: " << Zip << endl;
    }

private:
    string Name, Addr, Zip;
};
int main()
{
    system("");
    Employee s("张  三", "中山路 18 号", "200020");
    Employee staff[3] = {"李  四", s,
                         Employee("王  五", "中南路 100 号")};
    staff[1].ChangeName("赵  六");
    s.Display();
    for (int i = 0; i < 3; i++)
    {
        staff[i].Display();
    }
    return 0;
}