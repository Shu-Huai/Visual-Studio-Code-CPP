#pragma once
#ifndef __STRING_H__
#define __STRING_H__
#include "Assistance.h"
#include "LinkList.h"
class String
{
protected:
    char *_s;
    int _length;

public:
    String();
    virtual ~String();
    String(const String &S);
    String(const char *c);
    String(LinkList<char> &LL);
    int GetLength() const;
    bool IsEmpty() const;
    String &operator=(const String &S);
    const char *CStr() const;
    char &operator[](int i) const;
};
String::String() : _s(NULL), _length(0)
{
}
String::~String()
{
    delete[] _s;
}
String::String(const String &S) : _length(S._length)
{
    _s = new char[_length + 1];
    strcpy(_s, S._s);
}
String::String(const char *c) : _length(strlen(c))
{
    _s = new char[_length + 1];
    strcpy(_s, c);
}
String::String(LinkList<char> &LL) : _length(LL.GetLength())
{
    _s = new char[_length + 1];
    for (int i = 0; i < _length; i++)
    {
        LL.GetElem(i + 1, _s[i]);
    }
    _s[_length] = '\0';
}
int String::GetLength() const
{
    return _length;
}
bool String::IsEmpty() const
{
    return _length == 0;
}
String &String::operator=(const String &S)
{
    if (&S != this)
    {
        delete[] _s;
        _length = S._length;
        _s = new char[_length + 1];
        strcpy(_s, S._s);
    }
    return *this;
}
const char *String::CStr() const
{
    return (const char *)_s;
}
char &String::operator[](int i) const
{
    return _s[i];
}
#endif