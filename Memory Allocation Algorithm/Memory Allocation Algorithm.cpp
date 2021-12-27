#include "Allocation Algorithm.cpp"
int main()
{
    int memorySize = 0;
    cout << "请输入系统中的空闲区个数：";
    cin >> memorySize;
    Partition *freePartition = new Partition[memorySize]{0};
    for (int i = 0; i < memorySize; i++)
    {
        int size = 0;
        int address = 0;
        cout << "请输入第" << i + 1 << "个空闲区的大小和首地址：";
        cin >> size >> address;
        freePartition[i] = Partition(size, address);
    }
    int count = 0;
    cout << "请输入分配轮数：";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int jobNumber = 0;
        cout << "请输入第" << i + 1 << "轮分配的作业个数：";
        cin >> jobNumber;
        int *jobs = new int[jobNumber];
        for (int j = 0; j < jobNumber; j++)
        {
            cout << "请输入第" << j + 1 << "个作业的内存需求：";
            cin >> jobs[j];
        }
        AllocationAlgorithm allocationAlgorithm = 0;
        for (int j = 0; j < 3; j++)
        {
            allocationAlgorithm = AllocationAlgorithm(memorySize, memorySize, freePartition);
            string method[3] = {"首次", "最佳", "最坏"};
            string key[3] = {"address", "size", "size"};
            bool reverse[3] = {false, false, true};
            cout << "使用" << method[j] << "适应算法分配内存：";
            for (int k = 0; k < jobNumber; k++)
            {
                cout << jobs[k] << (k == jobNumber - 1 ? "。" : "，");
            }
            FreePartitionTable temp = allocationAlgorithm.GetFreePartitionTable();
            temp.Sort(key[j], reverse[j]);
            allocationAlgorithm.SetFreePartitionTable(temp);
            allocationAlgorithm.ShowFreePartition();
            for (int k = 0; k < jobNumber; k++)
            {
                cout << "分配" << jobs[k] << "空间";
                bool (AllocationAlgorithm ::*allocation)(int) = nullptr;
                switch (j)
                {
                case 0:
                    allocation = &AllocationAlgorithm::FirstFit;
                    break;
                case 1:
                    allocation = &AllocationAlgorithm::BestFit;
                    break;
                case 2:
                    allocation = &AllocationAlgorithm::WorstFit;
                    break;
                default:
                    break;
                }
                cout << ((allocationAlgorithm.*allocation)(jobs[k]) ? "成功" : "失败") << "。";
                allocationAlgorithm.ShowFreePartition();
            }
        }
        delete[] jobs;
    }
    delete[] freePartition;
    return 0;
}