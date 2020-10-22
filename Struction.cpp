#include <iostream>
using namespace std;
struct student
{
    int id = 0;
    string name;
    int mark = 0;
    student *next;
};
int main()
{
    student *head = NULL;
    student student1 = {12345, "fgtredcvg", 100};
    head = &student1;
    student student2 = {23456789, "349rcfl", 90};
    student1.next = &student2;
    return 0;
}