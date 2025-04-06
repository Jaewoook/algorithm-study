/**
 * number: 189
 * name: Rotate Array
 * link: https://leetcode.com/problems/rotate-array
 */

#include <stdint.h>

#include <vector>
#include <iostream>

#define DEBUG

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        if (k == 0)
        {
            return;
        }
        vector<int> result(nums.size());
        uint32_t index = nums.size() - k;
        uint32_t insert_index = 0;

        while (insert_index < nums.size())
        {
            result[insert_index++] = nums[index++];
            index %= nums.size();
        }

        nums = result;
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

    std::vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    std::vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    std::vector<int> nums3 = {1};
    int k3 = 0;
    std::vector<int> nums4 = {-1};
    int k4 = 2;
    s.rotate(nums1, k1);
    print(nums1);
    s.rotate(nums2, k2);
    print(nums2);
    s.rotate(nums3, k3);
    print(nums3);
    s.rotate(nums4, k4);
    print(nums4);
    return 0;
}

#endif
