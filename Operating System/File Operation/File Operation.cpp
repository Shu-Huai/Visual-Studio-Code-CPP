#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
string a[10] = {"carol", "Lily", "Lucy", "Bob", "A", "B", " C ", " D ", " E ", "F"};
string command[7] = {"CREATE", "DELETE", "OPEN", " CLOSE ", " READ ", " WRITE ", " BYE "};
struct UFD
{
    string filename;
    int pro[3];
    int codel;
    UFD *next;
};
struct MFD
{
    string username;
    UFD *file;
    MFD *next;
};
struct AFD
{
    int filenum;
    char filepro[3];
    UFD *point;
    AFD *next;
};
AFD *openfile = NULL;
MFD *user = NULL;
MFD *thisuser;
void init()
{
    int x = 0;
    for (int i = 0; i < 10; i++)
    {
        MFD *p;
        p = new MFD;
        p->username = a[x];
        UFD *fhead = NULL;
        for (int j = 0; j < 10; j++)
        {
            UFD *q;
            q = new UFD;
            q->filename = "******";
            for (int a = 0; a < 3; a++)
            {
                q->pro[a] = 0;
            }
            q->codel = 0;
            q->next = fhead;
            fhead = q;
            p->file = fhead;
            if (j == 9)
            {
                UFD *r = fhead;
                while (r->next != NULL)
                {
                    r = r->next;
                }
                r->next = fhead;
            }
        }
        p->next = user;
        user = p;
        x++;
    }
    for (int i = 0; i < 5; i++)
    {
        AFD *f;
        f = new AFD;
        f->filenum = 5 - i;
        for (int j = 0; j < 3; j++)
        {
            f->filepro[i] = 0;
        }
        f->point = NULL;
        f->next = openfile;
        openfile = f;
        if (i == 4)
        {
            AFD *p = openfile;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = openfile;
        }
    }
}
int checkUser(string username)
{
    MFD *p;
    for (p = user; p != NULL; p = p->next)
    {
        if (p->username == username)
        {
            break;
        }
    }
    if (p != NULL)
    {
        thisuser = p;
        return 1;
    }
    else
    {
        return 0;
    }
}
void show()
{
    cout << "YOUR FILE DIRECTORY" << endl;
    cout << setw(20) << setiosflags(ios::left) << setfill(' ') << "FILE NAME";
    cout << setw(20) << setiosflags(ios::left) << setfill(' ') << "PROTECTION";
    cout << setw(20) << setiosflags(ios::left) << setfill(' ') << "CODE LENGTH" << endl;
    MFD *p = thisuser;
    UFD *q = p->file;
    for (int i = 0; i < 10; i++)
    {
        cout << setw(20) << setiosflags(ios::left) << setfill(' ') << q->filename;
        cout << q->pro[0] << q->pro[1] << q->pro[2];
        cout << setw(20) << setiosflags(ios::left) << setfill(' ') << " ";
        cout << setw(20) << setiosflags(ios::left) << setfill(' ') << q->codel << endl;
        q = q->next;
    }
}
void OpenMode(UFD *p, string name)
{
    AFD *f = openfile;
    int i;
    for (i = 0; i < 5; i++)
    {
        if (f->point != NULL && f->point->filename == name)
        {
            cout << "THIS FILE IS ALREADY OPENED !" << endl;
            return;
        }
        f = f->next;
    }
    for (i = 0; i < 5; i++)
    {
        if (f->point == NULL)
        {
            break;
        }
        f = f->next;
    }
    if (i == 5)
    {
        cout << "ERROR!YOU CAN'T OPEN THIS FILE, NUMBER MUST <=5!";
    }
    else
    {
        cout << "ENTER THE OPEN MODE?";
        string protect;
        cin >> protect;
        int j;
        for (j = 0; j < 3; j++)
        {
            if (p->pro[j] != protect[j] - 48)
            {
                break;
            }
        }
        if (j != 3)
        {
            cout << "ERROR, OPEN MODE IS WRONG!" << endl;
            return;
        }
        else
        {
            cout << "THIS FILE IS OPENED,ITS OPEN NUMBER IS ";
            cout << f->filenum << endl;
            f->point = p;
            for (int j = 0; j < 3; j++)
            {
                f->filepro[j] = p->pro[j];
            }
        }
    }
    return;
}
void Create()
{

    cout << "THE NEW FILE S NAME(LESS THAN 9 CHARS)?                ";
    string name;
    cin >> name;
    cout << "THE NEW FILE'S PROTECTION CODE?                    ";
    string protect;
    cin >> protect;
    UFD *p = thisuser->file;
    UFD *q = p;
    int n;
    for (n = 0; n < 10; n++)
    {
        if (q->filename == "******")
        {
            break;
        }
        q = q->next;
    }
    if (n == 10)
    {
        cout << "CREAT FAILED!!THERE IS NO SPACE,FILE NUMBER MUST<=10!" << endl;
        return;
    }
    else
    {
        q->filename = name;
        for (int i = 0; i < 3; i++)
        {
            q->pro[i] = protect[i] - 48;
        }
    }
    cout << "THE NEW FILE IS CREATED." << endl;
    OpenMode(q, name);
    return;
}
void Open()
{
    cout << "FILE NAME TO BE OPENED?      ";
    string name;
    cin >> name;
    UFD *p = thisuser->file;
    UFD *q = p;
    int n;
    for (n = 0; n < 10; n++)
    {
        if (q->filename == name)
        {
            break;
        }
        q = q->next;
    }
    if (n == 10)
    {
        cout << "ERROR!THIS FILE IS NOT EXISTS!" << endl;
        return;
    }
    else
    {
        OpenMode(q, name);
    }
    return;
}
void Close1(AFD *f)
{
    f->point = NULL;
    for (int i = 0; i < 3; i++)
    {
        f->filepro[i] = 0;
    }
    cout << "SUCCESS!THIS FILE IS CLOSED!" << endl;
    return;
}
void Close()
{
    cout << "CLOSE THE FILE'S NAME:      ";
    string name;
    cin >> name;
    UFD *p = thisuser->file;
    UFD *q = p;
    int n;
    for (n = 0; n < 10; n++)
    {
        if (q->filename == name)
        {
            break;
        }
        q = q->next;
    }
    if (n == 10)
    {
        cout << "ERROR!CAN'T FIND THIS FILE!" << endl;
        return;
    }
    else
    {
        AFD *f = openfile;
        int i;
        for (i = 0; i < 5; i++)
        {
            if (f->point == q)
            {
                break;
            }
            f = f->next;
        }
        if (n == 5)
        {
            cout << "ERROR!THIS FILE IS NOT OPENED!" << endl;
            return;
        }
        else
        {
            Close1(f);
        }
    }
    return;
}
void Delete()
{
    cout << "DELETE FILENAME?              ";
    string name;
    cin >> name;
    UFD *p = thisuser->file;
    UFD *q = p;
    int n;
    for (n = 0; n < 10; n++)
    {
        if (q->filename == name)
        {
            break;
        }
        q = q->next;
    }
    if (n == 10)
    {
        cout << "ERROR!CAN'T FIND THIS FILE!" << endl;
        return;
    }
    else
    {
        AFD *f = openfile;
        int i;
        for (i = 0; i < 5; i++)
        {
            if (f->point == q)
            {
                cout << "ERROR!THIS FILE IS OPENED! CLOSED IT?(Y/N)" << endl;
                char y;
                cin >> y;
                if (y == 'Y')
                {
                    Close1(f);
                    break;
                }
                else
                {
                    return;
                }
            }
            f = f->next;
        }
        q->filename = "******";
        q->codel = 0;
        for (int x = 0; x < 3; x++)
        {
            q->pro[x] = 0;
        }
        cout << "SUCCESS!THIS FILE IS BE DELETED! " << endl;
    }
    return;
}
void Read()
{
    cout << "OPEN FILE NUMBER?        ";
    int num;
    cin >> num;
    AFD *f = openfile;
    int i;
    for (i = 0; i < 5; i++)
    {
        if (f->filenum == num && f->point != NULL)
        {
            break;
        }
        f = f->next;
    }
    if (i == 5)
    {
        cout << "ERROR!THIS FILE IS NOT OPENED!" << endl;
        return;
    }
    else
    {
        if (f->filepro[0] == 1)
        {
            cout << "SUCCESS!READING!" << endl;
        }
        else
        {
            cout << "ERROR!THIS FILE CAN'T READ WITH READING RIGHT LIMITED!" << endl;
        }
    }
    return;
}
void Write()
{
    cout << "OPEN FILE NUMBER?        ";
    int num;
    cin >> num;
    AFD *f = openfile;
    int i;
    for (i = 0; i < 5; i++)
    {
        if (f->filenum == num && f->point != NULL)
        {
            break;
        }
        f = f->next;
    }
    if (i == 5)
    {
        cout << "ERROR!THIS FILE IS NOT OPENED!" << endl;
        return;
    }
    else
    {
        if (f->filepro[1] == 1)
        {
            cout << "HOW MANY CHARACTERS TO BE WRITTEN INTO THAT FILE?          ";
            int code;
            cin >> code;
            f->point->codel = code;
        }
        else
        {
            cout << "ERROR!THIS FILE CAN'T WRITE WITH WRITING RIGHT LIMITED!" << endl;
        }
    }
    return;
}
void FileWork(int com)
{
    if (com == 1)
    {
        Create();
    }
    if (com == 2)
    {
        Delete();
    }
    if (com == 3)
    {
        Open();
    }
    if (com == 4)
    {
        Close();
    }
    if (com == 5)
    {
        Read();
    }
    if (com == 6)
    {
        Write();
    }
    if (com == 7)
    {
        cout << "NOW YOUR FILE DIRECTORY IS FOLLOWING:" << endl;
        show();
    }
    return;
}
int main()
{
    cout << "RUN" << endl;
    init();
    int x = 0;
    while (x == 0)
    {

        cout << "YOUR NAME?"
             << "      ";
        string username;
        cin >> username;
        x = checkUser(username);
        if (x == 0)
        {
            cout << "YOUR NAME IS NOT IN THE USER NAME TABLE,TRY AGAIN." << endl;
        }
    }
    show();
    int com = 0;
    while (com != 7)
    {
        cout << "COMMAND NAME?      ";
        string s;
        cin >> s;
        int i;
        for (i = 0; i < 7; i++)
        {

            if (s == command[i])
            {
                com = i + 1;
                break;
            }
        }
        if (i == 7)
        {
            cout << "COMMAND NAME GIVEN IS WRONG!" << endl;
            cout << "IT SHOULD BE ONE OF FOLLOWING : " << endl;
            cout << "CREATE, DELETE, OPEN, CLOSE, READ, WRITE, BYE    .TRY AGAIN" << endl;
            continue;
        }
        else
        {
            FileWork(com);
        }
    }
    return 0;
}