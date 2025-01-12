/**
 * number: 88
 * name: Merge Sorted Array
 * link: https://leetcode.com/problems/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define DEBUG

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int remainingN = m, nums1Pos = 0, nums2Pos = 0, outPos = 0;
        vector<int> merged(m + n);

        while (nums2Pos < n && remainingN > 0)
        {
            if (nums1[nums1Pos] <= nums2[nums2Pos])
            {
                merged[outPos++] = nums1[nums1Pos++];
                remainingN--;
            }
            else
            {
                merged[outPos++] = nums2[nums2Pos++];
            }
        }

        cout << "remainingN: " << remainingN << " ";
        cout << "nums1 pos: " << nums1Pos << " nums2 pos: " << nums2Pos << " outPos: " << outPos << "\n";

        if (remainingN == 0)
        {
            copy(nums2.begin() + nums2Pos, nums2.end(), merged.begin() + outPos);
        }
        else if (nums2Pos == n)
        {
            copy(nums1.begin() + nums1Pos, nums1.begin() + m, merged.begin() + outPos);
        }

        nums1 = merged;
    }
};

#ifdef DEBUG
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

    vector<int> v1 = {1};
    vector<int> v2 = {};

    s.merge(v1, 1, v2, 0);
    print(v1);

    return 0;
}

#endif
