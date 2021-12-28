#include "Request Page Storage Algorithm.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
RequestPageStorageAlgorithm::RequestPageStorageAlgorithm(int virtualMemorySize, int instructionNumber, int pageSize, int realMemorySize)
    : m_virtualMemorySize(virtualMemorySize), m_instructionNumber(instructionNumber), m_pageSize(pageSize), m_realMemorySize(realMemorySize)
{
    CreateAddress();
    CalcPage();
}
void RequestPageStorageAlgorithm::CreateAddress()
{
    int counter = 0;
    default_random_engine randomGetter(time(0));
    for (int i = 0; i < m_instructionNumber; i++)
    {
        int temp = rand() % 4;
        uniform_int_distribution<int> start(0, m_virtualMemorySize / 2 - 1);
        uniform_int_distribution<int> end(m_virtualMemorySize / 2 - 1, m_virtualMemorySize - 1);
        switch (temp)
        {
        case 0:
        case 1:
            m_address.push_back(counter++);
            break;
        case 2:
            m_address.push_back(start(randomGetter));
            break;
        case 3:
            m_address.push_back(end(randomGetter));
            break;
        }
    }
}
void RequestPageStorageAlgorithm::CalcPage()
{
    int pageNumber = m_virtualMemorySize / m_pageSize + (m_virtualMemorySize % m_pageSize ? 1 : 0);
    for (int i = 0; i < m_instructionNumber; i++)
    {
        for (int j = 0; j < pageNumber; j++)
        {
            if (m_address[i] < (j + 1) * m_pageSize)
            {
                m_page.push_back(j);
                break;
            }
        }
    }
}
void RequestPageStorageAlgorithm::Optimal()
{
    int failureCounter = 0;
    vector<int> table;
    table.push_back(m_page[0]);
    for (int i = 0; i < m_instructionNumber; i++)
    {
        bool hit = false;
        for (int elem : table)
        {
            if (elem == m_page[i])
            {
                cout << "address" << left << setw(5) << ("[" + to_string(i) + "]") << "命中。" << endl;
                hit = true;
            }
        }
        if (!hit)
        {
            cout << "address" << left << setw(5) << ("[" + to_string(i) + "]") << "未命中。";
            if ((int)table.size() < m_realMemorySize)
            {
                table.push_back(m_page[i]);
                failureCounter++;
                cout << "页表未满，"
                     << " address" << left << setw(5) << ("[" + to_string(i) + "] ") << "存入页表。" << endl;
            }
            else
            {
                int next = 0;
                int out = 0;
                for (int t = 0; t < m_realMemorySize; t++)
                {
                    int elem = table[t];
                    vector<int>::iterator s = find(m_page.begin() + i, m_page.end(), elem);
                    int pos = distance(m_page.begin(), s);
                    if (s == m_page.end())
                    {
                        out = t;
                        break;
                    }
                    else if (pos < m_instructionNumber && pos > next)
                    {
                        next = pos;
                        out = t;
                    }
                }
                cout << "页表已满，换出第" << out + 1 << "项，"
                     << " address" << left << setw(5) << ("[" + to_string(i) + "] ") << "存入页表" << endl;
                failureCounter++;
                table[out] = m_page[i];
            }
        }
    }
    cout << "最佳淘汰算法的命中率：" << (1 - (double)failureCounter / m_instructionNumber) * 100 << "%。" << endl;
}
void RequestPageStorageAlgorithm::LeastRecentlyUsed()
{
    vector<int> table;
    int failureCounter = 0;
    table.push_back(m_page[0]);
    for (int i = 0; i < m_instructionNumber; i++)
    {
        vector<int>::iterator f = find(table.begin(), table.end(), m_page[i]);
        if (f == table.end())
        {
            cout << "address" << left << setw(5) << ("[" + to_string(i) + "]") << "未命中。";
            if ((int)table.size() < m_realMemorySize)
            {
                table.push_back(m_page[i]);
                failureCounter++;
                cout << "页表未满，"
                     << "address" << left << setw(5) << ("[" + to_string(i) + "]") << "存入页表。" << endl;
            }
            else
            {
                table.erase(table.begin());
                table.push_back(m_page[i]);
                failureCounter++;
                cout << "页表已满，换出第1项，"
                     << " address" << left << setw(5) << ("[" + to_string(i) + "] ") << "存入页表" << endl;
            }
        }
        else
        {
            cout << "address" << left << setw(5) << ("[" + to_string(i) + "]") << "命中。" << endl;
            int pos = distance(table.begin(), f);
            table.push_back(table[pos]);
            table.erase(table.begin() + pos);
        }
    }
    cout << "最近最久未使用算法的命中率：" << (1 - (double)failureCounter / m_instructionNumber) * 100 << "%。" << endl;
}
int RequestPageStorageAlgorithm::GetVirtualMemorySize()
{
    return m_virtualMemorySize;
}
int RequestPageStorageAlgorithm::GetInstructionNumber()
{
    return m_instructionNumber;
}
int RequestPageStorageAlgorithm::GetPageSize()
{
    return m_pageSize;
}
int RequestPageStorageAlgorithm::GetRealMemorySize()
{
    return m_realMemorySize;
}
void RequestPageStorageAlgorithm::ShowAddress()
{
    cout << "地址流：" << endl;
    for (int i = 0; i < m_instructionNumber; i++)
    {
        cout << "address" << left << setw(5) << ("[" + to_string(i) + "]") << " = " << m_address[i] << ((i + 1) % 4 ? "\t" : "\n");
    }
}
void RequestPageStorageAlgorithm::ShowPage()
{
    cout << "页号：" << endl;
    for (int i = 0; i < m_instructionNumber; i++)
    {
        cout << "address" << left << setw(5) << ("[" + to_string(i) + "]") << " = " << m_page[i] << ((i + 1) % 4 ? "\t" : "\n");
    }
}