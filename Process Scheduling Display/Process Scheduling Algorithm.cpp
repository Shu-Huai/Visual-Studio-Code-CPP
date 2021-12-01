#include "Process Scheduling Algorithm.h"
#include <iostream>
ProcessSchedulingAlgorithm::ProcessSchedulingAlgorithm(int number) : m_number(number), m_head(0), m_tail(0)
{
    m_PCB = new ProcessControlBlock[m_number + 1];
    m_list = new int[m_number + 1];
    srand(time(NULL));
    for (int i = 1; i <= m_number; i++)
    {
        m_PCB[i].m_id = i;
        m_PCB[i].m_priority = rand() % 4 + 1;
        m_PCB[i].m_totalTime = rand() % 8 + 1;
    }
}
ProcessSchedulingAlgorithm::~ProcessSchedulingAlgorithm()
{
    delete[] m_PCB;
    delete[] m_list;
}
void ProcessSchedulingAlgorithm::Display()
{
    cout << "新一轮调度。" << endl
         << setw(16) << "进程标识符：";
    for (int i = 1; i <= m_number; i++)
    {
        cout << setw(4) << m_PCB[i].m_id;
    }
    cout << endl
         << setw(16) << "进程优先级：";
    for (int i = 1; i <= m_number; i++)
    {
        cout << setw(4) << m_PCB[i].m_priority;
    }
    cout << endl
         << setw(16) << "运行时间：";
    for (int i = 1; i <= m_number; i++)
    {
        cout << setw(4) << m_PCB[i].m_runTime;
    }
    cout << endl
         << setw(16) << "总时间：";
    for (int i = 1; i <= m_number; i++)
    {
        cout << setw(4) << m_PCB[i].m_totalTime;
    }
    cout << endl
         << setw(16) << "当前状态：";
    for (int i = 1; i <= m_number; i++)
    {
        cout << setw(4) << m_PCB[i].m_status;
    }
    if (m_running != -1)
    {
        cout << endl
             << "正在运行的进程：" << m_running << endl;
    }
    else
    {
        cout << endl
             << "无当前正在运行的进程。" << endl;
    }
    cout << "等待队列：";
    for (int i = m_head; i != -1; i = m_list[i])
    {
        cout << i << " ";
    }
    cout << endl;
}
void ProcessSchedulingAlgorithm::PriorityScheduling()
{
    int *sort = new int[m_number + 1];
    for (int i = 1; i <= m_number; i++)
    {
        sort[i] = i;
    }
    for (int i = 1; i <= m_number; i++)
    {
        for (int j = m_number; j > i; j--)
        {
            if (m_PCB[sort[j]].m_priority > m_PCB[sort[j - 1]].m_priority)
            {
                int temp = sort[j];
                sort[j] = sort[j - 1];
                sort[j - 1] = temp;
            }
        }
    }
    m_head = sort[1];
    for (int i = 1; i < m_number; i++)
    {
        m_list[sort[i]] = sort[i + 1];
    }
    m_tail = sort[m_number];
    delete[] sort;
    m_list[m_tail] = -1;
    m_running = m_head;
    m_PCB[m_running].m_status = Running;
    m_head = m_list[m_head];
    while (m_running != -1)
    {
        Display();
        m_PCB[m_running].m_totalTime--;
        m_PCB[m_running].m_priority -= 3;
        m_PCB[m_running].m_runTime++;
        if (!m_PCB[m_running].m_totalTime)
        {
            m_PCB[m_running].m_status = Complete;
            m_running = m_head;
            if (m_head != -1)
            {
                m_head = m_list[m_head];
            }
            m_PCB[m_running].m_status = Running;
        }
        else
        {
            if (m_head != -1 && m_PCB[m_running].m_priority < m_PCB[m_head].m_priority)
            {
                int k = m_head;
                m_PCB[m_running].m_status = Ready;
                while (k != m_tail && m_PCB[m_list[k]].m_priority > m_PCB[m_running].m_priority)
                {
                    k = m_list[k];
                }
                if (k == m_tail)
                {
                    m_list[k] = m_running;
                    m_tail = m_running;
                    m_list[m_running] = -1;
                    m_running = m_head;
                    m_head = m_list[m_head];
                    m_PCB[m_running].m_status = Running;
                }
                else
                {
                    m_list[m_running] = m_list[k];
                    m_list[k] = m_running;
                    m_running = m_head;
                    m_head = m_list[m_head];
                    m_PCB[m_running].m_status = Running;
                }
            }
        }
    }
    Display();
}
void ProcessSchedulingAlgorithm::RoundRobin()
{
    m_head = 1;
    for (int i = 1; i < m_number; i++)
    {
        m_list[i] = i + 1;
    }
    m_tail = m_number;
    m_list[m_tail] = -1;
    m_running = -1;
    m_running = m_head;
    m_PCB[m_running].m_status = Running;
    m_head = m_list[m_head];
    while (m_running != -1)
    {
        Display();
        m_PCB[m_running].m_totalTime--;
        m_PCB[m_running].m_runTime++;
        if (!m_PCB[m_running].m_totalTime)
        {
            m_PCB[m_running].m_status = Complete;
            m_running = m_head;
            if (m_head != -1)
            {
                m_head = m_list[m_head];
            }
            m_PCB[m_head].m_status = Running;
        }
        else
        {
            if (m_head != -1 && m_PCB[m_running].m_runTime % m_PCB[m_running].m_priority == 0)
            {
                m_PCB[m_running].m_status = Ready;
                m_list[m_tail] = m_running;
                m_list[m_running] = -1;
                m_tail = m_running;
                m_running = m_head;
                m_head = m_list[m_head];
                m_PCB[m_running].m_status = Running;
            }
        }
    }
    Display();
}