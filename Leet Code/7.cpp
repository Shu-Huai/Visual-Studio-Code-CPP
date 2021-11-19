#include <iostream>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        long result = 0;
        while (x)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result > INT_MAX || result < INT_MIN ? 0 : result;
    }
};
int main()
{
    Solution solution;
    cout << solution.reverse(123);
    return 0;
}