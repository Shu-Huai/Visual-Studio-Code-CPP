#include "Resource.cpp"
class BankerAlgorithm
{
private:
    int m_processNumber;
    int m_resourceNumber;
    int *m_available;
    Resource *m_max;
    Resource *m_allocation;
    Resource *m_need;

public:
    BankerAlgorithm(int processNumber, int resourceNumber, int **tempMax, int **tempAllocation, int **tempNeed);
    ~BankerAlgorithm();
    void Begin();
    void DisplaySystem();
    void DisplaySafe(const Resource &work, int i);
    bool NotNeed(int i);
    bool CheckSafe();
};