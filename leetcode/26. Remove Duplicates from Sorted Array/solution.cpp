/**
 * number: 26
 * name: Remove Duplicates from Sorted Array
 * link: https://leetcode.com/problems/
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define DEBUG

class Solution
{
public:
    int removeDuplicatesWithSet(vector<int>& nums)
    {
        set<int> s(nums.begin(), nums.end());
        vector<int> v(s.begin(), s.end());
        nums = v;

        return v.size();
    }
    int removeDuplicates(vector<int>& nums)
    {
        auto pos = nums.begin();

        for (auto i = nums.begin(); i != nums.end(); i++)
        {
            if (*pos == *i) continue;

            pos++;
            *pos = *i;
        }

        return pos - nums.begin() + 1;
    }
};

#ifdef DEBUG
#include <vector>
#define FASTIO std::cin.tie(0); std::cout.tie(0); std::ios::sync_with_stdio(0);

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
    std::vector<int> nums = {1, 1, 2};
    int k = s.removeDuplicates(nums);

    print(nums);
    std::cout << "result k: " << k << std::endl;

    return 0;
}

#endif
