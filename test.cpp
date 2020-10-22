#include <iostream>
using namespace std;
const int REFEREES = 8;
struct Player
{
    int num;
    char name[7];
    double x[REFEREES], aver;
    int rank;
    Player *next;
};
void Show(const Player *node) // 输出一个结点的数据
{
    cout << node->num << " " << node->name;
    for (int i = 0; i < REFEREES; i++)
        cout << " " << node->x[i];
    cout << " " << node->aver << " " << node->rank << endl;
}
void ShowList(const Player *head)
{
    if (head == NULL)
    {
        cout << "链表为空。" << endl;
        return;
    }
    while (head)
    {
        Show(head);        // 输出的二维表格中数据可能未对齐
        head = head->next; // 指向下一个结点首地址
    }
}
void DELETE(Player *&head)
{
    Player *p;
    p = head;
    head = head->next;
    delete p;
}
int main()
{
    system("");
    Player *head = NULL;
    Player *p;
    p = new Player;
    p->num = 1;
    p->next = head;
    head = p;
    p = new Player;
    p->num = 2;
    p->next = head;
    head = p;
    DELETE(head);
    return 0;
}