/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    void travel(TreeNode *node, int targetSum, vector<vector<int>> &ret, vector<int> &path)
    {
        if (!node)
        {
            return;
        }

        path.push_back(node->val);

        if (!node->left && !node->right)
        {
            if (targetSum == node->val)
            {
                ret.push_back(path);
            }
        }
        else
        {
            travel(node->left, targetSum - node->val, ret, path);
            travel(node->right, targetSum - node->val, ret, path);
        }

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ret;
        vector<int> path;

        travel(root, targetSum, ret, path);

        return ret;
    }
};
// @lc code=end
