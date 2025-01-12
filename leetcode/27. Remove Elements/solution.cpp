/**
 * number: 27
 * name: Remove Elements
 * link: https://leetcode.com/problems/
 */

#include <iostream>
#include <vector>

using namespace std;
#define DEBUG

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int k = nums.size();
        for (auto i = nums.begin(); i != nums.end();)
        {
            if (*i != val)
            {
                i++;
                continue;
            }
            nums.erase(i);
            k--;
        }

        return k;
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

    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int k = 2;
    int resultK = s.removeElement(nums, k);

    print(nums);
    std::cout << "result K: " << resultK << std::endl;

    return 0;
}

#endif
