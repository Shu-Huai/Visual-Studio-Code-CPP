#include "Resource.cpp"
class BankerAlgorithm
{
private:
    int processNum;
    int resourceNum;
    int *available;
    Resource *maxRequest;
    Resource *allocation;
    Resource *need;
    bool *Finish;
    int *safeSeries;
    int *request;
    int num;

public:
    BankerAlgorithm();
    ~BankerAlgorithm();
    void Begin();
    void DisplaySystem();
    void DisplaySafe(const Resource &work, int i);
    bool NotNeed(int i);
    bool CheckSafe();
};