#include "Process Control Block.h"
#include <iomanip>
ProcessControlBlock::ProcessControlBlock() : m_id(0), m_priority(0), m_runTime(0), m_totalTime(0), m_status(Ready)
{
}
ProcessControlBlock::~ProcessControlBlock()
{
}