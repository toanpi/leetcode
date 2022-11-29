/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
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
    vector<int> nextLargerNodes(ListNode *head)
    {
        {ios_base::sync_with_stdio(false);cin.tie(nullptr);}

        ListNode *node = head;
        vector<int> db;
        vector<int> ret;

        while (node)
        {
            ret.push_back(node->val);
            db.push_back(ret.size() - 1);

            if (node->next)
            {
                for (auto it = db.rbegin(); it != db.rend() && ret[*it] < node->next->val; it++)
                {
                    ret[*it] = node->next->val;
                    db.pop_back();
                }
            }
            else
            {
                for (auto i : db)
                {
                    ret[i] = 0;
                }
            }

            node = node->next;
        }


        return ret;
    }
};
// @lc code=end
