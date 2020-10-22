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
        strcpy(Name, "no name");
        strcpy(Addr, "no addr");
        strcpy(Zip, "no zip");
    }
    Employee(const char *name, const char *addr, const char *zip)
    {
        Name = const_cast<char *>(name);
        Addr = const_cast<char *>(addr);
        Zip = const_cast<char *>(zip);
    }
    Employee(const char *name, const char *addr)
    {
        Name = const_cast<char *>(name);
        Addr = const_cast<char *>(addr);
        Zip = (char *)"no zip";
    }
    Employee(const char *name)
    {
        Name = const_cast<char *>(name);
        Addr = (char *)"no addr";
        Zip = (char *)"no zip";
    }
    void ChangeName(const char *name)
    {
        Name = const_cast<char *>(name);
    }
    void Display()
    {
        cout << "The name is: " << Name << endl
             << "The address is: " << Addr << endl
             << "The zip is: " << Zip << endl;
    }

private:
    char *Name, *Addr, *Zip;
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