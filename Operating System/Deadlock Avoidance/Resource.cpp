#include "Resource.h"
#include <iomanip>
Resource::Resource(int number, int *resources) : m_number(number)
{
    if (!number)
    {
        m_resources = nullptr;
        return;
    }
    m_resources = new int[m_number]{0};
    if (resources)
    {
        for (int i = 0; i < m_number; i++)
        {
            m_resources[i] = resources[i];
        }
    }
}
Resource::Resource(const Resource &resource) : m_number(resource.m_number)
{
    m_resources = new int[m_number];
    for (int i = 0; i < m_number; i++)
    {
        m_resources[i] = resource.m_resources[i];
    }
}
Resource::~Resource()
{
    if (m_resources)
    {
        delete[] m_resources;
    }
}
bool Resource::EqualsZero()
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
Resource &Resource::operator+=(const Resource &resource)
{
    if (m_number != resource.m_number)
    {
        throw(string) "操作错误。";
    }
    for (int i = 0; i < m_number; i++)
    {
        m_resources[i] += resource.m_resources[i];
    }
    return *this;
}
Resource &Resource::operator-=(const Resource &resource)
{
    if (m_number != resource.m_number)
    {
        throw(string) "操作错误。";
    }
    for (int i = 0; i < m_number; i++)
    {
        m_resources[i] -= resource.m_resources[i];
    }
    return *this;
}
bool Resource::operator>(const Resource &resource)
{
    for (int i = 0; i < m_number; i++)
    {
        if (m_resources[i] > resource.m_resources[i])
        {
            return true;
        }
    }
    return false;
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
istream &operator>>(istream &in, Resource &resource)
{
    for (int i = 0; i < resource.m_number; i++)
    {
        in >> resource.m_resources[i];
    }
    return in;
}