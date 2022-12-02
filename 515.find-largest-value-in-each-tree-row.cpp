/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    void build(TreeNode *node, int depth, vector<int> &db)
    {
        if (!node)
        {
            return;
        }

        if (depth >= db.size())
        {
            db.push_back(node->val);
        }
        else
        {
            db[depth] = max(db[depth], node->val);
        }

        build(node->left, depth + 1, db);
        build(node->right, depth + 1, db);
    }

    vector<int> largestValues(TreeNode *root)
    {
        vector<int> db;

        build(root, 0, db);

        return db;
    }
};
// @lc code=end
