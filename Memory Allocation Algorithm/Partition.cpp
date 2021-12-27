#include "Partition.h"
Partition::Partition(int size, int address, Status status) : m_size(size), m_address(address), m_status(status)
{
    if (size < 0 || address < 0)
    {
        throw(string) "错误。";
    }
}
Partition ::~Partition()
{
}
void Partition::Show()
{
    cout << m_index << "\t" << m_size << "\t" << m_address << "\t" << (m_status ? "占用" : "空闲") << endl;
}
Partition &Partition::operator=(const Partition &partition)
{
    if (&partition != this)
    {
        m_index = partition.m_index;
        m_size = partition.m_size;
        m_address = partition.m_address;
        m_status = partition.m_status;
    }
    return *this;
}