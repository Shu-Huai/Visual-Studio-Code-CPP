#include "Resource.h"
#include <iomanip>
Resource::Resource(int number, int *resources) : m_number(number)
{
    if (!resources)
    {
        m_resources = nullptr;
        return;
    }
    m_resources = new int[m_number];
    for (int i = 0; i < m_number; i++)
    {
        m_resources[i] = resources[i];
    }
}
Resource::~Resource()
{
    delete[] m_resources;
}
bool Resource::IsFinished()
{
    for (int i = 0; i < m_number; i++)
    {
        if (m_resources[i] != 0)
        {
            return false;
        }
    }
    return true;
}
Resource Resource::operator+(const Resource &resource)
{
    if (m_number != resource.m_number)
    {
        throw(string) "操作错误。";
    }
    Resource result(m_number);
    result.m_resources = new int[m_number];
    for (int i = 0; i < m_number; i++)
    {
        result.m_resources[i] = m_resources[i] + resource.m_resources[i];
    }
    return result;
}
Resource &Resource::operator=(const Resource &resource)
{
    if (&resource != this)
    {
        delete[] m_resources;
        m_number = resource.m_number;
        m_resources = new int[m_number];
        for (int i = 0; i < m_number; i++)
        {
            m_resources[i] = resource.m_resources[i];
        }
    }
    return *this;
}
int &Resource::operator[](int i)
{
    if (i < 0 || i >= m_number)
    {
        throw(string) "范围错误。";
    }
    return m_resources[i];
}
ostream &operator<<(ostream &out, const Resource &resource)
{
    for (int i = 0; i < resource.m_number; i++)
    {
        out << setw(2) << resource.m_resources[i];
    }
    return out;
}