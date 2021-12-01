#include "Process Scheduling Algorithm.cpp"
int main()
{
    cout << "请选择调度算法：" << endl
         << "1. 优先数调度算法；" << endl
         << "2. 简单轮转调度算法。" << endl;
    char choice;
    cin >> choice;
    ProcessSchedulingAlgorithm scheduling(5);
    switch (choice)
    {
    case '1':
        cout << "使用优先数调度算法进行调度。" << endl;
        scheduling.PriorityScheduling();
        break;
    case '2':
        cout << "使用简单轮转调度算法进行调度。" << endl;
        scheduling.RoundRobin();
        break;
    default:
        break;
    }
    cout << "运行完毕。" << endl;
    return 0;
}