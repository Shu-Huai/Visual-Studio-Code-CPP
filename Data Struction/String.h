#pragma once
#ifndef __STRING_H__
#define __STRING_H__
#include <cstring>
#include <iostream>
using namespace std;
class String
{
protected:
    char *characters_;
    int length_;
    int *GetFailure(const String &string);

public:
    String();
    String(const char *characters);
    String(const string &string);
    String(const String &string);
    virtual ~String();
    bool IsEmpty() const;
    void Display() const;
    void Traverse() const;
    void InsertString(const String &string, int index);
    void DeleteString(int index, int length);
    int GetLength() const;
    int GetIndex(const char character) const;
    char GetChar(int index) const;
    String GetSubString(int index, int length) const;
    const char *GetCharacters() const;
    void Copy(const String &string);
    void Copy(const String &string, int length);
    int Compare(const String &string) const;
    int BruteForcePatternMatching(const String &string);
    int KMPPatternMatching(const String &string);
    String &operator=(const String &string);
    char &operator[](int index) const;
    String operator+(const String &string) const;
    void operator+=(const String &string);
    bool operator==(const String &string) const;
    bool operator!=(const String &string) const;
    bool operator>(const String &string) const;
    bool operator>=(const String &string) const;
    bool operator<(const String &string) const;
    bool operator<=(const String &string) const;
    friend istream &operator>>(istream &in, String &string);
    friend ostream &operator<<(ostream &out, const String &string);
};
int *String::GetFailure(const String &string)
{
    int j = 0;
    int k = -1;
    int *failure = new int[string.length_];
    failure[0] = -1;
    while (j < string.length_ - 1)
    {
        if (k == -1 || string[j] == string[k])
        {
            j++;
            k++;
            failure[j] = k;
        }
        else
        {
            k = failure[k];
        }
    }
    return failure;
}
String::String() : characters_(NULL), length_(0)
{
}
String::String(const char *characters) : length_(strlen(characters))
{
    characters_ = new char[length_ + 1];
    strcpy(characters_, characters);
}
String::String(const string &string) : length_(string.length())
{
    characters_ = new char[length_ + 1];
    for (int index = 0; index < length_; index++)
    {
        characters_[index] = string[index];
    }
    characters_[length_] = '\0';
}
String::String(const String &string) : length_(string.length_)
{
    characters_ = new char[length_ + 1];
    strcpy(characters_, string.characters_);
}
String::~String()
{
    delete[] characters_;
}
bool String::IsEmpty() const
{
    return length_ == 0;
}
void String::Display() const
{
    cout << *this << endl
         << "长度是：" << length_ << "。" << endl;
}
void String::Traverse() const
{
    cout << *this << endl;
}
void String::InsertString(const String &string, int index)
{
    if (index < 0 || index > length_ + 1)
    {
        throw std::string("范围错误。");
    }
    length_ += string.length_;
    const char *temp = GetCharacters();
    characters_ = new char[length_];
    for (int i = 0; i < length_; i++)
    {
        if (i < index)
        {
            characters_[i] = temp[i];
        }
        else if (i >= index && i < index + string.length_)
        {
            characters_[i] = string[i - index];
        }
        else
        {
            characters_[i] = temp[i - string.length_];
        }
    }
    characters_[length_] = '\0';
}
void String::DeleteString(int index, int length)
{
    if (index < 0 || index + length > length_ + 1)
    {
        throw string("范围错误。");
    }
    length_ -= length;
    const char *temp = GetCharacters();
    characters_ = new char[length_];
    for (int i = 0; i < length_; i++)
    {
        if (i < index)
        {
            characters_[i] = temp[i];
        }
        else
        {
            characters_[i] = temp[i + length];
        }
    }
    characters_[length_] = '\0';
}
int String::GetLength() const
{
    return length_;
}
int String::GetIndex(const char character) const
{
    for (int i = 0; i < length_; i++)
    {
        if (characters_[i] == character)
        {
            return i;
        }
    }
    return -1;
}
char String::GetChar(int index) const
{
    return characters_[index];
}
String String::GetSubString(int index, int length) const
{
    if (index < 0 || index + length > length_ + 1)
    {
        throw string("范围错误。");
    }
    char *temp = new char[length + 1];
    for (int i = 0; i < length; i++)
    {
        temp[i] = characters_[i + index];
    }
    temp[length] = '\0';
    return String(temp);
}
const char *String::GetCharacters() const
{
    return (const char *)characters_;
}
void String::Copy(const String &string)
{
    delete[] characters_;
    length_ = string.length_;
    characters_ = new char[length_ + 1];
    strcpy(characters_, string.characters_);
}
void String::Copy(const String &string, int length)
{
    delete[] characters_;
    length_ = length;
    characters_ = new char[length_ + 1];
    strncpy(characters_, string.characters_, length_);
    characters_[length_] = '\0';
}
int String::Compare(const String &string) const
{
    return strcmp(characters_, string.characters_);
}
int String::BruteForcePatternMatching(const String &string)
{
    int i = 0;
    int j = 0;
    while (j < string.length_ && i < length_ && string.length_ - j <= length_ - i)
    {
        if (characters_[i] == string.characters_[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= string.length_)
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}
int String::KMPPatternMatching(const String &string)
{
    int *failure = GetFailure(string);
    int i = 0;
    int j = 0;
    while (j < string.length_ && i < length_ && string.length_ - j <= length_ - i)
    {
        if (j == -1 || characters_[i] == string.characters_[j])
        {
            i++;
            j++;
        }
        else
        {
            j = failure[j];
        }
    }
    delete[] failure;
    if (j >= string.length_)
    {
        return i - j;
    }
    return -1;
}
String &String::operator=(const String &string)
{
    if (&string != this)
    {
        delete[] characters_;
        length_ = string.length_;
        characters_ = new char[length_ + 1];
        strcpy(characters_, string.characters_);
    }
    return *this;
}
char &String::operator[](int index) const
{
    return characters_[index];
}
String String::operator+(const String &string) const
{
    int index = length_;
    int length = length_ + string.length_;
    char *result = new char[length];
    for (int i = 0; i < length; i++)
    {
        if (i < index)
        {
            result[i] = characters_[i];
        }
        else if (i >= index && i < index + string.length_)
        {
            result[i] = string[i - index];
        }
        else
        {
            result[i] = characters_[i - string.length_];
        }
    }
    result[length] = '\0';
    return String(result);
}
void String::operator+=(const String &string)
{
    *this = *this + string;
}
bool String::operator==(const String &string) const
{
    return strcmp(characters_, string.characters_) == 0;
}
bool String::operator!=(const String &string) const
{
    return strcmp(characters_, string.characters_) != 0;
}
bool String::operator>(const String &string) const
{
    return strcmp(characters_, string.characters_) > 0;
}
bool String::operator>=(const String &string) const
{
    return strcmp(characters_, string.characters_) >= 0;
}
bool String::operator<(const String &string) const
{
    return strcmp(characters_, string.characters_) < 0;
}
bool String::operator<=(const String &string) const
{
    return strcmp(characters_, string.characters_) <= 0;
}
istream &operator>>(istream &in, String &string)
{
    std::string temp;
    in >> temp;
    string = String(temp);
    return in;
}
ostream &operator<<(ostream &out, const String &string)
{
    for (int i = 0; i < string.length_; i++)
    {
        out << string[i];
    }
    return out;
}
#endif