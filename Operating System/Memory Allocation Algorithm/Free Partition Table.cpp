#include "Free Partition Table.h"
FreePartitionTable::FreePartitionTable(int maxSize, int size, Partition *freePartition) : m_maxSize(maxSize), m_size(size)
{
    m_freePartition = new Partition[m_maxSize];
    for (int i = 0; i < m_size; i++)
    {
        m_freePartition[i] = freePartition[i];
        m_freePartition[i].m_index = i;
    }
}
FreePartitionTable::FreePartitionTable(const FreePartitionTable &freePartitionTable) : m_maxSize(freePartitionTable.m_maxSize), m_size(freePartitionTable.m_size)
{
    m_freePartition = new Partition[m_maxSize];
    for (int i = 0; i < m_size; i++)
    {
        m_freePartition[i] = freePartitionTable.m_freePartition[i];
    }
}
FreePartitionTable ::~FreePartitionTable()
{
    delete[] m_freePartition;
}
void FreePartitionTable::Show()
{
    cout << "系统中的空闲区：" << endl
         << "编号\t大小\t首址\t状态" << endl;
    for (int i = 0; i < m_size; i++)
    {
        m_freePartition[i].Show();
    }
}
void FreePartitionTable::SetIndex()
{
    for (int i = 0; i < m_size; i++)
    {
        m_freePartition[i].m_index = i;
    }
}
void FreePartitionTable::Delete(int index)
{
    if (index < 0 || index >= m_size)
    {
        throw string("范围错误。");
    }
    for (int j = index; j < m_size - 1; j++)
    {
        m_freePartition[j] = m_freePartition[j + 1];
    }
    m_size--;
}
void FreePartitionTable::Sort(string key, bool reverse)
{
    if (key != "size" && key != "address")
    {
        throw(string) "错误。";
    }
    for (int i = 0; i < m_size; i++)
    {
        for (int j = 0; j < m_size - i - 1; j++)
        {
            if ((key == "size" && reverse ^ (m_freePartition[j].m_size > m_freePartition[j + 1].m_size)) ||
                (key == "address" && reverse ^ (m_freePartition[j].m_address > m_freePartition[j + 1].m_address)))
            {
                swap(m_freePartition[j], m_freePartition[j + 1]);
            }
        }
    }
    SetIndex();
}
Partition &FreePartitionTable::operator[](int index)
{
    if (index < 0 || index >= m_size)
    {
        throw(string) "范围错误。";
    }
    return m_freePartition[index];
}
FreePartitionTable &FreePartitionTable::operator=(const FreePartitionTable &freePartitionTable)
{
    if (&freePartitionTable != this)
    {
        delete[] m_freePartition;
        m_maxSize = freePartitionTable.m_maxSize;
        m_size = freePartitionTable.m_size;
        m_freePartition = new Partition[m_maxSize];
        for (int i = 0; i < m_size; i++)
        {
            m_freePartition[i] = freePartitionTable.m_freePartition[i];
        }
    }
    return *this;
}