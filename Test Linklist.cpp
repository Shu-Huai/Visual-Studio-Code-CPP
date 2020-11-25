#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void insert(Node *&head, int n)
{
    Node *p = new Node;
    p->data = n;
    p->next = head;
    head = p;
}
void show(Node *&head)
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << ", ";
        p = p->next;
    }
    cout << "\b\b " << endl;
}
void append(Node *&head, int n)
{
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = new Node;
    p->next->data = n;
    p->next->next = NULL;
}
void release(Node *&head)
{
    Node *p = head;
    while (head != NULL)
    {
        p = head;
        head = head->next;
        delete p;
    }
}
int main()
{
    Node *head = NULL;
    for (int i = 10; i >= 0; i--)
    {
        insert(head, i);
    }
    show(head);
    for (int i = 11; i <= 20; i++)
    {
        append(head, i);
    }
    show(head);
    release(head);
    show(head);
    return 0;
}