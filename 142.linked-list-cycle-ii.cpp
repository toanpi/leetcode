/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

#include "cpp_h.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *node)
    {
        while (node && node->val <= (int)(1e5))
        {
            node->val += 2e5 + 1;
            node = node->next;
        }

        return node;
    }
};
// @lc code=end

