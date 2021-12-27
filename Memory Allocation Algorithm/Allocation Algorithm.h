#include "Free Partition Table.cpp"
class AllocationAlgorithm
{
public:
    AllocationAlgorithm(int maxSize = 0, int size = 0, Partition *freePartition = nullptr);
    ~AllocationAlgorithm();
    AllocationAlgorithm(const AllocationAlgorithm &allocationAlgorithm);
    FreePartitionTable GetFreePartitionTable();
    void SetFreePartitionTable(FreePartitionTable freePartitionTable);
    bool FirstFit(int size);
    bool BestFit(int size);
    bool WorstFit(int size);
    void ShowFreePartition();
    AllocationAlgorithm &operator=(const AllocationAlgorithm &allocationAlgorithm);

private:
    FreePartitionTable m_freePartitionTable;
};