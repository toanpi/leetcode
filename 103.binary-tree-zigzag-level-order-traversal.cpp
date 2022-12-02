/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    void build(TreeNode *node, int depth, vector<vector<int>> &ret)
    {
        if (!node)
        {
            return;
        }

        if (depth >= ret.size())
        {
            ret.push_back({node->val});
        }
        else
        {
            ret[depth].push_back(node->val);
        }

        build(node->left, depth + 1, ret);
        build(node->right, depth + 1, ret);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;

        build(root, 0, ret);

        for (int i = 0; i < ret.size(); i++)
        {
            if (i % 2)
            {
                reverse(ret[i].begin(), ret[i].end());
            }
        }

        return ret;
    }
};
// @lc code=end
