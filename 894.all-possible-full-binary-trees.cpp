/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
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
    void build(int n, vector<TreeNode *> &list, string &tree)
    {
        if (n == 0)
        {
        }

        if (n >= 2)
        {
            tree += 'l';
            build(n - 2, list, tree);
            tree.pop_back();

            tree += 'r';
            build(n - 2, list, tree);
            tree.pop_back();
        }
    }

    vector<TreeNode *> allPossibleFBT(int n)
    {
        vector<TreeNode *> list;
        string tree = "r";

        build(n - 1, list, tree);

        return list;
    }
};
// @lc code=end
