#include <array>
#include <iostream>
using namespace std;
int main()
{
    array<int, 8> test0;
    int length = test0.size();
    for (int i = 0; i < 8; i++)
    {
        test0[i] = i;
    }
    auto a = test0.rbegin();
    array<int, 8> test1 = {8};
    test1.fill(9);
    test0.swap(test1);
    for (auto i : test0)
    {
        cout << i << " ";
    }
    return 0;
}