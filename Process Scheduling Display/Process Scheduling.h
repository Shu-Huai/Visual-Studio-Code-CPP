#include "Process Control Block.cpp"
using namespace std;
class ProcessScheduling
{
public:
    ProcessScheduling(int number);
    ~ProcessScheduling();
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