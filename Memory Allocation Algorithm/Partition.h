#include "Status.h"
#include <iostream>
using namespace std;
class Partition
{
    friend class FreePartitionTable;
    friend class AllocationAlgorithm;

public:
    Partition(int size = 0, int address = 0, Status status = Free);
    ~Partition();
    void Show();
    Partition &operator=(const Partition &partition);

private:
    int m_index;
    int m_size;
    int m_address;
    Status m_status;
};