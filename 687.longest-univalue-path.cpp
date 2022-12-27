/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
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
    int lenght(TreeNode *node, int *maxLen)
    {
        if (!node)
        {
            return 0;
        }

        int leftL = node->left && node->left->val == node->val ? 1 : 0;
        int rightL = node->right && node->right->val == node->val ? 1 : 0;

        int maxL = lenght(node->left, maxLen);
        int maxR = lenght(node->right, maxLen);

        if (leftL)
        {
            leftL += maxL;
        }

        if (rightL)
        {
            rightL += maxR;
        }

        *maxLen = max(*maxLen, leftL + rightL);

        return max(rightL, leftL);
    }

    int longestUnivaluePath(TreeNode *root)
    {
        int maxLen = 0;

        lenght(root, &maxLen);

        return maxLen;
    }
};
// @lc code=end
