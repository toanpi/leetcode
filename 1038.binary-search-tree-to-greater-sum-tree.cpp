/*
 * @lc app=leetcode id=1038 lang=cpp
 *
 * [1038] Binary Search Tree to Greater Sum Tree
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
    int build(TreeNode *root, int preVal)
    {
        if(!root) return preVal;
        root->val += build(root->right, preVal);
        return build(root->left, root->val);
    }

    TreeNode *bstToGst(TreeNode *root)
    {
        build(root, 0);
        return root;
    }
};
// @lc code=end
