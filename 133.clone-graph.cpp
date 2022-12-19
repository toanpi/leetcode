/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */
#include "cpp_h.h"

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *clone(Node *node, vector<Node *> &db)
    {
        if (!db[node->val])
        {
            db[node->val] = new Node(node->val);

            for (auto n : node->neighbors)
            {
                db[node->val]->neighbors.push_back(clone(n, db));
            }
        }

        return db[node->val];
    }

    Node *cloneGraph(Node *node)
    {
        vector<Node *> db(101, nullptr);
        return node ? clone(node, db) : node;
    }
};

// @lc code=end
