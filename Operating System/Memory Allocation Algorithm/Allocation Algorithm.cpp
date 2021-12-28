#include "Allocation Algorithm.h"
AllocationAlgorithm::AllocationAlgorithm(int maxSize, int size, Partition *freePartition)
{
    m_freePartitionTable = FreePartitionTable(maxSize, size, freePartition);
}
AllocationAlgorithm ::~AllocationAlgorithm()
{
}
AllocationAlgorithm::AllocationAlgorithm(const AllocationAlgorithm &allocationAlgorithm)
{
    m_freePartitionTable = allocationAlgorithm.m_freePartitionTable;
}
FreePartitionTable AllocationAlgorithm::GetFreePartitionTable()
{
    return m_freePartitionTable;
}
void AllocationAlgorithm::SetFreePartitionTable(FreePartitionTable freePartitionTable)
{
    m_freePartitionTable = freePartitionTable;
}
bool AllocationAlgorithm::FirstFit(int size)
{
    m_freePartitionTable.Sort("address");
    for (int i = 0; i < m_freePartitionTable.m_size; i++)
    {
        if (m_freePartitionTable[i].m_size >= size)
        {
            m_freePartitionTable[i].m_size -= size;
            if (!m_freePartitionTable[i].m_size)
            {
                m_freePartitionTable.Delete(i);
            }
            m_freePartitionTable.Sort("address");
            return true;
        }
    }
    return false;
}
bool AllocationAlgorithm::BestFit(int size)
{
    m_freePartitionTable.Sort("size");
    for (int i = 0; i < m_freePartitionTable.m_size; i++)
    {
        if (m_freePartitionTable[i].m_size >= size)
        {
            m_freePartitionTable[i].m_size -= size;
            if (!m_freePartitionTable[i].m_size)
            {
                m_freePartitionTable.Delete(i);
            }
            m_freePartitionTable.Sort("size");
            return true;
        }
    }
    return false;
}
bool AllocationAlgorithm::WorstFit(int size)
{
    m_freePartitionTable.Sort("size", true);
    if (m_freePartitionTable[0].m_size >= size)
    {
        m_freePartitionTable[0].m_size -= size;
        if (!m_freePartitionTable[0].m_size)
        {
            m_freePartitionTable.Delete(0);
        }
        m_freePartitionTable.Sort("size");
        return true;
    }
    return false;
}
void AllocationAlgorithm::ShowFreePartition()
{
    m_freePartitionTable.Show();
}
AllocationAlgorithm &AllocationAlgorithm::operator=(const AllocationAlgorithm &allocationAlgorithm)
{
    if (&allocationAlgorithm != this)
    {
        m_freePartitionTable = allocationAlgorithm.m_freePartitionTable;
    }
    return *this;
}