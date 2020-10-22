#pragma warning(disable : 4996)
#include <cstring>
#include <iostream>
using namespace std;
class CString
{
private:
    char *cstring;
    int strlength;

public:
    CString();
    CString(const char *str);
    CString(string str);
    CString(const CString &str);
    ~CString();
    CString &operator=(const CString str);
    int length();
    char *c_str();
    friend ostream &operator<<(ostream &out, CString &str);
    friend istream &operator>>(istream &in, CString &str);
    CString &operator+(const CString &s);
    CString &operator+=(const CString &s);
    bool operator<(const CString &str) const;
    bool operator<=(const CString &str) const;
    bool operator>(const CString &str) const;
    bool operator>=(const CString &str) const;
    bool operator==(const CString &str) const;
    bool operator!=(const CString &str) const;
    char &operator[](int number);
};
CString::CString()
{
    strlength = 0;
    cstring = new char[strlength + 1];
    cstring[0] = '\0';
}
CString::CString(const char *str)
{
    strlength = strlen(str);
    cstring = new char[strlength + 1];
    strcpy(cstring, str);
}
CString::CString(string str)
{
    strlength = str.length();
    cstring = new char[strlength + 1];
    strcpy(cstring, str.c_str());
    cstring[strlength] = '\0';
}
CString::CString(const CString &str)
{
    strlength = str.strlength;
    cstring = new char[strlength + 1];
    strcpy(cstring, str.cstring);
}
CString::~CString()
{
    if (cstring != NULL)
    {
        delete[] cstring;
        cstring = NULL;
    }
}
CString &CString::operator=(const CString str)
{
    if (this == &str)
    {
        return *this;
    }
    if (cstring != NULL)
    {
        delete[] cstring;
        cstring = NULL;
    }
    strlength = str.strlength;
    cstring = new char[strlength + 1];
    strcpy(cstring, str.cstring);
    return *this;
}
int CString::length()
{
    strlength = strlen(cstring);
    return strlength;
}
char *CString::c_str()
{
    return cstring;
}
ostream &operator<<(ostream &out, CString &str)
{
    out << "The cstring is: ";
    for (int i = 0; i < str.length(); i++)
    {
        out << str.cstring[i];
    }
    out << endl
        << "The length of cstring is: " << str.strlength << endl;
    return out;
}
istream &operator>>(istream &in, CString &str)
{
    char temp[1000] = {'\0'};
    cin >> temp;
    str = CString(temp);
    return in;
}
CString &CString::operator+(const CString &str)
{
    char *temp = cstring;
    strlength = strlen(cstring) + strlen(str.cstring);
    cstring = new char[strlength + 1];
    strcpy(cstring, temp);
    strcat(cstring, str.cstring);
    delete[] temp;
    return *this;
}
CString &CString::operator+=(const CString &str)
{
    *this = *this + str;
    return *this;
}
bool CString::operator<(const CString &str) const
{
    if (strcmp(cstring, str.cstring) < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool CString::operator<=(const CString &str) const
{
    if (*this < str or *this == str)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool CString::operator>(const CString &str) const
{
    if (*this <= str)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
bool CString::operator>=(const CString &str) const
{
    if (*this < str)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
bool CString::operator==(const CString &str) const
{
    if (strlength == str.strlength)
    {
        for (int i = 0; i < strlength; i++)
        {
            if (cstring[i] != str.cstring[i])
            {
                return 0;
                break;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
bool CString::operator!=(const CString &str) const
{
    if (*this == str)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
char &CString::operator[](int number)
{
    if (number > strlength)
    {
        throw(int) number;
    }
    return cstring[number];
}
int main()
{
    CString test0 = ("ABCD");
    string temp = "1234567890";
    CString test1(temp);
    cout << "test0: " << endl
         << test0 << "test1: " << endl
         << test1 << "Please input test0: ";
    cin >> test0;
    cout << "test0: " << endl
         << test0
         << "Whether test0 < test1: " << boolalpha << (test0 < test1) << endl
         << "Whether test0 <= test1: " << boolalpha << (test0 <= test1) << endl
         << "Whether test0 > test1: " << boolalpha << (test0 > test1) << endl
         << "Whether test0 >= test1: " << boolalpha << (test0 >= test1) << endl
         << "Whether test0 == test1: " << boolalpha << (test0 == test1) << endl
         << "Whether test0 != test1: " << boolalpha << (test0 != test1) << endl;
    test1 = test1 + test0;
    cout << "Connect test0 after test1. " << endl
         << "test1: " << endl
         << test1;
    test1 += test0;
    cout << "Connect test0 after test1. " << endl
         << "test1: " << endl
         << test1;
    test1 = test0;
    cout << "Assign test0 to test1. " << endl
         << "test1: " << endl
         << test1 << "The content of test0 is: " << test0.c_str() << endl
         << "The third character of test0 is: ";
    try
    {
        cout << test0[3] << endl;
    }
    catch (int &index)
    {
        cout << "This index " << index << " dosen't exist. " << endl;
    }
    cout << "The twenty-fifth character of test0 is: ";
    try
    {
        cout << test0[25] << endl;
    }
    catch (int &index)
    {
        cout << "Index " << index << " dosen't exist. " << endl;
    }
    test0.~CString();
    test1.~CString();
    cout << "Deconstruct test0 and test1. " << endl;
    return 0;
}