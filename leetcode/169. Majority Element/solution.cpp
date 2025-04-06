/**
 * number: 169
 * name: Majority Element
 * link: https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2https://leetcode.com/problems/envId=top-interview-150
 */

#include <stdint.h>

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
#define DEBUG

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<uint16_t, uint16_t> counter;
        int majority = 0;
        int num = 0;
        for (auto n : nums)
        {
            auto it = counter.find(n);
            uint16_t count = it == counter.end() ? 1 : it->second + 1;
            if (count > majority) {
                majority = count;
                num = n;
            }

            if (count == 1) {
                counter.insert({n, 1});
            } else {
                it->second++;
            }
        }

        return num;
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

    vector<int> nums1 = {3, 2, 3};
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    std::cout << s.majorityElement(nums1) << std::endl;
    std::cout << s.majorityElement(nums2) << std::endl;
    return 0;
}

#endif
