#pragma once
#include "Protect Code.h"
#include <string>
using namespace std;
class UserFileDirectory
{
public:
    string m_name;
    ProtectCode m_proCode;
    int m_length;
    UserFileDirectory *m_next;
    UserFileDirectory(string name, ProtectCode proCode, int length, UserFileDirectory *next)
    {
        m_name = name;
        m_proCode = proCode;
        m_length = length;
        m_next = next;
    }
};