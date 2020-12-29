#pragma once
#ifndef __STRING_H__
#define __STRING_H__
#include "Assistance.h"
#include "LinkList.h"
class String
{
protected:
    char *s_;
    int length_;

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
String::String() : s_(NULL), length_(0)
{
}
String::~String()
{
    delete[] s_;
}
String::String(const String &S) : length_(S.length_)
{
    s_ = new char[length_ + 1];
    strcpy(s_, S.s_);
}
String::String(const char *c) : length_(strlen(c))
{
    s_ = new char[length_ + 1];
    strcpy(s_, c);
}
String::String(LinkList<char> &LL) : length_(LL.GetLength())
{
    s_ = new char[length_ + 1];
    for (int i = 0; i < length_; i++)
    {
        LL.GetElem(i + 1, s_[i]);
    }
    s_[length_] = '\0';
}
int String::GetLength() const
{
    return length_;
}
bool String::IsEmpty() const
{
    return length_ == 0;
}
String &String::operator=(const String &S)
{
    if (&S != this)
    {
        delete[] s_;
        length_ = S.length_;
        s_ = new char[length_ + 1];
        strcpy(s_, S.s_);
    }
    return *this;
}
const char *String::CStr() const
{
    return (const char *)s_;
}
char &String::operator[](int i) const
{
    return s_[i];
}
#endif