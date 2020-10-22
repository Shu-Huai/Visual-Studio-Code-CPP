#include <iostream>
using namespace std;

struct T_shirt
{
    int size;
    int amount;
    T_shirt *next;
};

void insertLast(T_shirt *&head)
{
    T_shirt *p, *q;
    p = new T_shirt;
    cout << "输入参数一:";
    cin >> p->size;
    cout << "输入参数二:";
    cin >> p->amount;

    if (head->next == NULL)
        head->next = p;
    else
    {
        q = head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
    p->next = NULL;
}

void insertFirst(T_shirt *&head)
{
    T_shirt *p;
    p = new T_shirt;
    cout << "输入参数一:";
    cin >> p->size;
    cout << "输入参数二:";
    cin >> p->amount;

    if (head->next == NULL)
        head->next = p;
    else
    {
        p->next = head->next;
        head->next = p;
    }
}

void displayList(T_shirt *&head)
{
    T_shirt *p = head->next;
    while (p != NULL)
    {
        cout << p->size << endl
             << p->amount << endl
             << endl;
        p = p->next;
    }
}

void sortList(T_shirt *&head)
{
    T_shirt *a, *b, *c;
    for (a = head; a->next != NULL; a = a->next)
    {
        for (b = head; b->next != NULL; b = b->next)
        {
            c = b->next;
            if (c->amount < b->amount)
            {
                swap(c->amount, b->amount);
                swap(c->size, b->size);
            }
        }
    }
}

int main()
{
    T_shirt *head;
    head = new T_shirt;
    head->next = NULL;
    cout << "1" << endl;
    insertLast(head);
    cout << "2" << endl;
    insertLast(head);
    cout << "3" << endl;
    insertLast(head);
    cout << "4" << endl;
    insertFirst(head);
    displayList(head);
    sortList(head);
    displayList(head);
    system("pause");
}