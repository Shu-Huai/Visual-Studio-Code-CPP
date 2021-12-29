#pragma once
#include "User File Directory.h"
#include <string>
using namespace std;
class MasterFileDirectory
{
public:
    string m_userName;
    UserFileDirectory *m_file;
    MasterFileDirectory *m_next;
};