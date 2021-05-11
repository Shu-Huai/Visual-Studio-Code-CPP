#pragma once
#ifndef __ASSISTANCE_H__
#define __ASSISTANCE_H__
#define DEFAULT_SIZE 1000
#define DEFAULT_INFINITY 1000000
#define MAX_ERROR_MESSAGE_LEN 100
#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
enum Status
{
    SUCCESS,
    FAIL,
    UNDER_FLOW,
    OVER_FLOW,
    RANGE_ERROR,
    DUPLICATE_ERROR,
    NOT_PRESENT,
    ENTRY_INSERTED,
    ENTRY_FOUND,
    VISITED,
    UNVISITED
};
char GetChar(istream &inStream)
{
    char temp;
    while ((temp = (inStream).peek()) != EOF && ((temp = (inStream).get()) == ' ' || temp == '\t'))
        ;
    return temp;
}
class Error
{
private:
    char message_[MAX_ERROR_MESSAGE_LEN];

public:
    Error(const char *message = "一般性异常！");
    ~Error();
    void Show() const;
};
Error::Error(const char *message)
{
    strcpy(message_, message);
}
Error::~Error()
{
}
void Error::Show() const
{
    cout << message_ << endl;
}
template <class ElemType>
void Swap(ElemType &elemA, ElemType &elemB)
{
    ElemType temp;
    temp = elemA;
    elemA = elemB;
    elemB = temp;
}
template <class ElemType>
void Display(ElemType elems[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << elems[i] << "  ";
    }
    cout << endl;
}
template <class ElemType>
void Write(const ElemType &elem)
{
    cout << elem << "  ";
}
#endif