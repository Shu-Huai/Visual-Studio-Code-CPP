#include "Resource.cpp"
class BankerAlgorithm
{
private:
    int m_processNumber;
    int m_resourceNumber;
    Resource m_available;
    Resource *m_max;
    Resource *m_allocation;
    Resource *m_need;

public:
    BankerAlgorithm(int processNumber, int resourceNumber, int *available, int **tempMax, int **tempAllocation, int **tempNeed);
    ~BankerAlgorithm();
    void Begin();
    void DisplaySystem();
    void DisplaySafe(const Resource &work, int i);
    bool CheckSafe();
};