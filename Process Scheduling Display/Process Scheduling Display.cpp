#include "Process Scheduling.cpp"
int main()
{
    cout << "请选择调度算法：" << endl
         << "1. 优先级调度算法；" << endl
         << "2. 时间片轮转调度算法。" << endl;
    char choice;
    cin >> choice;
    ProcessScheduling scheduling(5);
    switch (choice)
    {
    case '1':
        scheduling.PriorityScheduling();
        break;
    case '2':
        scheduling.RoundRobin();
        break;
    default:
        break;
    }
    cout << "运行完毕。" << endl;
    return 0;
}