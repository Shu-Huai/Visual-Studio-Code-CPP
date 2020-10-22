#include <conio.h>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void Create(Node *&head, int n, int *array);
int NumNodes(Node *&head);
void ShowList(Node *&head);
Node *Insert(Node *&head, int x);
Node *Append(Node *&head, int x);
void FreeList(Node *&head);
ostream &operator<<(ostream &out, const Node *head);
Node *Locate(Node *head, int x, int &num, bool newsearch = false);
int Save(const char *filename, const Node *head);
int Load(const char *filename, Node *&head);
int Pos(char ch, const char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        if (ch == str[i])
            return i;
    return -1;
}
int Choice(const char *prompt, const char *options = "")
{
    int key;
    cout << prompt << "{";
    for (int i = 0; options[i] != '\0'; i++)
    {
        if (' ' < (options[i] & 0x7f) && (options[i] & 0x7f) < 127)
            cout << options[i] << ' ';
        else
        {
            switch (options[i])
            {
            case '\t':
                cout << "[Tab] ";
                break;
            case '\x1b':
                cout << "[Esc] ";
                break;
            case ' ':
                cout << "[Space] ";
                break;
            }
        }
    }
    cout << "\b}: ";
    do
    {
        key = getch();
    } while (options[0] != '\0' && Pos(key, options) < 0);
    cout << endl;
    return key;
}
void Init(Node *&head)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 5, 2, 5, 8};
    int n = sizeof(array) / sizeof(*array);
    Create(head, n, array);
}
void Find(Node *head, int x)
{
    Node *p;
    int n = 0, num;
    p = Locate(head, x, num, true);
    while (p != NULL)
    {
        cout << "找到第 " << num << " 结点(编号从0开始)：\t" << p->data << endl;
        n++;
        p = Locate(head, x, num);
    }
    cout << "\t共找到 " << n << " 个结点，满足条件。" << endl;
}
void Create(Node *&head, int n, int *array)
{
    Node *p;
    head = new Node;
    p = head;
    for (int i = 0; i < n; i++)
    {
        Node *s = new Node;
        s->data = array[i];
        p->next = s;
        p = s;
    }
    head = head->next;
    p->next = NULL;
}
int NumNodes(Node *&head)
{
    int n = 0;
    Node *p = head;
    while (p != NULL)
    {
        p = p->next;
        n++;
    }
    return n;
}
void ShowList(Node *&head)
{
    cout << "head -> ";
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}
Node *Insert(Node *&head, int x)
{
    Node *p = head;
    Node *p0 = new Node;
    p0->data = x;
    p0->next = NULL;
    head = p0;
    p0->next = p;
    return p0;
}
Node *Append(Node *&head, int x)
{
    Node *p = head;
    Node *p0 = new Node;
    p0->data = x;
    p0->next = NULL;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = p0;
    return p0;
}
void FreeList(Node *&head)
{
    Node *p;
    while (head != NULL)
    {
        p = head;
        head = head->next;
        delete p;
    }
}
ostream &operator<<(ostream &out, const Node *head)
{
    for (; head != NULL; head = head->next)
        out << head->data << endl;
    return out;
}
Node *Locate(Node *head, int x, int &num, bool newsearch)
{
    static Node *p = NULL;
    static int data = 0;
    static int k = 0;
    Node *temp;
    if (p == NULL || newsearch)
    {
        p = head;
        data = x;
        k = 0;
    }
    for (; p != NULL && p->data != data; p = p->next, k++)
        ;
    temp = p;
    num = k;
    if (p != NULL)
    {
        p = p->next;
        k++;
    }
    return temp;
}
int Save(const char *filename, const Node *head)
{
    ofstream outfile(filename);
    if (outfile.fail())
        return 0;
    int n = 0;
#if (1)
    const Node *p;
    for (p = head; p != NULL; p = p->next, n++)
        outfile << p->data << endl;
#else
    outfile << head;
    n = NumNodes(head);
#endif
    outfile.close();
    return n;
}
int Load(const char *filename, Node *&head)
{
    int n;
    int x;
    ifstream infile(filename);
    if (infile.fail())
        return 0;
    for (n = 0; infile >> x; n++)
        Append(head, x);
    infile.close();
    return n;
}
int main()
{
    system("");
    Node *head = NULL;
    char filename[80] = "data_int.txt";
    int x;
    int n, key, yn;
    Init(head);
    while (true)
    {
        cout << "\n========== MENU ==========" << endl;
        cout << "  1 ---- 输 出 链 表 (P)" << endl;
        cout << "  2 ---- 插 入 结 点 (I)" << endl;
        cout << "  3 ---- 追 加 结 点 (A)" << endl;
        cout << "  4 ---- 查 询 结 点 (S)" << endl;
        cout << "  5 ---- 数据写入文件(W)" << endl;
        cout << "  6 ---- 读取数据文件(R)" << endl;
        cout << "  7 ---- 释放所有结点(F)" << endl;
        cout << "  0 ---- 退      出(ESC)" << endl;
        cout << "==========================" << endl;
        key = Choice("请选择", "01234567\x1bpPiIaAsSwWrRfF");
        cout << "\n\n";
        if (key == 27 || key == '0')
            break;
        switch (key)
        {
        case '1':
        case 'p':
        case 'P':
            cout << "第一种格式输出" << endl;
            ShowList(head);
            cout << "\n第二种格式输出" << endl;
            cout << head << endl;
            break;
        case '2':
        case 'i':
        case 'I':
            cout << "插入一个结点到链表首结点前。请输入数据域数据(int): ";
            cin >> x;
            Insert(head, x);
            break;
        case '3':
        case 'a':
        case 'A':
            cout << "追加一个结点(至尾结点后)。请输入数据域数据(int): ";
            cin >> x;
            Append(head, x);
            break;
        case '4':
        case 's':
        case 'S':
            cout << "根据数据域数据查询。请输入待查询的数据(int): ";
            cin >> x;
            Find(head, x);
            break;
        case '5':
        case 'w':
        case 'W':
            n = Save(filename, head);
            cout << "将 " << n << " 个结点的数据写入 "
                 << filename << " 文件。" << endl;
            break;
        case '6':
        case 'r':
        case 'R':
            cout << "读取数据文件。是否先释放已有的所有结点(y/[N])? ";
            yn = getche();
            if (yn == 'y' || yn == 'Y')
                FreeList(head);
            n = Load(filename, head);
            cout << "从 " << filename << " 文件中读取 "
                 << n << " 个数据。" << endl;
            break;
        case '7':
        case 'f':
        case 'F':
            cout << "释放所有结点。是否继续(y/[N])? ";
            yn = getche();
            if (yn == 'y' || yn == 'Y')
                FreeList(head);
            break;
        }
    }
    if (head != NULL)
    {
        cout << "\n即将退出程序，链表数据是否存盘([Y]/n)? ";
        yn = getche();
        if (yn != 'n' && yn != 'N')
        {
            filename[Pos('.', filename)] = '\0';
            strcat(filename, "(1).txt");
            n = Save(filename, head);
            cout << "\n已将 " << n << " 个结点的数据存入 " << filename << " 文件。" << endl;
        }
    }
    cout << "\n释放所有结点，返回操作系统。" << endl;
    FreeList(head);
    return 0;
}