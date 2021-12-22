#include <vector>
class RequestPageStorageAlgorithm
{
private:
    int m_memorySize;
    int m_addressNumber;
    int m_pageSize;
    int m_tableSize;
    vector<int> m_address;
    vector<int> m_page;

public:
    RequestPageStorageAlgorithm(int memorySize, int addressNumber, int pageSize, int windowSize);
    void CreateAddress();
    void CalcPage();
    void Optimal();
    void LeastRecentlyUsed();
    int GetMemorySize();
    int GetAddressNumber();
    int GetPageSize();
    int GetTableSize();
    void ShowAddress();
    void ShowPage();
};