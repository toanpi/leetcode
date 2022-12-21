/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *node = head;
        ListNode *pre = nullptr;
        ListNode *root = head;

        while (node && node->next)
        {
            ListNode *next = node->next;

            pre ? pre->next = next : root = next;

            node->next = next->next;
            next->next = node;

            pre = node;
            node = node->next;
        }

        return root;
    }
};
// @lc code=end
