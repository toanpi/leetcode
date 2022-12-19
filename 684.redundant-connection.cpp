/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

#include "cpp_h.h"

// @lc code=start
class Solution
{
public:
    int find(vector<int> &parent, int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent, parent[x]);
        }

        return parent[x];
    }

    bool Union(vector<int> &parent, int x, int y, vector<int> &rank)
    {
        x = find(parent, x);
        y = find(parent, y);

        if (x != y)
        {
            if (rank[x] > rank[y])
            {
                parent[y] = x;
            }
            else if (rank[x] < rank[y])
            {
                parent[x] = y;
            }
            else
            {
                parent[x] = y;
                rank[y]++;
            }

            return true;
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);

        while (n)
        {
            parent[n] = n;
            n--;
        }

        for (auto ed : edges)
        {
            if (!Union(parent, ed[0], ed[1], rank))
            {
                return ed;
            }
        }

        return vector<int>{};
    }
};
// @lc code=end
