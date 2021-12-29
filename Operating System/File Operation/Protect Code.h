#include <string>
using namespace std;
class ProtectCode
{
public:
    bool m_write;
    bool m_read;
    bool m_execute;
    ProtectCode() : m_write(false), m_read(false), m_execute(false)
    {
    }
    ProtectCode(bool write, bool read, bool execute) : m_write(write), m_read(read), m_execute(execute)
    {
    }
    ProtectCode(const ProtectCode &protectCode) : m_write(protectCode.m_write), m_read(protectCode.m_read), m_execute(protectCode.m_execute)
    {
    }
    bool Check(const string &proCode)
    {
        return m_write == (proCode[0] == '1') && m_read == (proCode[1] == '1') && m_execute == (proCode[2] == '1');
    }
    ProtectCode &operator=(const string &proCode)
    {
        m_write = proCode[0] == '1';
        m_read = proCode[1] == '1';
        m_execute = proCode[2] == '1';
        return *this;
    }
    ProtectCode &operator=(const ProtectCode &proCode)
    {
        if (this != &proCode)
        {
            m_write = proCode.m_write;
            m_read = proCode.m_read;
            m_execute = proCode.m_execute;
        }
        return *this;
    }
};