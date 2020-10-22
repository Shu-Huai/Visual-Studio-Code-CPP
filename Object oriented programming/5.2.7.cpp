#include <iostream>
using namespace std;
void exchange(char *&p1, char *&p2)
{
    char *temp = p1;
    p1 = p2;
    p2 = temp;
}
int main()
{
    char *p1 = (char *)"I'm a programmer.";
    char *p2 = (char *)"Hello, World.";
    cout << p1 << '\n'
         << p2 << endl;
    exchange(p1, p2);
    cout << p1 << '\n'
         << p2 << endl;
    return 0;
}