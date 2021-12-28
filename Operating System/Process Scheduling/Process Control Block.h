#include "Status.h"
class ProcessControlBlock
{
    friend class ProcessSchedulingAlgorithm;

public:
    ProcessControlBlock();
    ~ProcessControlBlock();

private:
    int m_id;
    int m_priority;
    int m_runTime;
    int m_totalTime;
    Status m_status;
};