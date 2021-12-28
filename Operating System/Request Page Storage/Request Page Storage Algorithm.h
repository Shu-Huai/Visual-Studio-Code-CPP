#include <vector>
using namespace std;
class RequestPageStorageAlgorithm
{
private:
    int m_virtualMemorySize;
    int m_instructionNumber;
    int m_pageSize;
    int m_realMemorySize;
    vector<int> m_address;
    vector<int> m_page;

public:
    RequestPageStorageAlgorithm(int virtualMemorySize, int instructionNumber, int pageSize, int realMemorySize);
    void CreateAddress();
    void CalcPage();
    void Optimal();
    void LeastRecentlyUsed();
    int GetVirtualMemorySize();
    int GetInstructionNumber();
    int GetPageSize();
    int GetRealMemorySize();
    void ShowAddress();
    void ShowPage();
};