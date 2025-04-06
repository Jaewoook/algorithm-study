/**
 * number: 80
 * name: Remove Duplicates from Sorted Array II
 * link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
 */

#include <stdint.h>

#include <vector>
#include <iostream>

using namespace std;
#define DEBUG

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        vector<int> result;
        uint32_t base = 0;

        for (uint32_t i = 0; i < nums.size(); i++)
        {
            if (i - base == 0)
            {
                result.push_back(nums[i]);
            }
            else if (i - base == 1)
            {
                result.push_back(nums[i]);
                if (nums[i - 1] != nums[i])
                {
                    base = i;
                }
            }
            else if (nums[base] != nums[i])
            {
                result.push_back(nums[i]);
                base = i;
            }
        }

        nums = result;
        return result.size();
    }
};

#ifdef DEBUG
#include <vector>
#define FASTIO        \
    std::cin.tie(0);  \
    std::cout.tie(0); \
    std::ios::sync_with_stdio(0);

void print(vector<int> v, bool vertical = false)
{
    for (auto i = v.begin(); i != v.end(); i++)
    {
        std::cout << *i;
        if (vertical)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    FASTIO;
    Solution s;

    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    vector<int> nums2 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    vector<int> nums3 = {1, 2, 2, 2};
    std::cout << s.removeDuplicates(nums1) << std::endl;
    print(nums1);
    std::cout << s.removeDuplicates(nums2) << std::endl;
    print(nums2);
    std::cout << s.removeDuplicates(nums3) << std::endl;
    print(nums3);
    return 0;
}

#endif
