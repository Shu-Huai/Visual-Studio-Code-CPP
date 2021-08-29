#include "Very Long Int.h"
#include <cstring>
using namespace std;
VeryLongInt::VeryLongInt(int length) : m_length(length)
{
    m_numbers = new int[m_length]{0};
}
VeryLongInt::VeryLongInt(const char *number) : m_length(strlen(number))
{
    m_numbers = new int[m_length]{0};
    for (int i = 0; i < m_length; i++)
    {
        if (number[i] >= '0' && number[i] <= '9')
        {
            m_numbers[i] = (int)number[i] - 48;
        }
        else
        {
            throw(string) "非法字符。";
        }
    }
    DeleteZero();
}
void VeryLongInt::Show() const
{
    for (int i = 0; i < m_length; i++)
    {
        cout << m_numbers[i];
    }
}
void VeryLongInt::DeleteZero()
{
    int i = 0;
    while (i < m_length - 1)
    {
        if (!m_numbers[i])
        {
            i++;
        }
        else
        {
            break;
        }
    }
    for (int j = 0; j < m_length - i; j++)
    {
        m_numbers[j] = m_numbers[j + i];
    }
    m_length -= i;
}
VeryLongInt VeryLongInt::operator+(const VeryLongInt &number)
{
    int minLength = m_length > number.m_length ? number.m_length : m_length;
    int maxLength = m_length < number.m_length ? number.m_length : m_length;
    VeryLongInt result(maxLength + 1);
    for (int i = 0; i < minLength; i++)
    {
        int index = result.m_length - 1 - i;
        result.m_numbers[index] += m_numbers[m_length - 1 - i] + number.m_numbers[number.m_length - 1 - i];
        if (result.m_numbers[index] >= 10)
        {
            result.m_numbers[index] -= 10;
            result.m_numbers[index - 1] += 1;
        }
    }
    for (int i = 0; i < maxLength - minLength; i++)
    {
        int index = result.m_length - minLength - 1 - i;
        result.m_numbers[index] += m_length == minLength ? number.m_numbers[index - 1] : m_numbers[index - 1];
        if (result.m_numbers[index] >= 10)
        {
            result.m_numbers[index] -= 10;
            result.m_numbers[index - 1] += 1;
        }
    }
    result.DeleteZero();
    return result;
}