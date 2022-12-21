/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 */
#include "cpp_h.h"

// @lc code=start
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        vector<int> d1;
        vector<int> d2;
        ListNode *node = l1;

        d1.reserve(101);
        d2.reserve(101);

        while (node)
        {
            d1.push_back(node->val);
            node = node->next;
        }

        node = l2;

        while (node)
        {
            d2.push_back(node->val);
            node = node->next;
        }

        int s1 = d1.size();
        int s2 = d2.size();
        vector<int>d;
        int n = 0;

        d.reserve(102);

        while (s1 || s2 || n)
        {
            n += s1 ? d1[--s1] : 0;
            n += s2 ? d2[--s2] : 0;

         
            d.push_back(n % 10);
            n /= 10;
        }

        node = nullptr;
        ListNode *root = nullptr;

        for (int i = d.size() - 1; i >= 0 ; --i)
        {
            ListNode *newNode = new ListNode(d[i]);

            if (node)
            {
                node->next = newNode;
            }
            else
            {
                root = newNode;
            }

            node = newNode;
        }

        return root;
    }
};
// @lc code=end
