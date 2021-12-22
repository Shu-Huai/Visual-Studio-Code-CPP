using namespace std;
#include "Request Page Storage Algorithm.cpp"
int main()
{
    RequestPageStorageAlgorithm algorithm(32768, 256, 4096, 5);
    cout << "内存大小：" << algorithm.GetMemorySize() << "字节。" << endl
         << "指令总数：" << algorithm.GetAddressNumber() << "条。" << endl
         << "页面大小：" << algorithm.GetPageSize() << "字节。" << endl
         << "页表容量：" << algorithm.GetTableSize() << endl;
    algorithm.ShowAddress();
    algorithm.ShowPage();
    algorithm.Optimal();
    algorithm.LeastRecentlyUsed();
    return 0;
}