/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 */
#include "cpp_h.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s = to_string(root->val);

        if (root->left)
        {
            s += " " + serialize(root->left);
        }

        if (root->right)
        {
            s += " " + serialize(root->right);
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *decode(vector<int> &val, int idx)
    {
        TreeNode *node = new TreeNode(val[idx]);

        if (val[idx + 1] < val[idx])
        {
            node->left = decode(val, idx + 1);
        }

        if (val[idx + 2] > val[idx])
        {
            node->right = decode(val, idx + 2);
        }

        return node;
    }

    TreeNode *deserialize(string data)
    {
        vector<int> val;
        string n = "";

        for (int i = 0; i < data.size(); ++i)
        {
            n = data[i] != ' ' ? n + data[i] : n;

            if (n.size() && (i == data.size() - 1 || data[i] == ' '))
            {
                val.push_back(stoi(n));
                n = "";
            }
        }

        return decode(val, 0);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
