#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < (int)nums.size(); i++)
        {
            for (int j = i + 1; j < (int)nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return vector<int>({i, j});
                }
            }
        }
        return vector<int>();
    }
};
int main()
{
    Solution solution;
    vector<int> source({3, 2, 4});
    vector<int> result = solution.twoSum(source, 6);
    if (result.size())
    {
        cout << result[0] << ", " << result[1] << endl;
    }
    return 0;
}