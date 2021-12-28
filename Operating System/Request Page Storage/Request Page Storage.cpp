#include "Request Page Storage Algorithm.cpp"
int main()
{
    RequestPageStorageAlgorithm algorithm(32768, 256, 4096, 5);
    cout << "虚存容量" << algorithm.GetVirtualMemorySize() << "字节。" << endl
         << "指令总数：" << algorithm.GetInstructionNumber() << "条。" << endl
         << "页面大小：" << algorithm.GetPageSize() << "字节。" << endl
         << "实存容量" << algorithm.GetRealMemorySize() << "页。" << endl;
    algorithm.ShowAddress();
    algorithm.ShowPage();
    algorithm.Optimal();
    algorithm.LeastRecentlyUsed();
    return 0;
}