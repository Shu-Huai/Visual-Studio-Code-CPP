#include <iostream>
using namespace std;
struct ListNode
{
    double value;
    ListNode *next;
};
void InitializeList(ListNode *&head)
{
    head = new ListNode;
    head->value = 1;
    head->next = NULL;
}
void Insert(ListNode *&head, int val)
{
    ListNode *p = new ListNode;
    p->value = val;
    p->next = head;
    head = p;
    int a = 0;
}
void Expand(ListNode *&head, int val)
{
    ListNode *p = head;
    ListNode *temp = new ListNode;
    temp->value = val;
    temp->next = NULL;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
}
void ChangeValue(ListNode *head, int val, int n)
{
    ListNode *p = head;
    int count = 0;
    for (ListNode *p = head; p != NULL; p = p->next)
    {
        if (count == n)
        {
            p->value = val;
        }
        count++;
    }
}
void ShowList(ListNode *head)
{
    for (ListNode *p = head; p != NULL; p = p->next)
    {
        cout << p->value;
        if (p->next != NULL)
        {
            cout << " -> ";
        }
    }
    cout << endl;
}
void Delete(ListNode *&head, int n)
{
    int count = 0;
    for (ListNode *p = head; p != NULL; p = p->next)
    {
        if (count == n - 1)
        {
            p->next = p->next->next;
        }
        count++;
    }
}
void DeleteList(ListNode *&head)
{
    ListNode *p;
    while (head != NULL)
    {
        p = head;
        head = head->next;
        delete p;
    }
}
int main()
{
    ListNode *head = NULL;
    InitializeList(head);
    Insert(head, 0);
    Expand(head, 2);
    ChangeValue(head, 2020, 2);
    ShowList(head);
    Delete(head, 2);
    DeleteList(head);
    return 0;
}