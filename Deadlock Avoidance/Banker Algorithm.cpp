#include "Banker Algorithm.h"
using namespace std;
BankerAlgorithm::BankerAlgorithm()
{
    processNum = 5;
    resourceNum = 3;
    const int tempProcessNum = 5;
    const int tempResourceNum = 3;
    available = new int[resourceNum]{3, 3, 2};
    maxRequest = new Resource[processNum];
    int tempMax[tempProcessNum][tempResourceNum] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    allocation = new Resource[processNum];
    int tempAllocation[tempProcessNum][tempResourceNum] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    need = new Resource[processNum];
    int tempNeed[tempProcessNum][tempResourceNum] = {{7, 4, 3}, {1, 2, 2}, {6, 0, 0}, {0, 1, 1}, {4, 3, 1}};
    for (int i = 0; i < processNum; i++)
    {
        maxRequest[i] = Resource(resourceNum, tempMax[i]);
        allocation[i] = Resource(resourceNum, tempAllocation[i]);
        need[i] = Resource(resourceNum, tempNeed[i]);
    }
    Finish = new bool[processNum];
    safeSeries = new int[processNum]{0};
    request = new int[resourceNum];
}
BankerAlgorithm::~BankerAlgorithm()
{
    delete[] available;
    delete[] maxRequest;
    delete[] allocation;
    delete[] need;
    delete[] Finish;
    delete[] safeSeries;
    delete[] request;
}
void BankerAlgorithm::Begin()
{
    int curProcess = 0;
    DisplaySystem();
    cout << "系统安全情况分析：" << endl
         << "PID\tWork\t\tAllocation\tNeed\t\tWork+Allocation\n";
    bool isStart = CheckSafe();
    while (isStart)
    {
        cout << endl
             << "------------------------------------------------------------------------------------" << endl
             << "请输入分配的进程：";
        cin >> curProcess;
        cout << "请输入分配的资源：";
        for (int i = 0; i < resourceNum; i++)
        {
            cin >> request[i];
        }
        num = 0;
        for (int i = 0; i < resourceNum; i++)
        {
            if (request[i] <= need[curProcess][i] && request[i] <= available[i])
            {
                num++;
            }
            else
            {
                printf("\n发生错误！可能原因如下：\n(1)您请求分配的资源可能大于该进程的某些资源的最大需要！\n(2)系统所剩的资源已经不足了！\n");
                break;
            }
        }
        if (num == resourceNum)
        {
            num = 0;
            for (int j = 0; j < resourceNum; j++)
            {
                //分配资源
                available[j] = available[j] - request[j];
                allocation[curProcess][j] = allocation[curProcess][j] + request[j];
                need[curProcess][j] = need[curProcess][j] - request[j];
                //记录分配以后，是否该进程需要值为0了
                if (need[curProcess][j] == 0)
                {
                    num++;
                }
            }
            //如果分配以后出现该进程对所有资源的需求为0了，即刻释放该进程占用资源（视为完成）
            if (num == resourceNum)
            {
                //释放已完成资源
                for (int i = 0; i < resourceNum; i++)
                {
                    available[i] = available[i] + allocation[curProcess][i];
                }
                printf("\n\n本次分配进程 P%d 完成,该进程占用资源全部释放完毕！\n", curProcess);
            }
            else
            {
                //资源分配可以不用一次性满足进程需求
                printf("\n\n本次分配进程 P%d 未完成！\n", curProcess);
            }

            DisplaySystem();
            printf("\n系统安全情况分析\n");
            printf(" PID\t Work\t\tAllocation\t Need\t\tWork+Allocation\n");

            //预分配完成以后，判断该系统是否安全，若安全，则可继续进行分配，若不安全，将已经分配的资源换回来
            if (!CheckSafe())
            {
                for (int j = 0; j < resourceNum; j++)
                {
                    available[j] = available[j] + request[j];
                    allocation[curProcess][j] = allocation[curProcess][j] - request[j];
                    need[curProcess][j] = need[curProcess][j] + request[j];
                }
                printf("资源不足，等待中...\n\n分配失败！\n");
            }
        }
    }
}
void BankerAlgorithm::DisplaySystem()
{
    cout << endl
         << "------------------------------------------------------------------------------------" << endl
         << "系统资源剩余情况：" << endl;
    for (int i = 0; i < resourceNum; i++)
    {
        cout << available[i] << " ";
    }
    cout << endl
         << "进程资源分配情况：" << endl
         << "PID\tMax\t\tAllocation\tNeed" << endl;
    for (int i = 0; i < processNum; i++)
    {
        cout << "P" << i << "\t" << maxRequest[i] << "\t\t" << allocation[i] << "\t\t" << need[i] << endl;
    }
}
void BankerAlgorithm::DisplaySafe(const Resource &work, int i)
{
    cout << "P" << i << "\t" << work << "\t\t" << allocation[i] << "\t\t" << need[i] << "\t\t"
         << allocation[i] + work << endl;
}
bool BankerAlgorithm::NotNeed(int i)
{
    return need[i].IsAllZero();
}
bool BankerAlgorithm::CheckSafe()
{
    int safeIndex = 0;
    int allFinish = 0;
    Resource work(resourceNum, available);
    int r = 0;
    int temp = 0;
    int pNum = 0;
    for (int i = 0; i < processNum; i++)
    {
        if (NotNeed(i))
        {
            Finish[i] = true;
            allFinish++;
        }
        else
        {
            Finish[i] = false;
        }
    }
    while (allFinish != processNum)
    {
        num = 0;
        for (int i = 0; i < resourceNum; i++)
        {
            if (need[r][i] <= work[i] && !Finish[r])
            {
                num++;
            }
        }
        if (num == resourceNum)
        {
            work = work + allocation[r];
            allFinish++;
            DisplaySafe(work, r);
            safeSeries[safeIndex] = r;
            safeIndex++;
            Finish[r] = true;
        }
        r++;
        if (r >= processNum)
        {
            r %= processNum;
            if (temp == allFinish)
            {
                break;
            }
            temp = allFinish;
        }
        pNum = allFinish;
    }
    for (int i = 0; i < processNum; i++)
    {
        if (!Finish[i])
        {
            cout << "当前系统不安全。" << endl;
            return false;
        }
    }
    cout << "当前系统安全。" << endl
         << "安全序列为：";
    for (int i = 0; i < processNum; i++)
    {
        if (NotNeed(i))
        {
            pNum--;
        }
    }
    for (int i = 0; i < pNum; i++)
    {
        cout << safeSeries[i] << " ";
    }
    return true;
}