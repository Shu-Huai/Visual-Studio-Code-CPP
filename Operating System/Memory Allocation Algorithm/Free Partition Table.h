#include "Partition.cpp"
class FreePartitionTable
{
    friend class AllocationAlgorithm;

public:
    FreePartitionTable(int maxSize = 0, int size = 0, Partition *freePartition = nullptr);
    FreePartitionTable(const FreePartitionTable &freePartitionTable);
    ~FreePartitionTable();
    void Show();
    void SetIndex();
    void Delete(int index);
    void Sort(string key, bool reverse = false);
    Partition &operator[](int index);
    FreePartitionTable &operator=(const FreePartitionTable &freePartitionTable);

private:
    int m_maxSize;
    int m_size;
    Partition *m_freePartition;
};