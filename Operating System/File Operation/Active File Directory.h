#pragma once
#include "User File Directory.h"
class ActiveFileDirectory
{
public:
    int m_fileIndex;
    ProtectCode m_proCode;
    UserFileDirectory *m_point;
    ActiveFileDirectory *m_next;
    ActiveFileDirectory(int fileIndex, ProtectCode proCode, UserFileDirectory *point, ActiveFileDirectory *next)
    {
        m_fileIndex = fileIndex;
        m_proCode = proCode;
        m_point = point;
        m_next = next;
    }
};