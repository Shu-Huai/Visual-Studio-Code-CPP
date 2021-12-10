#include "Banker Algorithm.h"
using namespace std;
BankerAlgorithm::BankerAlgorithm(int processNumber, int resourceNumber, int *available, int **max, int **allocation, int **need)
    : m_processNumber(processNumber), m_resourceNumber(resourceNumber)
{
    m_available = Resource(3, available);
    m_max = new Resource[m_processNumber];
    m_allocation = new Resource[m_processNumber];
    m_need = new Resource[m_processNumber];
    for (int i = 0; i < m_processNumber; i++)
    {
        m_max[i] = Resource(m_resourceNumber, max[i]);
        m_allocation[i] = Resource(m_resourceNumber, allocation[i]);
        m_need[i] = Resource(m_resourceNumber, need[i]);
    }
}
BankerAlgorithm::~BankerAlgorithm()
{
    delete[] m_max;
    delete[] m_allocation;
    delete[] m_need;
}
void BankerAlgorithm::Begin()
{
    DisplaySystem();
    cout << "系统安全情况分析：" << endl
         << "PID\tWork\t\tAllocation\tNeed\t\tWork + Allocation\n";
    bool isStart = CheckSafe();
    while (isStart)
    {
        cout << endl
             << "------------------------------------------------------------------------------------" << endl
             << "请输入想分配的进程：";
        int curProcess = 0;
        cin >> curProcess;
        cout << "请输入想分配的资源：";
        Resource request(m_resourceNumber);
        cin >> request;
        int count = 0;
        for (int i = 0; i < m_resourceNumber; i++)
        {
            if (request[i] <= m_need[curProcess][i] && request[i] <= m_available[i])
            {
                count++;
            }
            else
            {
                cout << "分配错误，想分配的资源大于该进程的最大需要或系统所剩的资源不够这次分配。" << endl;
                break;
            }
        }
        if (count == m_resourceNumber)
        {
            count = 0;
            for (int i = 0; i < m_resourceNumber; i++)
            {
                m_available[i] -= request[i];
                m_allocation[curProcess][i] += request[i];
                m_need[curProcess][i] -= request[i];
                if (!m_need[curProcess][i])
                {
                    count++;
                }
            }
            if (m_need[curProcess].IsFinished())
            {
                for (int i = 0; i < m_resourceNumber; i++)
                {
                    m_available[i] = m_available[i] + m_allocation[curProcess][i];
                }
                cout << "本次分配进程P" << curProcess << "完成，该进程占用资源全部释放完毕。" << endl;
            }
            else
            {
                cout << "本次分配进程P" << curProcess << "未完成。" << endl;
            }
            DisplaySystem();
            cout << "系统安全情况分析：" << endl
                 << "PID\tWork\t\tAllocation\tNeed\t\tWork + Allocation\n";
            if (!CheckSafe())
            {
                for (int i = 0; i < m_resourceNumber; i++)
                {
                    m_available[i] += request[i];
                    m_allocation[curProcess][i] -= request[i];
                    m_need[curProcess][i] += request[i];
                }
                cout << "资源不足，分配失败。" << endl;
            }
        }
    }
}
void BankerAlgorithm::DisplaySystem()
{
    cout << endl
         << "------------------------------------------------------------------------------------" << endl
         << "系统资源剩余情况：" << endl;
    for (int i = 0; i < m_resourceNumber; i++)
    {
        cout << m_available[i] << " ";
    }
    cout << endl
         << "进程资源分配情况：" << endl
         << "PID\tMax\t\tAllocation\tNeed" << endl;
    for (int i = 0; i < m_processNumber; i++)
    {
        cout << "P" << i << "\t" << m_max[i] << "\t\t" << m_allocation[i] << "\t\t" << m_need[i] << endl;
    }
}
void BankerAlgorithm::DisplaySafe(const Resource &work, int i)
{
    cout << "P" << i << "\t" << work << "\t\t" << m_allocation[i] << "\t\t" << m_need[i] << "\t\t"
         << m_allocation[i] + work << endl;
}
bool BankerAlgorithm::NotNeed(int i)
{
    return m_need[i].IsFinished();
}
bool BankerAlgorithm::CheckSafe()
{
    Resource work(m_available);
    bool *finish = new bool[m_processNumber]{false};
    int finishNumber = 0;
    for (int i = 0; i < m_processNumber; i++)
    {
        if (NotNeed(i))
        {
            finish[i] = true;
            finishNumber++;
        }
        else
        {
            finish[i] = false;
        }
    }
    int r = 0;
    int temp = 0;
    int processNumber = 0;
    int safeIndex = 0;
    int *safeSeries = new int[m_processNumber]{0};
    while (finishNumber != m_processNumber)
    {
        int count = 0;
        for (int i = 0; i < m_resourceNumber; i++)
        {
            if (m_need[r][i] <= work[i] && !finish[r])
            {
                count++;
            }
        }
        if (count == m_resourceNumber)
        {
            DisplaySafe(work, r);
            work = work + m_allocation[r];
            finishNumber++;
            safeSeries[safeIndex] = r;
            safeIndex++;
            finish[r] = true;
        }
        r++;
        if (r >= m_processNumber)
        {
            r %= m_processNumber;
            if (temp == finishNumber)
            {
                break;
            }
            temp = finishNumber;
        }
        processNumber = finishNumber;
    }
    for (int i = 0; i < m_processNumber; i++)
    {
        if (!finish[i])
        {
            cout << "当前系统不安全。" << endl;
            delete[] safeSeries;
            delete[] finish;
            return false;
        }
    }
    delete[] finish;
    cout << "当前系统安全。" << endl
         << "安全序列为：";
    for (int i = 0; i < m_processNumber; i++)
    {
        if (NotNeed(i))
        {
            processNumber--;
        }
    }
    for (int i = 0; i < processNumber; i++)
    {
        cout << safeSeries[i] << " ";
    }
    delete[] safeSeries;
    return true;
}