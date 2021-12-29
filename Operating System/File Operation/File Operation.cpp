#include "Active File Directory.h"
#include "Master File Directory.h"
#include <iomanip>
#include <iostream>
string a[10] = {"carol", "Lily", "Lucy", "Bob", "A", "B", " C ", " D ", " E ", "F"};
string command[7] = {"CREATE", "DELETE", "OPEN", " CLOSE ", " READ ", " WRITE ", " BYE "};
ActiveFileDirectory *openFile;
MasterFileDirectory *user = nullptr;
MasterFileDirectory *thisuser;
int userNumber;
int fileNumber;
int openNumber;
void Initialize()
{
    userNumber = 10;
    fileNumber = 10;
    openNumber = 5;
    for (int i = 0; i < userNumber; i++)
    {
        MasterFileDirectory *p = new MasterFileDirectory;
        p->m_userName = a[i];
        UserFileDirectory *head = nullptr;
        for (int j = 0; j < fileNumber; j++)
        {
            UserFileDirectory *q = new UserFileDirectory("", ProtectCode(), 0, head);
            head = q;
            p->m_file = head;
        }
        p->m_next = user;
        user = p;
    }
    for (int i = 0; i < 5; i++)
    {
        ActiveFileDirectory *f = new ActiveFileDirectory(5 - i, ProtectCode(), nullptr, openFile);
        openFile = f;
    }
}
bool CheckUser(string userName)
{
    MasterFileDirectory *p = user;
    for (p = user; p; p = p->m_next)
    {
        if (p->m_userName == userName)
        {
            thisuser = p;
            return true;
        }
    }
    return false;
}
void Show()
{
    cout << "YOUR FILE DIRECTORY" << endl;
    cout << setw(20) << setiosflags(ios::left) << setfill(' ') << "FILE NAME";
    cout << setw(20) << setiosflags(ios::left) << setfill(' ') << "PROTECTION";
    cout << setw(20) << setiosflags(ios::left) << setfill(' ') << "CODE LENGTH" << endl;
    MasterFileDirectory *p = thisuser;
    UserFileDirectory *q = p->m_file;
    for (q = p->m_file; q; q = q->m_next)
    {
        cout << setw(20) << setiosflags(ios::left) << setfill(' ') << q->m_name;
        cout << q->m_proCode.m_write << q->m_proCode.m_read << q->m_proCode.m_execute;
        cout << setw(20) << setiosflags(ios::left) << setfill(' ') << " ";
        cout << setw(20) << setiosflags(ios::left) << setfill(' ') << q->m_length << endl;
    }
}
void OpenMode(UserFileDirectory *p, string name)
{
    ActiveFileDirectory *f = openFile;
    for (int i = 0; i < openNumber; i++)
    {
        if (f->m_point && f->m_point->m_name == name)
        {
            cout << "文件已经打开。" << endl;
            return;
        }
    }
    for (int i = 0; i < openNumber; i++)
    {
        if (!f->m_point)
        {
            cout << "输入文件保护码：";
            string proCode;
            cin >> proCode;
            if (p->m_proCode.Check(proCode))
            {
                cout << "文件已打开，文件编号为" << f->m_fileIndex << "。" << endl;
                f->m_point = p;
                f->m_proCode = p->m_proCode;
            }
            else
            {
                cout << "保护码错误。" << endl;
            }
            return;
        }
    }
    cout << "打开的文件数量已达上限。" << endl;
}
void Create()
{
    cout << "请输入文件名：";
    string fileName;
    cin >> fileName;
    cout << "请输入保护码：";
    string proCode;
    cin >> proCode;
    UserFileDirectory *p = thisuser->m_file;
    UserFileDirectory *q = p;
    for (int i = 0; i < fileNumber; i++)
    {
        if (p[i].m_name == "")
        {
            q->m_name = fileName;
            q->m_proCode = proCode;
            cout << "创建成功。" << endl;
            OpenMode(q, fileName);
            return;
        }
    }
    cout << "文件数量达到上限，创建失败。" << endl;
}
void Open()
{
    cout << "请输入文件名：";
    string fileName;
    cin >> fileName;
    UserFileDirectory *p = thisuser->m_file;
    UserFileDirectory *q = p;
    for (int i = 0; i < fileNumber; i++)
    {
        if (q->m_name == fileName)
        {
            OpenMode(q, fileName);
            break;
        }
        q = q->m_next;
    }
    cout << "文件不存在。" << endl;
}
void Close(ActiveFileDirectory *f)
{
    f->m_point = NULL;
    f->m_proCode = "000";
    cout << "SUCCESS!THIS FILE IS CLOSED!" << endl;
    return;
}
void Close()
{
    cout << "请输入文件名：";
    string fileName;
    cin >> fileName;
    UserFileDirectory *p = thisuser->m_file;
    UserFileDirectory *q = p;
    for (int i = 0; i < fileNumber; i++)
    {
        if (q->m_name == fileName)
        {
            ActiveFileDirectory *f = openFile;
            int i;
            for (i = 0; i < openNumber; i++)
            {
                if (f->m_point == q)
                {
                    Close(f);
                    return;
                }
                f = f->m_next;
            }
            cout << "文件未打开。" << endl;
            return;
        }
        q = q->m_next;
    }
    cout << "文件不存在。" << endl;
}
void Delete()
{
    cout << "请输入文件名：";
    string fileName;
    cin >> fileName;
    UserFileDirectory *p = thisuser->m_file;
    UserFileDirectory *q = p;
    int n;
    for (n = 0; n < 10; n++)
    {
        if (q->m_name == fileName)
        {
            break;
        }
        q = q->m_next;
    }
    if (n == 10)
    {
        cout << "文件不存在。" << endl;
        return;
    }
    else
    {
        ActiveFileDirectory *f = openFile;
        int i;
        for (i = 0; i < 5; i++)
        {
            if (f->m_point == q)
            {
                cout << "文件已打开，将关闭。" << endl;
                Close(f);
            }
            f = f->m_next;
        }
        q->m_name = "";
        q->m_length = 0;
        q->m_proCode = "000";
        cout << "文件已删除。" << endl;
    }
    return;
}
void Read()
{
    cout << "请输入打开的文件编号：";
    int num;
    cin >> num;
    ActiveFileDirectory *f = openFile;
    int i;
    for (i = 0; i < 5; i++)
    {
        if (f->m_fileIndex == num && f->m_point != NULL)
        {
            break;
        }
        f = f->m_next;
    }
    if (i == 5)
    {
        cout << "文件未打开。" << endl;
        return;
    }
    else
    {
        if (f->m_proCode.m_read)
        {
            cout << "已读取文件。" << endl;
        }
        else
        {
            cout << "没有读取权限。" << endl;
        }
    }
    return;
}
void Write()
{
    cout << "请输入打开的文件编号：";
    int num;
    cin >> num;
    ActiveFileDirectory *f = openFile;
    int i;
    for (i = 0; i < 5; i++)
    {
        if (f->m_fileIndex == num && f->m_point != NULL)
        {
            break;
        }
        f = f->m_next;
    }
    if (i == 5)
    {
        cout << "ERROR!THIS FILE IS NOT OPENED!" << endl;
        return;
    }
    else
    {
        if (f->m_proCode.m_write == 1)
        {
            cout << "HOW MANY CHARACTERS TO BE WRITTEN INTO THAT FILE?          ";
            int code;
            cin >> code;
            f->m_point->m_length = code;
        }
        else
        {
            cout << "ERROR!THIS FILE CAN'T WRITE WITH WRITING RIGHT LIMITED!" << endl;
        }
    }
    return;
}
void Exit()
{
    cout << "已退出。" << endl;
}
int FileWork(string instruction)
{
    if (instruction == "创建")
    {
        Create();
        return 0;
    }
    else if (instruction == "删除")
    {
        Delete();
        return 1;
    }
    else if (instruction == "打开")
    {
        Open();
        return 2;
    }
    else if (instruction == "关闭")
    {
        Close();
        return 3;
    }
    else if (instruction == "读取")
    {
        Read();
        return 4;
    }
    else if (instruction == "写入")
    {
        Write();
        return 5;
    }
    else if (instruction == "退出")
    {
        Exit();
        return 6;
    }
    else
    {
        return -1;
    }
}
int main()
{
    cout << "RUN" << endl;
    Initialize();
    bool authorized = false;
    while (!authorized)
    {
        cout << "请输入用户名：";
        string userName;
        cin >> userName;
        authorized = CheckUser(userName);
        if (!authorized)
        {
            cout << "用户名验证失败，请重新输入。" << endl;
        }
    }
    Show();
    int result = 0;
    while (result != 6)
    {
        cout << "请输入文件指令：";
        string s;
        cin >> s;
        result = FileWork(s);
        if (result == -1)
        {
            cout << "指令错误，请重新输入（创建、删除、打开、关闭、读取、写入、退出）。" << endl;
        }
    }
    return 0;
}