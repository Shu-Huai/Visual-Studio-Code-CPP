#include <iostream>
using namespace std;
class VeryLongInt
{
public:
    VeryLongInt(int length);
    VeryLongInt(const char *number);
    void Show() const;
    void DeleteZero();
    VeryLongInt operator+(const VeryLongInt &number);

protected:
    int *m_numbers;
    int m_length;
};