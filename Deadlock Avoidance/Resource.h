#include <iostream>
using namespace std;
class Resource
{
private:
    int m_number;
    int *m_resources;

public:
    Resource(int number = 0, int *resources = nullptr);
    ~Resource();
    bool IsFinished();
    Resource operator+(const Resource &resource);
    Resource &operator=(const Resource &resource);
    int &operator[](int i);
    friend ostream &operator<<(ostream &out, const Resource &resource);
};