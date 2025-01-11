/**
 * number: 1
 * name: Two Sum
 * link: https://leetcode.com/problems/two-sum/
 */

#include <iostream>
#include <vector>

using namespace std;
// #define DEBUG

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> r(2);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    r[0] = i;
                    r[1] = j;
                    return r;
                }
            }
        }

        return r;
    }
};

#ifdef DEBUG
#define FASTIO std::cin.tie(0); std::cout.tie(0); std::ios::sync_with_stdio(0);

int main()
{
    FASTIO;
    Solution s;

    std::cout << s.solution() << std::endl;
    return 0;
}

#endif
