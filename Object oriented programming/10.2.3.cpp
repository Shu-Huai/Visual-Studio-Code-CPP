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
        strcpy(Name, name);
        strcpy(Addr, addr);
        strcpy(Zip, zip);
    }
    Employee(const char *name, const char *addr)
    {
        strcpy(Name, name);
        strcpy(Addr, addr);
        strcpy(Zip, "no zip");
    }
    Employee(const char *name)
    {
        strcpy(Name, name);
        strcpy(Addr, "no addr");
        strcpy(Zip, "no zip");
    }
    void ChangeName(const char *name)
    {
        strcpy(Name, name);
    }
    void Display()
    {
        cout << "The name is: " << Name << endl
             << "The address is: " << Addr << endl
             << "The zip is: " << Zip << endl;
    }

private:
    char Name[100], Addr[100], Zip[100];
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