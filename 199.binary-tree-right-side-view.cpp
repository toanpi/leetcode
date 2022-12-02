/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    void travel(TreeNode *node, vector<int> &db, int level)
    {
        if (!node)
        {
            return;
        }

        if(level >= db.size())
        {
            db.push_back(node->val);
        }

        travel(node->right, db, level + 1);
        travel(node->left, db, level + 1);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> db;

        travel(root, db, 0);

        return db;
    }
};
// @lc code=end
