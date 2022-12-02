/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */
#include "cpp_h.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void searching(TreeNode *root, int *k, int *val, bool *start)
    {
        if (!root || *val >= 0)
        {
            *start = true;
            return;
        }

        searching(root->left, k, val, start);

        *k += (*start) ? -1 : 0;
        *val = (*k == 0) ? root->val : *val;

        searching(root->right, k, val, start);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        int val = -1;
        bool start = false;

        searching(root, &k, &val, &start);

        return val;
    }
};
// @lc code=end
