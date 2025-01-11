/**
 * number: 2
 * name: Add two Numbers
 * link: https://leetcode.com/problems/add-two-numbers/
 */

#include <iostream>

using namespace std;
// #define DEBUG

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void print()
    {
        ListNode *l = next;
        std::cout << val << " ";
        while (l)
        {
            std::cout << l->val << " ";
            l = l->next;
        }
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void carryOver(ListNode *l)
    {
        while (l)
        {
            if (l->val < 10)
            {
                l = l->next;

                continue;
            };

            l->val -= 10;

            if (!l->next)
            {
                ListNode *next = new ListNode(1);
                l->next = next;
            }
            else
            {
                l->next->val++;
            }

            if (l->val > 9)
            {
                continue;
            }
            l = l->next;
        }
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *r = l1;
        while (l1->next && l2->next)
        {
            l1->val += l2->val;

            l1 = l1->next;
            l2 = l2->next;
        }
        l1->val += l2->val;

        if (l2->next)
        {
            l1->next = l2->next;
        }
        carryOver(r);

        return r;
    }
};

#ifdef DEBUG
#define FASTIO        \
    std::cin.tie(0);  \
    std::cout.tie(0); \
    std::ios::sync_with_stdio(0);

int main()
{
    // FASTIO;
    Solution s;

    ListNode l1(2, new ListNode(4, new ListNode(3)));
    ListNode l2(5, new ListNode(6, new ListNode(4)));

    s.addTwoNumbers(&l1, &l2)->print();
    std::cout << std::endl;
    return 0;
}

#endif
