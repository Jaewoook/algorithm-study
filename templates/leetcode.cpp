/**
 * number:
 * name:
 * link: https://leetcode.com/problems/
 */

#include <iostream>

using namespace std;
// #define DEBUG

class Solution
{
public:
    uint32_t solution()
    {
        return 0;
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

    std::cout << s.solution() << std::endl;
    return 0;
}

#endif
