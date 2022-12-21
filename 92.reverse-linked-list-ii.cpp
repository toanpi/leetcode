/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *node = head;
        ListNode *pre = head;
        ListNode *end = nullptr;
        ListNode *begin = nullptr;
        ListNode *lNode = node;
        int i = 1;

        while (node && i <= right)
        {

            if (i < left)
            {
                begin = node;
            }
            else if (i == left)
            {
                lNode = node;
            }
            else if (i > left)
            {
                ListNode *next = node->next;
                node->next = pre;
                pre = node;
                node = next;
            }
            else if (i == right)
            {
                ListNode *rNode = node;

                begin->next = rNode;
                rNode->next = pre;
                lNode = rNode->next;
            }

            ++i;
        }


        return head;
    }
};
// @lc code=end
