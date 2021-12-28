#include "Process Control Block.cpp"
using namespace std;
class ProcessSchedulingAlgorithm
{
public:
    ProcessSchedulingAlgorithm(int number);
    ~ProcessSchedulingAlgorithm();
    void Display();
    void PriorityScheduling();
    void RoundRobin();

private:
    int m_number;
    int m_head;
    int m_tail;
    int m_running;
    ProcessControlBlock *m_PCB;
    int *m_list;
};