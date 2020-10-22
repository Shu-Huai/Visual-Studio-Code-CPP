#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;

struct Room //房间信息
{
    string name;       //房间编号
    string type;       //房间类型
    int price;         //房间单价
    bool b;            //房屋入住状态
    Room *next, *fron; //后一节点地址，前一节点地址
};
struct Customer //客人信息
{
    string id;             //客人身份证信息
    string name;           //客人姓名
    int indate, outdate;   //入住日期，退房日期
    string roomnum;        //入住房间编号
    int cost;              //客人总花费
    Customer *next, *fron; //后一节点地址，前一节点地址
};

bool mmp1 = 0, mmp2 = 0;
Room *hroom = new Room[sizeof(Room)], *troom = new Room[sizeof(Room)];                                    //头节点与尾节点
Customer *hcustomer = new Customer[sizeof(Customer)], *tcustomer = new Customer[sizeof(Customer)], *pass; //头节点与尾节点
string fff;

void save()
{
    ofstream fileout1("客人信息.txt", ios::trunc);
    Room *q;
    Customer *p;
    p = hcustomer;
    q = hroom;

    while (p->next != NULL)
    {
        if (p->id == "" or p->name == "" or p->indate == 0 or p->outdate == 0)
            goto k;
        fileout1 << p->id << " ";
        fileout1 << p->name << " ";
        fileout1 << p->indate << " ";
        fileout1 << p->outdate << " " << p->roomnum << " " << p->cost << endl;
    k:
        p = p->next;
    }
    fileout1.close();
    ofstream fileout2("客房信息.txt", ios::trunc);
    while (q->next != NULL)
    {
        if (q->name.length() == 0 or q->type.length() == 0 or q->price == 0)
            goto kk;
        fileout2 << q->name << " " << q->type << " " << q->price << " " << q->b << endl;
    kk:
        q = q->next;
    }
    fileout2.close();
}
void read() //读取文件
{
    ifstream filein("客人信息.txt");
    Customer *p, *temp;
    hcustomer->next = tcustomer;
    tcustomer->fron = hcustomer;

    while (!filein.eof())
    {
        filein >> tcustomer->id >> tcustomer->name >> tcustomer->indate >> tcustomer->outdate >> tcustomer->roomnum >> tcustomer->cost;
        p = new Customer[sizeof(Customer)];
        tcustomer->next = p;
        p->fron = tcustomer;
        tcustomer = p;
    }
    filein.close();
    Room *q;
    hroom->next = troom;
    troom->fron = hroom;
    ifstream filein2("客房信息.txt");
    int fuck = 0;
    while (!filein2.eof())
    {
        filein2 >> troom->name >> troom->type >> troom->price >> troom->b;
        q = new Room[sizeof(Room)];
        troom->next = q;
        q->fron = troom;
        troom = q;
        fuck++;
        if (fuck == 2)
            mmp1 = 1;
    }
    filein2.close();
}

//计算入住天数
bool isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
int getDays(int year, int month, int day)
{
    int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year))
        m[2]++;
    int result = 0;
    for (int i = 1; i < year; i++)
    {
        result += 365;
        if (isLeapYear(i))
            result++;
    }
    for (int i = 1; i < month; i++)
    {
        result += m[i];
    }
    result += day;

    return result;
}
int dayDis(int year1, int month1, int day1,
           int year2, int month2, int day2)
{
    return abs(getDays(year2, month2, day2) - getDays(year1, month1, day1));
}

//第三层菜单
void searchroom2() //找客房第四层菜单
{
    Room *p;
    cout << "请输入需查找的房间上下价格区间(下限 上限)：";
    int a1, a2;
    cin >> a1 >> a2;
    p = hroom;
    while (p->next != NULL)
    {
        if (p->price >= a1 and p->price <= a2)
        {
            cout << endl;
            cout << "房间编号" << p->name << "    "
                 << "房间类型" << p->type << "    "
                 << "房间单价" << p->price << "    ";
            if (p->b == 0)
                cout << "该房间无人" << endl;
            else
                cout << "该房间已有客人入住" << endl;
        }
        p = p->next;
    }
    system("pause");
}
void searchall() //查询所有客人信息
{
    Customer *p;
    p = hcustomer;
    int fffu = 0;
    cout << "\n\n                客房管理系统             \n\n";
    cout << "      ----------------------------------   \n\n";
    while (p->next != NULL)
    {
        if (p->id == "")
            goto u;
        cout << "客人姓名" << p->name << "    "
             << "客人身份证号" << p->id << "   "
             << "客人入住时间" << p->indate << "   "
             << "客人退房时间" << p->outdate << "  "
             << "客人入住房号" << p->roomnum << "  "
             << "客人消费金额" << p->cost << endl
             << endl;
        fffu = 1;
    u:
        p = p->next;
    }
    if (fffu == 0)
        cout << "               暂无客人信息" << endl
             << endl;
    system("pause");
}
void changecustomer() //改客人
{
    cout << "\n\n                客房管理系统             \n\n";
    cout << "      ----------------------------------   \n\n";
    Customer *p;
    p = hcustomer;
    int yy3, mm3, dd3;
    while (p->next != NULL)
    {
        if (pass->id == p->id)
        {
            yy3 = p->outdate / 10000;
            mm3 = p->outdate / 100 % 100;
            dd3 = p->outdate % 100;
            string kkk = p->roomnum;
            cout << "  请输入需修改的客人的姓名：";
            cin >> p->name;
            cout << "  请输入需修改该客人入住日期：";
            cin >> p->indate;
            cout << "  请输入需修改该客人退房日期：";
            cin >> p->outdate;
            cout << "  是否需要更换房间（Y/N）：";
            char temp;
            cin >> temp;
            if (temp == 'Y' or temp == 'y')
            {
                int yy1, mm1, dd1, yy2, mm2, dd2;
                yy1 = p->indate / 10000;
                yy2 = p->outdate / 10000;
                mm1 = p->indate / 100 % 100;
                mm2 = p->outdate / 100 % 100;
                dd1 = p->indate % 100;
                dd2 = p->outdate % 100;

                Room *q = new Room;
                system("cls");
                q = hroom;
                cout << "\n\n                客房管理系统             \n\n";
                cout << "      ----------------------------------   \n\n";
                while (q->next != NULL) //选择房间
                {
                    if (q->b != 1 and q != hroom and q->price != 0)
                    {
                        cout << endl;
                        cout << "房间编号:" << q->name << "  ";
                        cout << "房间类型:" << q->type << "  ";
                        cout << "房间单价:" << q->price << "  ";
                    }
                    q = q->next;
                }
                cout << endl;
            fuckoff:
                cout << "  请选择房间（输入房间号）：" << endl;
                string s;
                int ffff = 0;
                cin >> s;
                q = hroom;
                while (q->next != NULL) //更新房间与客人信息
                {
                    if (s == q->name)
                    {
                        ffff = 1;
                        q->b = 1;
                        p->roomnum = s;
                        p->cost = q->price * dayDis(yy1, mm1, dd1, yy2, mm2, dd2);
                        goto o;
                    }
                    q = q->next;
                }
                system("cls");
                if (ffff == 1)
                {
                    cout << "\n\n                客房管理系统             \n\n";
                    cout << "      ----------------------------------   \n\n";
                    cout << "                 已更新客房与客人信息\n";
                    system("pause");
                    system("cls");
                    p = new Customer[sizeof(Customer)];
                    tcustomer->next = p;
                    p->fron = tcustomer;
                    tcustomer = p;
                }
                else
                {
                    cout << "\n\n                客房管理系统             \n\n";
                    cout << "      ----------------------------------   \n\n";
                    cout << "                 房间编号输入错误，请重新输入\n";
                    q = hroom;
                    while (q->next != NULL) //选择房间
                    {
                        if (q->b != 1 and q != hroom and q->price != 0)
                        {
                            cout << endl;
                            cout << "房间编号:" << q->name << "  ";
                            cout << "房间类型:" << q->type << "  ";
                            cout << "房间单价:" << q->price << "  ";
                        }
                        q = q->next;
                    }
                    cout << endl;
                    goto fuckoff;
                }
            o:
                system("cls");
                cout << "\n\n                客房管理系统             \n\n";
                cout << "      ----------------------------------   \n\n";
                cout << "                 已更新客房与客人信息\n";
                system("pause");
                system("cls");
                q = hroom;
                while (q->next != NULL) //清空房间
                {
                    if (q->name == kkk)
                    {
                        q->b = 0;
                    }
                    q = q->next;
                }
                return;
            }
            cout << "\n\n                客房管理系统             \n\n";
            cout << "      ----------------------------------   \n\n";
            cout << "                 已更新客房与客人信息\n";
            system("pause");
            Room *er = hroom;
            while (er->next != NULL) //清空房间
            {
                if (er->name == kkk)
                {
                    er->b = 0;
                }
                er = er->next;
            }
            return;
        }
        p = p->next;
    }
    cout << "                 无该客人信息\n";
    system("pause");
}
void changecustomer1() //找客人一层
{
    cout << "\n\n                客房管理系统             \n\n";
    cout << "      ----------------------------------   \n\n";
    cout << "  请输入需修改的客人的身份信息（身份证号）：";
    cin >> pass->id;
    changecustomer();
    system("cls");
}
void searchcustomer() //找客人二层
{
    Customer *p;
    cout << "请输入需查找的客人姓名或身份证：";
    string temp;
    cin >> temp;
    int m = 0;
    p = hcustomer;
    while (p->next != NULL)
    {
        if (temp == p->name or temp == p->id)
        {
            cout << endl;
            cout << "客人姓名" << p->name << endl
                 << endl;
            cout << "客人身份证号" << p->id << endl
                 << endl;
            cout << "客人入住时间" << p->indate << endl
                 << endl;
            cout << "客人退房时间" << p->outdate << endl
                 << endl;
            cout << "客人入住房号" << p->roomnum << endl
                 << endl;
            cout << "客人消费金额" << p->cost << endl
                 << endl;
            m = 1;
        }
        p = p->next;
    }
    if (m == 0)
    {
        cout << "\n\n                客房管理系统             \n\n";
        cout << "      ----------------------------------   \n\n";
        cout << "		 查无此人" << endl;
    }
    system("pause");
    system("cls");
}
void searchroom1() //找房间
{
    Room *p;
    cout << "请输入需查找的房间类型：";
    string temp;
    cin >> temp;
    p = hroom;
    int fffu = 0;
    while (p->next != NULL)
    {
        if (temp == p->type)
        {
            cout << endl;
            cout << "房间编号" << p->name << "    "
                 << "房间类型" << p->type << "    "
                 << "房间单价" << p->price << "    ";
            if (p->b == 0)
                cout << "该房间无人" << endl;
            else
                cout << "该房间已有客人入住" << endl;
            fffu = 1;
        }
        p = p->next;
    }
    if (fffu == 1)
        goto l;
    system("cls");
    cout << "\n\n                客房管理系统             \n\n";
    cout << "      ----------------------------------   \n\n";
    cout << "		 查无此类房间房" << endl;
l:
    system("pause");
    system("cls");
    system("cls");
}
void insertroom() //增加房间
{
    Room *p;
    cout << "\n\n                客房管理系统             \n\n";
    cout << "      ----------------------------------   \n\n";
    cout << "请输入需录入的房间编号：";
    cin >> troom->name;
    p = hroom;
    while (p->next != NULL)
    {
        if (troom->name == p->name)
        {
            system("cls");
            cout << "\n\n                客房管理系统             \n\n";
            cout << "      ----------------------------------   \n\n";
            cout << "                    该房间已存在";
            system("pause");
            goto a;
        }
        p = p->next;
    }
    cout << "请输入需入住的房间类型：";
    cin >> troom->type;
    cout << "请输入该房间单价（单位RMB）（请务必输入数字）：";
    cin >> troom->price;
    p = new Room[sizeof(Room)];
    if (mmp1 == 0)
    {
        hroom->next = troom;
        troom->fron = hroom;
        mmp1 = 1;
    }
    troom->b = 0;
    troom->next = p;
    p->fron = troom;
    troom = p;
    system("pause");
    system("cls");
    cout << "\n\n                客房管理系统             \n\n";
    cout << "      ----------------------------------   \n\n";
    cout << "                    录入成功";
    system("pause");
    system("cls");
a:
    system("cls");
    cout << "\n\n                客房管理系统             \n\n";
    cout << "      ----------------------------------   \n\n";
    cout << "是否需要继续录入房间？（Y/N）";
    char temp;
    cin >> temp;
    system("cls");
    if (temp == 'Y' or temp == 'y')
        insertroom();
    system("cls");
}
void insertcustomer() //增加客人
{
    cout << "\n\n                客房管理系统             \n\n";
    cout << "      ----------------------------------   \n\n";
    cout << "  请输入需入住的客人的身份信息（身份证号）：";
    cin >> tcustomer->id;
    Customer *p;
    p = hcustomer;
    while (p->next != NULL) //查重
    {
        if (p->id == tcustomer->id)
        {
            system("cls");
            cout << "\n\n                客房管理系统             \n\n";
            cout << "      ----------------------------------   \n\n";
            cout << "               该客人已存在，如需修改请输入Y,回到主菜单请输入任意字母：";
            char y;
            cin >> y;
            pass = tcustomer;
            if (y == 'Y' or y == 'y')
                changecustomer();
            else
            {
                pass = NULL;
                return;
            }
        }
        p = p->next;
    }
    cout << "  请输入需入住的客人的姓名：";
    cin >> tcustomer->name;
    cout << "  请输入需入住该客人入住日期：";
    cin >> tcustomer->indate;
    cout << "  请输入需入住该客人退房日期：";
    cin >> tcustomer->outdate;
    int yy1, mm1, dd1, yy2, mm2, dd2;
    yy1 = tcustomer->indate / 10000;
    yy2 = tcustomer->outdate / 10000;
    mm1 = tcustomer->indate / 100 % 100;
    mm2 = tcustomer->outdate / 100 % 100;
    dd1 = tcustomer->indate % 100;
    dd2 = tcustomer->outdate % 100;
    int i = 0, ffff = 0;
    Room *q = new Room;
    q = hroom;
    system("cls");
    cout << "\n\n                客房管理系统             \n\n";
    cout << "      ----------------------------------   \n\n";
    if (q->next == NULL)
    {
        cout << "   请先录入客房信息";
        system("pause");
        return;
    }
    while (q->next != NULL) //选择房间
    {
        if (q->b != 1 and q != hroom and q->price != 0)
        {
            cout << endl;
            cout << "房间编号:" << q->name << "  ";
            cout << "房间类型:" << q->type << "  ";
            cout << "房间单价:" << q->price << "  ";
            i = 1;
        }
        q = q->next;
    }
    if (q->next == NULL and i == 0)
    {
        cout << "   暂无空房间";
        system("pause");
        return;
    }
    cout << endl;
fuckoff:
    cout << "  请选择房间（输入房间号）：" << endl;
    string s;
    cin >> s;
    q = hroom;
    while (q->next != NULL) //更新房间与客人信息
    {
        if (s == q->name)
        {
            ffff = 1;
            q->b = 1;
            tcustomer->roomnum = s;
            tcustomer->cost = q->price * dayDis(yy1, mm1, dd1, yy2, mm2, dd2);
            goto o;
        }
        q = q->next;
    }
o:
    system("cls");
    if (ffff == 1)
    {
        cout << "\n\n                客房管理系统             \n\n";
        cout << "      ----------------------------------   \n\n";
        cout << "                 已更新客房与客人信息\n";
        system("pause");
        system("cls");
        p = new Customer[sizeof(Customer)];
        tcustomer->next = p;
        p->fron = tcustomer;
        tcustomer = p;
    }
    else
    {
        cout << "\n\n                客房管理系统             \n\n";
        cout << "      ----------------------------------   \n\n";
        cout << "                 房间编号输入错误，请重新输入\n";
        q = hroom;
        while (q->next != NULL) //选择房间
        {
            if (q->b != 1 and q != hroom and q->price != 0)
            {
                cout << endl;
                cout << "房间编号:" << q->name << "  ";
                cout << "房间类型:" << q->type << "  ";
                cout << "房间单价:" << q->price << "  ";
                i = 1;
            }
            q = q->next;
        }
        cout << endl;
        goto fuckoff;
    }
}

void deletecustomer() //删除客人
{
    cout << "\n\n                客房管理系统             \n\n";
    cout << "      ----------------------------------   \n\n";
    cout << "  请输入退房客人身份证号或姓名：";
    Customer *p;
    Room *q;
    string temp;
    cin >> temp;
    p = hcustomer;
    int sum, dd = 0;
    while (p->next != NULL)
    {
        if (temp == p->name or temp == p->id)
        {
            q = hroom;
            while (q->next != NULL)
            {
                if (q->name == p->roomnum)
                {
                    q->b = 0;
                    goto ppp;
                }
                q = q->next;
            }
        ppp:
            Customer *t1, *t2;
            t1 = p;
            t2 = p->next;
            sum = p->cost;
            p = p->fron;
            delete t1;
            dd = 1;
            p->next = t2;
            break;
        }
        p = p->next;
        dd = 0;
    }
    system("cls");
    if (dd == 1)
    {
        cout << "\n\n                客房管理系统             \n\n";
        cout << "      ----------------------------------   \n\n";
        cout << "      客人退房成功，需支付: " << sum << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "\n\n                客房管理系统             \n\n";
        cout << "      ----------------------------------   \n\n";
        cout << "      该客人不存在 " << endl;
        system("pause");
    }
}
void changeroom() //改客房
{
    cout << "\n\n                客房管理系统             \n\n";
    cout << "      ----------------------------------   \n\n";
    cout << "  请输入需修改的客房的房号：";
    string n;
    cin >> n;
    Room *p;
    p = hroom;
    while (p->next != NULL)
    {
        if (n == p->name)
        {
            cout << endl;
            if (p->b == 0)
            {
                cout << "  请输入需修改的客房的类型：";
                cin >> p->type;
                cout << "  请输入需修改的客房的单价：";
                cin >> p->price;
            }
            else
                cout << "该房间已有客人入住,请等客人退房后修改客房信息" << endl;
            goto l;
        }
        p = p->next;
    }
    system("cls");
    cout << "\n\n                客房管理系统             \n\n";
    cout << "      ----------------------------------   \n\n";
    cout << "		 查无此房" << endl;
l:
    system("pause");
    system("cls");
}

//第二层菜单
void insertdepend() //增加信息（判断）
{
    cout << "\n\n                客房管理系统             \n\n";
    cout << "      ----------------------------------   \n\n";
    cout << "               1.录入客房信息                 \n\n";
    cout << "               2.录入客人信息                 \n\n";
    cout << "               3.返回上层菜单                 \n\n";
    cout << "  请选择：";
    char n;
    cin >> n;
    string s;
    getline(cin, s);
    system("cls");
    if (s.length() == 0)
    {
        switch (n)
        {
        case '1':
            insertroom();
            break;
        case '2':
            insertcustomer();
            break;
        case '3':;
        }
    }
    else
    {
        cout << "\n\n                客房管理系统             \n\n";
        cout << "      ----------------------------------   \n\n";
        cout << "非法字符" << endl;
        system("pause");
        system("cls");
    }
}
void searchdepend() //查找信息（判断）
{
    cout << "\n\n                客房管理系统             \n\n";
    cout << "      ----------------------------------   \n\n";
    cout << "               1.按类型查询客房信息                 \n\n";
    cout << "               2.按价格查询客房信息                 \n\n";
    cout << "               3.查询客人信息                 \n\n";
    cout << "               4.查询所有客人信息                 \n\n";
    cout << "               5.返回上层菜单                 \n\n";
    cout << "  请选择：";
    char n;
    cin >> n;
    string s;
    getline(cin, s);
    system("cls");
    if (s.length() == 0)
    {
        switch (n)
        {
        case '1':
            searchroom1();
            break;
        case '2':
            searchroom2();
            break;
        case '3':
            searchcustomer();
            break;
        case '4':
            searchall();
            break;
        case '5':;
        }
    }
    else
    {
        cout << "\n\n                客房管理系统             \n\n";
        cout << "      ----------------------------------   \n\n";
        cout << "非法字符" << endl;
        system("pause");
        system("cls");
    }
}
void changedepend() //更改信息（判断）
{
    cout << "\n\n                客房管理系统             \n\n";
    cout << "      ----------------------------------   \n\n";
    cout << "               1.修改客房信息                 \n\n";
    cout << "               2.修改客人信息                 \n\n";
    cout << "               3.返回上层菜单                 \n\n";
    cout << "  请选择：";
    char n;
    cin >> n;
    string s;
    getline(cin, s);
    system("cls");
    if (s.length() == 0)
    {
        switch (n)
        {
        case '1':
            changeroom();
            break;
        case '2':
            changecustomer1();
            break;
        case '3':;
        }
    }
    else
    {
        cout << "\n\n                客房管理系统             \n\n";
        cout << "      ----------------------------------   \n\n";
        cout << "非法字符" << endl;
        system("pause");
        system("cls");
    }
}

int main()
{
    system("color F0");
    //文件初始化判断
    ifstream filein("客人信息.txt");
    if (!filein.is_open())
    {
        ofstream fileout("客人信息.txt", ios::trunc);
        fileout.close();
    }
    ifstream filein2("客房信息.txt");
    if (!filein2.is_open())
    {
        ofstream fileout2("客房信息.txt", ios::trunc);
        fileout2.close();
    }
    //读取文件
    read();
    //主菜单
    while (1)
    {
        pass = new Customer[sizeof(Customer)];
        system("cls");
        cout << "\n\n                客房管理系统             \n\n";
        cout << "      ----------------------------------   \n\n";
        cout << "               1.录入                 \n\n";
        cout << "               2.查询           \n\n";
        cout << "               3.退房           \n\n";
        cout << "               4.修改           \n\n";
        cout << "               5.退出系统           \n\n";
        cout << "  请选择：";
        char n;
        cin >> n;
        string s;
        getline(cin, s);
        system("cls");
        if (s.length() == 0)
        {
            switch (n)
            {
            case '1':
                insertdepend();
                break;
            case '2':
                searchdepend();
                break;
            case '3':
                deletecustomer();
                break; //在第三层菜单中
            case '4':
                changedepend();
                break;
            case '5':
                save();
                exit(0);
            default:
                break;
            }
        }
        else
        {
            cout << "\n\n                客房管理系统             \n\n";
            cout << "      ----------------------------------   \n\n";
            cout << "非法字符" << endl;
            system("pause");
            system("cls");
        }
    }
    return 0;
}