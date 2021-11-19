#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x == 0)
        {
            return true;
        }
        if (x < 0 || x % 10 == 0)
        {
            return false;
        }
        int reversed = 0;
        while (x > reversed)
        {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return x == reversed || x == reversed / 10;
    }
};
int main()
{
    Solution solution;
    cout << solution.isPalindrome(12321);
    return 0;
}