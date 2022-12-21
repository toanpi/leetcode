/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *node = head;
        ListNode *root = head;
        ListNode *pre = nullptr;
        int val = INT_MIN;

        while (node)
        {
            if (node->val == val || (node->next && node->val == node->next->val))
            {
                val = node->val;
                pre ? pre->next = node->next : root = node->next;
            }
            else
            {
                pre = node;
            }

            node = node->next;
        }

        return root;
    }
};
// @lc code=end
