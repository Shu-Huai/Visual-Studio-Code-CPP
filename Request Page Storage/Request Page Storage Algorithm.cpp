#include "Request Page Storage Algorithm.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
using namespace std;
RequestPageStorageAlgorithm::RequestPageStorageAlgorithm(int memorySize, int addressNumber, int pageSize, int windowSize)
    : m_memorySize(memorySize), m_addressNumber(addressNumber), m_pageSize(pageSize), m_tableSize(windowSize)
{
    CreateAddress();
    CalcPage();
}
void RequestPageStorageAlgorithm::CreateAddress()
{
    int counter = 0;
    default_random_engine randomGetter(123);
    for (int i = 0; i < m_addressNumber; i++)
    {
        int temp = rand() % 4;
        uniform_int_distribution<int> start(0, m_memorySize / 2 - 1);
        uniform_int_distribution<int> end(m_memorySize / 2 - 1, m_memorySize - 1);
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
    int pageNumber = m_memorySize / m_pageSize + (m_memorySize % m_pageSize ? 1 : 0);
    for (int i = 0; i < m_addressNumber; i++)
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
    for (int i = 0; i < m_addressNumber; i++)
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
            if ((int)table.size() < m_tableSize)
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
                for (int t = 0; t < m_tableSize; t++)
                {
                    int elem = table[t];
                    vector<int>::iterator s = find(m_page.begin() + i, m_page.end(), elem);
                    int pos = distance(m_page.begin(), s);
                    if (s == m_page.end())
                    {
                        out = t;
                        break;
                    }
                    else if (pos < m_addressNumber && pos > next)
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
    cout << "最佳淘汰算法的命中率：" << (1 - (double)failureCounter / m_addressNumber) * 100 << "%。" << endl;
}
void RequestPageStorageAlgorithm::LeastRecentlyUsed()
{
    vector<int> table;
    int failureCounter = 0;
    table.push_back(m_page[0]);
    for (int i = 0; i < m_addressNumber; i++)
    {
        vector<int>::iterator f = find(table.begin(), table.end(), m_page[i]);
        if (f == table.end())
        {
            cout << "address" << left << setw(5) << ("[" + to_string(i) + "]") << "未命中。";
            if ((int)table.size() < m_tableSize)
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
    cout << "最近最久未使用算法的命中率：" << (1 - (double)failureCounter / m_addressNumber) * 100 << "%。" << endl;
}
int RequestPageStorageAlgorithm::GetMemorySize()
{
    return m_memorySize;
}
int RequestPageStorageAlgorithm::GetAddressNumber()
{
    return m_addressNumber;
}
int RequestPageStorageAlgorithm::GetPageSize()
{
    return m_pageSize;
}
int RequestPageStorageAlgorithm::GetTableSize()
{
    return m_tableSize;
}
void RequestPageStorageAlgorithm::ShowAddress()
{
    cout << "地址流：" << endl;
    for (int i = 0; i < m_addressNumber; i++)
    {
        cout << "address" << left << setw(5) << ("[" + to_string(i) + "]") << " = " << m_address[i] << ((i + 1) % 4 ? "\t" : "\n");
    }
}
void RequestPageStorageAlgorithm::ShowPage()
{
    cout << "页号：" << endl;
    for (int i = 0; i < m_addressNumber; i++)
    {
        cout << "address" << left << setw(5) << ("[" + to_string(i) + "]") << " = " << m_page[i] << ((i + 1) % 4 ? "\t" : "\n");
    }
}